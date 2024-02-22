#include <TMC2209.h>

HardwareSerial & usart = Serial3;
TMC2209 stepper_driver;


const long SERIAL_BAUD_RATE = 115200;
const int DELAY = 3000;

const int PIN_EN = 2;


void setup()
{
  // pinMode(PIN_EN, OUTPUT); may not need if using .enable()?

  Serial.begin(SERIAL_BAUD_RATE);

  Serial.println("Hi!!!");

  delay(10);

  // Set up TMC2209 driver
  stepper_driver.setup(usart, SERIAL_BAUD_RATE, TMC2209::SERIAL_ADDRESS_0);  // Set to whatever address (0 - 3)

  // Enable driver
  stepper_driver.enable();

  // Configure features
  stepper_driver.setMicrostepsPerStep(16);
  stepper_driver.setRunCurrent(50);         // 50% of max
  stepper_driver.setHoldCurrent(25);        // 25% of max
  stepper_driver.enableStealthChop();       // Non-quiet ops (enables SpreadCycle for higher speeds)

  Serial.println("Done with setup");
}

void loop()
{
  if (stepper_driver.isSetupAndCommunicating())
  {
    Serial.println("Stepper driver is setup and communicating!");
    Serial.println("Try turning driver power off to see what happens.");
  }
  else if (stepper_driver.isCommunicatingButNotSetup())
  {
    Serial.println("Stepper driver is communicating but not setup!");
    Serial.println("Running setup again...");
    stepper_driver.setup(usart, SERIAL_BAUD_RATE, TMC2209::SERIAL_ADDRESS_0); // Updated to use baud and serial address
  }
  else
  {
    Serial.println("Stepper driver is not communicating!");
    Serial.println("Try turning driver power on to see what happens.");
  }
  Serial.println();
  delay(DELAY);
}