/*
 * File        : GPIO_register.h
 * Description : This file includes the addresses of the SPI registers
 * Author      : Ayman Elgammal 
 * Date        : April 4,2021
 * Git account : https://github.com/aymanyou15
 * mail        : aymanyou15@gmail.com 
 */


#ifndef SPI_REGISTER_H
#define SPI_REGISTER_H

#define SPCR (*(volatile u8 *)(0x2D))
#define SPSR (*(volatile u8 *)(0x2E))
#define SPDR (*(volatile u8 *)(0x2F))


#endif /* GPIO_REGISTER_H */