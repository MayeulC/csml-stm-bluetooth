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
