/**
 * Author Teemu Mäntykallio
 * Initializes the library and runs the stepper
 * motor in alternating directions.
 */

#include <TMCStepper.h>

#define EN_PIN            7 // Enable
#define DIR_PIN           5 // Direction
#define STEP_PIN          6 // Step
#define CS_PIN           42 // Chip select
#define SW_MOSI          66 // Software Master Out Slave In (MOSI)
#define SW_MISO          44 // Software Master In Slave Out (MISO)
#define SW_SCK           64 // Software Slave Clock (SCK)
#define SW_RX            63 // TMC2208/TMC2224 SoftwareSerial receive pin
#define SW_TX            40 // TMC2208/TMC2224 SoftwareSerial transmit pin
#define TMC_USART Serial1 // TMC2208/TMC2224 HardwareSerial port
#define DEBUG_SERIAL Serial  // Serial connection

#define DRIVER_ADDRESS 0b00 // TMC2209 Driver address according to MS1 and MS2

#define R_SENSE 0.11f // Match to your driver
                      // SilentStepStick series use 0.11
                      // UltiMachine Einsy and Archim2 boards use 0.2
                      // Panucatt BSD2660 uses 0.1
                      // Watterott TMC5160 uses 0.075

// Select your stepper driver type
//TMC2130Stepper driver(CS_PIN, R_SENSE);                           // Hardware SPI
//TMC2130Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK); // Software SPI
//TMC2660Stepper driver(CS_PIN, R_SENSE);                           // Hardware SPI
//TMC2660Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);
//TMC5160Stepper driver(CS_PIN, R_SENSE);
//TMC5160Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);

// TMC2208Stepper driver(&TMC_USART, R_SENSE);                     // Hardware Serial
//TMC2208Stepper driver(SW_RX, SW_TX, R_SENSE);                     // Software serial
TMC2209Stepper driver(&TMC_USART, R_SENSE, DRIVER_ADDRESS);
//TMC2209Stepper driver(SW_RX, SW_TX, R_SENSE, DRIVER_ADDRESS);

const unsigned long runDuration = 3000; // Duration to run before stopping and changing direction, in milliseconds
unsigned long lastStepTime = 0;
unsigned long lastDirectionChangeTime = 0;
int stepDelay = 1000;                   // Start with slow speed, maybe <500ms?
int minStepDelay = 9;                   // Target speed (~2000 RPM?)
int accelerationRate = 50;              // Acceleration rate
int decelerationRate = 50;              // Deceleration rate
bool direction = HIGH;                  // Direction flag, HIGH for one direction, LOW for the opposite
bool isRunning = true;                  // Indicates of the motor is running or stopped

void setup() {
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);      // Enable driver in hardware

                                  // Enable one according to your setup
//SPI.begin();                    // SPI drivers
  TMC_USART.begin(115200);      // HW UART drivers
  // driver.beginSerial(115200);     // SW UART drivers

  DEBUG_SERIAL.begin(115200);
  DEBUG_SERIAL.println("begin()...");

  driver.begin();                 //  SPI: Init CS pins and possible SW SPI pins
                                  // UART: Init SW UART (if selected) with default 115200 baudrate
  DEBUG_SERIAL.println("toff(5)");
  driver.toff(5);                 // Enables driver in software
  DEBUG_SERIAL.println("rms_current(600)");
  driver.rms_current(600);        // Set motor RMS current
  driver.microsteps(16);          // Set microsteps to 1/16th

//driver.en_pwm_mode(true);       // Toggle stealthChop on TMC2130/2160/5130/5160
//driver.en_spreadCycle(false);   // Toggle spreadCycle on TMC2208/2209/2224
  driver.pwm_autoscale(true);     // Needed for stealthChop
}

bool shaft = false;

void loop() {
  unsigned long currentTime = millis();

  // Check if it's time to decelerate and stop
  if (isRunning && currentTime - lastDirectionChangeTime >= runDuration) {
    isRunning = false;                      // Stop the motor after the run duration
  }

  unsigned long currentStepTime = micros();
  if (currentStepTime - lastStepTime >= stepDelay) {
    if (isRunning) {
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(1);               // Ensure the stop pulse is registered
      digitalWrite(STEP_PIN, LOW);
      lastStepTime = currentStepTime;

      // Accelerate to max speed if not at minStepDelay yet
      if (stepDelay > minStepDelay) {
        stepDelay -= accelerationRate;
      }
    } else {
      // Decelerate to stop if running
      if (stepDelay < maxStepDelay) {
        stepDelay += decelerationRate;
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(1);           // Ensure the stop pulse is registered
        digitalWrite(STEP_PIN, LOW);
        lastStepTime = currentStepTime;
      } else {
        // Once stopped, change direction and reset for the next run
        direction = !direction;
        digitalWrite(DIR_PIN, direction);
        lastDirectionChangeTime = currentTime;  // Reset the timer for direction change
        isRunning = true;               // Ready to run again
        stepDelay = 1000;               // Reset step delay to start slow again
      }
    }
  }

  // Run 5000 steps and switch direction in software
//   for (uint16_t i = 5000; i>0; i--) {
//     digitalWrite(STEP_PIN, HIGH);
//     delayMicroseconds(160);
//     digitalWrite(STEP_PIN, LOW);
//     delayMicroseconds(160);
//   }
//   shaft = !shaft;
//   driver.shaft(shaft);
}