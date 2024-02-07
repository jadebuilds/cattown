#include <TMC2209.h>
#include <arduino-timer.h>

int STP=7; //define Step pin
int DIR=6; //define Direction pin
int ENA=5; //define Enable Pin

TMC2209 stepper_driver;
int SW_SER_RX = 2;
int SW_SER_TX = 3;
SoftwareSerial swSerial = SoftwareSerial(SW_SER_RX, SW_SER_TX);

int dir = LOW;  // arbitrary direction

int sleepTime = 50;

void setup() {
  pinMode (STP, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
  swSerial.begin(9600);

  stepper_driver.setup(Serial); // I believe this calls Serial.begin() -- the docs don't ask you to separately begin() the serial cxn

  if (stepper_driver.isSetupAndCommunicating()) {
    swSerial.println("TMC2209 is happy!");
  } else {
    swSerial.println("TMC2209 is sad :(");
  }
}

void loop() {

  if (swSerial.available() > 0) {
    char command = swSerial.read();

    if (command == 'a') {
      sleepTime += 1;
    }
    else if (command == 'd') {
      sleepTime -= 1;

      if (sleepTime < 1) {
        sleepTime = 1;
      }
    }
    else if (command == 's') {
      if (dir == LOW) {
        dir = HIGH;
      }
      else {
        dir = LOW;
      }
    }
    swSerial.print(sleepTime);
  }

  for (int j=0; j<1000; j++)    //Forward 1000 steps (five revolutions)
  {
    digitalWrite(DIR,dir);
    digitalWrite(ENA,LOW);
    digitalWrite(STP,HIGH);
    delayMicroseconds(sleepTime);
    digitalWrite(STP,LOW);
    delayMicroseconds(sleepTime);
  }
}