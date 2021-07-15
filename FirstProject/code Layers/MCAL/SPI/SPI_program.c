/*
 * File        : GPIO_programs.h
 * Description : This file includes the GPIO function implementation
 * Author      : Ayman Elgammal 
 * Date        : April 4,2021
 * Git account : https://github.com/aymanyou15
 * mail        : aymanyou15@gmail.com 
 */
#include "SPI_interface.h"


void SPI_SlaveInit(void)
{
/* Set MISO output, all others input */
    SetPinDirection( GPIO_PORTB ,  PIN6 , OUTPUT);
    SetPinDirection( GPIO_PORTB ,  PIN5 , INPUT);
    SetPinDirection( GPIO_PORTB ,  PIN7 , INPUT);
    SetPinDirection( GPIO_PORTB ,  PIN4 , INPUT);


    /* Enable SPI */
    SPCR = (1<<SPE);
}
u8 SPI_SlaveReceive(void)
{
/* Wait for reception complete */
while(!(SPSR & (1<<SPIF)));
/* Return data register */
return SPDR;
}


