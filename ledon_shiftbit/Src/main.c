//ledon_shiftbit

#include <stdint.h>

int main(void)
{
	uint32_t *pClkCtrlreg   = (uint32_t*)0x40023830;
	uint32_t *pPortAModeReg = (uint32_t*)0x40020000;
	uint32_t *pPortAOutReg  = (uint32_t*)0x40020014;

	//1.Enable the clock for GPIOA peripheral in the AHB1ENR
	*pClkCtrlreg |= (1 << 0);

	//2. Configure the mode of the IO pin as output
	//a. clear the 10th and 11th bit position(CLEAR)
	*pPortAModeReg &= ~(3 << 10);
	//b. make 10th bit position as 1 (SET)
	*pPortAModeReg |= (1 << 10);

	//3.Set 5th bit of the output data register to make I/O pin-5 high
	*pPortAOutReg |= (1 << 5);

	while(1);
}
