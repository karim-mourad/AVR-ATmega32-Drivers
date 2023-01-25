/*
 * bit_math.h
 *
 *  Created on: Nov 3, 2021
 *      Author: Karim
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) ((VAR >> BITNO) & 0x01)
#define SET_HIG_NIB(REG) ((REG)|= (F<<(sizeof(REG)*8-4)))
#define CLR_HIG_NIB(REG) ((REG) &=~(F<<(sizeof(REG)*8-4)))
#define GET_HIG_NIB(REG) ((REG&(F<<(sizeof(REG)*8-4)))>>(sizeof(REG)*8-4))
#define TGL_HIG_NIB(REG) (REG ^= (F<<(sizeof(REG)*8-4)))
#define SET_LOW_NIB(REG) ((REG)|= F)
#define CLR_LOW_NIB(REG) ((REG) &=~(F))
#define GET_LOW_NIB(REG) (REG&F)
#define TGL_LOW_NIB(REG) (REG ^= F)
#define SET_REG(REG)     (REG |= 0xFF)
#define CLR_REG(REG)    (REG &= 0x00)
#define ASSIGN_REG(REG,VALUE) (REG=((REG&0xFF)|VALUE))
#define ASSIGN_HIG_NIB(REG,VALUE) (REG= (REG& ~(0x0F<<(sizeof(REG)*8-4))) | (VALUE<<(sizeof(REG)*8-4)))
#define ASSIGN_LOW_NIB(REG,VALUE) (REG= (REG& ~(0x0F)) | VALUE)
#define SHIFT_RIGHT(REG,VALUE) (REG>>=VALUE)
#define SHIFT_LEFT(REG,VALUE) (REG<<=VALUE)
#define CLR_RIGHT_SHIFT(REG,VALUE) (REG) = ( (REG >> VALUE) | ( REG << (sizeof(REG)*8-VALUE) ))
#define CLR_LEFT_SHIFT(REG,VALUE) (REG) = ( (REG << VALUE) | (REG >> (sizeof(REG)*8-VALUE)) )

#endif /* BIT_MATH_H_ */
