 /************************************************************************/
 /************************************************************************/
 /***********************  Author :Mahmoud Hamed   ***********************/
 /***********************       Layer :HAL        ***********************/
 /**********************         SWC :LED         ***********************/
 /***********************       Version :1.00      ***********************/
 /************************************************************************/
 /************************************************************************/


#ifndef LEDSH_H_
#define LEDSH_H_

/*pint input or out put */
#define LED_u8PIN_OUTPUT  1

/*pin high or low */
#define LED_u8PIN_HIGH    1




/*macros for ports */
#define LED_PORT      DIO_u8PORTB
/*
#define LED_u8PORTB      DIO_u8PORTB
#define LED_u8PORTC      DIO_u8PORTC
#define LED_u8PORTD      DIO_u8PORTD*/

/*macros for pins */
#define  LED_LOW          DIO_u8PIN4
#define  LED_NORMAL       DIO_u8PIN5
#define  LED_HIGH        DIO_u8PIN6


#define  LED_u8PIN3       3
#define  LED_u8PIN4       4
#define  LED_u8PIN5       5
#define  LED_u8PIN6       6
#define  LED_u8PIN7       7



/*function to set led pin high  turn led on */
u8 LED_u8SetLedOn(u8 copy_u8LedPort , u8 copy_u8LedPin);

/*function to set led pin low turn led off */
u8 LED_u8SetLedOff(u8 copy_u8LedPort , u8 copy_u8LedPin);

/*function to toggle led pin */
u8 LED_u8ToggleLed(u8 copy_u8LedPort , u8 copy_u8LedPin);





#endif /* LEDSH_H_ */