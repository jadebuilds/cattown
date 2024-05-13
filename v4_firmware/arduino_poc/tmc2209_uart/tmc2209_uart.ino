#include <TMC2209.h>

HardwareSerial & usart = Serial3;
TMC2209 stepper_driver;


const long SERIAL_BAUD_RATE = 115200;
const int DELAY = 3000;

const int PIN_EN = 2;


void setup()
{
  pinMode(PIN_EN, OUTPUT);

  Serial.begin(SERIAL_BAUD_RATE);

  Serial.println("Hi!!!");

  delay(10);

  stepper_driver.setup(usart);
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
    stepper_driver.setup(usart);
  }
  else
  {
    Serial.println("Stepper driver is not communicating!");
    Serial.println("Try turning driver power on to see what happens.");
  }
  Serial.println();
  delay(DELAY);
}