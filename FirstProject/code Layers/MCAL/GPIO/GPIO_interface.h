#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../GPIO/GPIO_register.h"

#include <stdio.h>

void SetPinDirection(u8 PORT , u8 PIN , u8 Direction);

void SetPortDirection(u8 PORT , u8 Direction);

void SetPin(u8 PORT , u8 PIN);

void ClearPin(u8 PORT , u8 PIN);

void SetPinValue(u8 PORT , u8 PIN , u8 Value);

u8 GetPinValue(u8 Port , u8 PIN);

void SetPortValue(u8 PORT , u8 Value);

void TogglePin(u8 PORT , u8 PIN);


#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT  0
#define OUTPUT 1

#define LOW  0
#define HIGH 1


#endif /* GPIO_INTERFACE_H */