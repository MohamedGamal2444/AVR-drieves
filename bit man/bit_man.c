/*
 * bit_man.c
 *
 * Created: 10/4/2022 10:14:26 PM
 *  Author: DELL
 */ 
#include "bit_man.h"

uint8_t set_bit(uint8_t bit_number){
	uint8_t result ;
	result |= (1<<bit_number);
	return result;
}
uint8_t clear_bit(uint8_t sent_register, uint8_t bit_number){
	sent_register &= ~(1<<bit_number);
	return sent_register;
}
uint8_t toggle_bit(uint8_t bit_number){
	uint8_t result ;
	result ^= (1<<bit_number);
	return result;
}
uint8_t get_bit(uint8_t bit_number,uint8_t byte){
	uint8_t result ;
	result =((byte & (1<<bit_number))>>bit_number);
	return result;
}