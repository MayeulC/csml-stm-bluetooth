/*
 *   uart_custom.h contains header declarations for uart_custom.c
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
#ifndef UART_CUSTOM_H
#define UART_CUSTOM_H
#include "usart.h"

#define RX_BUFFER_LEN 50

HAL_StatusTypeDef uart_print(char * str);
uint8_t read_uart_bt( char * buffer, uint8_t maxsize);
HAL_StatusTypeDef uart_bt_2bytes(uint8_t A, uint8_t B);

#endif // UART_CUSTOM_H
