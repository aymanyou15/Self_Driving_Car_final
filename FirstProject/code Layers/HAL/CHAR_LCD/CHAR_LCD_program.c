/*
 * File        : CHAR_LCD_program.c
 * Description : This file includes the character LCD functions implementation
 * Notes	   : in case of using LEDS in your application, just include this file
 * Author      : Ayman Elgammal 
 * Date        : April 4,2021
 * Git account : https://github.com/aymanyou15
 * mail        : aymanyou15@gmail.com 
 */


#include "CHAR_LCD_interface.h"


static void lcd_send_enable(char_lcd_t *lcd)
{
    if( NULL == lcd )
    {
        // Please check the lcd_send_enable inputs
    }
    else
    {     
#if char_lcd_mode==4
    SetPin(lcd->lcd_port , lcd->en_pin);
    _delay_us(200);
    ClearPin(lcd->lcd_port, lcd->en_pin);
#elif char_lcd_mode==8
    SetPin(lcd->data_Port , lcd->en_pin);
    __delay_us(200);
    ClearPin(lcd->data_Port, lcd->en_pin);
#endif
    
    }
}

static void lcd_send_data_4bits(char_lcd_t *lcd , u8 data)
{
    if( NULL == lcd )
    {
        // Please check the lcd_send_data_4bits inputs
    }
    else
    {  
    SetPinValue(lcd->lcd_port , lcd->data_pin4 , (data>>0 & (0x01)));
    SetPinValue(lcd->lcd_port , lcd->data_pin5 , (data>>1 & (0x01)));
    SetPinValue(lcd->lcd_port , lcd->data_pin6 , (data>>2 & (0x01)));
    SetPinValue(lcd->lcd_port , lcd->data_pin7 , (data>>3 & (0x01)));
    }
}

static void lcd_set_cursor_location(char_lcd_t *lcd , u8 row , u8 coloum)
{
        if( NULL == lcd )
    {
        // Please check the lcd_Initialize inputs
    }
    else
    {    
        coloum--;
        switch(row)
        {
        
            case 1 : lcd_send_command(lcd , (0x80 + coloum)); break;
            case 2 : lcd_send_command(lcd , (0xC0 + coloum)); break;
            case 3 : lcd_send_command(lcd , (0x94 + coloum)); break;
            case 4 : lcd_send_command(lcd , (0xD4 + coloum)); break;
            default : /* do nothing */ ;
        }
    }
}

void lcd_initialize(char_lcd_t *lcd)
{
        if( NULL == lcd )
    {
        // Please check the lcd_Initialize inputs
    }
    else
    {
#if char_lcd_mode==4
    SetPinDirection(lcd->lcd_port , lcd->data_pin4 , OUTPUT);
    SetPinDirection(lcd->lcd_port , lcd->data_pin5 , OUTPUT);
    SetPinDirection(lcd->lcd_port , lcd->data_pin6 , OUTPUT);
    SetPinDirection(lcd->lcd_port , lcd->data_pin7 , OUTPUT);
    SetPinDirection(lcd->lcd_port , lcd->en_pin , OUTPUT);
    SetPinDirection(lcd->lcd_port , lcd->rs_pin , OUTPUT);
    
    ClearPin(lcd->lcd_port , lcd->data_pin4);
    ClearPin(lcd->lcd_port , lcd->data_pin5);
    ClearPin(lcd->lcd_port , lcd->data_pin6);
    ClearPin(lcd->lcd_port , lcd->data_pin7);
    ClearPin(lcd->lcd_port , lcd->en_pin);
    ClearPin(lcd->lcd_port , lcd->rs_pin);
    
    lcd_send_command(lcd , clear_display);
    lcd_send_command(lcd , return_home);
    lcd_send_command(lcd , cursor_disappear_display_on);
    lcd_send_command(lcd , shift_display_to_right);
    lcd_send_command(lcd , mode_4bit_DL_2_lines);
    lcd_send_command(lcd , DDRAM_start_address);


#elif char_lcd_mode==8
    SetPortDirection(lcd->data_Port , OUTPUT);
    SetPinDirection(lcd->en_Port , lcd->en_pin , OUTPUT);
    SetPinDirection(lcd->rs_Port , lcd->rs_pin , OUTPUT);
    
    SetPortValue(lcd->data_Port , LOW);
    ClearPin(lcd->en_Port, lcd->en_pin);
    ClearPin(lcd->rs_Port , lcd->rs_pin);
    
    lcd_send_command(lcd , clear_display);
    lcd_send_command(lcd , return_home);
    lcd_send_command(lcd , increment_cursor_mode);
    lcd_send_command(lcd , cursor_display_blink);
    lcd_send_command(lcd , cursor_move_to_right);
    lcd_send_command(lcd , mode_8bit_DL_1_lines);
    lcd_send_command(lcd , DDRAM_start_address);
    
#endif
    }
}   
        
void lcd_send_command(char_lcd_t *lcd , u8 command)
{
    if( NULL == lcd )
    {
        // Please check lcd_send_command inputs
    }
    else
    {
#if char_lcd_mode==4
    SetPinValue(lcd->lcd_port , lcd->rs_pin , LOW);
    lcd_send_data_4bits(lcd , (command>>4));
    lcd_send_enable(lcd);
    lcd_send_data_4bits(lcd , (command & 0x0F));
    lcd_send_enable(lcd);
    
#elif char_lcd_mode==8
    SetPinValue(lcd->rs_Port , lcd->rs_pin , LOW);
    SetPortValue(lcd->data_Port , command);
    lcd_send_enable(lcd);
    
#endif
    } 
    
}

void lcd_send_data_character(char_lcd_t *lcd , u8 data)
{
    if( NULL == lcd )
    {
        // Please check the lcd_send_data_character inputs
    }
    else
    {
#if char_lcd_mode==4
    SetPinValue(lcd->lcd_port , lcd->rs_pin , HIGH);
    lcd_send_data_4bits(lcd , (data>>4));
    lcd_send_enable(lcd);
    lcd_send_data_4bits(lcd , (data & 0x0F));
    lcd_send_enable(lcd);
    
#elif char_lcd_mode==8
    SetPinValue(lcd->rs_Port , lcd->rs_pin , HIGH);
    SetPortValue(lcd->data_Port , data);
    lcd_send_enable(lcd);
    
#endif
    }   
}

void lcd_send_data_character_position(char_lcd_t *lcd , u8 row , u8 coloum ,  u8 data)
{
    if( NULL == lcd )
    {
        // Please check the lcd_send_data_character_position inputs
    }
    else
    {
        lcd_set_cursor_location(lcd , row , coloum);
        lcd_send_data_character(lcd , data);
    }
}

void lcd_send_data_string(char_lcd_t *lcd , const u8 *data)
{
    if( NULL == lcd )
    {
        /* future feature */
    }
    else 
    {
        while(*data)
        {
            lcd_send_data_character(lcd , *data++);
            _delay_us(20);
        }
    }
}

void lcd_send_data_string_position(char_lcd_t *lcd , u8 row , u8 coloum , const u8 *data)
{    
    if( NULL == lcd )
    {
        /* future feature */
    }
    else 
    {
        lcd_set_cursor_location(lcd , row , coloum);
        while(*data)
        {
            lcd_send_data_character(lcd , *data++);
            _delay_us(20);  
        }
    }
}

void lcd_send_custom_character(char_lcd_t *lcd , u8 row , u8 coloum , const u8 *char_arr , u8 position)
{
    if( NULL == lcd || position > 7)
    {
        /* future feature */
    }
    else
    {
        lcd_send_command(lcd , CGRAM_start_address +(position*8));
        int counter = 0;
        for(counter = 0; counter <= 7; counter++)
        {
            lcd_send_data_character(lcd , char_arr[counter]);
        }
        lcd_send_command(lcd , DDRAM_start_address);
        lcd_send_data_character_position(lcd , row , coloum , position);
    }
}

void number_u8_to_string(u8 number , u8 *output)
{
    sprintf(output , "%i" , number);
}

void number_u16_to_string(u16 number , u16 *output)
{
    sprintf(output , "%i" , number);
}

void number_u32_to_string(u32 number , u32 *output)
{
    sprintf(output , "%i" , number);
}