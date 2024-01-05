
 /*************************************************************************/
 /*************************************************************************/
 /***********************  Author :Mahmoud Hamed    ***********************/
 /***********************       Layer :HAL          ***********************/
 /**********************         SWC :CLCD          ***********************/
 /***********************       Version :1.00       ***********************/
 /*************************************************************************/
 /*************************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#define LCD_ROW1    0
#define LCD_ROW2    1

#define LCD_COL1    0
#define LCD_COL2	1
#define LCD_COL3	2
#define LCD_COL4	3
#define LCD_COL5	4
#define LCD_COL6	5
#define LCD_COL7	6
#define LCD_COL8	7
#define LCD_COL9	8
#define LCD_COL10	9
#define LCD_COL11	10
#define LCD_COL12	11
#define LCD_COL13	12
#define LCD_COL14	13
#define LCD_COL15	14
#define LCD_COL16	15
#define LCD_COL17	16
#define LCD_COL18	17
#define LCD_COL19	18
#define LCD_COL20	19

/*function that send command to LCD */
void CLCD_vidSendCommand(u8 copy_u8Command); 

/*function that send data to display on LCD*/
void CLCD_vidSendData(u8 copy_u8Data);

/*function to send string*/
void CLCD_vidSednString(const char* copy_pcString);

/*function that initialize LCD to work*/
void CLCD_vidInit(void);

/*function to go to certain position on screen defined by (x,y )coordinates */
void CLCD_vidGoToXY(u8 copy_u8Xpos , u8 copy_u8Ypos);

/*function to write special character on LCD by writing in CGRAM*/
void CLCD_vidWriteSpecialCaracter(u8 * copy_pu8Pattern , u8 copy_u8PatternNumber, u8 copy_u8Xpos , u8 copy_u8Ypos ); 

/*function to write  large number on LCD*/
/*void CLCD_vidSendLargeNmber(u32 copy_u32Data);*/
void CLCD_vidSendLargeNmber(u32 Copy_u32Num);
/*function to clear LCD*/
void CLCD_vidClearLcd(void);



#endif