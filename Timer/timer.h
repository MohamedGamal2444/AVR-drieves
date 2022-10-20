/*
 * IncFile1.h
 *
 * Created: 10/7/2022 2:32:30 PM
 *  Author: DELL
 */ 


#ifndef TIMER_H_
#define TIMER_H_
//include needed libraries 
#include "..\bit man\bit_man.h"
#include "..\registers\registers.h"
#include "..\std_types\STD_TYPES.h"
#include "..\Interrupts\interrupts.h"
#include "math.h"
//defined timers
#define TIMER0					0
#define TIMER1					1
#define TIMER2					2

//defined mode macros 
#define Normal_Mode				0
#define CTC_Mode				1
#define FAST_PWM_Mode			2
#define PHASE_Correct_Mode		3

//defined prescaler macros 
#define TIMER_STOPPED			0
#define NO_PRESCALER			1
#define CLK_OVER_8				2
#define	CLK_OVER_64				3
#define CLK_OVER_256			4
#define CLK_OVER_1024			5	
#define EXTERNAL_CLK_FALLING	6
#define	EXTERNAL_CLK_RISING		7

//defined OC pin macros 
#define DISCONNECTED			0
#define Toggle					1
#define Clear					2
#define set						3
#define non_inverting			4
#define inverting				5
#define	clear_up_count			6
#define set_up_count			7
#define F_CPU					16000
 
//error handling enum
typedef enum EN_TIMER_ERROR_Handler_t {
	OK_T = 1,ERROR_T
}EN_TIMER_ERROR_Handler_t;

//functions declaration 
EN_TIMER_ERROR_Handler_t timer_init(uint8_t Timer_NO,uint8_t MODE,uint8_t initial_value);
EN_TIMER_ERROR_Handler_t timer_start(uint8_t Timer_NO,uint8_t prescaler);
EN_TIMER_ERROR_Handler_t set_OC_pin(uint8_t Timer_NO,uint8_t MODE,uint8_t type);
EN_TIMER_ERROR_Handler_t set_ocr_value(uint8_t Timer_NO,uint8_t value);
EN_TIMER_ERROR_Handler_t set_Timer_delay_ms (uint8_t Timer_NO,uint32_t delay, uint16_t prescaler);
EN_TIMER_ERROR_Handler_t stop_timer(uint8_t Timer_NO);
#endif /* TIMER_H_ */