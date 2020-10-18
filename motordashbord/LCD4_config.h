/*
 * LCD_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: D.MONA
 */

/* Preprocessor Guard */


#ifndef LCD4_CONFIG_H_
#define LCD4_CONFIG_H_

/* Macros of LCD command codes*/

#define  LCD_PORT   DIO_PORT_B

#define LCD_CLEAR    0x01

#define LCD_CURSOR_OFF    0x0C

#define LCD_SHIFT_TO_LEFT   0x18

#define LCD_SHIFT_TO_RIGHT   0x1C

#define LCD_CURSOR_BEGIN_FIRST_LINE   0x80

#define LCD_CURSOR_BEGIN_SECOUND_LINE   0xC0

#define LCD_DISPLAYON_CURSORBLLINK         0x0E



#endif /* LCD4_CONFIG_H_ */
