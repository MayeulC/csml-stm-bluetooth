#ifndef UART_CUSTOM_H
#define UART_CUSTOM_H
#include "usart.h"

#define RX_BUFFER_LEN 50

HAL_StatusTypeDef uart_print(char * str);
uint8_t read_uart_bt( char * buffer, uint8_t maxsize);
HAL_StatusTypeDef uart_bt_2bytes(uint8_t A, uint8_t B);

#endif // UART_CUSTOM_H
