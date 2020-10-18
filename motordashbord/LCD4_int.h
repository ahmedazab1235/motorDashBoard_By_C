/*
 * LCD_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: D.MONA
 */

/* Preprocessor Guard */

#ifndef LCD4_INT_H_
#define LCD4_INT_H_



/*
 * Description: Function send the command to cmd
 * Inputs: code of command
 * Output: void
 */

void LCD4_voidInit(void) ;

/*
 * Description: Function to initialize the LCD
 * Inputs: none
 * Output: void
 */

void LCD4_voidSendCmd(u8 cmd);

/*
 * Description: Function send a character to LCD
 * Inputs: the character will be send
 * Output: void
 */


void LCD4_voidSendChar(u8 data);

/*
 * Description: Function send a string to LCD
 * Inputs: pointer to the array of string
 * Output: void
 */

void LCD4_voidSendString (u8 * u8Str);



#endif /* LCD4_INT_H_ */
