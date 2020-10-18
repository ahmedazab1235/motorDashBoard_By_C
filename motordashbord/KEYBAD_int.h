/*
 * KEYBAD_int.h
 *
 *  Created on: Aug 31, 2019
 *      Author: Mohamed Adel
 */

#ifndef KEYBAD_INT_H_
#define KEYBAD_INT_H_

#define KEY_BAD_PORT   DIO_PORT_D

#define KEY_BAD_PIN    PIND

#define KEY_BAD_NUM_OF_COL    4

#define R0  0

#define R1  1

#define R2  2

#define R3  3

#define C0  4

#define C1  5

#define C2  6

#define C3  7

void KeyBad_voidInit(void);

void KeyBad_u8GetKey(u8*key);


#endif /* KEYBAD_INT_H_ */
