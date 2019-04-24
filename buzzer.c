/*

 * buzzer.c
 *
 *  Created on: Jan 3, 2019
 *      Author: hosam
 */
#include "buzzer.h"

buzzer_init() {
	DDRD |= (1 << PD5);
}

buzzer_on() {
	PORTD |= (1 << PD5);
}

buzzer_off() {
	PORTD &= ~(1 << PD5);
}
