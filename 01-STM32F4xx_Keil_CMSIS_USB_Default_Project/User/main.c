/**
 *	Keil project template
 *
 *	Before you start, select your target, on the right of the "Load" button
 *
 *	@author		Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@ide		Keil uVision 5
 *	@conf		System clock configured for USB if needed
 *	@conf		STM32F429 and STM32F446 are set to 168MHz and STM32F411xx to 96MHz for USB 48MHz clock
 *	@conf		PLL parameters are set in "Options for Target" -> "C/C++" -> "Defines"
 *	@packs		STM32F4xx Keil packs version 2.4.0 or greater required
 *	@stdperiph	STM32F4xx Standard peripheral drivers version 1.5.0 or greater required
 */
/* Include core modules */
#include "stm32f4xx.h"
/* Include my libraries here */
#include "defines.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_usart.h"
#include "tm_stm32f4_l3gd20.h"
#include <stdio.h>
#include "tm_stm32f4_lis302dl_lis3dsh.h"


int main(void) {


	TM_LIS302DL_LIS3DSH_t Axes_Data;
	
	uint8_t c,b;
	short *x,*y,*z;
	short *a;
	
	*a=c;

    char buffer[20];
	
	/* Initialize system */
	SystemInit();
	TM_DELAY_Init();
	/* Initialize USART2 at 9600 baud, TX: PA2, RX: PA3 */
	TM_USART_Init(USART2, TM_USART_PinsPack_1, 9600);
	
	
	
	/* Detect proper device */
	if (TM_LIS302DL_LIS3DSH_Detect() == TM_LIS302DL_LIS3DSH_Device_LIS302DL) {
							TM_USART_Puts(USART2, "radi TM_LIS302DL_LIS3DSH_Device_LIS302DL");					   
		/* Initialize LIS302DL */
		TM_LIS302DL_LIS3DSH_Init(TM_LIS302DL_Sensitivity_2_3G, TM_LIS302DL_Filter_2Hz);
	} else if (TM_LIS302DL_LIS3DSH_Detect() == TM_LIS302DL_LIS3DSH_Device_LIS3DSH) {
							TM_USART_Puts(USART2, "radi TM_LIS302DL_LIS3DSH_Device_LIS302DSH");					   
		/* Initialize LIS3DSH */
		TM_LIS302DL_LIS3DSH_Init(TM_LIS3DSH_Sensitivity_2G, TM_LIS3DSH_Filter_800Hz);
	} else {
		/* Device is not recognized */
		
		/* Turn on ALL leds */
							TM_USART_Puts(USART2, "nis ne radi ");					   
		
		/* Infinite loop */
	}
	
c='a';

		
	while (1) {
		
	TM_LIS302DL_LIS3DSH_ReadAxes(&Axes_Data);
		
		Delay(100000);
		
							sprintf(buffer, "X %d /   ",Axes_Data.X);
							TM_USART_Puts(USART2, buffer);					
							sprintf(buffer, "Y %d ,   ",Axes_Data.Y);
							TM_USART_Puts(USART2, buffer);		
						  sprintf(buffer, "Z %d .   ",Axes_Data.Z);
							TM_USART_Puts(USART2, buffer);	
	}
				
				

	
	}

