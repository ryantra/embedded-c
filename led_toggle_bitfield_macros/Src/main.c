/**
 ******************************************************************************
 * @file           : main.c
 * @author         : r_yantra
 * @brief          : led_toggle_bitfields_using_macros
 *******************************************************************************/

#include "main.h"

/*
    uint32_t *pClkCtrlreg   = (uint32_t*)0x40023830;
	uint32_t *pPortAModeReg = (uint32_t*)0x40020000;
	uint32_t *pPortAOutReg  = (uint32_t*)0x40020014; */

int main(void)
{

	RCC_AHB1ENR_t 	volatile *const pClkCtrlReg 	= ADDR_REG_AHB1ENR;
	GPIOx_MOD_t		volatile *const pPortAModeReg	= ADDR_REG_GPIOA_MODE;
	GPIOx_ODR_t		volatile *const	pPortAOutReg	= ADDR_REG_GPIOA_ODR;

	//1.Enable the clock for GPIOA peripheral in the AHB1ENR
	pClkCtrlReg->gpioa_en = CLOCK_ENABLE;

	//2. Configure the mode of the IO pin as output
	pPortAModeReg->pin_5 = MODE_CONF_OUTPUT;

	while(1)
	{
		//set 5th bit of the output data register to make I/O pin-5 as HIGH
		pPortAOutReg->pin_5 = PIN_STATE_HIGH;

		//introduce small human observable delay
		for(uint32_t i = 0; i < DELAY_COUNT ; i++);

		//Turn OFF the LED
		pPortAOutReg->pin_5 = PIN_STATE_LOW;

		for(uint32_t i = 0; i < DELAY_COUNT ; i++);

	}
}

