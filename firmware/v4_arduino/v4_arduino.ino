#include <TMC2209.h>
#include <arduino-timer.h>
#include <LiquidCrystal.h>

/*
 * This is a first pass at making V4 work. I'm going just for "Manual Mode" right now;
 * accepting commands is for later.
 * 
 * I'm thinking of this as something that will probably get thrown away; I'm realizing
 * that as constructed, there's gonna be a huge challenge here around stepper driving.
 * I think that it will probably make sense to fork Klipper or a similar 3D printer
 * firmware in order to adopt their concurrency model; OR we can try TMC429 chips
 * or similar to offload that work into an ASIC. (The internal pulse generator on
 * the TMC2209 seems too primitive to be reliable; we would need to either track
 * position by polling MSCNT, which sounds like it rolls over quite frequently, or
 * by inferring pulse count, which invites drift.
 */


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PIN ASSIGNMENTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ~~~~~~~~~~~~~~~~ Inputs ~~~~~~~~~~~~~~~~

// Joystick
const int PIN_JOYSTICK_DOWN = 53;
const int PIN_JOYSTICK_UP = 51;
const int PIN_JOYSTICK_LEFT = 49; // TODO is this actually how this works?
const int PIN_JOYSTICK_RIGHT = 47;

// Buttons
const int PIN_MOUSE_BTN = 41;  // this is gonna be fun to write
const int PIN_DODGE_BTN = 39;  // this is gonna be fun to write

// Switches
const int PIN_MANUAL_MODE_SW = 37;
const int PIN_DIRECT_MODE_SW = 35;

// LCD screen
// https://learn.adafruit.com/character-lcds/wiring-a-character-lcd
const int PIN_LCD_RS = 33;  // pin 4 on the LCD screen (1/24/24 first bringup: green)
const int PIN_LCD_EN = 31;  // pin 6 on the LCD screen (1/24/24 first bringup: blue)
const int PIN_LCD_D4 = 29;  // pin 11 on the LCD screen (1/24/24 first bringup: purple)
const int PIN_LCD_D5 = 27;  // pin 12 on the LCD screen (1/24/24 first bringup: gray)
const int PIN_LCD_D6 = 25;  // pin 13 on the LCD screen (1/24/24 first bringup: white)
const int PIN_LCD_D7 = 23;  // pin 14 on the LCD screen (1/24/24 first bringup: purple)

LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_EN, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7);


// ~~~~~~~~~~~~~~~~ Outputs ~~~~~~~~~~~~~~~~

// Motor control
const int PIN_MOTOR_L_STEP = 11;  // TODO FIXME
const int PIN_MOTOR_L_EN = 12;
const int PIN_MOTOR_L_DIR = 13;

const int PIN_MOTOR_R_STEP = 14;
const int PIN_MOTOR_R_EN = 15;
const int PIN_MOTOR_R_DIR = 16;

// Serial line shared between motor drivers (for currently)

const int PIN_SW_SERIAL_TX = 14;
const int PIN_SW_SERIAL_RX = 15;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ STATIC DATA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool modeManual = true;  // default to true for the moment (no alternative!)
bool modeDirect = false;  // 

int targetSpeedXmmps = 0;  // setpoint; will accelerate to/from this point
int targetSpeedYmmps = 0;

int instSpeedXmmps = 0;
int instSpeedYmmps = 0;

auto timer = timer_create_default();





// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETUP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void setup() {
  /* 
   * 
   */

  // ~~~~~~~~~~~~~~~~ LCD ~~~~~~~~~~~~~~~~

  lcd.begin(16, 2);


  // ~~~~~~~~~~~~~~~~ PINS ~~~~~~~~~~~~~~~~

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

  pinMode(PIN_MOTOR_L_STEP, OUTPUT);
  pinMode(PIN_MOTOR_L_EN, OUTPUT);
  pinMode(PIN_MOTOR_L_DIR, OUTPUT);
  pinMode(PIN_MOTOR_R_STEP, OUTPUT);
  pinMode(PIN_MOTOR_R_EN, OUTPUT);
  pinMode(PIN_MOTOR_R_DIR, OUTPUT);

  // ~~~~~~~~~~~~~~~~ TMC2209 ~~~~~~~~~~~~~~~~



  // ~~~~~~~~~~~~~~~~ INTERRUPTS ~~~~~~~~~~~~~~~~


  // ~~~~~~~~~~~~~~~~ TASKS ~~~~~~~~~~~~~~~~

  // TODO should we adjust refresh rate
  //timer.every(1, refresh_kinematics);


    // ~~~~~~~~ Game time :) ~~~~~~~~
  lcd.print("Cat Town 0.0.1");
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN LOOP WOO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void loop() {
  /*
   * Motor drive is currently done in the main loop. This is a kind of gnarly design decision,
   * very constraining, because it means that we need to constantly be coming back to service
   * the STEP pin. It also means we need to interleave the two motors which is also clunky.
   * 
   * Here I 
   *
   * TODO: should we either (A) use an offboard TMC429 or (B) fork a firmware codebase
   * that's got this figured out already such as Marlin?
   */

  timer.tick();

  delayMicroseconds(1);
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INTERRUPTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void refresh_kinematics() {

}

void joystick_down_isr() {
  int current_value = digitalRead(PIN_JOYSTICK_DOWN);
  
  // TODO bringup code remove me
  lcd.setCursor(0,0);
  if (current_value == LOW) {
    lcd.print("Joystick DOWN   ");
  } else {
    lcd.print("                ");
  }
}

void joystick_up_isr() {
  int current_value = digitalRead(PIN_JOYSTICK_UP);
  
  // TODO bringup code remove me
  lcd.setCursor(0,0);
  if (current_value == LOW) {
    lcd.print("Joystick UP     ");
  } else {
    lcd.print("                ");
  }
}

void joystick_left_isr() {
  int current_value = digitalRead(PIN_JOYSTICK_LEFT);
  
  // TODO bringup code remove me
  lcd.setCursor(0,0);
  if (current_value == LOW) {
    lcd.print("Joystick LEFT   ");
  } else {
    lcd.print("                ");
  }
}

void joystick_right_isr() {
  int current_value = digitalRead(PIN_JOYSTICK_RIGHT);
  
  // TODO bringup code remove me
  lcd.setCursor(0,0);
  if (current_value == LOW) {
    lcd.print("Joystick RIGHT  ");
  } else {
    lcd.print("                ");
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
  int current_value = digitalRead(PIN_MANUAL_MODE_SW);
  modeManual = (current_value == LOW);
  
  // TODO bringup code remove me
  lcd.setCursor(0,0);
  if (modeManual) {
    lcd.print("Manual mode ON  ");
  } else {
    lcd.print("Manual mode OFF ");
  }
}
void direct_mode_sw_isr() {
  int current_value = digitalRead(PIN_DIRECT_MODE_SW);
  
  modeDirect = (current_value == LOW);
  
  // TODO bringup code remove me
  lcd.setCursor(0,0);
  if (modeDirect) {
    lcd.print("Direct mode ON  ");
  } else {
    lcd.print("Direct mode OFF ");
  }
}
