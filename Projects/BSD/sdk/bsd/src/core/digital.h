
/************************************************************************/
/*																											*/
/*	digital.h 	Digital IO functions for Microblaze	header		        	*/
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



#ifndef DIGITAL_H_
#define DIGITAL_H_

#include "xgpio.h"

/* ------------------------------------------------------------ */
/*					Miscellaneous Declarations					*/
/* ------------------------------------------------------------ */

#define OUTPUT 0
#define INPUT  1

#define HIGH 1
#define LOW 0

struct digital_pin{
	XGpio *pGpio;
	u16 deviceID;
	unsigned channel;
	unsigned pin;
};

extern const struct digital_pin dPins[];

u32 digitalRead(int pin);
void digitalWrite(int pin, int state);
int pinMode(int pin, int state);
void delay(int millis);

#endif
