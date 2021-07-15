#ifndef _TIMER1_INT_H_
#define _TIMER1_INT_H_

#include "../LIB/STD_TYPES.h"
#include "timer_config.h"
#include "private.h"


u8 Timer1_u8Initialization(void);
void Fast_PWM1_init(uint8_t prescaler , uint16_t value , uint8_t pin);

#endif /*_TIMER_INT_H_ */