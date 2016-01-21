/************************************************************************/
/*																											*/
/*	arty.c 	Digital IO functions for Microblaze	header		        	*/
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
/*	Describes the arty board pins by Digilentinc								*/
/*																						*/
/************************************************************************/
/*  Revision History:														*/
/*																						*/
/*	10/12/2015(SamL): created										*/
/*																						*/
/************************************************************************/



#include "arty.h"

XGpio swGpio;
XGpio ledGpio;

/* ------------------------------------------------------------ */
/*				Pin description Array							*/
/* ------------------------------------------------------------ */

//need to add chipkit IO
const struct digital_pin dPins[] = {
		{&swGpio,  XPAR_AXI_GPIO_SW_DEVICE_ID,  2, 0},  //0:  btn0
		{&swGpio,  XPAR_AXI_GPIO_SW_DEVICE_ID,  2, 1},  //1:  btn1
		{&swGpio,  XPAR_AXI_GPIO_SW_DEVICE_ID,  2, 2},  //2:  btn2
		{&swGpio,  XPAR_AXI_GPIO_SW_DEVICE_ID,  2, 3},  //3:  btn3
		{&swGpio,  XPAR_AXI_GPIO_SW_DEVICE_ID,  1, 0},  //4:  sw0
		{&swGpio,  XPAR_AXI_GPIO_SW_DEVICE_ID,  1, 1},  //5:  sw1
		{&swGpio,  XPAR_AXI_GPIO_SW_DEVICE_ID,  1, 2},  //6:  sw2
		{&swGpio,  XPAR_AXI_GPIO_SW_DEVICE_ID,  1, 3},  //7:  sw3
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 0},  //8:  RGB0_G
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 1},  //9:  RGB0_B
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 2},  //10: RGB0_R
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 3},  //11: RGB1_G
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 4},  //12: RGB1_B
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 5},  //13: RGB1_R
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 6},  //14: RGB2_G
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 7},  //15: RGB2_B
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 8},  //16: RGB2_R
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 9},  //17: RGB3_G
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 10}, //18: RGB3_B
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 2, 11}, //19: RGB3_R
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 1, 0},  //20: LED0
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 1, 1},  //21: LED1
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 1, 2},  //22: LED2
		{&ledGpio, XPAR_AXI_GPIO_LED_DEVICE_ID, 1, 3}   //23: LED3
};
