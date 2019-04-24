/*

 * ultrasonic.c
 *
 *  Created on: Jan 3, 2019
 *      Author: hosam
 */
#include "ultrasonic.h"

ultrasonic_init()
{
	DDRA = 0xF0; //PA0,PA1,PA2,PA3 for Echo(input)         PA4,PA5,PA6,PA7 for Trigger(output)
}

ultrasonic_start() {
	PORTA &= 0x0F;        //TRIGGER_OFF
	_delay_us(15);
	PORTA |= 0xF0;        //TRIGGER_ON
	_delay_us(10);
	PORTA &= 0x0F;        //TRIGGER_OFF
}
