/*
 *   interruption_timer.h contains header declarations for interruption_timer.c
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
#ifndef INTERRUPTION_TIMER_H
#define INTERRUPTION_TIMER_H
#include "tim.h"
#include <stdbool.h>

extern volatile bool interrupt_received;
extern volatile uint8_t duty_cycle;

extern volatile uint32_t high_time;

void HAL_TIM_IC_CaptureCallback (TIM_HandleTypeDef *htim);

#endif //INTERRUPTION_TIMER_H
