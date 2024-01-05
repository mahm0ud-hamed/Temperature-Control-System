/************************************************************************/
/************************************************************************/
/***********************  Author :Mahmoud Hamed   ***********************/
/***********************       Layer :MCAl        ***********************/
/***********************         SWC :DIO         ***********************/
/***********************       Version :1.00      ***********************/
/************************************************************************/
/************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_




/*pin high or low */
#define DIO_u8PIN_HIGH    1 
#define DIO_u8PIN_LOW     0 


/*port high or low*/
#define DIO_u8PORT_HIGH 0xff
#define DIO_u8PORT_LOW  0x00

/*macros for ports */
#define DIO_u8PORTA       0  
#define DIO_u8PORTB       1
#define DIO_u8PORTC       2
#define DIO_u8PORTD       3

/*macros for pins */
#define  DIO_u8PIN0       0
#define  DIO_u8PIN1       1
#define  DIO_u8PIN2       2
#define  DIO_u8PIN3       3
#define  DIO_u8PIN4       4
#define  DIO_u8PIN5       5
#define  DIO_u8PIN6       6
#define  DIO_u8PIN7       7




/* function to set pin value high or low */
u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

/*function to set port value high or low */
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value);

/*function to read pin value high or low */
u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_Pu8Value);

/*function to toggle a pin */
u8 DIO_u8TogglePinValue(u8 Copy_u8Port , u8 Copy_u8Pin);


#endif