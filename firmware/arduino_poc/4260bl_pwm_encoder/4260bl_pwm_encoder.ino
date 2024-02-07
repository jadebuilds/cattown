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

const int PIN_FEEDBACK = 45;

void setup() {

  // ~~~~~~~~~~~~~~~~ PWM configuration (direct register access) ~~~~~~~~~~~~~~~~

  // Step 1: Configure Pin 35 (PC3) for Peripheral B (PWMH0)
  WRITE_REG(&PIOC->PIO_PDR, PIO_PC3); // Disable PIO Control on PC3
  WRITE_REG(&PIOC->PIO_ABSR, READ_REG(&PIOC->PIO_ABSR) | PIO_PC3); // Select Peripheral B for PC3

  // Step 2: Configure PWM for 20 kHz, 50% duty cycle
  pmc_enable_periph_clk(PWM_INTERFACE_ID); // Enable PWM peripheral clock

  uint32_t duty = PWM_PERIOD_20KHZ / 4; // 75% duty cycle

  // Configure PWM Clock A for channel 0 (use clock A as example)
  REG_PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(2); // Clock A = MCK / 2

  // Configure PWM Channel 0 for 40 kHz
  REG_PWM_CMR0 = PWM_CMR_CPRE_CLKA; // Channel 0, Clock A
  REG_PWM_CPRD0 = PWM_PERIOD_20KHZ; // Channel 0 Period
  REG_PWM_CDTY0 = duty; // Channel 0 Duty Cycle

  // Enable PWM Channel 0
  REG_PWM_ENA = PWM_ENA_CHID0;
  
  // ~~~~~~~~~~~~~~~~ Feedback interrupt configuration ~~~~~~~~~~~~~~~~

  pinMode(PIN_FEEDBACK, INPUT);
  // I'm only looking for rising edges; CHANGE would double-count each pulse which we don't need
  attachInterrupt(digitalPinToInterrupt(PIN_FEEDBACK), feedback_pulse_isr, RISING);

  
  // ~~~~~~~~~~~~~~~~ Serial ~~~~~~~~~~~~~~~~

  Serial.begin(9600);
}


volatile uint32_t pulse_count = 0;

void loop() {

  // Ramp through duty cycles

  uint32_t duty_pct;
  uint32_t num_ramp_steps = 20;

  for (uint32_t i = 0; i < num_ramp_steps; i++) {
    REG_PWM_CDTY0 = i * PWM_PERIOD_20KHZ / num_ramp_steps;  // set duty cycle to %

    start_counting_speed();
    delay(1000);
    char buffer[100]; // Ensure this buffer is large enough for the resulting string
    int duty_cycle_pct = (num_ramp_steps - i) * 100 / num_ramp_steps;
    int speed_rpm = get_speed_rpm(); // Call your function to get the speed
    snprintf(buffer, sizeof(buffer), "Duty cycle: %d ; Speed (RPM): %d ; Pulse count: %d    ", duty_cycle_pct, speed_rpm, pulse_count);
    Serial.println(buffer);
  }

}

void feedback_pulse_isr() {
  pulse_count++;
}

int start_pulse_count;
int start_time;

void start_counting_speed() {
  start_pulse_count = pulse_count;
  start_time = millis();
}

int get_speed_rpm() {
  int millis_since_start = millis() - start_time;
  int speed_rpm = ((pulse_count - start_pulse_count) * 60 / PULSES_PER_REVOLUTION * millis_since_start) / 1000;
  return speed_rpm;
}