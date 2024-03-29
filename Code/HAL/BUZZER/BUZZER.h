 /*************************************************************************/
 /*************************************************************************/
 /***********************  Author :Mahmoud Hamed    ***********************/
 /***********************       Layer :HAL          ***********************/
 /**********************         SWC :BUZZER          *********************/
 /***********************       Version :1.00       ***********************/
 /*************************************************************************/
 /*************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_


#define BUZEER_PORT   DIO_u8PORTA

#define BUZEER_PIN    DIO_u8PIN1

void BUZZER_ON(void);
void BUZZER_OFF(void); 
void BUZZER_TOGGLE(void);



#endif /* BUZZER_H_ */