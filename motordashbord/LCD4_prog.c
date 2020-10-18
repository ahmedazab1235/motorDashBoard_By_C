/*
  * LCD_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: D.MONA
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_int.h"
#include"avr/delay.h"
#include "LCD4_config.h"



/*
 * Description: Function send the command to cmd
 * Inputs: code of command
 * Output: void
 */
void LCD4_voidSendCmd(u8 cmd)

{
	/* RS  => 0 (command) */
	DIO_u8SetPinValue(LCD_PORT , 4 , DIO_PIN_LOW) ;

	/* R/W  => 0 (Write) */
	DIO_u8SetPinValue(LCD_PORT , 5 , DIO_PIN_LOW)  ;

	/* sending upper nibble */

	DIO_u8SetPinValue(LCD_PORT ,0 ,  GET_BIT(cmd, 4)) ;
	DIO_u8SetPinValue(LCD_PORT ,1 ,  GET_BIT(cmd, 5)) ;
	DIO_u8SetPinValue(LCD_PORT ,2 ,  GET_BIT(cmd, 6)) ;
	DIO_u8SetPinValue(LCD_PORT ,3 ,  GET_BIT(cmd, 7)) ;

	DIO_u8SetPinValue(LCD_PORT , 6 , DIO_PIN_HIGH)  ;

	_delay_ms(1);

	DIO_u8SetPinValue(LCD_PORT , 6 , DIO_PIN_LOW)  ;

	_delay_ms(100);

	/* sending lower nibble */

	DIO_u8SetPinValue(LCD_PORT ,0 ,  GET_BIT(cmd, 0)) ;
	DIO_u8SetPinValue(LCD_PORT ,1 ,  GET_BIT(cmd, 1)) ;
	DIO_u8SetPinValue(LCD_PORT ,2 ,  GET_BIT(cmd, 2)) ;
	DIO_u8SetPinValue(LCD_PORT ,3 ,  GET_BIT(cmd, 3)) ;

	DIO_u8SetPinValue(LCD_PORT , 6 , DIO_PIN_HIGH)  ;

	_delay_ms(1);

	DIO_u8SetPinValue(LCD_PORT , 6 , DIO_PIN_LOW)  ;

	_delay_ms(100);



}

/*
 * Description: Function to initialize the LCD
 * Inputs: none
 * Output: void
 */
void LCD4_voidInit(void)

{
	_delay_ms(40);

	DIO_u8SetPortDirection(LCD_PORT , DIO_PORT_OUTPUT) ;

	LCD4_voidSendCmd(0x02) ;

	_delay_ms(1);

	LCD4_voidSendCmd(0x28) ;

	_delay_ms(1);

	LCD4_voidSendCmd(LCD_CLEAR) ;

	_delay_ms(15);


	LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE) ;

	_delay_ms(15);

	LCD4_voidSendCmd(LCD_DISPLAYON_CURSORBLLINK) ;





}

/*
 * Description: Function send a character to LCD
 * Inputs: the character will be send
 * Output: void
 */

void LCD4_voidSendChar(u8 data)

{

	DIO_u8SetPinValue(LCD_PORT , 4 , DIO_PIN_HIGH) ;

	DIO_u8SetPinValue(LCD_PORT , 5 , DIO_PIN_LOW)  ;


	/* sending upper nibble */

	DIO_u8SetPinValue(LCD_PORT ,0 ,  GET_BIT(data, 4)) ;
	DIO_u8SetPinValue(LCD_PORT ,1 ,  GET_BIT(data, 5)) ;
	DIO_u8SetPinValue(LCD_PORT ,2 ,  GET_BIT(data, 6)) ;
	DIO_u8SetPinValue(LCD_PORT ,3 ,  GET_BIT(data, 7)) ;

	DIO_u8SetPinValue(LCD_PORT , 6 , DIO_PIN_HIGH)  ;

	_delay_ms(1);

	DIO_u8SetPinValue(LCD_PORT , 6 , DIO_PIN_LOW)  ;

	_delay_ms(100);

	/* sending lower nibble */

	DIO_u8SetPinValue(LCD_PORT, 0,  GET_BIT(data, 0)) ;
	DIO_u8SetPinValue(LCD_PORT, 1,  GET_BIT(data, 1)) ;
	DIO_u8SetPinValue(LCD_PORT, 2,  GET_BIT(data, 2)) ;
	DIO_u8SetPinValue(LCD_PORT, 3,  GET_BIT(data, 3)) ;

	DIO_u8SetPinValue(LCD_PORT, 6, DIO_PIN_HIGH)  ;

	_delay_ms(1);

	DIO_u8SetPinValue(LCD_PORT, 6, DIO_PIN_LOW)  ;

	_delay_ms(100);



}

/*
 * Description: Function send a string to LCD
 * Inputs: pointer to the array of string
 * Output: void
 */

void LCD4_voidSendString (u8 * u8Str)

{
	u8 i =0 ;

	while (u8Str[i] != '\0')
	{
		LCD4_voidSendChar(u8Str[i])  ;

		i++ ;
	}
}
