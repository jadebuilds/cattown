#include <LiquidCrystal.h>
#include <string>


// https://learn.adafruit.com/character-lcds/wiring-a-character-lcd
const int PIN_LCD_RS = 33;  // pin 4 on the LCD screen (1/24/24 first bringup: green)
const int PIN_LCD_EN = 31;  // pin 6 on the LCD screen (1/24/24 first bringup: blue)
const int PIN_LCD_D4 = 29;  // pin 11 on the LCD screen (1/24/24 first bringup: purple)
const int PIN_LCD_D5 = 27;  // pin 12 on the LCD screen (1/24/24 first bringup: gray)
const int PIN_LCD_D6 = 25;  // pin 13 on the LCD screen (1/24/24 first bringup: white)
const int PIN_LCD_D7 = 23;  // pin 14 on the LCD screen (1/24/24 first bringup: purple)

LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_EN, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7);

const int PIN_JOYSTICK_DOWN = 53;  // red lead
const int PIN_JOYSTICK_UP = 51;  // orange lead
const int PIN_JOYSTICK_LEFT = 49;  // yellow lead
const int PIN_JOYSTICK_RIGHT = 47;  // green lead

const int PIN_MANUAL_SW = 53;
const int PIN_DIRECT_SW = 53;


// TODO tear me out — this is just demo code. (Marked volatile because it's set in the ISR)
volatile bool dir_left = false;
volatile bool dir_right = false;
volatile bool dir_up = false;
volatile bool dir_down = false;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETUP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void setup() {
  // ~~~~~~~~ LCD screen setup ~~~~~~~~
  lcd.begin(16, 2);

  // ~~~~~~~~ Joystick setup ~~~~~~~~
  // Using pullups w/ common ground (on the black wire)
  pinMode(PIN_JOYSTICK_LEFT, INPUT_PULLUP);
  pinMode(PIN_JOYSTICK_RIGHT, INPUT_PULLUP);
  pinMode(PIN_JOYSTICK_UP, INPUT_PULLUP);
  pinMode(PIN_JOYSTICK_DOWN, INPUT_PULLUP);
  // Note that the joystick is serviced by interrupts so I can keep the main loop clear for step pulse generation
  attachInterrupt(digitalPinToInterrupt(PIN_JOYSTICK_LEFT), joystick_left_sw_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_JOYSTICK_RIGHT), joystick_right_sw_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_JOYSTICK_UP), joystick_up_sw_isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_JOYSTICK_DOWN), joystick_down_sw_isr, CHANGE);
  

  // ~~~~~~~~ Game time :) ~~~~~~~~
  lcd.print("Cat Town 0.0.1");
}




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN LOOP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void loop() {
  lcd.setCursor(0, 1);  // 0 row, 1 column (0-indexed)

  // These are all active low with pulldowns, so I'm using "NOT" on digitalRead
  // dir_left = !digitalRead(PIN_JOYSTICK_LEFT);
  // dir_right = !digitalRead(PIN_JOYSTICK_RIGHT);
  // dir_up = !digitalRead(PIN_JOYSTICK_UP);
  // dir_down = !digitalRead(PIN_JOYSTICK_DOWN);

  lcd.print(directionToText());  // no concurrency worries here, all boolean access (I think)
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ UTILITIES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


String directionToText() {
    String direction = "";

    if (dir_left) {
        direction += "Left";
    } else if (dir_right) {
        direction += "Right";
    }

    if (dir_up) {
        if (direction.length() > 0) {
            direction += " + ";
        }
        direction += "Up";
    } else if (dir_down) {
        if (direction.length() > 0) {
            direction += " + ";
        }
        direction += "Down";
    }

    while (direction.length() < 16) {
      direction += " ";
    }

    return direction;
}




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ INTERRUPTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void joystick_left_sw_isr() {
  dir_left = (bool) !digitalRead(PIN_JOYSTICK_LEFT);  // GPT-4 says this should work
}

void joystick_right_sw_isr() {
  dir_right = (bool) !digitalRead(PIN_JOYSTICK_RIGHT);
}

void joystick_up_sw_isr() {
  dir_up = (bool) !digitalRead(PIN_JOYSTICK_UP);
}

void joystick_down_sw_isr() {
  dir_down = (bool) !digitalRead(PIN_JOYSTICK_DOWN);
}
