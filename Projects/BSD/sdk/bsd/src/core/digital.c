
/************************************************************************/
/*																											*/
/*	digital.c 	Digital IO functions for Microblaze			        	*/
/*																											*/
/************************************************************************/
/*	Author:		Samuel Lowe																*/
/*	Copyright (c) 2015, Digilent Inc. All rights reserved.					*/

/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/************************************************************************/
/*  Module Description:													*/
/*																						*/
/*	Describes the Digital IO functions for microblaze				*/
/*																						*/
/************************************************************************/
/*  Revision History:														*/
/*																						*/
/*	10/12/2015(SamL): created										*/
/*																						*/
/************************************************************************/


/* ------------------------------------------------------------ */
/*				Include File Definitions						*/
/* ------------------------------------------------------------ */

#include <stdio.h>
#include "xgpio.h"
#include "xparameters.h"
#include "microblaze_sleep.h"
#include "xil_printf.h"
#include "digital.h"


/* ------------------------------------------------------------ */
/*  pinMode
**
**  Parameters:
**    int pin: pin number associated with the desired port. Can be found in the "board".h file
**    int state: State to write input or output. Should use constants INPUT and OUTPUT
**
**  Return Value:
**    0	placeholder
**
**  Errors:
**    none
**
**  Description:
**    Sets the direction of the pin
*/
int pinMode(int pin, int state){

	u32 status;
	u32 mask;

	//check iof device is initialized and if not then initialize

	if(!dPins[pin].pGpio->IsReady){
		xil_printf("initializing");
		status = XGpio_Initialize(dPins[pin].pGpio, dPins[pin].deviceID);
		if (status != XST_SUCCESS){
			return XST_FAILURE;
		}
	}

	//get current directions of the channels
	mask = XGpio_GetDataDirection(dPins[pin].pGpio, dPins[pin].channel);

	//assign mask according to the desired output direction
	switch(state){
	case OUTPUT:
		mask = mask ^ (1 << dPins[pin].pin);
		break;
	case INPUT:
		mask = mask | (1 << dPins[pin].pin);
	default: break;
	}

	//will need to add logic when not only using LEDs
	XGpio_SetDataDirection(dPins[pin].pGpio, dPins[pin].channel, mask);

	return 0;

}

/* ------------------------------------------------------------ */
/*  digitalWrite
**
**  Parameters:
**    int pin: pin number associated with the desired port. Can be found in the "board".h file
**    int state: State to write to pin. Should use constants HIGH or LOW
**
**  Return Value:
**    none
**
**  Errors:
**    none
**
**  Description:
**    Sets the pin to logic high or low
*/
void digitalWrite(int pin, int state){

	u32 mask = 0;
	//read in current channel states
	//will need to add logic when not only using LEDs
	mask = XGpio_DiscreteRead(dPins[pin].pGpio, dPins[pin].channel);
	//assign new mask. May need to add more once we add more GPIO
	switch(state){
		case LOW:
			//set 0
			mask = mask & (~(1 << dPins[pin].pin));
			break;
		case HIGH:
			//set 1
			mask = mask | (1 << dPins[pin].pin);
		default: break;
	}
	//will need to add logic when not only using LEDs
	XGpio_DiscreteWrite(dPins[pin].pGpio, dPins[pin].channel, mask);

}

/* ------------------------------------------------------------ */
/*  digitalRead
**
**  Parameters:
**    int pin: pin number associated with the desired port. Can be found in the "board".h file
**
**  Return Value:
**    none
**
**  Errors:
**    none
**
**  Description:
**    Reads the pins current logic level
*/
u32 digitalRead(int pin){

	u32 data;
	//read in entire LED channel and isolate desired bit
	//will need to add logic when not only using LEDs
	data = XGpio_DiscreteRead(dPins[pin].pGpio, dPins[pin].channel) & 1 << dPins[pin].pin;
	//if data is not 0, the read bit was 1
	if(data)
		return 1;
	else
		return 0;

}


/* ------------------------------------------------------------ */
/*  delay
**
**  Parameters:
**    int millis: milliseconds to delay
**
**  Return Value:
**    none
**
**  Errors:
**    does not seem like actual millis. In fact much shorter
**    Should be placed in future time.c file
**
**  Description:
**    delays for a set time measured in milliseconds
*/
void delay(int millis){
	MB_Sleep(millis);
}
