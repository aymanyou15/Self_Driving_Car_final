#include "code Layers/HAL/LED/LED_interface.h"
#include "code Layers/MCAL/PWM/PWM_interface.h"
#include "code Layers/MCAL/ADC/ADC_interface.h"
#include "code Layers/MCAL/ADC-t/MADC_Interface.h"
#include "code Layers/MCAL/SPI/SPI_interface.h"
#include "code Layers/HAL/servo/servo.h"
#include "code Layers/HAL/DC_Motor/DC_MOTOR_interface.h"
#include "code Layers/HAL/LCD/LCD.h"
#include "code Layers/HAL/ULTRASONIC/ultrasonic.h"
#include <avr/io.h>
#include <math.h>




#define F_CPU 8000000UL
#include <util/delay.h>



    // type your applications data here

	led_t led2 =
		{
			.PORT_name = GPIO_PORTC,
			.PIN_no = PIN1
		};
	led_t led3 =
		{
			.PORT_name = GPIO_PORTC,
			.PIN_no = PIN2
		};

	DC_MOTOR_t motor1 =
	{
		.PORT_name = GPIO_PORTA,
		.PIN_INT1 = PIN0,
		.PIN_INT2 = PIN1,
		.PWM = PWM2
	};
	
	void app_initialize(void);





int main(void)
{ 

    // type your initializations here
    app_initialize();
	
	sei();
	
	
    f32 check = 0;
	check_distance = 0;
	
	// get the servo to normal position
	Servo_Motor_GetAngle(187);
	
	
	while(1)
	{  
	
	// measure the distance using ultrasonic	
 		ultra_triger();
 		_delay_ms(15);

	//get the data from raspberry pi
  		 check = SPI_SlaveReceive();
		   
		   
	// checking the existence of stop sign and checking whether there are obstacles or not   		 	
 		if(check_distance > 50)
		 {
   				if (check <= 55) 
   				{
				// the road is clear
 					check = check * 2.54;
   		 			DC_motor_forward(&motor1 , 210);
   		 			Servo_Motor_GetAngle(check + 120);
					Led_TurnON(&led3);
					Led_TurnON(&led2);
   				}
   				else if(check >= 100 && check <= 155)
   				{
				// there is a pump sign
 					check = check - 100;
 					check = check * 2.54;
 					DC_motor_forward(&motor1 , 210);
 					Servo_Motor_GetAngle(check + 120);
 					Led_TurnON(&led3);
					Led_TurnOFF(&led2);
   				}
 				  else if (check > 200 )
 				  {
				   // there is a stop sign
 					  DC_motor_stop(&motor1);
 					  Led_TurnON(&led2);
					  Led_TurnOFF(&led3);
 				  }
  			}
			else
			{
			// there is an obstacle in front of the car
  				DC_motor_stop(&motor1);
  				Led_TurnOFF(&led2);
 				Led_TurnOFF(&led3);
  			}
		 
    }
    return 0;
}

void app_initialize(void)
{
    Led_Initialize(&led2);
    Led_Initialize(&led3);

    SPI_SlaveInit();
    PWM_Timer2_INIT();
	Servo_Motor_Init();
	DC_motor_intialize(&motor1);
	lcd_init();
	ultrasonic_init();
}
