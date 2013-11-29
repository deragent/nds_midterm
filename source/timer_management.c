#include "timer_management.h"

//Number of timer ticks (periods of 100 ms) passed
int timer_ticks;

void configureTimer() {
	// Initialize timer_ticks
	timer_ticks = 0;

	// Configure timer to trigger an interrupt every 100 ms
    TIMER_CR(0) = TIMER_ENABLE | TIMER_DIV_64 | TIMER_IRQ_REQ;
    TIMER_DATA(0) = TIMER_FREQ_64(10);

	// Associate the ISR (timerISR) to the interrupt line and enable it
    irqSet(IRQ_TIMER0, &timerISR);
    irqEnable(IRQ_TIMER0);
}

void timerISR() {
	// Hide the color sequence of the upper screen after 2 seconds (call to
	// hideColorSequence()) and disable the timer
    timer_ticks++;
    if(timer_ticks == 20)
    {
        hideColorSequence();
        irqDisable(IRQ_TIMER0);
        timer_ticks = 0;
    }
}
