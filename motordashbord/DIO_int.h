/*
 * test_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: D.MONA
 */


/* Preprocessor Guard */


#ifndef DIO_INT_H_
#define DIO_INT_H_


/* Macros to Ports mapping */

#define DIO_PORT_A     0

#define DIO_PORT_B     1

#define DIO_PORT_C     2

#define DIO_PORT_D     3

/* Macros for pin direction according to AVR */

#define DIO_PIN_OUTPUT    1

#define  DIO_PIN_INPUT     0

#define DIO_PIN_HIGH       1

#define DIO_PIN_LOW        0

/* Macros for PORT direction according to AVR */

#define DIO_PORT_OUTPUT   255

#define DIO_PORT_INPUT      0

#define DIO_PORT_HIGH   255

#define DIO_PORT_LOW      0

/*********************************************************************/


/*
 * Description: Function to set the direction of a specific pin in a specified port
 * Inputs: number of the port , the pin number , the pin direction
 * Output: the Error state of the function
 */

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/*
 * Description: Function to set the direction of a specific port
 * Inputs: number of the port ,  the port direction
 * Output: the Error state of the function
 */

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);


/*
 * Description: Function to set the value of a specific pin in a specified port
 * Inputs: number of the port , the pin number , the pin value (INPUT , OUTPUT )
 * Output: the Error state of the function
 */

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/*
 * Description: Function to set the value of a specific  port
 * Inputs: number of the port , the port value
 * Output: the Error state of the function
 */

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);


/*
 * Description: Function to get the value of a specific pin in a specified port
 * Inputs: number of the port , the pin number , address to return the got value on it
 * Output: the Error state of the function
 */


u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8*Copy_u8PValue);

/*
 * Description: Function to get the value of a specific  port
 * Inputs: number of the port , address to return the got value on it
 * Output: the Error state of the function
 */

u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8*Copy_u8PValue);

#endif
