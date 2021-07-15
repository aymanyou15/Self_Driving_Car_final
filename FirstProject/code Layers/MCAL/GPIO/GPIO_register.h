/*
 * File        : GPIO_register.h
 * Description : This file includes the addresses of the GPIO registers
 * Author      : Ayman Elgammal 
 * Date        : April 4,2021
 * Git account : https://github.com/aymanyou15
 * mail        : aymanyou15@gmail.com 
 */


#ifndef GPIO_REGISTER_H
#define GPIO_REGISTER_H


/* PORTA REGISTERS */
#define PORTA_REG  *((volatile u8 *) 0x3B)
#define DDRA_REG  *((volatile u8 *) 0x3A) 
#define PINA_REG  *((volatile u8 *) 0x39)

/* PORTB REGISTERS */
#define PORTB_REG  *((volatile u8 *) 0x38)
#define DDRB_REG  *((volatile u8 *) 0x37)
#define PINB_REG  *((volatile u8 *) 0x36)

/* PORTC REGISTERS */
#define PORTC_REG  *((volatile u8 *) 0x35)
#define DDRC_REG  *((volatile u8 *) 0x34)
#define PINC_REG  *((volatile u8 *) 0x33)

/* PORTD REGISTERS */
#define PORTD_REG  *((volatile u8 *) 0x32)
#define DDRD_REG  *((volatile u8 *) 0x31)
#define PIND_REG  *((volatile u8 *) 0x30)



#endif /* GPIO_REGISTER_H */