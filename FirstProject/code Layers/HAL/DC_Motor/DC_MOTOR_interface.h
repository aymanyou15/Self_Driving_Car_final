#ifndef DC_MOTOR_INTERFACE_H
#define DC_MOTOR_INTERFACE_H

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"

#define PWM0 0
#define PWM2 1


typedef struct
{
	u8 PORT_name : 4;
	u8 PIN_INT1 : 4;
	u8 PIN_INT2 : 4;
	u8 PWM : 4;
}DC_MOTOR_t;


void DC_motor_intialize(DC_MOTOR_t *motor);

void DC_motor_forward(DC_MOTOR_t *motor , u8 value);

void DC_motor_backward(DC_MOTOR_t *motor , u8 value);

void DC_motor_revese(DC_MOTOR_t *motor , u8 value);

void DC_motor_stop(DC_MOTOR_t *motor);


#endif /* DC_MOTOR_INTERFACE_H */