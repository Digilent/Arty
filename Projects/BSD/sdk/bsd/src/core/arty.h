

/************************************************************************/
/*																											*/
/*	arty.h 	Digital IO functions for Microblaze	header		        	*/
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
/*	Describes the arty board by Digilentinc								*/
/*																						*/
/************************************************************************/
/*  Revision History:														*/
/*																						*/
/*	10/12/2015(SamL): created										*/
/*																						*/
/************************************************************************/


#ifndef ARTY_H_
#define ARTY_H_

#include "xgpio.h"
#include "xparameters.h"
#include "digital.h"
//LED XPAR_AXI_GPIO_LED_DEVICE_ID



#define NUM_PINS 24

/////pins
//buttons
#define PIN_BTN0 0
#define PIN_BTN1 1
#define PIN_BTN2 2
#define PIN_BTN3 3

//Switches
#define PIN_SW0 4
#define PIN_SW1 5
#define PIN_SW2 6
#define PIN_SW3 7

//RGB Leds

#define PIN_RGB0_G 8
#define PIN_RGB0_B 9
#define PIN_RGB0_R 10

#define PIN_RGB1_G 11
#define PIN_RGB1_B 12
#define PIN_RGB1_R 13

#define PIN_RGB2_G 14
#define PIN_RGB2_B 15
#define PIN_RGB2_R 16

#define PIN_RGB3_G 17
#define PIN_RGB3_B 18
#define PIN_RGB3_R 19

#define PIN_LED0 20
#define PIN_LED1 21
#define PIN_LED2 22
#define PIN_LED3 23






#endif
