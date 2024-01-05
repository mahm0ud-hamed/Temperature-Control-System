 /*************************************************************************/
 /*************************************************************************/
 /***********************  Author :Mahmoud Hamed    ***********************/
 /***********************     Layer :APP            ***********************/
 /******************** SWC :TEMP_CTRL_SYSTE_EEPROM_STORE ******************/
 /***********************       Version :1.00       ***********************/
 /*************************************************************************/
 /*************************************************************************/


#ifndef EEPROM_STORE_H_
#define EEPROM_STORE_H_

#define EEPROM_ADRESS      0xA0


#define HIGH_TEMP_u8ADRESS			 EEPROM_ADRESS
#define LOW_TEMP_u8ADRESS			 EEPROM_ADRESS
#define LOW_TEMP_u8LOCATION		     0x10
#define HIGH_TEMP_u8LOCATION         0x22
#define BY_PASS_TEMP                 0x28

/*description : A function to set the HIGH AND LOW temperature at ext EEPROM
* INPUT :void                   
* OUTPUT:void    */
void STORE_voidTEMPRATURE(void); 

/*description : A function to READ the STORE HIGH AND LOW temperature at ext EEPROM
* INPUT :void
* OUTPUT:void    */
void READ_STOR_voidTEMPARTURE(void);    


#endif /* EEPROM_STORE_H_ */