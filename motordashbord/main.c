/*
 * main.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Ahmed Azab
 */
#include "STD_TYPES.h"
#include "DIO_int.h"
#include"avr/delay.h"

#include"KEYBAD_int.h"

#include"LCD4_config.h"
#include"LCD4_int.h"

#include"STEPPER_int.h"


int main(void)
{
	u8 x = 0;

	u8 chary = 0;

	u8 chary1 = 0 ;

	u8 counter = 0 ;

	u8 counter1 = 0 ;

	u8 counter3 = 0 ;

	u8 counter4 = 0 ;

	u8 mes1[] = "Motor Dashboard" ;

	u8 mes2[] = "1- Stepper Motor" ;

	u8 mes3[] = "2- DC Motor" ;

	u8 mes4[] = "1- Stepper CW" ;

	u8 mes5[] = "2- Stepper ACW" ;

	u8 mes6[] = "1- DC CW" ;

	u8 mes7[] = "2- DC ACW" ;

	u8 mes8[] = "Motor Loading " ;

	u8 mes10[] = "Motor stop" ;

	u8 mes9[] = "Ahmed Azab" ;

	u8 mes11[] = "Stepper CW" ;

	u8 mes12[] = "Stepper ACW" ;

	u8 mes13[] = "DC CW" ;

	u8 mes14[] = "DC ACW" ;

	u8 mes15[] = "Dr Ashraf" ;

	 LCD4_voidInit();

	 KeyBad_voidInit();

	 STEPPER_voidInit();

	 DIO_u8SetPortDirection(DIO_PORT_A , DIO_PORT_OUTPUT) ;


	 LCD4_voidSendString(mes1) ;

	 LCD4_voidSendCmd(LCD_CURSOR_BEGIN_SECOUND_LINE);

	 LCD4_voidSendString(mes9) ;

	 LCD4_voidSendCmd(LCD_CLEAR);

	 _delay_ms(10) ;

	 LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);

	 LCD4_voidSendString(mes15) ;

	 _delay_ms(500) ;

	 LCD4_voidSendCmd(LCD_CLEAR);

	 LCD4_voidSendString(mes2) ;

	 LCD4_voidSendCmd(LCD_CURSOR_BEGIN_SECOUND_LINE);

	 LCD4_voidSendString(mes3) ;



	while(1)
	{

if(!(x == 1))
{
	KeyBad_u8GetKey(&chary);
}


	if(chary == 1)
	{
		x = 1;

		if (counter == 0)
		{
			LCD4_voidSendCmd(LCD_CLEAR);

			_delay_ms(10) ;

			LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);

			LCD4_voidSendString(mes4) ;

			LCD4_voidSendCmd(LCD_CURSOR_BEGIN_SECOUND_LINE);

			LCD4_voidSendString(mes5) ;

		}
		KeyBad_u8GetKey(&chary1);

            if(chary1 == 1)
            	{

            	if (counter1 == 0)
      {
            		LCD4_voidSendCmd(LCD_CLEAR);

            		_delay_ms(10) ;

            		LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);



            		LCD4_voidSendString(mes8) ;

            		LCD4_voidSendChar(0b11110011) ;

            		LCD4_voidSendCmd(LCD_CURSOR_BEGIN_SECOUND_LINE);

            		LCD4_voidSendString(mes11) ;

        }

            		STEPPER_voidRunclockw();

            		counter1 = 10 ;

            		 counter4 = 0 ;


         }
            else if (chary1 == 2)
            {
              	if (counter1 == 0)
              {
            	LCD4_voidSendCmd(LCD_CLEAR);

	   	   		_delay_ms(10) ;

	   	   		LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);

	   	   		LCD4_voidSendString(mes8) ;

	   	   	LCD4_voidSendChar(0b11110011) ;

	   	 LCD4_voidSendCmd(LCD_CURSOR_BEGIN_SECOUND_LINE);

	   	             		LCD4_voidSendString(mes12) ;


              }

	   	   		STEPPER_voidRunAnticlockw() ;

	   	   	counter1 = 10 ;

	   	 counter4 = 0 ;

            }

else if (chary1 == 3)

       {

	STEPPER_voidStop();

	DIO_u8SetPinValue(DIO_PORT_C ,6 , DIO_PORT_LOW) ;

	DIO_u8SetPinValue(DIO_PORT_C ,7 , DIO_PORT_LOW) ;

            	if (counter4 == 0)
       {
            		LCD4_voidSendCmd(LCD_CLEAR);

            		_delay_ms(10) ;

            		LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);



            		LCD4_voidSendString(mes10) ;


            		_delay_ms(500);


            		LCD4_voidSendCmd(LCD_CLEAR);

            					_delay_ms(10) ;

            					LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);

            					LCD4_voidSendString(mes4) ;

            					LCD4_voidSendCmd(LCD_CURSOR_BEGIN_SECOUND_LINE);

            					LCD4_voidSendString(mes5) ;


        }




            	counter4 = 20 ;

            	counter1 = 0 ;
        	}



            counter = 10;


}

	else if(chary == 2 )
	{
		x = 1;

		if (counter3 == 0)
				{
	        	LCD4_voidSendCmd(LCD_CLEAR);

				_delay_ms(10) ;

				LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);

				LCD4_voidSendString(mes6) ;

			    LCD4_voidSendCmd(LCD_CURSOR_BEGIN_SECOUND_LINE);

				LCD4_voidSendString(mes7) ;

				}

					KeyBad_u8GetKey(&chary1);

		            if(chary1 == 1)
		            	{

		            	if (counter1 == 0)
		            	              {

		            		LCD4_voidSendCmd(LCD_CLEAR);

		            		_delay_ms(10) ;

		            		LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);

		            		LCD4_voidSendString(mes8) ;

		            		LCD4_voidSendChar(0b11110011) ;

		            		LCD4_voidSendCmd(LCD_CURSOR_BEGIN_SECOUND_LINE);

		            		            		LCD4_voidSendString(mes13) ;


		            	              }

		            		DIO_u8SetPinValue(DIO_PORT_C , 6, DIO_PIN_HIGH) ;

		            		counter1 = 10 ;

		            		 counter4 = 0 ;

		            	}
		            else if (chary1 == 2)
		            {

		            	if (counter1 == 0)
		            	              {


		            	LCD4_voidSendCmd(LCD_CLEAR);

			   	   		_delay_ms(10) ;

			   	   		LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);

			   	   		LCD4_voidSendString(mes8) ;

			   	   	LCD4_voidSendChar(0b11110011) ;
			   	 LCD4_voidSendCmd(LCD_CURSOR_BEGIN_SECOUND_LINE);

			   	             		LCD4_voidSendString(mes14) ;

		            	              }

			   	   	DIO_u8SetPinValue(DIO_PORT_C , 7, DIO_PIN_HIGH) ;

			   	   	counter1 = 10 ;

			   	 counter4 = 0 ;

		            }

		            else if (chary1 == 3)

		                   {
		        		STEPPER_voidStop();

		        		DIO_u8SetPortValue(DIO_PORT_A , DIO_PORT_LOW) ;

		                        	if (counter4 == 0)
		                   {
		                        		LCD4_voidSendCmd(LCD_CLEAR);

		                        		_delay_ms(10) ;

		                        		LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);



		                        		LCD4_voidSendString(mes10) ;

		                        		_delay_ms(500);

		                        		LCD4_voidSendCmd(LCD_CLEAR);

		                        		_delay_ms(10) ;

	                                    LCD4_voidSendCmd(LCD_CURSOR_BEGIN_FIRST_LINE);


	                                    LCD4_voidSendString(mes6) ;

	                                    			    LCD4_voidSendCmd(LCD_CURSOR_BEGIN_SECOUND_LINE);

	                                    				LCD4_voidSendString(mes7) ;



		                    }



		                        	counter4 = 20 ;

		                        	counter1 = 0 ;
		                    	}



		            counter3 = 10;
	}
	}









return 0;
}
