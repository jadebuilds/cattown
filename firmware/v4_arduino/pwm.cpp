/* 
 * pwm.cpp
 * 
 * Contains specific handling for PWM on the Arduino Due microcontroller.
 * 
 * Note that PWM frequency is currently hard-coded to 20 kHz, because that's
 * all I need to control the E-S 4260BL brushless motors.
 */


#include "pwm.h"
#include <Arduino.h>


// Direct register access macros
#define WRITE_REG(REG, VAL) (*(volatile uint32_t*)(REG) = (VAL))
#define READ_REG(REG) (*(volatile uint32_t*)(REG))



// Duty cycle is 50%, inverse is two, so this is the denominator (so I don't have to 
// do float math :shrug: idk)
const uint32_t INV_DUTY_CYCLE = 2;


// ------------------------------------------------------------------------- //
// Global state
// ------------------------------------------------------------------------- //

// Period for four 
volatile uint32_t period[4] = { 2048, 2048, 2048, 2048 };

// I feel like I might be able to set a fixed prescaler but don't feel like figuring
// it out right now. For now I'm saving them as global state, volatile just in case.
// Note that these are currently (March '24) mapped to PWMH3 and PWMH2, respectively.
volatile uint32_t prescaler_a = 2; // Clock A: PWMH2 (Motor 1)
volatile uint32_t prescaler_b = 2; // Clock B: PWMH3 (Motor 0) (todo maybe un-swap these in production PCBA?)


void setupPwm() {

  // Configure Pin 39 (PC7) for Peripheral B (PWMH2)
  WRITE_REG(&PIOC->PIO_PDR, PIO_PC7); // Disable PIO Control on PC7
  WRITE_REG(&PIOC->PIO_ABSR, READ_REG(&PIOC->PIO_ABSR) | PIO_PC7); // Select Peripheral B for PC7

  // Configure Pin 41 (PC9) for Peripheral B (PWMH3)
  WRITE_REG(&PIOC->PIO_PDR, PIO_PC9); // Disable PIO Control on PC9
  WRITE_REG(&PIOC->PIO_ABSR, READ_REG(&PIOC->PIO_ABSR) | PIO_PC9); // Select Peripheral B for PC9

  // Mapping: PWMH2 : Clock A, PWMH3 : Clock B
  // (This way we can do dynamic prescalers in setPwmFrequency; for four motors we'd have to figure out something different!)
  REG_PWM_CMR2 = PWM_CMR_CPRE_CLKA;
  REG_PWM_CMR3 = PWM_CMR_CPRE_CLKB;

  // Step 2: Configure PWM for 20 kHz, 50% duty cycle
  pmc_enable_periph_clk(PWM_INTERFACE_ID); // Enable PWM peripheral clock
}


// void configurePwm() {

//   // Configure Pin 39 (PC7) for Peripheral B (PWMH2)
//   WRITE_REG(&PIOC->PIO_PDR, PIO_PC7); // Disable PIO Control on PC7
//   WRITE_REG(&PIOC->PIO_ABSR, READ_REG(&PIOC->PIO_ABSR) | PIO_PC7); // Select Peripheral B for PC7

//   // Configure Pin 41 (PC9) for Peripheral B (PWMH3)
//   WRITE_REG(&PIOC->PIO_PDR, PIO_PC9); // Disable PIO Control on PC9
//   WRITE_REG(&PIOC->PIO_ABSR, READ_REG(&PIOC->PIO_ABSR) | PIO_PC9); // Select Peripheral B for PC9

//   // Step 2: Configure PWM for 20 kHz, 50% duty cycle
//   pmc_enable_periph_clk(PWM_INTERFACE_ID); // Enable PWM peripheral clock

//   uint32_t duty = PWM_PERIOD_20KHZ; // Start at 0% duty cycle

//   // Configure PWM Clock A
//   REG_PWM_CLK = PWM_CLK_PREB(0) | PWM_CLK_PREA(0) | PWM_CLK_DIVA(PWM_CLOCK_PRESCALER);

//   // Configure PWM Channel 2 (PWMH2 -> PC7 -> pin 39) for 20 kHz output
//   REG_PWM_CMR2 = PWM_CMR_CPRE_CLKA; // Channel 2, Clock A
//   REG_PWM_CPRD2 = PWM_PERIOD_20KHZ; // Channel 2 Period
//   REG_PWM_CDTY2 = duty; // Channel 2 Duty Cycle

//   // Configure PWM Channel 3 (PWMH3 -> PC9 -> pin 41) for 20 kHz output
//   REG_PWM_CMR3 = PWM_CMR_CPRE_CLKA; // Channel 2, Clock A
// }



void setPwmFrequency(PwmChannel pwmChannel, uint32_t targetFrequency) {
    // Supports only PWMH3 and PWMH2 for the moment, because I'm dedicating a clock

    if ((pwmChannel == PWMH0) | (pwmChannel == PWMH1)) {
      return;  // sorry!!! TODO please, i dunno, find a good fixed prescaler value or something
      // todo return an error code
    }

    // The master clock on the SAM3X8E is 84MHz.
    // We need to find a prescaler and a period that can achieve the target frequency.
    // This is GPT-4 code and I really like it, I'm glad to have not had to figure out a good
    // prescaler that works across our desired frequency range!
    // Note that it means that we need a dedicated clock per, of course.
    uint32_t mck = 84000000; // Master clock frequency in Hz
    uint32_t maxPrescaler = 1024; // Maximum prescaler value
    uint32_t clk, prescaler, period;

    // Find the best prescaler and period for the target frequency

    for (prescaler = 1; prescaler <= maxPrescaler; prescaler *= 2) {
        clk = mck / prescaler;
        period = clk / targetFrequency;
        if (period <= 0xFFFF) { // Period fits in the 16-bit register
            break; // Suitable prescaler found
        }
    }
    if (prescaler > maxPrescaler) {
        // Unable to achieve the target frequency with the available prescalers
        return; // todo return an error code!!
    }

    // Keep the prescaler for both channels (saved as global state) -- note that we could also bitmask this
    // out of REG_PWM_CLK? but this felt easier to do lol
    REG_PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_PREB(0) | PWM_CLK_DIVA(prescaler_a) | PWM_CLK_DIVB(prescaler_b);

    // Disable our channel
    if (pwmChannel == PWMH2) {
      REG_PWM_DIS = PWM_DIS_CHID2;  // Disable the channel for a second. // todo figure out how to be continuous from last cycle!
      REG_PWM_CPRD2 = period; // Set the period (sets upper limit on a counter in the PWM perimpheral)
      REG_PWM_CDTY2 = period / INV_DUTY_CYCLE; // Set the duty cycle (sets the "go high" point on that same counter; nb output resets low at wraparound)
      REG_PWM_ENA = PWM_ENA_CHID2; // I believe this is a "command register" -- ie won't deactivate other channels if they're not masked in

    }
    else if (pwmChannel == PWMH3) {
      REG_PWM_DIS = PWM_DIS_CHID3;
      REG_PWM_CPRD3 = period;
      REG_PWM_CDTY3 = period / INV_DUTY_CYCLE;
      REG_PWM_ENA = PWM_ENA_CHID3;
    }
}

void enablePwm(PwmChannel channel) {
  switch (channel) {
    case PWMH0:
      REG_PWM_ENA = PWM_ENA_CHID0;
      break;
    case PWMH1:
      REG_PWM_ENA = PWM_ENA_CHID1;
      break;
    case PWMH2:
      REG_PWM_ENA = PWM_ENA_CHID2;
      break;
    case PWMH3:
      REG_PWM_ENA = PWM_ENA_CHID3;
      break;
  }
}



void disablePwm(PwmChannel channel) {
  switch (channel) {
    case PWMH0:
      REG_PWM_DIS = PWM_DIS_CHID0;
      break;
    case PWMH1:
      REG_PWM_DIS = PWM_DIS_CHID1;
      break;
    case PWMH2:
      REG_PWM_DIS = PWM_DIS_CHID2;
      break;
    case PWMH3:
      REG_PWM_DIS = PWM_DIS_CHID3;
      break;
  }
}

void disablePwmAllChannels() {
  disablePwm(PWMH0);
  disablePwm(PWMH1);
  disablePwm(PWMH2);
  disablePwm(PWMH3);
}