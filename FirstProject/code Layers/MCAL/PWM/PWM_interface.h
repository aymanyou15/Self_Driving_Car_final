#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../PWM/PWM_registers.h"

#include <stdio.h>

void PWM_Timer0_INIT(void);
void PWM_Timer0_Analog_write(u8 value);

void PWM_Timer2_INIT(void);
void PWM_Timer2_Analog_write(u8 value);

#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM20   4
#define COM21   5
#define WGM20   6
#define FOC2    7



#endif  /* PWM_INTERFACE_H */