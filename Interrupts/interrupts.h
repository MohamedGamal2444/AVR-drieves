/*
 * interrupts.h
 *
 * Created: 10/8/2022 3:33:24 PM
 *  Author: DELL
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

//timer 0 overflow vector number
#define TIM0_OVF_VECT			__vector_12
//timer 0 compare vector number
#define TIM0_COMP_VECT			__vector_11
//timer 2 overflow vector number
#define TIM2_OVF_VECT			__vector_6
//timer 2 compare vector number
#define TIM2_COMP_VECT			__vector_5
//external interrupt 0
#define EXT_INT_0				__vector_1
//external interrupt 1
#define EXT_INT_1				__vector_2
//external interrupt 2
#define EXT_INT_2				__vector_3

//set global interrupt in SREG bit 7
# define sei()  __asm__ __volatile__ ("sei" ::: "memory")
//reset global interrupt in SREG bit 7
# define cli()  __asm__ __volatile__ ("cli" ::: "memory")

//ISR function macro
#define ISR(INT_VECT)	void INT_VECT(void)__attribute__((signal,used));\
void INT_VECT(void)
 


#endif /* INTERRUPTS_H_ */