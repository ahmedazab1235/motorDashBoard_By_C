/*
 * KEYBAD_prog.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Mohamed Adel
 */
#include "STD_TYPES.h"
#include "AVR_DIO_REG.h"
#include "DIO_int.h"
#include"KEYBAD_int.h"


u8 KeyBad_Col[]={C0,C1,C2,C3};

u8 KeyBad_Row[]={R0,R1,R2,R3};


void KeyBad_voidInit(void)
{
	DIO_u8SetPortDirection(KEY_BAD_PORT,0xF0);

	DIO_u8SetPortValue(KEY_BAD_PORT,0xFF);

}
void KeyBad_u8GetKey(u8*key)
{
	u8 i,j,getbit;//i co   j row

	for(i=0;i<4;i++)

	{
		DIO_u8SetPortValue(KEY_BAD_PORT,0xFF);

		DIO_u8SetPinValue(KEY_BAD_PORT,KeyBad_Col[i],DIO_PIN_LOW);

		for(j=0;j<4;j++)

		{
			DIO_u8GetPinValue(KEY_BAD_PORT,KeyBad_Row[j],&getbit);

			if(!(getbit))

			{
				while(!(getbit))

				{
					DIO_u8GetPinValue(KEY_BAD_PORT,KeyBad_Row[j],&getbit);
				}

		switch(i)

		{
				case 0:

						if(j==0)
							*key= 1 ;
						if(j==1)
							*key='4';
						if(j==2)
							*key='7';
						if(j==3)
							*key='=';
						break;

				case 1:
					{
						if(j==0)
							*key= 2 ;
						if(j==1)
							*key='5';
						if(j==2)
							*key='8';
						if(j==3)
							*key='*';
						break;
					}
				case 2:
					{
						if(j==0)
							*key= 3 ;
						if(j==1)
							*key='6';
						if(j==2)
							*key='9';
						if(j==3)
							*key='%';
						break;
					}
				case 3:
					{
						if(j==0)
							*key='+';
						if(j==1)
							*key='-';
						if(j==2)
							*key='/';
						if(j==3)
							*key='0';
						break;
					}

				}


			}
		}

	}

}

