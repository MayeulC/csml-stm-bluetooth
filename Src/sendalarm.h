#ifndef SENDALARM_H
#define SENDALARM_H
#include "stm32f4xx_hal.h"
#include "stdbool.h"

#define MEAN_WINDOW_LENGTH 50 // Note: change data types if > 255

uint8_t get_current_mean_duty_cycle();
void register_current_duty_cycle(uint8_t new_duty_cycle);
bool is_alarm_triggered();

#endif // SENDALARM_H
