/*
 * Test code for interacting with the TMC2209.
 * 
 * I'm using the PWM peripheral to generate speed control, then
 * reading it back into a separate feedback GPIO to count pulses
 * with interrupts. That way I end up still using the CPU but in 
 * interrupt context and thus I don't have to worry about jitter 
 * in the motor STEP output -- the PWM peripheral will put out super
 * clean and then counting will interleave with my loop() code.
 * Note that loop() maybe gets jittered a little, but that shouldn't
 * matter as we're not doing anything else real-time.
 */

// Direct register access macros
#define WRITE_REG(REG, VAL) (*(volatile uint32_t*)(REG) = (VAL))
#define READ_REG(REG) (*(volatile uint32_t*)(REG))

// Assuming PWM clock is set to use MCK/2, for 42 MHz clock (84 MHz MCK of SAM3X8E)
  // Period = Clock / Desired Frequency = 42e6 / 40e3 = 1050 (for example)
const uint32_t PWM_CLOCK = 42e6;

const uint32_t PULSES_PER_ROTATION = 1600; // 1/8 default microstep, 200 fullsteps per rotation

// Stepper configuration
const int PINS_FEEDBACK[2] = { 3, 6 };
const int PINS_EN[2] = { 2, 5 };
const int PINS_DIR[2] = { 4, 7 };


struct MotorSpeeds {
  int rpm0;
  int rpm1;
};


void setup() {

  // Configure Pin 39 (PC7) for Peripheral B (PWMH2)
  WRITE_REG(&PIOC->PIO_PDR, PIO_PC7); // Disable PIO Control on PC7
  WRITE_REG(&PIOC->PIO_ABSR, READ_REG(&PIOC->PIO_ABSR) | PIO_PC7); // Select Peripheral B for PC7

  // Configure Pin 41 (PC9) for Peripheral B (PWMH3)
  WRITE_REG(&PIOC->PIO_PDR, PIO_PC9); // Disable PIO Control on PC9
  WRITE_REG(&PIOC->PIO_ABSR, READ_REG(&PIOC->PIO_ABSR) | PIO_PC9); // Select Peripheral B for PC9

  // Step 2: Configure PWM for 20 kHz, 50% duty cycle
  pmc_enable_periph_clk(PWM_INTERFACE_ID); // Enable PWM peripheral clock

  //
  // The rest will get handed off to setPWMFrequency()...
  //
  //

  // // Configure PWM Clock A
  // REG_PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(2); // Clock A = MCK / 2

  // // Configure PWM Channel 2 (PWMH2 -> PC7 -> pin 39) for 20 kHz output
  // REG_PWM_CMR2 = PWM_CMR_CPRE_CLKA; // Channel 2, Clock A
  // REG_PWM_CPRD2 = PWM_PERIOD_20KHZ; // Channel 2 Period
  // REG_PWM_CDTY2 = duty; // Channel 2 Duty Cycle

  // // Configure PWM Channel 3 (PWMH3 -> PC9 -> pin 41) for 20 kHz output
  // REG_PWM_CMR3 = PWM_CMR_CPRE_CLKA; // Channel 2, Clock A
  // REG_PWM_CPRD3 = PWM_PERIOD_20KHZ; // Channel 2 Period
  // REG_PWM_CDTY3 = duty; // Channel 2 Duty Cycle

  // // Enable PWM Channels 2 and 3
  // REG_PWM_ENA = PWM_ENA_CHID2 | PWM_ENA_CHID3;
  
  // ~~~~~~~~~~~~~~~~ Feedback interrupt configuration ~~~~~~~~~~~~~~~~

  pinMode(PINS_FEEDBACK[0], INPUT);
  pinMode(PINS_FEEDBACK[1], INPUT);
  // I'm only looking for rising edges; CHANGE would double-count each pulse which we don't need
  attachInterrupt(digitalPinToInterrupt(PINS_FEEDBACK[0]), feedback_pulse_0_isr, RISING);
  attachInterrupt(digitalPinToInterrupt(PINS_FEEDBACK[1]), feedback_pulse_1_isr, RISING);

  
  // ~~~~~~~~~~~~~~~~ Serial ~~~~~~~~~~~~~~~~

  Serial.begin(9600);

  // ~~~~~~~~~~~~~~~~ Pins ~~~~~~~~~~~~~~~~
  pinMode(PINS_EN[0], OUTPUT);
  pinMode(PINS_EN[1], OUTPUT);
  pinMode(PINS_DIR[0], OUTPUT);
  pinMode(PINS_DIR[1], OUTPUT);

  // enable them
  digitalWrite(PINS_EN[0], LOW);
  digitalWrite(PINS_EN[1], LOW);
}


volatile uint32_t pulse_count[2] = { 0, 0 };

int dir = LOW;

void loop() {

  //  Ramp through duty cycles

  uint32_t duty_pct;
  uint32_t num_ramp_steps = 20;

  for (uint32_t f = 2000; f < 6000; f+= 500) {
    setPWMFrequency(f);

    start_counting_speed();
    
    delay(1000);

    char buffer[100]; // Ensure this buffer is large enough for the resulting string
    MotorSpeeds speeds = get_motor_speeds();  // Unpack the array out of the return struct
    // int adcRead[2] = {
    //   analogRead(PINS_FEEDBACK[0]),
    //   analogRead(PINS_FEEDBACK[1]),
    // };

    snprintf(buffer, sizeof(buffer), "Freq (Hz): %d; RPM0: %d, RPM1: %d", f, speeds.rpm0, speeds.rpm1);
    //snprintf(buffer, sizeof(buffer), "Duty: %d; RPM0: %d; I0: %d, RPM1: %d, I1: %d", duty_cycle_pct, speed_rpm[0], adcRead[0], speed_rpm[1], adcRead[1]);
    Serial.println(buffer);
  }

  // dir = ~dir;
  // digitalWrite(PINS_DIR, dir);
}

void feedback_pulse_0_isr() {
  pulse_count[0]++;
}

void feedback_pulse_1_isr() {
  pulse_count[1]++;
}

int start_pulse_count[2];
int start_time;

void start_counting_speed() {
  start_pulse_count[0] = pulse_count[0];
  start_pulse_count[1] = pulse_count[1];
  start_time = millis();
}

MotorSpeeds get_motor_speeds() {
  int millis_since_start = millis() - start_time;
  MotorSpeeds speeds;
  speeds.rpm0 = ((pulse_count[0] - start_pulse_count[0]) * 60 * 1000 / millis_since_start) / PULSES_PER_ROTATION;
  speeds.rpm1 = ((pulse_count[1] - start_pulse_count[1]) * 60 * 1000 / millis_since_start) / PULSES_PER_ROTATION;
  return speeds;
}


// Thanks to GPT-4. TODO support separate channels
void setPWMFrequency(uint32_t targetFrequency) {
    // The master clock on the SAM3X8E is 84MHz.
    // We need to find a prescaler and a period that can achieve the target frequency.
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
        return;
    }

    // Disable PWM channels to configure (note: is this necessary??)
    REG_PWM_DIS = PWM_DIS_CHID3 | PWM_DIS_CHID2;

    // Configure thes PWM clock (using clock A as an example)
    REG_PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(prescaler);

    // Set the period (CPRD) and duty cycle (CDTY) for channel 3
    REG_PWM_CMR3 = PWM_CMR_CPRE_CLKA; // Use clock A for channel 3
    REG_PWM_CPRD3 = period; // Set the period
    REG_PWM_CDTY3 = period / 2; // Set the duty cycle to 50%

    // Set the period (CPRD) and duty cycle (CDTY) for channel 2
    REG_PWM_CMR2 = PWM_CMR_CPRE_CLKA; // Use clock A for channel 2
    REG_PWM_CPRD2 = period; // Set the period
    REG_PWM_CDTY2 = period / 2; // Set the duty cycle to 50%

    // Enable the PWM channels
    REG_PWM_ENA = PWM_ENA_CHID3 | PWM_ENA_CHID2;
}

