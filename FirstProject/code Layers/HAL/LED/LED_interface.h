#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../MCAL/GPIO/GPIO_interface.h"

typedef struct
{
        u8 PORT_name : 4;
        u8 PIN_no : 4;
}led_t;


void Led_Initialize(led_t *LED);

void Led_TurnON(led_t *LED);

void Led_TurnOFF(led_t *LED);

void Led_Toggle(led_t *LED);


#endif /* LED_INTERFACE_H */