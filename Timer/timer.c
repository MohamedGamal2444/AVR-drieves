/*
 * timer.c
 *
 * Created: 10/7/2022 2:32:21 PM
 *  Author: DELL
 */ 
#include "timer.h"
//timer delay variables 
double tick_time = 0.0;
double max_time_delay = 0.0; 
uint16_t timer_overflow = 0;
uint16_t no_of_overflows = 0;
uint16_t start_value = 0;

EN_TIMER_ERROR_Handler_t timer_init(uint8_t Timer_NO,uint8_t MODE,uint8_t initial_value){
	switch (Timer_NO){
		case TIMER0:
		//initiate timer zero 
		switch (MODE){
			case Normal_Mode:
			//clear bits 3,6 WGM00,WGM01
			TCCR0 = clear_bit(TCCR0,3);
			TCCR0 = clear_bit(TCCR0,6);
			TCNT0 = initial_value;
			return OK_T;
			break;
			case CTC_Mode:
			//set bit 6 and clear bit 3 WGM00,WGM01
			TCCR0 = clear_bit(TCCR0,3);
			TCCR0 = set_bit(6);
			TCNT0 = initial_value;
			return OK_T;
			break;
			case FAST_PWM_Mode:
			//set bits 3,6 WGM00,WGM01
			TCCR0 = set_bit(3);
			TCCR0 = set_bit(6);
			TCNT0 = initial_value;
			return OK_T;
			break;
			case PHASE_Correct_Mode:
			//set bit 3 and clear bit 6 WGM00,WGM01
			TCCR0 = clear_bit(TCCR0,6);
			TCCR0 = set_bit(3);
			TCNT0 = initial_value;
			return OK_T;
			break;
			default:
			//error handler 
			return ERROR_T;
			break;
			}
		break;
		case TIMER1:
		//intiate timer 1
		return OK_T;
		break;
		break;
		case TIMER2:
		//initiate timer two
		return OK_T;
		break;
		default:
		return ERROR_T;
		break;
	}
}

EN_TIMER_ERROR_Handler_t timer_start(uint8_t Timer_NO,uint8_t prescaler){
	switch (Timer_NO){
		case TIMER0:
		switch (prescaler){
			case TIMER_STOPPED:
			//clear bits 0,1,2 cs00,cs01,cs02
			TCCR0 |= TIMER_STOPPED;
			return OK_T;
			break;
			case NO_PRESCALER:
			//clear bits 1,2 and set bit 0
			return OK_T;
			TCCR0 |= NO_PRESCALER;
			break;
			case CLK_OVER_8:
			//clear bits 0,2 and set bit 1
			TCCR0 |= CLK_OVER_8;
			return OK_T;
			break;
			case CLK_OVER_64:
			//clear bit 2 and set bits 0,1
			TCCR0 |= CLK_OVER_64;
			return OK_T;
			break;
			case CLK_OVER_256:
			//clear bits 0,1 and set bit 2
			TCCR0 |= CLK_OVER_256;
			return OK_T;
			break;
			case CLK_OVER_1024:
			//clear bit 1 and set bits 0,2
			TCCR0 |= CLK_OVER_1024;
			return OK_T;
			break;
			case EXTERNAL_CLK_FALLING:
			//clear bit 0 and set bits 1,2
			TCCR0 |= EXTERNAL_CLK_FALLING;
			return OK_T;
			break;
			case EXTERNAL_CLK_RISING:
			//set bits 0,1,2
			TCCR0 |= EXTERNAL_CLK_RISING;
			return OK_T;
			break;
			default:
			return ERROR_T;
			break;
		}
		break;
		case TIMER1:
		return OK_T;
		break;
		case TIMER2:
		return OK_T;
		break;
		default:
		return ERROR_T;
		break;
	}
}

EN_TIMER_ERROR_Handler_t set_OC_pin(uint8_t Timer_NO,uint8_t MODE,uint8_t type){
	switch (Timer_NO){
		case TIMER0:
		//initiate timer zero
		switch (MODE){
			case CTC_Mode:
			switch (type){
				case DISCONNECTED:
				//clear bits 4,5 com00 com01
				TCCR0 = clear_bit(TCCR0,4);
				TCCR0 = clear_bit(TCCR0,5);
				return OK_T;
				break;
				case Toggle:
				//set bit 4 and clear bit 5 com00,com01
				TCCR0 = set_bit(4);
				TCCR0 = clear_bit(TCCR0,5);
				return OK_T;
				break;
				case Clear:
				//set bit 5 and clear bit 4 
				TCCR0 = clear_bit(TCCR0,4);
				TCCR0 = set_bit(5);
				return OK_T;
				break;
				case set:
				//set bits 4,5 com00,com01
				TCCR0 = set_bit(4);
				TCCR0 = set_bit(5);
				return OK_T;
				break;
				default:
				return ERROR_T;
				break;
			}
			break;
			case FAST_PWM_Mode:
			switch (type){
				case DISCONNECTED:
				//clear bits 4,5 com00 com01
				TCCR0 = clear_bit(TCCR0,4);
				TCCR0 = clear_bit(TCCR0,5);
				return OK_T;
				break;
				case non_inverting:
				//set bit 5 and clear bit 4
				TCCR0 = clear_bit(TCCR0,4);
				TCCR0 = set_bit(5);
				return OK_T;
				break;
				case inverting:
				//set bits 4,5 com00,com01
				TCCR0 = set_bit(4);
				TCCR0 = set_bit(5);
				return OK_T;
				break;
				default:
				return ERROR_T;
				break;
			}
			break;
			case PHASE_Correct_Mode:
			switch (type){
				case DISCONNECTED:
				//clear bits 4,5 com00 com01
				TCCR0 = clear_bit(TCCR0,4);
				TCCR0 = clear_bit(TCCR0,5);
				return OK_T;
				break;
				case clear_up_count:
				//set bit 5 and clear bit 4
				TCCR0 = clear_bit(TCCR0,4);
				TCCR0 = set_bit(5);
				return OK_T;
				break;
				case set_up_count:
				//set bits 4,5 com00,com01
				TCCR0 = set_bit(4);
				TCCR0 = set_bit(5);
				return OK_T;
				break;
				default:
				return ERROR_T;
			}
			break;
			default:
			return ERROR_T;
			//error handler
			break;
		}
		break;
		case TIMER1:
		return OK_T;
		break;
		case TIMER2:
		return OK_T;
		break;
		default:
		return ERROR_T;
		break;
	}
}
EN_TIMER_ERROR_Handler_t set_ocr_value(uint8_t Timer_NO,uint8_t value){
	switch (Timer_NO){
		case TIMER0:
		OCR0 = value;
		return OK_T;
		break;
		case TIMER1:
		return OK_T;
		break;
		case TIMER2:
		return OK_T;
		break;
		default:
		return ERROR_T;
		break;
	}
}

EN_TIMER_ERROR_Handler_t set_Timer_delay_ms (uint8_t Timer_NO,uint32_t delay, uint16_t prescaler){
	tick_time = (double)prescaler / F_CPU;
	max_time_delay = 256 * tick_time;
	no_of_overflows = ceil((delay)/max_time_delay);
	switch (Timer_NO){
		case TIMER0:
		start_value = 256 - (((delay)/tick_time ) / no_of_overflows);
		timer_init(TIMER0,Normal_Mode,start_value);
		if (prescaler == 1){
			timer_start(TIMER0,NO_PRESCALER);	
		}
		else if (prescaler == 8){
			timer_start(TIMER0,CLK_OVER_8);	
		}
		else if (prescaler == 64){
			timer_start(TIMER0,CLK_OVER_64);
		}
		else if (prescaler == 256){
			timer_start(TIMER0,CLK_OVER_256);
		}
		else if (prescaler == 1024){
			timer_start(TIMER0,CLK_OVER_1024);
		}
		//reach overflow numbers
		while (timer_overflow<no_of_overflows){
			while((TIFR&0x01)==0);
			TIFR = 0x1;
			timer_overflow ++;	
		}		
		timer_overflow = 0;
		stop_timer(TIMER0);
		return OK_T;
		break;
		default:
		return ERROR_T;
		break;
	}	  
}
EN_TIMER_ERROR_Handler_t stop_timer(uint8_t Timer_NO){
	switch (Timer_NO){
		case TIMER0:
		TCCR0 = 0;
		return OK_T;
		break;
		case TIMER1:
		return OK_T;
		break;
		case TIMER2:
		return OK_T;
		break;
		default:
		return ERROR_T;
	}
}