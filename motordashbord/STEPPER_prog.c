#include "STD_TYPES.h"
#include "DIO_int.h"
#include"avr/delay.h"
#include"KEYBAD_int.h"
#include"STEPPER_config.h"


void STEPPER_voidRunclockw();

 void STEPPER_voidRunAnticlockw() ;


void STEPPER_voidInit(void)
{

	DIO_u8SetPortDirection(STEPPER_PORT , DIO_PORT_OUTPUT) ;


}

void STEPPER_voidStop(void)
{

	DIO_u8SetPortValue(STEPPER_PORT , DIO_PORT_LOW) ;


}


void STEPPER_voidRunclockw(void)
{

		DIO_u8SetPinValue(STEPPER_PORT , 0 , DIO_PIN_LOW) ;
		DIO_u8SetPinValue(STEPPER_PORT , 1 , DIO_PIN_LOW) ;
		DIO_u8SetPinValue(STEPPER_PORT , 2 , DIO_PIN_LOW) ;
		DIO_u8SetPinValue(STEPPER_PORT , 3 , DIO_PIN_HIGH) ;

		_delay_ms(10) ;

		DIO_u8SetPinValue(STEPPER_PORT , 0 , DIO_PIN_LOW) ;
		DIO_u8SetPinValue(STEPPER_PORT , 1 , DIO_PIN_LOW) ;
		DIO_u8SetPinValue(STEPPER_PORT , 2 , DIO_PIN_HIGH) ;
		DIO_u8SetPinValue(STEPPER_PORT , 3 , DIO_PIN_LOW) ;

		_delay_ms(10) ;

		DIO_u8SetPinValue(STEPPER_PORT , 0 , DIO_PIN_LOW) ;
		DIO_u8SetPinValue(STEPPER_PORT , 1 , DIO_PIN_HIGH) ;
		DIO_u8SetPinValue(STEPPER_PORT , 2 , DIO_PIN_LOW) ;
		DIO_u8SetPinValue(STEPPER_PORT , 3 , DIO_PIN_LOW) ;

		_delay_ms(10) ;

		DIO_u8SetPinValue(STEPPER_PORT , 0 , DIO_PIN_HIGH) ;
		DIO_u8SetPinValue(STEPPER_PORT , 1 , DIO_PIN_LOW) ;
		DIO_u8SetPinValue(STEPPER_PORT , 2 , DIO_PIN_LOW) ;
		DIO_u8SetPinValue(STEPPER_PORT , 3 , DIO_PIN_LOW) ;

		_delay_ms(10) ;




}



void STEPPER_voidRunAnticlockw(void)
{




						DIO_u8SetPinValue(STEPPER_PORT , 0 , DIO_PIN_LOW) ;
						DIO_u8SetPinValue(STEPPER_PORT , 1 , DIO_PIN_LOW) ;
						DIO_u8SetPinValue(STEPPER_PORT , 2 , DIO_PIN_LOW) ;
						DIO_u8SetPinValue(STEPPER_PORT , 3 , DIO_PIN_HIGH) ;

						_delay_ms(3) ;

						DIO_u8SetPinValue(STEPPER_PORT , 0 , DIO_PIN_HIGH) ;
						DIO_u8SetPinValue(STEPPER_PORT , 1 , DIO_PIN_LOW) ;
						DIO_u8SetPinValue(STEPPER_PORT , 2 , DIO_PIN_LOW) ;
						DIO_u8SetPinValue(STEPPER_PORT , 3 , DIO_PIN_LOW) ;

						_delay_ms(3) ;
						DIO_u8SetPinValue(STEPPER_PORT , 0 , DIO_PIN_LOW) ;
						DIO_u8SetPinValue(STEPPER_PORT , 1 , DIO_PIN_HIGH) ;
						DIO_u8SetPinValue(STEPPER_PORT , 2 , DIO_PIN_LOW) ;
				        DIO_u8SetPinValue(STEPPER_PORT , 3 , DIO_PIN_LOW) ;

						_delay_ms(3) ;
						DIO_u8SetPinValue(STEPPER_PORT , 0 , DIO_PIN_LOW) ;
												DIO_u8SetPinValue(STEPPER_PORT , 1 , DIO_PIN_LOW) ;
												DIO_u8SetPinValue(STEPPER_PORT , 2 , DIO_PIN_HIGH) ;
												DIO_u8SetPinValue(STEPPER_PORT , 3 , DIO_PIN_LOW) ;

												_delay_ms(3) ;


}









