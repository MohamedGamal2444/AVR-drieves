/*
 * ex_interrupt.c
 *
 * Created: 10/9/2022 12:43:00 AM
 *  Author: DELL
 */ 
#include "ex_interrupt.h"

EXT_INT_ERROR_Handler ext_interrupt_init (uint8_t PIN_NO, uint8_t MODE){
	switch (PIN_NO){
		case INT0:
		// set mode in MCUCR register 
		MCUCR |= MODE;
		//enable external INT
		GICR |= 1<<INT0;
		return OK_INT;
		break;
		case INT1:
		MCUCR |= (MODE << 2);
		GICR |= 1<<INT1;
		return OK_INT;
		break;
		case INT2:
		MCUCSR |= (MODE <<6);
		GICR |= 1<<INT2;
		return OK_INT;
		break;
		default:
		return ERROR_INT;
	}	
}