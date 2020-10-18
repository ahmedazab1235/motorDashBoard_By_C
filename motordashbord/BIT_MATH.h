/*
 * BIT_MATH.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: D.MONA
 */


/* Preprocessor Guard */


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var, bit_no)        ((var)|=(1<<bit_no))

#define CLR_BIT(var, bit_no)        ((var)&=(~(1<<bit_no)))

#define TOGGLE_BIT(var, bit_no)     ((var)^=(1<<bit_no))

#define GET_BIT(var, bit_no)        (((var)>>bit_no)&0x01)

#define ASSIGN_BIT(var, bit_no, val) (var=((var)&(~(1<<bit_no)))|(val<<bit_no))

#endif /* BIT_MATH_H_ */
