/*

 * timer.c
 *
 *  Created on: Jan 3, 2019
 *      Author: hosam
 */
#include "timer.h"

uint8_t overflow = 0;

Timer_Start_Count() {
	TCNT0 = 0;
	TCCR0 = 0x05;		//normal mode,1024 prescaler.
	TIMSK = (1 << TOIE0);
	sei();
}

ISR(TIMER0_OVF_vect) {
	overflow = 1;
}
