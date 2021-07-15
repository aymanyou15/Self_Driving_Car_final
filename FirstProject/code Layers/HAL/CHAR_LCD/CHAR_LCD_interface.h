/*
 * File        : CHAR_LCD_interface.h
 * Description : This file includes the character LCD functions declaration
 * Notes	   : in case of using LEDS in your application, just include this file
 * Author      : Ayman Elgammal 
 * Date        : April 4,2021
 * Git account : https://github.com/aymanyou15
 * mail        : aymanyou15@gmail.com 
 */


#ifndef CHAR_LCD_INTERFACE_H
#define CHAR_LCD_INTERFACE_H


#include "../../MCAL/GPIO/GPIO_interface.h"
#define F_CPU 1000000UL
#include <util/delay.h>

// macro declaration
#define char_lcd_mode 4  // lcd data bus may be 4 or 8
/*****commands to use with 2 line LCD*****/
/*****this commands is used as a parameter in lcd_send_command function*****/
#define clear_display 0x01
#define return_home   0x02
#define increment_cursor_mode  0x06
#define decrememnt_cursor_mode 0x04
#define cursor_disappear_display_on  0x0C
#define cursor_disappear_display_off 0x08
#define cursor_display_blink   0x0F
#define cursor_display_stable  0x0E
#define shift_display_to_right 0x1C
#define shift_display_to_left  0x18
#define cursor_move_to_right   0x14
#define cursor_move_to_left    0x10
#define mode_8bit_DL_2_lines    0x38
#define mode_4bit_DL_2_lines    0x28
#define mode_8bit_DL_1_lines    0x30
#define mode_4bit_DL_1_lines    0x20
#define CGRAM_start_address 0x40
#define DDRAM_start_address 0x80


// data type definitions
typedef struct{
#if char_lcd_mode==4
    u8 lcd_port : 4;
    u8 data_pin4 : 3;
    u8 data_pin5 : 3;
    u8 data_pin6 : 3;
    u8 data_pin7 : 3;
    u8 en_pin : 4;
    u8 rs_pin: 4; 
#elif char_lcd_mode==8
    u8 data_Port :6;
    u8 en_Port : 5;
    u8 en_pin : 4;
    u8 rs_Port : 5;
    u8 rs_pin : 4;
#else
#error "please chek the LCD data length mode"
#endif   
}char_lcd_t;

// Functions declarations 
void lcd_initialize(char_lcd_t *lcd);

void lcd_send_command(char_lcd_t *lcd , u8 command);

void lcd_send_data_character(char_lcd_t *lcd , u8 data);

void lcd_clear_display(char_lcd_t *lcd);

void lcd_send_data_character_position(char_lcd_t *lcd , u8 row , u8 coloum , u8 data);

void lcd_send_data_string(char_lcd_t *lcd , const u8 *data);

void lcd_send_data_string_position(char_lcd_t *lcd , u8 row , u8 coloum , const u8 *data);

void lcd_send_custom_character(char_lcd_t *lcd , u8 row , u8 coloum , const u8 char_arr[] , u8 position);

void number_u8_to_string(u8 number , u8 *output);

void number_u16_to_string(u16 number , u16 *output);

void number_u32_to_string(u32 number , u32 *output);


#endif /* CHAR_LCD_INTERFACE_H */