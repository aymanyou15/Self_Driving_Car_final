#ifndef PWM_PROGRAM_H
#define PWM_PROGRAM_H


#include "PWM_interface.h"
#include "../GPIO/GPIO_interface.h"

void PWM_Timer0_INIT(void)
{
    // make the pin output
    SetPinDirection( GPIO_PORTB , PIN3 , OUTPUT);
    
    CLEAR_PORT(TCCR0_REG); 
            
    // wave generation mode is fast PWM
    SET_BIT(TCCR0_REG , WGM00);
    SET_BIT(TCCR0_REG , WGM01);
    
    // compare output mode is non-inverting
    SET_BIT(TCCR0_REG , COM01);
    CLEAR_BIT(TCCR0_REG , COM00);
    
    // prescaler value is 64
    SET_BIT(TCCR0_REG , CS02);
    CLEAR_BIT(TCCR0_REG , CS01);
    SET_BIT(TCCR0_REG , CS00);
}


void PWM_Timer0_Analog_write(u8 value)
{
    OCR0_REG = value;
}


void PWM_Timer2_INIT(void)
{
    // make the pin output
    SetPinDirection( GPIO_PORTD , PIN7 , OUTPUT);
    
    CLEAR_PORT(TCCR2_REG); 
            
    // wave generation mode is fast PWM
    SET_BIT(TCCR2_REG , WGM20);
    SET_BIT(TCCR2_REG , WGM21);
    
    // compare output mode is non-inverting
    SET_BIT(TCCR2_REG , COM21);
    CLEAR_BIT(TCCR2_REG , COM20);
    
    // prescaler value is 64
    SET_BIT(TCCR2_REG , CS22);
    CLEAR_BIT(TCCR2_REG , CS21);
    CLEAR_BIT(TCCR2_REG , CS20);
}


void PWM_Timer2_Analog_write(u8 value)
{
    OCR2_REG = value;
}


#endif /* PWM_PROGRAM_H */