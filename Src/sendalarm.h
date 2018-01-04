/*
 *   sendalarm.h contains the header definitions for sendalarm.c
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
#ifndef SENDALARM_H
#define SENDALARM_H
#include "stm32f4xx_hal.h"
#include "stdbool.h"

#define MEAN_WINDOW_LENGTH 50 // Note: change data types if > 255

uint8_t get_current_mean_duty_cycle();
void register_current_duty_cycle(uint8_t new_duty_cycle);
bool is_alarm_triggered();

#endif // SENDALARM_H
