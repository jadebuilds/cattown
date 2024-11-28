/* 
 * pwm.h
 * 
 * Contains specific handling for PWM on the Arduino Due microcontroller.
 * 
 * Note that PWM frequency is currently hard-coded to 20 kHz, because that's
 * all I need to control the E-S 4260BL brushless motors.
 * 
 * I'm also 
 */

#ifndef PWM_H
#define PWM_H

#include <Arduino.h>  // for uint32_t lol

// The four hardware PWM channels available on the Arduino Due / Atmel SAM 3x8E.
// Note that these correspond to Arduino Due pins 35, 37, 39, 41 / 3x8E pins PC3, PC4, PC7, PC9.
enum PwmChannel { PWMH0, PWMH1, PWMH2, PWMH3 };

// Initialization, must be called at setup()
void setupPwm();

// Enabling/disabling by channel (useful for coming to a complete stop / for calibration)
void enablePwm(PwmChannel channel);
void disablePwm(PwmChannel channel);

void disablePwmAllChannels();

// Set PWM for a specific channel
void setPwmFrequency(PwmChannel channel, uint32_t frequency_hz);

#endif // PWM_H