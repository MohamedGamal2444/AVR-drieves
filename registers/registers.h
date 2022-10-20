/************************************************************************/
/*					   		 DIO registers  					        */
/************************************************************************/

//define port addresses
#define PORTA *((volatile uint8_t *) 0x3B)
#define PORTB *((volatile uint8_t *) 0x38)
#define PORTC *((volatile uint8_t *) 0x35)
#define PORTD *((volatile uint8_t *) 0x32)

//define DDR addresses
#define DDRA *((volatile uint8_t *) 0x3A)
#define DDRB *((volatile uint8_t *) 0x37)
#define DDRC *((volatile uint8_t *) 0x34)
#define DDRD *((volatile uint8_t *) 0x31)

//define PIN addresses
#define PINA *((volatile uint8_t *) 0x39)
#define PINB *((volatile uint8_t *) 0x36)
#define PINC *((volatile uint8_t *) 0x33)
#define PIND *((volatile uint8_t *) 0x30)

/************************************************************************/
/*							general timer registers  			        */
/************************************************************************/
#define TIFR *((volatile uint8_t *) 0x58)
#define TIMSK *((volatile uint8_t *) 0x59)

/************************************************************************/
/*					   		 timer0 registers  					        */
/************************************************************************/
#define OCR0 *((volatile uint8_t *) 0x5C)
#define TCCR0 *((volatile uint8_t *) 0x53)
#define TCNT0 *((volatile uint8_t *) 0x52)

/************************************************************************/
/*					   		 timer2 registers  					        */
/************************************************************************/
#define OCR2 *((volatile uint8_t *) 0x43)
#define TCCR2 *((volatile uint8_t *) 0x45)
#define TCNT2 *((volatile uint8_t *) 0x44)


/************************************************************************/
/*                           Interrupt Registers	                    */
/************************************************************************/
#define SREG *((volatile uint8_t *) 0x5F)
#define MCUCR *((volatile uint8_t *) 0x55)
#define MCUCSR *((volatile uint8_t *) 0x54)
#define GICR *((volatile uint8_t *) 0x5B)
#define GIFR *((volatile uint8_t *) 0x5A

