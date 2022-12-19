# Embedded-c

This project generally  contains a source code which is tested for STM-NUCLEOF411RE  board.
Host Machine was Ubuntu 20.04. This project gave hands-on exposure for Mastering Modern Embedded C
coding style technique and its optimization.

Following step were perfom strickly to (Environment setup) build, debug and running the code successfully.

1.STM32CubeIDE Generic Linux Installer.

Once zip downloaded and extracted you get a .sh script file.
Make it executable (chmod +x ***.sh)
 
For Ubuntu, either:
   
   1. sudo ./st-stm32cubeide_1.4.0_7511_20200720_0928_amd64.deb_bundle​.sh

or 
   
   1. ./st-stm32cubeide_1.4.0_7511_20200720_0928_amd64​.sh

The 2nd will ask you later to execute some install steps as sudo. This is required since STLink-Server, Udev rules for 
STLink/Jlink installation need to change some basic system settings.

2.GCC Compiler on Linux

Before installing the GCC compiler on your Linux system, you need to check whether it is already installed on your system or not.

gcc –version

If gcc is installed already skip this step and jump into next step, otherwise 
sudo apt install build-essential


3.FPU warning fix

Right click on the project 
                        -> properties
                                    -> expand C/C++ build 
                                                        -> Settings 
                                                                    -> Tool settings 
                                                                                    -> MCU settings
                                                                                    
    • Floating-point unit: None 
    
    • Floating-point ABI: Software implementation ( -mfloat-abi=soft ) 
                  
                  
4.Setting up SWV ITM Data Console

Open syscalls.c file and paste following code bellow Includes

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//           Implementation of printf like feature using ARM Cortex M3/M4/ ITM functionality
//           This function will not work for ARM Cortex M0/M0+
//           If you are using Cortex M0, then you can use semihosting feature of openOCD
/////////////////////////////////////////////////////////////////////////////////////////////////////////


//Debug Exception and Monitor Control Register base address
#define DEMCR                   *((volatile uint32_t*) 0xE000EDFCU )

/* ITM register addresses */
#define ITM_STIMULUS_PORT0      *((volatile uint32_t*) 0xE0000000 )
#define ITM_TRACE_EN            *((volatile uint32_t*) 0xE0000E00 )

void ITM_SendChar(uint8_t ch)
{

        //Enable TRCENA
        DEMCR |= ( 1 << 24);

        //enable stimulus port 0
        ITM_TRACE_EN |= ( 1 << 0);

        // read FIFO status in bit [0]:
        while(!(ITM_STIMULUS_PORT0 & 1));

        //Write to ITM stimulus port0
        ITM_STIMULUS_PORT0 = ch;
}
 
After that find function _write and replace __io_putchar(*ptr++) with ITM_SendChar(*ptr++) like in code snippet below
__attribute__((weak)) int _write(int file, char *ptr, int len)
{
        int DataIdx;

        for (DataIdx = 0; DataIdx < len; DataIdx++)
        {
                //__io_putchar(*ptr++);
                ITM_SendChar(*ptr++);
        }
        return len;
}

5.Debug Configuration Setting for Serial Wire Viewer
In Debugger Menu under Serial Wire Viewer(SWV) make SWV enable with following settings
Clock Setting
Core Clock 16.0 Mhz
leave other as it is


    

