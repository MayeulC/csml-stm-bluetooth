/*
 *   interruption_timer.c contains the timer interrupt routine
 *   Copyright (C) 2017  Mayeul Cantan <mayeul.cantan@gmail.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "interruption_timer.h"
#include "globals.h"
#include "gpio.h"
#include "stm32f4xx_hal.h"

volatile bool interrupt_received = false;
volatile uint32_t high_time = 0;
volatile uint8_t duty_cycle = 255;

void HAL_TIM_IC_CaptureCallback (TIM_HandleTypeDef *htim)
{
	if(htim != &htim5)
		return;
	uint32_t time = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
	__HAL_TIM_SetCounter(htim, 0);

	GPIO_PinState state =  HAL_GPIO_ReadPin( GPIOA, GPIO_PIN_0);

	if(state == GPIO_PIN_RESET) // we are low, therefore, we just got the high time
	{
		high_time = time;
	}
	else // time is low_time
	{
		if(time != 0 && high_time < 16843009 )
		{
			duty_cycle = (255 * high_time) / (high_time + time);
			// 51 secondes maximum pour 1 int32.
			// On a donc 25 secondes de dynamique max au dénominateur
			// et 51/255 = 0.2 secondes
		}
		else
		{
			duty_cycle = 255;
		}

		interrupt_received = true;
	}

}
