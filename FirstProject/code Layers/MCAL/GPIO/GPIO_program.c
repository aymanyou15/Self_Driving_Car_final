/*
 * File        : GPIO_programs.h
 * Description : This file includes the GPIO function implementation
 * Author      : Ayman Elgammal 
 * Date        : April 4,2021
 * Git account : https://github.com/aymanyou15
 * mail        : aymanyou15@gmail.com 
 */


#include "../GPIO/GPIO_interface.h"


void SetPinDirection(u8 PORT , u8 PIN , u8 Direction)
{
	if(PORT < 4 && PIN < 8)
	{
		if(Direction == INPUT)
		{
			switch(PORT)
			{
				case GPIO_PORTA: CLEAR_BIT(DDRA_REG , PIN); break;
				case GPIO_PORTB: CLEAR_BIT(DDRB_REG , PIN); break;
				case GPIO_PORTC: CLEAR_BIT(DDRC_REG , PIN); break;
				case GPIO_PORTD: CLEAR_BIT(DDRD_REG , PIN); break;
			}
		}
		else if(Direction == OUTPUT)
		{
			switch(PORT)
			{
				case GPIO_PORTA: SET_BIT(DDRA_REG , PIN); break;
				case GPIO_PORTB: SET_BIT(DDRB_REG , PIN); break;
				case GPIO_PORTC: SET_BIT(DDRC_REG , PIN); break;
				case GPIO_PORTD: SET_BIT(DDRD_REG , PIN); break;
			}
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		// please chek the PORT and the PIN entry
	}

}


void SetPortDirection(u8 PORT , u8 Direction)
{
	if(PORT < 4)
	{
		if(Direction == INPUT) 
		{
			switch(PORT)
			{
				case GPIO_PORTA: CLEAR_PORT(DDRA_REG); break;
				case GPIO_PORTB: CLEAR_PORT(DDRB_REG); break;
				case GPIO_PORTC: CLEAR_PORT(DDRC_REG); break;
				case GPIO_PORTD: CLEAR_PORT(DDRD_REG); break;
			}
		}
		else if(Direction == OUTPUT) 
		{
			switch(PORT)
			{
				case GPIO_PORTA: SET_PORT(DDRA_REG); break;
				case GPIO_PORTB: SET_PORT(DDRB_REG); break;
				case GPIO_PORTC: SET_PORT(DDRC_REG); break;
				case GPIO_PORTD: SET_PORT(DDRD_REG); break;
			}
		}
		else
		{
			/* Do Nothing */
		}
	}
	else 
	{
		// please chek the PORT entry
	}
}


void SetPin(u8 PORT , u8 PIN)
{
	if(PORT < 4 && PIN < 8)
	{
		switch(PORT)
		{
			case GPIO_PORTA: SET_BIT(PORTA_REG , PIN); break;
			case GPIO_PORTB: SET_BIT(PORTB_REG , PIN); break;
			case GPIO_PORTC: SET_BIT(PORTC_REG , PIN); break;
			case GPIO_PORTD: SET_BIT(PORTD_REG , PIN); break;
		}
	}
	else
	{
		// please chek the PORT and the PIN entry
	}
}


void ClearPin(u8 PORT , u8 PIN)
{
	if(PORT < 4 && PIN < 8)
	{
		switch(PORT)
		{
			case GPIO_PORTA: CLEAR_BIT(PORTA_REG , PIN); break;
			case GPIO_PORTB: CLEAR_BIT(PORTB_REG , PIN); break;
			case GPIO_PORTC: CLEAR_BIT(PORTC_REG , PIN); break;
			case GPIO_PORTD: CLEAR_BIT(PORTD_REG , PIN); break;
		}
	}
	else
	{
		// please chek the PORT and the PIN entry
	}
}


void SetPinValue(u8 PORT , u8 PIN , u8 Value)
{
	if(PORT < 4 && PIN < 8)
	{
		if(Value == HIGH)
		{
			switch(PORT)
			{
			case GPIO_PORTA: SET_BIT(PORTA_REG , PIN); break;
			case GPIO_PORTB: SET_BIT(PORTB_REG , PIN); break;
			case GPIO_PORTC: SET_BIT(PORTC_REG , PIN); break;
			case GPIO_PORTD: SET_BIT(PORTD_REG , PIN); break;
			}
		}
		else if(Value == LOW)
		{
			switch(PORT)
			{
			case GPIO_PORTA: CLEAR_BIT(PORTA_REG , PIN); break;
			case GPIO_PORTB: CLEAR_BIT(PORTB_REG , PIN); break;
			case GPIO_PORTC: CLEAR_BIT(PORTC_REG , PIN); break;
			case GPIO_PORTD: CLEAR_BIT(PORTD_REG , PIN); break;
			}
		}
		else
		{
			/* Do Nothing */ 
		}
	}
	else
	{
		// please chek the PORT and the PIN entry
	}
}


u8 GetPinValue(u8 PORT , u8 PIN)
{
	u8 Local_PinValue = 0;
	
	if(PORT < 4 && PIN < 8)
	{	
		switch(PORT)
			{
			case GPIO_PORTA: Local_PinValue = GET_BIT(PINA_REG , PIN); break;
			case GPIO_PORTB: Local_PinValue = GET_BIT(PINB_REG , PIN); break;
			case GPIO_PORTC: Local_PinValue = GET_BIT(PINC_REG , PIN); break;
			case GPIO_PORTD: Local_PinValue = GET_BIT(PIND_REG , PIN); break;
			}
	}
	else
	{
		// please chek the PORT and the PIN entry
	}
	
	return Local_PinValue;
}



void SetPortValue(u8 PORT , u8 Value)
{
	if(PORT < 4 && Value < 256)
	{
		switch(PORT)
			{
			case GPIO_PORTA: PORTA_REG = Value; break;
			case GPIO_PORTB: PORTB_REG = Value; break;
			case GPIO_PORTC: PORTC_REG = Value; break;
			case GPIO_PORTD: PORTD_REG = Value; break;
			}
	}
	else
	{
		// please chek the PORT entry and enter value between (0 to 255) 
	}
}


void TogglePin(u8 PORT , u8 PIN)
{
	if(PORT < 4 && PIN < 8)
	{
		switch(PORT)
			{
			case GPIO_PORTA: TOGGLE_BIT(PORTA_REG , PIN); break;
			case GPIO_PORTB: TOGGLE_BIT(PORTB_REG , PIN); break;
			case GPIO_PORTC: TOGGLE_BIT(PORTC_REG , PIN); break;
			case GPIO_PORTD: TOGGLE_BIT(PORTD_REG , PIN); break;
			}
	}
	else
	{
		// please chek the PORT and the PIN entry
	}
}