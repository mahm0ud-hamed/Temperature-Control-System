/*****************************************************************/
/*                      Author : Moamen Mamdouh Thabet           */
/*                      Date   : 16/11/2022                      */
/*                      Module : UART_praivate                   */
/*                      Layer  : MCAL                            */
/*                      Version:  1.0                            */
/*****************************************************************/

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR   (* (  volatile u8 * ) (0x2C) )    // on the fly pointer USART I/O Data Register
#define UCSRA (* (  volatile u8 * ) (0x2B) )    // USART Control and Status Register A
#define UCSRB (* (  volatile u8 * ) (0x2A) )    // USART Control and Status Register B
#define UCSRC (* (  volatile u8 * ) (0x40) )
#define UBRRH (* (  volatile u8 * ) (0x40) )
#define UBRRL (* (  volatile u8 * ) (0x29) )

/* UCSRA PINS */   /* This is a flag  register */
#define UCSRA_RXC   	7  //  USART Receive Complete
#define UCSRA_TXC   	6  //  USART Transmit Complete
#define UCSRA_UDRE   	5  //  USART Data Register Empty
#define UCSRA_FE 		4  //  Frame Error
#define UCSRA_DOR 	    3  //  Data OverRun
#define UCSRA_PE 		2  //  Parity Error
#define UCSRA_U2X 	    1  //  Double the USART Transmission Speed
#define UCSRA_MPCM 	    0  //  Multi-processor Communication Mode

/* UCSRB PINS */
#define UCSRB_RXCIE 	7  //  RX Complete Interrupt Enable
#define UCSRB_TXCIE 	6  //  TX Complete Interrupt Enable
#define UCSRB_UDRIE 	5  //  USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN 	    4  //  Receiver Enable
#define UCSRB_TXEN 	    3  //  Transmitter Enable
#define UCSRB_UCSZ2 	2  //  Character Size
#define UCSRB_RXB8 	    1  //  Receive Data Bit 8
#define UCSRB_TXB8 	    0  //  Transmit Data Bit 8

/* UCSRC PINS */
#define UCSRC_URSEL 	7  //  Register Select
#define UCSRC_UMSEL 	6  //  USART Mode Select
#define UCSRC_UPM1 	    5  //  Parity Mode
#define UCSRC_UPM0   	4  //  Parity Mode
#define UCSRC_USBS 	    3  //  Stop Bit Select
#define UCSRC_UCSZ1 	2  //  Character Size
#define UCSRC_UCSZ0 	1  //  Character Size
#define UCSRC_UCPOL 	0  //  Clock Polarity



/*Parity Modes*/
#define DISABLED        0
#define RESERVED        1
#define EVEN_PARITY     2
#define ODD_PARITY      3

/*Stop Bits*/
#define _1_BIT          0
#define _2_BIT          1

/*Data Size*/
#define _5_BIT          0
#define _6_BIT          1
#define _7_BIT          2
#define _8_BIT          3

/*Baud Rates*/
#define B_2400          416
#define B_4800          207
#define B_9600          103
#define B_14400         68
#define B_19200         51
#define B_28800         34
#define B_38400         25
#define B_57600         16
#define B_76800         12
#define B_115200        8
#define B_250000        3
#define B_500000        1
#define B_1000000       0


#endif /* UART_PRIVATE_H_ */
