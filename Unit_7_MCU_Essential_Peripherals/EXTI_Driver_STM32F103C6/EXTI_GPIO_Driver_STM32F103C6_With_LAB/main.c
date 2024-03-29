/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103x6.h"
#include <STM32F103x6_GPIO.h>
#include "Keypad.h"
#include "LCD.h"
#include "STM32F103x6_EXTI.h"

uint8_t flag = 1;

void IRQ_B9_Handler(void)
{
	flag = 0;
	LCD_Write_String("IRQ EXTI9 is Happened _|- ");
	delay_ms(1000);
	LCD_Clear_Screen();
}

int main(void)
{
	//Enable Clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	LCD_init();
	LCD_Clear_Screen();

	//Set and Initialize The EXTI PIN
	MCAL_EXTI_GPIO_SET_PIN_INFO(EXTI9B9,EXTI_Trigger_RISING,EXTI_IRQ_Enable,IRQ_B9_Handler);

	while(1)
	{
		if(flag == 1)
		{
			LCD_Clear_Screen();
			delay_ms(1000);
		}
	}
}


