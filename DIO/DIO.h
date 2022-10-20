#ifndef DIO_H_
#define DIO_H_
//needed libraries include  
#include "..\std_types\STD_TYPES.h"
#include "..\registers\registers.h"
#include "..\bit man\bit_man.h"
//define port macros 
#define PORT_A			'A'
#define PORT_B			'B'
#define PORT_C			'C'
#define PORT_D			'D'

//define common used macros
#define INPUT			 0
#define OUTPUT			 1	
#define INPUT_PULLUP	 2

#define LOW				 0
#define HIGH			 1 
//error handling enum 
typedef enum EN_DIO_ERROR_Handler_t {
	OK = 1,ERROR
}EN_DIO_ERROR_Handler_t; 
//functions declaration 
/*DIO initiation function*/
EN_DIO_ERROR_Handler_t DIO_init(uint8_t Pin_number,uint8_t Port_number,uint8_t direction);
/*DIO write function*/
EN_DIO_ERROR_Handler_t DIO_Write(uint8_t Pin_number,uint8_t Port_number,uint8_t value);
/*DIO toggle function*/
EN_DIO_ERROR_Handler_t DIO_toggle(uint8_t Pin_number,uint8_t Port_number);
/*DIO read function*/
EN_DIO_ERROR_Handler_t DIO_read(uint8_t Pin_number,uint8_t Port_number,uint8_t* value);

#endif 