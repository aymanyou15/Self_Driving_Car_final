#ifndef PWM_REGISTER_H
#define PWM_REGISTER_H

#define TCCR0_REG  *(volatile u8 *)0x53
#define OCR0_REG  *(volatile u8 *)0x5C

#define TCCR2_REG  *(volatile u8 *)0x45
#define OCR2_REG  *(volatile u8 *)0x43
#define TCNT2_REG  *(volatile u8 *)0x44


#endif /* PWM_REGISTER_H */