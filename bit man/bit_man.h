/*
 * IncFile1.h
 *
 * Created: 10/4/2022 10:14:35 PM
 *  Author: DELL
 */ 


#ifndef BIT_MAN_H_
#define BIT_MAN_H_

#include "..\std_types\STD_TYPES.h"

uint8_t set_bit(uint8_t bit_number);
uint8_t clear_bit(uint8_t sent_register,uint8_t bit_number);
uint8_t toggle_bit(uint8_t bit_number);
uint8_t get_bit(uint8_t bit_number, uint8_t byte);

#endif /* BIT_MAN_H_ */