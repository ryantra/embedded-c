#include <stdint.h>

int main(void)
{
	uint32_t volatile *pClkCtrlreg   = (uint32_t*)0x40023830;
	uint32_t volatile *pPortAModeReg = (uint32_t*)0x40020000;
	uint32_t volatile *pPortAOutReg  = (uint32_t*)0x40020014;

	uint32_t volatile *pPortAInReg  = (uint32_t*)0x40020010;

	//Enable the clock for GPIOA peripheral in the AHB1ENR
	*pClkCtrlreg |= (1 << 0);

	//configuring PA5 as output
	*pPortAModeReg &= ~(3 << 10);
	//b. make 10th bit position as 1 (SET)
	*pPortAModeReg |= (1 << 10);

	//configure PA0 as input mode (GPIO MODE REGISTER)
	*pPortAModeReg &= ~(3 << 0);



	while(1)
	{
		//read the pin status of the pin PA0 (GPIOA INPUT DATA REGISTER)
		uint8_t pinStatus = (uint8_t)(*pPortAInReg & 0x1);	//zero out all other bits except bit 0

		if(pinStatus){
			//turn on the led
			*pPortAOutReg |= (1 << 5);
		}else{
			//turn off the LED
			*pPortAOutReg |= ~(1 << 5);
		}
	}

}
