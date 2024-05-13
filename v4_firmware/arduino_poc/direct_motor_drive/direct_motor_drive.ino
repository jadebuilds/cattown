// TODO two motors!
const int pwmPin = 9;
const int directionPin = 12;

int speed = 0; // -256 to 256
int direction = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwmPin, OUTPUT);
  pinMode(directionPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // Accept serial characters and change direction each time
  if (Serial.available() > 0) {
    char command = Serial.read();

    // Change speed based on key strokes
    if (command == 'a') {
      speed += 32;

      if (speed > 256) {
        speed = 256;
      }
    } 
    else if (command == 'd') {
      speed -= 32;

      if (speed < -256) {
        speed = -256;
      }
    }
    else if (command == 's') {
      speed = 0;
    }

    direction = (speed > 0) ? HIGH : LOW;

    digitalWrite(directionPin, direction);
    analogWrite(pwmPin, abs(speed));
  }

  delay(50);
}
