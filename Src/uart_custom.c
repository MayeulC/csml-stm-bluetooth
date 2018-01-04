/*
 *   uart_custom.c contains custom uart-related functions
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
#include "uart_custom.h"
#include "string.h"

#define uart_bt &huart1
#define uart_pc &huart2

char charRead = '\0';

HAL_StatusTypeDef uart_print(char * str)
{
	if(str == NULL)
		return HAL_OK;
	uint16_t len = strlen(str);

	HAL_StatusTypeDef status =  HAL_UART_Transmit(
					uart_pc,
					(uint8_t *) str,
					len,
					10);
	return status;
}

// This function sends a message with two bytes, plus the \r \n chars
HAL_StatusTypeDef uart_bt_2bytes(uint8_t A, uint8_t B)
{
	uint8_t ch[4] = {A, B, '\r', '\n'};
	HAL_StatusTypeDef status =  HAL_UART_Transmit(
					uart_bt,
					ch,
					4,
					10);
	return status;
}

// Reads from BT UART to the buffer, and return the number of chars read
// Max size is the size of the buffer (includes one termination byte)
uint8_t read_uart_bt( char * buffer, uint8_t maxsize)
{
	uint8_t received = 0;
	HAL_StatusTypeDef status = HAL_OK;
	while(received < maxsize - 1 && status == HAL_OK)
	{
		status =  HAL_UART_Receive(
				uart_bt,
				(uint8_t *) buffer + received,
				1,
				10);
		if(status == HAL_OK)
			received++;
	}
	buffer[received] = '\0';
	return received;
}
