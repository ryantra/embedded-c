/**
 ******************************************************************************
 * @file           : main.c
 * @author         : r_yantra
 * @brief          : LED (LD2) Nucleo-F411RE
 ******************************************************************************
 */
#include <stdint.h>

int main(void)
{
	uint32_t *pClkCtrlreg   = (uint32_t*)0x40023830;
	uint32_t *pPortAModeReg = (uint32_t*)0x40020000;
	uint32_t *pPortAOutReg  = (uint32_t*)0x40020014;

	//1.Enable the clock for GPIOA peripheral in the AHB1ENR
	*pClkCtrlreg |= 0x01;

	//2. Configure the mode of the IO pin as output
	//a. clear the 10th and 11th bit position
	*pPortAModeReg &= 0xFFFFF3FF;
	//b. make 5th bit position as 1 (SET)
	*pPortAModeReg |= 0x00000400;

	//3.Set 5th bit of the output data register to make I/O pin-5 high
	*pPortAOutReg |= 0x0020;

	while(1);
}
