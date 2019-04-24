/*
 * ultrasonic.h
 *
 *  Created on: Jan 3, 2019
 *      Author: hosam
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <avr/io.h>
#include "util/delay.h"

void ultrasonic_init(void);

void ultrasonic_start(void);

#endif /* ULTRASONIC_H_ */
