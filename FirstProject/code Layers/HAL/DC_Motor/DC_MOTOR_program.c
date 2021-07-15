#include "DC_MOTOR_interface.h"


void DC_motor_intialize(DC_MOTOR_t *motor)
{
	if( (NULL == motor) )
	{
		// Please check the Led_Initialize inputs
	}
	else
	{
		SetPinDirection(motor->PORT_name , motor->PIN_INT1 , OUTPUT);
		SetPinDirection(motor->PORT_name , motor->PIN_INT2 , OUTPUT);
		ClearPin(motor->PORT_name , motor->PIN_INT1);
		ClearPin(motor->PORT_name , motor->PIN_INT1);
	}
}


void DC_motor_forward(DC_MOTOR_t *motor , u8 value)
{
	if( (NULL == motor) || (value > 255) )
	{
		// Please check the Led_Initialize inputs
	}
	else
	{
		SetPin(motor->PORT_name , motor->PIN_INT2);
		ClearPin(motor->PORT_name , motor->PIN_INT1);
		switch(motor ->PWM)
		{
			//case PWM0 : PWM_Timer0_Analog_write(value); break;
			case PWM2 : PWM_Timer2_Analog_write(value); break;

		}
		
	}
}

void DC_motor_backward(DC_MOTOR_t *motor , u8 value)
{
	if( (NULL == motor) || (value > 255) )
	{
		// Please check the Led_Initialize inputs
	}
	else
	{
		ClearPin(motor->PORT_name , motor->PIN_INT2);
		SetPin(motor->PORT_name , motor->PIN_INT2);
		switch(motor ->PWM)
		{
			//case PWM0 : PWM_Timer0_Analog_write(value); break;
			case PWM2 : PWM_Timer2_Analog_write(value); break;

		}
	}
}

void DC_motor_revese(DC_MOTOR_t *motor , u8 value)
{
	if( (NULL == motor) || (value > 255))
	{
		// Please check the Led_Initialize inputs
	}
	else
	{
		TogglePin(motor->PORT_name , motor->PIN_INT1);
		TogglePin(motor->PORT_name , motor->PIN_INT2);
		switch(motor ->PWM)
		{
			//case PWM0 : PWM_Timer0_Analog_write(value); break;
			case PWM2 : PWM_Timer2_Analog_write(value); break;

		}
	}
}

void DC_motor_stop(DC_MOTOR_t *motor)
{
	if( (NULL == motor) )
	{
		// Please check the Led_Initialize inputs
	}
	else
	{
		ClearPin(motor->PORT_name , motor->PIN_INT1);
		ClearPin(motor->PORT_name , motor->PIN_INT2);
	}
}