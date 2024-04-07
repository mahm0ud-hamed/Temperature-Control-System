/************************************************************************/
/************************************************************************/
/***********************  Author :Mahmoud Hamed   ***********************/
/***********************       Layer :MCAl        ***********************/
/**********************         SWC :GIE         ***********************/
/***********************       Version :1.00      ***********************/
/************************************************************************/
/************************************************************************/

#include "../../SERVICE/STD_TYPES.h"
#include "../../SERVICE/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"
// function to enable General interrupt 
void GIE_vidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

// function to disable general interrupt 
void GIE_vidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
