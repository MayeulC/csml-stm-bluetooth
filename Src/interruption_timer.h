#ifndef INTERRUPTION_TIMER_H
#define INTERRUPTION_TIMER_H
#include "tim.h"
#include <stdbool.h>

extern volatile bool interrupt_received;
extern volatile uint8_t duty_cycle;

extern volatile uint32_t high_time;

void HAL_TIM_IC_CaptureCallback (TIM_HandleTypeDef *htim);

#endif //INTERRUPTION_TIMER_H
