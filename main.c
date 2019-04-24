/*

 * main.c
 *
 *  Created on: Jan 3, 2019
 *      Author: hosam
 */
#include "EF_7Segment.h"
#include "timer.h"
#include "ultrasonic.h"
#include "buzzer.h"

extern uint8_t overflow;

int main(void)
{
	volatile uint16_t distance = 0;

	EF_void_Segment_Init();
	buzzer_init();
	buzzer_off();
	ultrasonic_init();

	while (1)
	{
		ultrasonic_start();
		while ((PINA & (1 << PA0))==0);// && (PINA & (1 << PA1)) && (PINA & (1 << PA2))&& (PINA & (1 << PA3)) == 0);
		Timer_Start_Count();
		while ((PINA & (1 << PA0))); //|| (PINA & (1 << PA1)) || (PINA & (1 << PA2))|| (PINA & (1 << PA3)));
		distance = TCNT0 * 128 / 58;
		if (overflow)
		{
			overflow = 0;
			continue;
		}
		if (distance <= 99)
		{
			EF_void_Segment_Display(distance);
		}
		else
		{
			PORTC&=(0x0F);     //turn off 7-segment
		}
		if ((distance < 50) && (distance >= 30))
		{
			buzzer_on();
			_delay_ms(500);
			buzzer_off();
			_delay_ms(500);
		}
		else if ((distance < 30) && (distance >= 20))
		{
			buzzer_on();
			_delay_ms(200);
			buzzer_off();
			_delay_ms(200);
		}
		else if ((distance < 20) && (distance >= 10))
		{
			buzzer_on();
			_delay_ms(50);
			buzzer_off();
			_delay_ms(50);
		}
		else if ((distance < 10))
		{
			buzzer_on();
		}

	}
	return 0;
}

