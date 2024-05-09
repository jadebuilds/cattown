/* 
 * errors.h
 * 
 * Contains specific handling for the Arduino Due microcontroller, including PWM.
 */

#ifndef ERRORS_H
#define ERRORS_H

#include <Arduino.h>

struct Result {
    bool success;
    String message;
}

const bool OK = true;
const bool ERROR = false;

#endif // ERRORS_H