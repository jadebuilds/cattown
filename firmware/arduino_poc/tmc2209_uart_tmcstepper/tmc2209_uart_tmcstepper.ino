/**
 * Author Teemu Mäntykallio
 * Initializes the library and runs the stepper
 * motor in alternating directions.
 */

#include <TMCStepper.h>

// MOTOR 0
// #define EN_PIN            2 // Enable
// #define DIR_PIN           4 // Direction
// #define STEP_PIN          3 // Step
// #define TMC_USART Serial3 // pins 14/15

// MOTOR 1
#define EN_PIN            5 // Enable
#define DIR_PIN           7 // Direction
#define STEP_PIN          6 // Step
#define TMC_USART Serial2 // pins 16/17

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

void setup() {
  pinMode(EN_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);      // Enable driver in hardware

                                  // Enable one according to your setup
//SPI.begin();                    // SPI drivers
  TMC_USART.begin(19200);      // HW UART drivers
  // driver.beginSerial(115200);     // SW UART drivers

  DEBUG_SERIAL.begin(115200);
  DEBUG_SERIAL.println("begin()...");

  driver.begin();                 //  SPI: Init CS pins and possible SW SPI pins
                                  // UART: Init SW UART (if selected) with default 115200 baudrate
  DEBUG_SERIAL.println("toff(5)");
  driver.toff(5);                 // Enables driver in software
  DEBUG_SERIAL.println("rms_current(600)");
  driver.rms_current(600);        // Set motor RMS current
  driver.microsteps(8);          // Set microsteps to 1/16th

//driver.en_pwm_mode(true);       // Toggle stealthChop on TMC2130/2160/5130/5160
  driver.en_spreadCycle(false);   // Toggle spreadCycle on TMC2208/2209/2224
  //driver.pwm_autoscale(true);     // Needed for stealthChop
}

bool shaft = false;

void loop() {
  // Run 5000 steps and switch direction in software
  for (uint16_t i = 2500; i>0; i--) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(160);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(160);
  }
  shaft = !shaft;
  driver.shaft(shaft);
  delayMicroseconds(10);
  bool shaft_state = driver.shaft();
  DEBUG_SERIAL.print("Shaft state: ");
  DEBUG_SERIAL.print(shaft_state);
  DEBUG_SERIAL.println();
}