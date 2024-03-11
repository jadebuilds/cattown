#include <LiquidCrystal.h>
#include <TMCStepper.h>
#include "kinematics.h"
#include "pwm.h"
#include <arduino-timer.h>


/*
 * This is a first pass at making V4 work. I'm going just for "Manual Mode" right now;
 * accepting commands is for later.
 * 
 * I'm writing for E-S Motor 4260BL motors, assuming a Maslow-style design with a cable
 * pull doing stabilization.
 * 
 */

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CONSTANTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// todo should these be #defines?
const int DEBUG_UART_BAUD = 115200;

// I'm going fairly slowly for the moment because I expect to introduce discontinuities
// into the PWM output each time we change the PWM duty cycle (I keep disabling and re-enabling
// those channels)
const int MAIN_LOOP_PERIOD_MILLIS = 100;  // used in a delay() call in each loop()

// How fast should a mouse accelerate? For my first pass I'll try 1G (9/8 m/s^2).
// With a 25 mm pulley diameter that works out to 
// dw/dt = a/r = (9.8 m/s^2) / (0.0125 m) * (60 s / 1 min) * (1 rev / 2π) = 7480 rpm/s
// So basically I'll allow the motor to ramp up to full over one second.
// Actually thinking about it I'm gonna use the Nice Round Number of 8000 rpm/s,
// which should work out to 1.07 G (very close) and invites a world of pleasant integral
// calculations. Also constitutes the motor spinning up fully over half a second which is
// nicne and round to think about.

// Note that I might move away from RPM as a measure of rotational speed but for now
// it seems both nicely legible and large enough to be pleasantly integral. So we're gonna
// stick with it for the moment and see how it feels.
//const int MAX_ACCEL_RPM_PER_S = 8000;

// Actually I want to accelerate much slower than that for testing. Let's do this (todo remove me)
const int MAX_ACCEL_RPM_PER_S = 200;

// How do pulses map to string length? Well, it's 12 pulses per rotation and 25 mm diameter:
// (pi * 25 mm / rotation) / (12 pulses/rotation) = 6.54498 mm/pulse. That's not a nice round 
// number. So I'm going to measure in **micrometers** for this conversion, which is a bizarre
// choice of unit but I'm going for it and we'll see what comes of it.
const int STRING_UM_PER_PULSE = 6545;

// In testing I'm finding that I can't get my steppers to spin faster than this without 
// starting to buzz and skip steps. Some work to do here around tuning SpreadCycle chopping
// to try to get it to run faster (or possibly checking out some of the other TMC chips, 2130
// I think?, that have a dedicated high-speed mode??)
const int MAX_RPM = 300;
const int MAX_NEG_RPM = -300;

// Leaving at the default number of microsteps for the moment.
const int MICROSTEPS = 8;

// TMC2209 sense resistor, corresponding to the board it's on. Presumably in ohms?
#define R_SENSE 0.11f // todo this is for SilentStepStick; assuming BigTreeTech has cloned this value?? but plz confirm

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PIN ASSIGNMENTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~ Front panel ~~~~~~~~~~~~~~~~

// Joystick
const int PIN_JOYSTICK_DOWN = 53;
const int PIN_JOYSTICK_UP = 51;
const int PIN_JOYSTICK_LEFT = 49; // TODO is this actually how this works?
const int PIN_JOYSTICK_RIGHT = 47;

// Buttons
const int PIN_MOUSE_BTN = 8;  // re-routed out of the 53-23 pin block so I could use pin 41 for PWM
const int PIN_DODGE_BTN = 9;  // re-routed out of the 53-23 pin block so I could use pin 39 for PWM

// Switches
const int PIN_MANUAL_MODE_SW = 37;
const int PIN_DIRECT_MODE_SW = 35;

// LCD screen
// https://learn.adafruit.com/character-lcds/wiring-a-character-lcd
const int PIN_LCD_RS = 33;  // pin 4 on the LCD screen (1/24/24 first bringup: green)
const int PIN_LCD_EN = 31;  // pin 6 on the LCD screen (1/24/24 first bringup: blue)
const int PIN_LCD_D4 = 29;  // pin 11 on the LCD screen (1/24/24 first bringup: purple)
const int PIN_LCD_D6 = 25;  // pin 13 on the LCD screen (1/24/24 first bringup: white)
const int PIN_LCD_D5 = 27;  // pin 12 on the LCD screen (1/24/24 first bringup: gray)
const int PIN_LCD_D7 = 23;  // pin 14 on the LCD screen (1/24/24 first bringup: purple)

LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_EN, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7);

// ~~~~~~~~~~~~~~~~ Motors ~~~~~~~~~~~~~~~~


struct MotorPins {
  PwmChannel pwmChannel;
  int pinStep;
  int pinEn;
  int pinDir;
  int pinStepFeedback;  // Second GPIO tied to the STEP line so that we can pulse-count the PWM peripheral
  int driverAddress;
  HardwareSerial & uart;
};

const MotorPins motorPins[2] = {
  // Motor 0
  {
    PWMH3,  // pin 41 is PC9 / PWMH3 (from the datasheet) (Jade's notes: "RM-ESMO-01E Bringup")
    41, // note that this isn't really used, we go through the PWM peripheral above
    2,  // enable
    4,  // direction
    3,  // step feedback
    0,  // both pins left low
    Serial3  // Using RX3/TX3 on pins 14/15
  },
  // Motor 1
  {
    PWMH2,  // pin 39 is PC7 / PWMH2 (from the datasheet)  (Jade's notes: "RM-ESMO-01E Bringup")
    39, // note that this isn't really used, we go through the PWM peripheral above
    5, // enable
    7, // direction
    6, // step feedback
    0,  // Currently using as its own address on a separate UART
    Serial2  // Using RX2/TX2 on pins 16/17 (split out for convenience)
  }
};




// **** 3/10/24: Switching back to stepper motors, redoing motor pin declarations
// **** (keeping this here in case I change my mind again again)

// struct MotorPins {
//   int speedControlPin;
//   int encoderFeedbackPin;
//   int directionPin;
//   PwmChannel pwmChannel;
// };

// // I was following a color scheme on the board which doesn't match the motor's color
// // scheme. We did the harness following the motor. Sooooo there's a color change at
// // the interface to the board. Sorry about that. I probably... could have... IDK,
// // done that in a less confusing way.
// const MotorPins motorPins[2] = {
//   { // Motor 0
//     41,  // speed (*special PWM-capable pin!*) (yellow on board, blue on harness)
//     12,  // encoder (*special PWM-capable pin!*) (brown on board, yellow on harness)
//     10,  // direction (blue on board, white on harness)
//     PWMH3,  // Motor 0 is wired to pin 41 on the Arduino, which maps to PC9 on the MCU / channel PWMH3
//   },
//   { // Motor 1
//     39,  // speed (special PWM-capable pin!) (yellow on board, blue on harness)
//     13,  // encoder (special PWM-capable pin!) (brown on board, yellow on harness)
//     11,  // direction (blue on board, white on harness)
//     PWMH2,  // Motor 1 is wired to pin 39 on the Arduino, which maps to PC7 on the MCU / channel PWMH2
//     }
// };


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GLOBAL PROGRAM STATE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool modeManual = true;  // There is no alternative!! for the moment
bool modeDirect;  // Will get filled in setup()

// 10 concurrent tasks, millisecond resolution
//https://github.com/contrem/arduino-timer
Timer<10, millis> timer;


enum RotationalDirection { CW, CCW };

struct MotorState {
  TMC2209Stepper & driver;
  int32_t targetRpm;
  // I'm sticking to integer math for the moment since I don't know fixed point (yet! eek) and 
  // the Due doesn't have an FPU so floating point math is slow as shit. The "string length change per pulse" 
  // calculation is always going to be approximate / non-integral because it involves pi; so to avoid drift
  // I'm going to track motor state as encoder pulse count (definitely integral, 12/rotation) and redo the string
  // length calculation each time I need it (to avoid accumulating error).
  // Note that pulse count is signed so that it can go negative to account for turning "the other direction".
  // 
  // Sign convention: ** positive is clockwise, negative is counterclockwise **
  int encoderPulseCount;
  // Similarly, calibration is done in terms of pulse count so I can do apples to apples. We'll figure
  // out how exactly to calibrate later...
  bool calibrated;
  int pulseCountZeroStringLength;
  RotationalDirection direction;  // actual direction set by control pin (should get synchronized with targetRpm)
  // TODO do I store measurements of actual inst speed?
};

// todo can I declare these in the struct below? are they even worth including in the struct? idk
TMC2209Stepper driver_0(&motorPins[0].uart, R_SENSE, motorPins[0].driverAddress);
TMC2209Stepper driver_1(&motorPins[1].uart, R_SENSE, motorPins[1].driverAddress);

// TODO implement calibration routine!!!!!
// For the moment I'm going to assume that we start with the carriage in the exact middle of the platform.
// This means we'll have to do it by hand -- power the thing off (or at least release motor control somehow)
// and spin the pulleys manually until the carriage is correctly positioned. (The stabilizer will probably
// fuck this up when added and we'll probably need to change the routine pretty quickly. Hopefully it gives
// us at least a known starting position, like pulls the carriage down to the bottom).
//
// So I'm just hard-coding the "zero string length" pulse count. Here's my math:
// String length: sqrt((4 feet / 2)^2 + (82" / 2)^2) = 47.5" = 1206.7 mm
// At 6.544 mm per pulse, that's 1206.7 / 6.544 = 184.3 pulses.
// Note that this does not account for a bunch of things, such as the width of the 2x4s and the offset of 
// the motors, and I'll need to do a more careful geometric accounting some time quite soon.
MotorState motorState[2] = {
  {driver_0, 0, 0, true, -184, CW},
  {driver_1, 0, 0, true, -184, CW},
};

// todo should I structify these numbers too ("carriageState" maybe)?
int targetSpeedXmmps = 0;  // In mm/s to keep it as a nice big integer
int targetSpeedYmmps = 0;

int instSpeedXmmps = 0; // todo is this needed
int instSpeedYmmps = 0;

struct {
  bool up;
  bool down;
  bool left;
  bool right;
} joystickState {false, false, false, false};



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TIMER FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Declared above setup() because apparently in C++ functions have to be declared before they're used,
// top to bottom, even if they're used "later" in runtime by a function?? that's pretty surprising.

uint32_t temp_freq_readout[2] = { 0, 0 };

// Utility function to occasionally read out what's going on.
bool send_state_debug_message(void * /* unused */) { // n.b. function signature is set by the timer library
  char buffer[100]; // Ensure this buffer is large enough for the resulting string
  snprintf(buffer, sizeof(buffer), "Motor 0: %d RPM / %d Hz; Motor 1: %d RPM / %d Hz", motorState[0].targetRpm, temp_freq_readout[0], motorState[1].targetRpm, temp_freq_readout[1]);
  Serial.println(buffer);
  snprintf(buffer, sizeof(buffer), "Target RPM: Motor 0: %d; Motor 1: %d", motorState[0].targetRpm, motorState[1].targetRpm);
  return true;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ UTILITY FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Used to decrease speed at constant rate to zero... in direct mode, and maybe elsewhere.
// Should be added to the value of the thing you want to decrease:
// 
//     motorSpeed += decrease_to_zero(motorSpeed, acceleration_per_loop_time);
// 
// Note that I got this wrong first try but GPT got it right... sigh
int32_t decrease_to_zero(int32_t counter, uint32_t increment) {
  if (counter == 0) {
    return 0;
  }
  else if (counter > 0) {
    // If the counter is positive and greater than increment, decrease by increment.
    // Otherwise, just decrease it to zero.
    return (counter > increment) ? -static_cast<int32_t>(increment) : -counter;
  }
  else {
    // If the counter is negative and its absolute value is greater than increment,
    // increase by increment. Otherwise, just increase it to zero.
    return (abs(counter) > static_cast<int32_t>(increment)) ? increment : -counter;
  }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETUP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void setup() {
  /* 
   * Sets up pins, configures interrupts, starts the LCD screen manager, and so on. 
   * Does not do any active motor control, including calibration; that'll happen in loop().
   */


  // ~~~~~~~~~~~~~~~~ Initialize console log ~~~~~~~~~~~~~~~~
  Serial.begin(DEBUG_UART_BAUD);
  Serial.println("Starting setup()");


  // ~~~~~~~~~~~~~~~~ TMC2209 stepper drivers ~~~~~~~~~~~~~~~~

  Serial.println("    ... initializing motor drivers");

  motorPins[0].uart.begin(19200);
  motorPins[1].uart.begin(19200);

  motorState[0].driver.begin();
  motorState[1].driver.begin();

  // ~~~~~~~~~~~~~~~~ LCD ~~~~~~~~~~~~~~~~


  Serial.println("    ... initializing LCD screen");

  lcd.begin(16, 2);

  // ~~~~~~~~~~~~~~~~ PINS ~~~~~~~~~~~~~~~~

  Serial.println("    ... configuring pins");

  // Input pins, each with their own interrupt, all pulled up to 3.3V and switched to ground
  pinMode(PIN_MANUAL_MODE_SW, INPUT_PULLUP);
  pinMode(PIN_DIRECT_MODE_SW, INPUT_PULLUP);
  pinMode(PIN_JOYSTICK_LEFT, INPUT_PULLUP);
  pinMode(PIN_JOYSTICK_RIGHT, INPUT_PULLUP);
  pinMode(PIN_JOYSTICK_UP, INPUT_PULLUP);
  pinMode(PIN_JOYSTICK_DOWN, INPUT_PULLUP);
  pinMode(PIN_MOUSE_BTN, INPUT_PULLUP);
  pinMode(PIN_DODGE_BTN, INPUT_PULLUP);
  pinMode(PIN_DIRECT_MODE_SW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_MANUAL_MODE_SW), manual_mode_sw_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_DIRECT_MODE_SW), direct_mode_sw_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_JOYSTICK_LEFT), joystick_left_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_JOYSTICK_RIGHT), joystick_right_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_JOYSTICK_UP), joystick_up_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_JOYSTICK_DOWN), joystick_down_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_MOUSE_BTN), mouse_btn_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_DODGE_BTN), dodge_btn_isr, CHANGE);

  // Pin feedback pins: similar, but no pullup because we're counting the PWM GPIO to set level both ways
  // Also I'm triggering on rising edge so as to count each pulse only once
  pinMode(motorPins[0].pinStepFeedback, INPUT);
  pinMode(motorPins[1].pinStepFeedback, INPUT);
  attachInterrupt(digitalPinToInterrupt(motorPins[0].pinStepFeedback), motor0_encoder_isr, RISING);
  attachInterrupt(digitalPinToInterrupt(motorPins[1].pinStepFeedback), motor1_encoder_isr, RISING);

  pinMode(motorPins[0].pinEn, OUTPUT);
  pinMode(motorPins[1].pinEn, OUTPUT);
  pinMode(motorPins[0].pinDir, OUTPUT);
  pinMode(motorPins[1].pinDir, OUTPUT);
  // Note that pin mode for the PWM pins gets handled through setupPwm() -- don't need to pinMode them

  // ~~~~~~~~~~~~~~~~ PWM peripheral ~~~~~~~~~~~~~~~~

  Serial.println("    ... starting PWM peripheral");
  setupPwm(); // calls out to pwm.h to do register-level stuff

  // ~~~~~~~~~~~~~~~~ Initialize switch values ~~~~~~~~~~~~~~~~

  modeDirect = true;
  // modeDirect = (digitalRead(PIN_DIRECT_MODE_SW) == LOW);
  // TODO read in manual mode switch too (when this starts to matter)


// ~~~~~~~~~~~~~~~~ Start timers ~~~~~~~~~~~~~~~~

  timer.every(1000, send_state_debug_message);

  // ~~~~~~~~ Game time :) ~~~~~~~~
    Serial.println("    ... welcome message");
  lcd.print("Cat Town 0.0.2");
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN LOOP WOO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Some local state declared statically
int stringLength_mm_q8 [2];  // in millimeters, Q24.8
int stringLength_in[2];  // in inches, converted for the LUT (TODO redo the LUT in metric?)

void loop() {
  /*
   * I thought for a little while that we would do motor pulse generation/counting in the main loop,
   * but it turned out to be more straightforward to do elsewhere (counting in interrupts, generation
   * in the PWM peripheral). So this becomes relatively simple:
   * 
   * - Adjust string lengths based on the change in encoder position since last loop
   * - Adjust motor speed targets based on target acceleration requests from the joystick, bounded by string length
   *     - If mode is direct: directly set motor speed
   *     - Else: Look up partials from in LUT, multiply them in. Also look up X and Y and do some bounding.
   *       Maybe reduce speed target to slow to a stop at the edge of the platform????
   */

  timer.tick();  // advance the timer

  // ~~~~~~~~~~~~~~~~ Interpret joystick ~~~~~~~~~~~~~~~~

  // Direct mode: left/right controls Motor 0, up/down controls Motor 1.
  // Left and up "feel" more like retracting to me, right and down "feel" more like extending,
  // so that's how I've programmed it. We can always futz with this later.

  uint32_t accel = (MAX_ACCEL_RPM_PER_S * MAIN_LOOP_PERIOD_MILLIS) / 1000;

  if (modeDirect) {
    if (joystickState.left) {
      motorState[0].targetRpm -= accel;  // mouse go fast :shrug:
    } else if (joystickState.right) {
      motorState[0].targetRpm += accel;
    } else {
      motorState[0].targetRpm += decrease_to_zero(motorState[0].targetRpm, accel);
    }

    if (joystickState.up) {
      motorState[1].targetRpm -= accel;
    } else if (joystickState.down) {
      motorState[1].targetRpm += accel;
    } else {
      motorState[1].targetRpm += decrease_to_zero(motorState[1].targetRpm, accel);
    }
  }

  // X/Y mode: left/right and up/down map to actual X/Y motion.
  // This gets a little more complicated: we need to reach into the auto-generated LUT in kinematics.cpp
  // and look up mappings. I'm going to start with looking up the nearest based on the integral string length
  // and then worry about interpolation later.
  else {

    // ****** TODO FINISH MEEEEEEE THANKS <3 ****** //


    // TODO call out to a calibration routine as appropriate (probably a little FSM?)
    // stringLength_um[0] = (motorState[0].encoderPulseCount - motorState[0].pulseCountZeroStringLength) * STRING_UM_PER_PULSE;
    // stringLength_um[1] = (motorState[1].encoderPulseCount - motorState[1].pulseCountZeroStringLength) * STRING_UM_PER_PULSE;

    // stringLength_in[0] = stringLength_um[0] / 25400;  // Note that this rounds down to the nearest inch
    // stringLength_in[1] = stringLength_um[1] / 25400;

    // TODO handle errors
    // TODO debug

    // LocalKinematics kinematics = lookupTable[stringLength_in[1]][stringLength_in[0]];
    

    // TODO look up in LUT
    // TODO resolve unit mismatch between LUT (inches, sigh) and string length calc in UM
  }

  // ~~~~~~~~~~~~~~~~ Apply speed and acceleration limits ~~~~~~~~~~~~~~~~

  // todo
  for (int i = 0; i < 2; i++) {
    if (motorState[i].targetRpm > MAX_RPM) {
      motorState[i].targetRpm = MAX_RPM;
      
      lcd.setCursor(0,0);
      lcd.print("Motor speed max ");
    } 
    else if (motorState[i].targetRpm < MAX_NEG_RPM) {
      motorState[i].targetRpm = MAX_NEG_RPM;

      lcd.setCursor(0,0);
      lcd.print("Motor speed min ");
    }
  }

  // ~~~~~~~~~~~~~~~~ Send to motor ~~~~~~~~~~~~~~~~

  for (int i = 0; i < 2; i++) {
    uint32_t freq; // todo this won't get heap allocated will it?

    if (motorState[i].targetRpm > 0) {
      digitalWrite(motorPins[i].pinDir, LOW); // todo figure out this mapping on hardware
      motorState[i].direction = CW;  // todo get this mapping right
      freq = (motorState[i].targetRpm * MICROSTEPS * 200) / 60;  // One revolution is 200 fullsteps, 1 Hz is 1/60 minutes
    } else {
      digitalWrite(motorPins[i].pinDir, HIGH); // todo figure out this mapping
      motorState[i].direction = CCW; // todo get mapping right (as above)
      // todo is there a better way to abs() a signed integer than * -1?
      freq = (-1 * motorState[i].targetRpm * MICROSTEPS * 200) / 60;
    }
    temp_freq_readout[i] = freq;
    setPwmFrequency(motorPins[i].pwmChannel, freq);
  }
  
  // ~~~~~~~~~~~~~~~~ Sleep til next time ~~~~~~~~~~~~~~~~

  delay(MAIN_LOOP_PERIOD_MILLIS);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INTERRUPTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void motor0_encoder_isr() {
  if (motorState[0].direction == CW) {
    motorState[0].encoderPulseCount++;
  } else {
    motorState[0].encoderPulseCount--;
  }
}

void motor1_encoder_isr() {
  if (motorState[1].direction == CW) {
    motorState[1].encoderPulseCount++;
  } else {
    motorState[1].encoderPulseCount--;
  }
}

void joystick_down_isr() {
  joystickState.down = (digitalRead(PIN_JOYSTICK_DOWN) == LOW);
  if (joystickState.down) {
    lcd.setCursor(0,0);
    lcd.print("Joystick down!  ");
  }
}

void joystick_up_isr() {
  joystickState.up = (digitalRead(PIN_JOYSTICK_UP) == LOW);
  if (joystickState.up) {
    lcd.setCursor(0,0);
    lcd.print("Joystick up!    ");
  }
}

void joystick_left_isr() {
  joystickState.left = (digitalRead(PIN_JOYSTICK_LEFT) == LOW);
  if (joystickState.left) {
    lcd.setCursor(0,0);
    lcd.print("Joystick left!  ");
  }
}

void joystick_right_isr() {
  joystickState.right = (digitalRead(PIN_JOYSTICK_RIGHT) == LOW);
  if (joystickState.right) {
    lcd.setCursor(0,0);
    lcd.print("Joystick right! ");
    Serial.println("Joystick right pressed");
  } else {
    Serial.println("Joystick right released");
  }
}


void mouse_btn_isr() {
  int current_value = digitalRead(PIN_MOUSE_BTN);
  
  // TODO bringup code remove me
  lcd.setCursor(0,0);
  if (current_value == LOW) {
    lcd.print("Mouse button!   ");
  }
}

void dodge_btn_isr() {
  int current_value = digitalRead(PIN_DODGE_BTN);
  
  // TODO bringup code remove me
  lcd.setCursor(0,0);
  if (current_value == LOW) {
    lcd.print("Dodge button!   ");
  }
}

void manual_mode_sw_isr() {
  // Not currently used! We're always in manual mode. There is no autonomy
}

void direct_mode_sw_isr() {
  modeDirect = (digitalRead(PIN_DIRECT_MODE_SW) == LOW);
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ UTILITY FUNCTIONS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


const int MIN_DUTY_PCT = 35;
const int RPM_PER_DUTY_PCT = 90;


int dutyCycleFromRpm(int targetRpm) {
  /*
   * In testing of the first 4260BL I got my hands on, I observed great linearity between 35% and 85% duty cycle.
   * This is n=1 and so I really hope that they both behave this way... really don't want to have to 
   */
  
}

void fault() {
  lcd.setCursor(0,0);
  lcd.print("Faulted :(");
  lcd.setCursor(1,0);
  lcd.print("");
  disablePwmAllChannels();
}