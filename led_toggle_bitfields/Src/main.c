/**
 ******************************************************************************
 * @file           : main.c
 * @author         : r_yantra
 * @brief          : led_toggle_bitfields
 *******************************************************************************/

#include "main.h"

/*
    uint32_t *pClkCtrlreg   = (uint32_t*)0x40023830;
	uint32_t *pPortAModeReg = (uint32_t*)0x40020000;
	uint32_t *pPortAOutReg  = (uint32_t*)0x40020014; */

int main(void)
{

	RCC_AHB1ENR_t 	volatile *const pClkCtrlReg 	= (RCC_AHB1ENR_t*)0x40023830;
	GPIOx_MOD_t		volatile *const pPortAModeReg	= (GPIOx_MOD_t*)0x40020000;
	GPIOx_ODR_t		volatile *const	pPortAOutReg	= (GPIOx_ODR_t*)0x40020014;

	//1.Enable the clock for GPIOA peripheral in the AHB1ENR
	pClkCtrlReg->gpioa_en = 1;

	//2. Configure the mode of the IO pin as output
	pPortAModeReg->pin_5 = 1;

	while(1)
	{
		//set 5th bit of the output data register to make I/O pin-5 as HIGH
		pPortAOutReg->pin_5 = 1;

		//introduce small human observable delay
		for(uint32_t i = 0; i < 300000 ; i++);

		//Turn OFF the LED
		pPortAOutReg->pin_5 = 0;

		for(uint32_t i = 0; i < 300000 ; i++);

	}
}
