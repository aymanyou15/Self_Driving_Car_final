/*
 * File        : LED_program.c
 * Description : This file includes the LED functions implementation
 * Notes	   : in case of using LEDS in your application, just include this file
 * Author      : Ayman Elgammal 
 * Date        : April 4,2021
 * Git account : https://github.com/aymanyou15
 * mail        : aymanyou15@gmail.com 
 */

#include "LED_interface.h"


void Led_Initialize(led_t *LED)
{
    if( (NULL == LED) || (LED->PORT_name > 4) || (LED->PIN_no > 7) )
    {
        // Please check the Led_Initialize inputs
    }
    else
    {
        SetPinDirection(LED->PORT_name , LED->PIN_no , OUTPUT);
        ClearPin(LED->PORT_name , LED->PIN_no);
    }
}


void Led_TurnON(led_t *LED)
{
    if( (NULL == LED) || (LED->PORT_name > 4) || (LED->PIN_no > 7) )
    {
        // Please check the Led_Initialize inputs
    }
    else
    {
        SetPin(LED->PORT_name , LED->PIN_no);
    }
}

void Led_TurnOFF(led_t *LED)
{
    if( (NULL == LED) || (LED->PORT_name > 4) || (LED->PIN_no > 7) )
    {
        // Please check the Led_Initialize inputs
    }
    else
    {
        ClearPin(LED->PORT_name , LED->PIN_no);
    }
}

void Led_Toggle(led_t *LED)
{
    if( (NULL == LED) || (LED->PORT_name > 4) || (LED->PIN_no > 7) )
    {
        // Please check the Led_Initialize inputs
    }
    else
    {
        TogglePin(LED->PORT_name , LED->PIN_no);
    }
}