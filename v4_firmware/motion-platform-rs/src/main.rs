#![no_std]
#![no_main]

// pick a panicking behavior
use panic_halt as _; // you can put a breakpoint on `rust_begin_unwind` to catch panics
// use panic_abort as _; // requires nightly
// use panic_itm as _; // logs messages over ITM; requires ITM support
// use panic_semihosting as _; // logs messages to the host stderr; requires a debugger

use cortex_m::asm;
use cortex_m_rt::entry;
use stm32f4xx_hal::{
    pac::{self},
    prelude::*,
    timer::Channel,
};

#[entry]
fn main() -> ! {

    let cp = cortex_m::Peripherals::take().unwrap();
    let p = stm32f4xx_hal::pac::Peripherals::take().unwrap();

    // borrowed from https://apollolabsblog.hashnode.dev/stm32f4-embedded-rust-at-the-hal-pwm-buzzer
    let gpio_bank_a: stm32f4xx_hal::gpio::gpioa::Parts = p.GPIOA.split();
    let pwm_pin: stm32f4xx_hal::gpio::Pin<'A', 9, stm32f4xx_hal::gpio::Alternate<_>> = gpio_bank_a.pa9.into_alternate();

    let rcc: stm32f4xx_hal::rcc::Rcc = p.RCC.constrain();
    let clocks: stm32f4xx_hal::rcc::Clocks = rcc.cfgr.use_hse(8.MHz()).freeze();

    let mut motor_pwm = p.TIM1.pwm_hz(pwm_pin, 2000.Hz(), &clocks);

    asm::nop(); // To not have main optimize to abort in release mode, remove when you add code

    loop {
        // your code goes here
    }
}
