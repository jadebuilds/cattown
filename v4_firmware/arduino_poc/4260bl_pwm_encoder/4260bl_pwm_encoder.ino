/*
 * Test code for interacting with the E-S Motor 4260 BL:
 * http://www.e-smotor.com/products/Brushless_DC_motor/2018/0402/32.html
 * This program runs the motor in a ramp pattern, counts encoder pulses, and
 * sends them back to the computer for processing in Python/PANDAS.
 */

// Direct register access macros
#define WRITE_REG(REG, VAL) (*(volatile uint32_t*)(REG) = (VAL))
#define READ_REG(REG) (*(volatile uint32_t*)(REG))

// Assuming PWM clock is set to use MCK/2, for 42 MHz clock (84 MHz MCK of SAM3X8E)
  // Period = Clock / Desired Frequency = 42e6 / 40e3 = 1050
const uint32_t PWM_PERIOD_20KHZ = 2100;

// From motor spec sheet: https://cdn.robotshop.com/rbm/a00a7635-653b-4220-aac9-b0c23c5c5e2c/6/6230ac54-39ef-4e5e-b943-8b6d3305b15f/8505c4f2_4260BL.pdf
const uint32_t PULSES_PER_REVOLUTION = 12;

const int PINS_FEEDBACK[2] = { 12, 13 };

// const int PINS_CURRENT_SENSE[2] = { };

struct MotorSpeeds {
  int rpm0;
  int rpm1;
};

void setup() {

  // Configure Pin 39 (PC7) for Peripheral B (PWMH0)
  WRITE_REG(&PIOC->PIO_PDR, PIO_PC7); // Disable PIO Control on PC7
  WRITE_REG(&PIOC->PIO_ABSR, READ_REG(&PIOC->PIO_ABSR) | PIO_PC7); // Select Peripheral B for PC7

  // Configure Pin 41 (PC9) for Peripheral B (PWMH1)
  WRITE_REG(&PIOC->PIO_PDR, PIO_PC9); // Disable PIO Control on PC9
  WRITE_REG(&PIOC->PIO_ABSR, READ_REG(&PIOC->PIO_ABSR) | PIO_PC9); // Select Peripheral B for PC9

  // Step 2: Configure PWM for 20 kHz, 50% duty cycle
  pmc_enable_periph_clk(PWM_INTERFACE_ID); // Enable PWM peripheral clock

  uint32_t duty = PWM_PERIOD_20KHZ; // Start at 0% duty cycle

  // Configure PWM Clock A
  REG_PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(2); // Clock A = MCK / 2

  // Configure PWM Channel 2 (PWMH2 -> PC7 -> pin 39) for 20 kHz output
  REG_PWM_CMR2 = PWM_CMR_CPRE_CLKA; // Channel 2, Clock A
  REG_PWM_CPRD2 = PWM_PERIOD_20KHZ; // Channel 2 Period
  REG_PWM_CDTY2 = duty; // Channel 2 Duty Cycle

  // Configure PWM Channel 3 (PWMH3 -> PC9 -> pin 41) for 20 kHz output
  REG_PWM_CMR3 = PWM_CMR_CPRE_CLKA; // Channel 2, Clock A
  REG_PWM_CPRD3 = PWM_PERIOD_20KHZ; // Channel 2 Period
  REG_PWM_CDTY3 = duty; // Channel 2 Duty Cycle

  // Enable PWM Channels 2 and 3
  REG_PWM_ENA = PWM_ENA_CHID2 | PWM_ENA_CHID3;
  
  // ~~~~~~~~~~~~~~~~ Feedback interrupt configuration ~~~~~~~~~~~~~~~~

  pinMode(PINS_FEEDBACK[0], INPUT);
  pinMode(PINS_FEEDBACK[1], INPUT);
  // I'm only looking for rising edges; CHANGE would double-count each pulse which we don't need
  attachInterrupt(digitalPinToInterrupt(PINS_FEEDBACK[0]), feedback_pulse_0_isr, RISING);
  attachInterrupt(digitalPinToInterrupt(PINS_FEEDBACK[1]), feedback_pulse_1_isr, RISING);

  
  // ~~~~~~~~~~~~~~~~ Serial ~~~~~~~~~~~~~~~~

  Serial.begin(9600);
}


volatile uint32_t pulse_count[2] = { 0, 0 };


void loop() {

  //  Ramp through duty cycles

  uint32_t duty_pct;
  uint32_t num_ramp_steps = 20;

  for (uint32_t i = 6; i < num_ramp_steps; i++) {
    REG_PWM_CDTY2 = PWM_PERIOD_20KHZ - (i * PWM_PERIOD_20KHZ / num_ramp_steps);  // set duty cycle to % (inverse)
    REG_PWM_CDTY3 = PWM_PERIOD_20KHZ - (i * PWM_PERIOD_20KHZ / num_ramp_steps);  // set duty cycle to % (inverse)

    start_counting_speed();
    
    delay(1000);

    char buffer[100]; // Ensure this buffer is large enough for the resulting string
    int duty_cycle_pct = i * 100 / num_ramp_steps;
    MotorSpeeds speeds = get_motor_speeds();  // Unpack the array out of the return struct
    // int adcRead[2] = {
    //   analogRead(PINS_FEEDBACK[0]),
    //   analogRead(PINS_FEEDBACK[1]),
    // };

    snprintf(buffer, sizeof(buffer), "Duty: %d; RPM0: %d, RPM1: %d", duty_cycle_pct, speeds.rpm0, speeds.rpm1);
    //snprintf(buffer, sizeof(buffer), "Duty: %d; RPM0: %d; I0: %d, RPM1: %d, I1: %d", duty_cycle_pct, speed_rpm[0], adcRead[0], speed_rpm[1], adcRead[1]);
    Serial.println(buffer);
  }
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
  speeds.rpm0 = ((pulse_count[0] - start_pulse_count[0]) * 60 * 1000 / millis_since_start) / PULSES_PER_REVOLUTION;
  speeds.rpm1 = ((pulse_count[1] - start_pulse_count[1]) * 60 * 1000 / millis_since_start) / PULSES_PER_REVOLUTION;
  return speeds;
}
