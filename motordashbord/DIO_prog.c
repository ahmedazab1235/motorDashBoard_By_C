/*
 * DIO_prog.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Ahmed Azab
 */

#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "AVR_DIO_REG.h"

#include "DIO_int.h"



/*
 * Description: Function set a  specific pin direction in a a  specific port
 * Inputs: number of the port , pin number ,  pin direction ( INPUT , OUTPUT )
 * Output: Error state
 */

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8Error=0;

	if((Copy_u8Pin <= 7) && (Copy_u8Direction <= 1))
	{

	switch(Copy_u8Port)

		{

		case DIO_PORT_A :

		ASSIGN_BIT(DDRA, Copy_u8Pin, Copy_u8Direction);

		break;

		case DIO_PORT_B :

		ASSIGN_BIT(DDRB, Copy_u8Pin, Copy_u8Direction);

		break;

		case DIO_PORT_C :

		ASSIGN_BIT(DDRC, Copy_u8Pin, Copy_u8Direction);

		break;

		case DIO_PORT_D :

		ASSIGN_BIT(DDRD, Copy_u8Pin, Copy_u8Direction);

		break;

		default:Local_u8Error = 1;

		break ;

		}
	}
	else
		{

		Local_u8Error = 1;

		}

		return Local_u8Error;
}


/*
 * Description: Function set a  specific port direction
 * Inputs: number of the port , port direction ( INPUT , OUTPUT )
 * Output: Error state
 */

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{

	u8 Local_u8Error=0;

	if((Copy_u8Port <= 3) && (Copy_u8Direction <= 0xFF))

	{
		switch(Copy_u8Port)

		{
			case DIO_PORT_A :

				DDRA = Copy_u8Direction;

				break;

			case DIO_PORT_B :

				DDRB = Copy_u8Direction;

				break;

			case DIO_PORT_C :

				DDRC = Copy_u8Direction;

				break;

			case DIO_PORT_D :

				DDRD=Copy_u8Direction;

				break;

			default:Local_u8Error = 1;

			break;
		}
	}
		else
		{

			Local_u8Error = 1;
		}

	return Local_u8Error;
}


/*
 * Description: Function set a  specific pin value in a a  specific port
 * Inputs: number of the port , pin number ,  port direction ( INPUT , OUTPUT )
 * Output: Error state
 */

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8Error=0;

	if((Copy_u8Pin <= 7) && (Copy_u8Value <= 1))

	{

	switch(Copy_u8Port)

		{

		case DIO_PORT_A :

		ASSIGN_BIT(PORTA, Copy_u8Pin, Copy_u8Value);

		break;

		case DIO_PORT_B :

		ASSIGN_BIT(PORTB, Copy_u8Pin, Copy_u8Value);

		break;

		case DIO_PORT_C :

		ASSIGN_BIT(PORTC, Copy_u8Pin, Copy_u8Value);

		break;

		case DIO_PORT_D :

		ASSIGN_BIT(PORTD, Copy_u8Pin, Copy_u8Value);

		break;

		default:

		Local_u8Error=1;

		break ;

		}
	}
		else
		{

		Local_u8Error = 1;

		}

	return Local_u8Error;

}

/*
 * Description: Function set a  specific port value
 * Inputs: number of the port , port value
 * Output: Error state
 */

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8Error = 0;

	if((Copy_u8Port <= 3) && (Copy_u8Value <= 0xFF))
	{
		switch(Copy_u8Port)
		{
			case DIO_PORT_A :

				PORTA = Copy_u8Value;

				break;

			case DIO_PORT_B :

				PORTB = Copy_u8Value;

				break;

			case DIO_PORT_C :

				PORTC = Copy_u8Value;

				break;

			case DIO_PORT_D :

				PORTD = Copy_u8Value;

				break;

			default:

			Local_u8Error = 1;

			break;
		}
	}

		else
		{

			Local_u8Error = 1;

		}

	return Local_u8Error;
}

/*
 * Description: Function get a value of specific  pin on specific port
 * Inputs: number of the port , pin number , pointer to variable to save the got value on it
 * Output: Error state
 */

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8*Copy_u8PValue)
{
	u8 Local_u8Error = 0;

	if((Copy_u8Port <= 3) && (Copy_u8Pin <= 7))
	{
		switch(Copy_u8Port)
		{
			case DIO_PORT_A:

				*Copy_u8PValue = GET_BIT(PINA, Copy_u8Pin);

				break;

			case DIO_PORT_B:

				*Copy_u8PValue = GET_BIT(PINB, Copy_u8Pin);

				break;

			case DIO_PORT_D:

				*Copy_u8PValue = GET_BIT(PIND, Copy_u8Pin);

				break;

			case DIO_PORT_C:

				*Copy_u8PValue = GET_BIT(PINC, Copy_u8Pin);

				break;

			default: Local_u8Error = 1;

			break ;
		}
	}

	else
	{

		Local_u8Error = 1;

	}
	return Local_u8Error;

}



/*
 * Description: Function get a value of specific  port
 * Inputs: number of the port ,pointer to variable to save the got value on it
 * Output: Error state
 */

u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8*Copy_u8PValue)
{

	u8 Local_u8Error = 0;

	if((Copy_u8Port <= 3))

	{
		switch(Copy_u8Port)
			{


				case DIO_PORT_A:

					*Copy_u8PValue = PINA;

					break;

				case DIO_PORT_B:

					*Copy_u8PValue = PINB;

					break;

				case DIO_PORT_D:

					*Copy_u8PValue = PIND;

					break;

				case DIO_PORT_C:

					*Copy_u8PValue = PINC;

					break;

				default : Local_u8Error = 1;

					break ;

			}
	}

				else

					{
		                Local_u8Error = 1 ;

					}


	        return Local_u8Error ;
	}
