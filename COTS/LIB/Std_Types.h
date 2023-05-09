/*
 * std_types.h
 *
 *  Created on: Nov 3, 2021
 *      Author: Karim
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define MY_ISR(ISR_NO)		CONC(ISR_NO)
#define CONC(ISR_NO) void __vector_##ISR_NO(void) __attribute__((signal));\
						void __vector_##ISR_NO(void)

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long  int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long  int s32;

typedef float  f32;
typedef double f64;

#define TRUE 1
#define FALSE 0
#define NULL (void*)0

#endif /* STD_TYPES_H_ */
