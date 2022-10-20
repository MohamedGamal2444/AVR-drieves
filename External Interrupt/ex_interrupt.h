/*
 * ex_interrupt.h
 *
 * Created: 10/9/2022 12:42:09 AM
 *  Author: DELL
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

#include "..\registers\registers.h"
#include "..\std_types\STD_TYPES.h"

#define INT0				6
#define INT1				7
#define INT2				5
#define INT_LOW_LEVEL		0
#define INT_any_logic		1
#define INT_failing_edge	2
#define INT_rising_edge		3
#define INT2_rising			1
#define INT2_failing		0
typedef enum EXT_INT_ERROR_Handler {
	OK_INT = 1, ERROR_INT
}EXT_INT_ERROR_Handler;
//interrupt function definition
EXT_INT_ERROR_Handler ext_interrupt_init (uint8_t PIN_NO, uint8_t MODE);



#endif /* EX_INTERRUPT_H_ */