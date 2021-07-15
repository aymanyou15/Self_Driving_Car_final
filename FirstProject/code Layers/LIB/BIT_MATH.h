/*
 * File        : BIT_MATH.h
 * Description : This file includes standard functions that deal with bits & PORTS
 * Author      : Ayman Elgammal 
 * Date        : April 4,2021
 * Git account : https://github.com/aymanyou15
 * mail        : aymanyou15@gmail.com 
 */


#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(REG , BIT_NUM)	REG |= (1<<BIT_NUM)

#define  SET_BIT_VALUE(REG,BIT,Value) ( (Value == 0) ? ( REG &= ~(1<<BIT) ) : ( REG |= (1<<BIT) ) )

#define SET_PORT(REG)	REG = 0xff

#define CLEAR_BIT(REG , BIT_NUM)	REG &= ~(1<<BIT_NUM)

#define CLEAR_PORT(REG)	REG = 0x00

#define TOGGLE_BIT(REG , BIT_NUM)	REG ^= (1<<BIT_NUM)

#define GET_BIT(REG , BIT_NUM)	 ((REG>>BIT_NUM) & 1 )



#endif /* BIT_MATH_H */