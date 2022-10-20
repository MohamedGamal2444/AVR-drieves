#include "DIO.h"

/*DIO initiation function*/
EN_DIO_ERROR_Handler_t DIO_init(uint8_t Pin_number,uint8_t Port_number,uint8_t direction){
	switch(Port_number){
		/*SET PORT A*/
		case PORT_A:
		if (direction == OUTPUT){
			DDRA |=set_bit(Pin_number);
			return OK;
		}
		else if (direction == INPUT){
			DDRA = clear_bit(DDRA,Pin_number);
			return OK;
		}
		else if (direction == INPUT_PULLUP){
			DDRA = clear_bit(DDRA,Pin_number);
			PORTA |= set_bit(Pin_number);
			return OK;
		}
		else 
			//error handler
			return ERROR;
		break;
		/*SET PORT B*/
		case PORT_B:
		if (direction == OUTPUT){
			DDRB |= set_bit(Pin_number);
			return OK;
		}
		else if (direction == INPUT){
			DDRB = clear_bit(DDRB,Pin_number);
			return OK;
		}
		else if (direction == INPUT_PULLUP){
			DDRB = clear_bit(DDRB,Pin_number);
			PORTB |= set_bit(Pin_number);
			return OK;
		}
		else {
			//error handler
			return ERROR;
		}
		break;
		/*SET PORT C*/
		case PORT_C:
		if (direction == OUTPUT){
			DDRC |= set_bit(Pin_number);
			return OK;
		}
		else if (direction == INPUT){
			DDRC |= clear_bit(DDRC,Pin_number);
			return OK;
		}
		else if (direction == INPUT_PULLUP){
			DDRC |= clear_bit(DDRC,Pin_number);
			PORTC |= set_bit(Pin_number);
			return OK;
		}
		else {
			//error handler
			return ERROR;	
		}
		break;
		/*SET PORT D*/
		case PORT_D:
		if (direction == OUTPUT){
			DDRD |= set_bit(Pin_number);
			return OK;
		}
		else if (direction == INPUT){
			DDRD |= clear_bit(DDRD,Pin_number); 
			return OK;
		}
		else if (direction == INPUT_PULLUP){
			DDRD |= clear_bit(DDRD,Pin_number);
			PORTD |= set_bit(Pin_number);
			return OK;
		}
		else {
			//error handler
			return ERROR;
		}
		break;
		default:
		return ERROR;
		break;
	}
}
/*DIO write function*/
EN_DIO_ERROR_Handler_t DIO_Write(uint8_t Pin_number,uint8_t Port_number,uint8_t value){
	switch(Port_number){
		/*SET PIN IN PORT A*/
		case PORT_A:
		if (value == HIGH){
			PORTA |= set_bit(Pin_number);
			return OK;
		}
		else if (value == LOW){
			PORTA = clear_bit(PORTA,Pin_number);
			return OK;
		}
		else {
			//error handler
			return ERROR;
		}
		break;
		/*SET PIN IN B*/
		case PORT_B:
		if (value == HIGH){
			PORTB |= set_bit(Pin_number);
			return OK;
		}
		else if (value == LOW){
			PORTB = clear_bit(PORTB,Pin_number);
			return OK;
		}
		else {
			//error handler
			return ERROR;
		}
		break;
		/*SET PIN IN C*/
		case PORT_C:
		if (value == HIGH){
			PORTC |= set_bit(Pin_number);
			return OK;
		}
		else if (value == LOW){
			PORTC = clear_bit(PORTC,Pin_number);
			return OK;
		}
		else {
			//error handler
			return ERROR;
		}
		break;
		/*SET PIN IN D*/
		case PORT_D:
		if (value == HIGH){
			PORTD |= set_bit(Pin_number);
			return OK;
		}
		else if (value == LOW){
			PORTD = clear_bit(PORTD,Pin_number);
			return OK;
		}
		else {
			//error handler
			return ERROR;
		}
		break;
	default: 
	return ERROR;
	break;
	}	
}
/*DIO toggle function*/
EN_DIO_ERROR_Handler_t DIO_toggle(uint8_t Pin_number,uint8_t Port_number){
	switch(Port_number){
		/*TOGGLE PIN IN PORT A*/
		case PORT_A:
		PORTA |= toggle_bit(Pin_number);
		return OK;
		break;
		/*TOGGLE PIN IN PORT B*/
		case PORT_B:
		PORTB |= toggle_bit(Pin_number);
		return OK;
		break;
		/*TOGGLE PIN IN PORT C*/
		case PORT_C:
		PORTC |= toggle_bit(Pin_number);
		return OK;
		break;
		/*TOGGLE PIN IN PORT D*/
		case PORT_D:
		PORTD |= toggle_bit(Pin_number);
		return OK;
		break;
		default:
		return ERROR;
		break;
	}	
	
}
/*DIO read function*/
EN_DIO_ERROR_Handler_t DIO_read(uint8_t Pin_number,uint8_t Port_number,uint8_t* value){
	switch(Port_number){
		/*read PIN IN PORT A*/
		case PORT_A:
		*value = (get_bit(Pin_number,PINA));
		return OK;
		break;
		/*read PIN IN PORT B*/
		case PORT_B:
		*value = (get_bit(Pin_number,PINB));
		return OK;
		break;
		/*read PIN IN PORT C*/
		case PORT_C:
		*value = (get_bit(Pin_number,PINC));
		return OK;
		break;
		/*read PIN IN PORT D*/
		case PORT_D:
		*value = (get_bit(Pin_number,PIND));
		return OK;
		break;
		default:
		return ERROR;
		break;
	}
}
