#include "configPWM.h"
#include "stm32f4xx_hal.h"
#include "tim.h"

void configPWM(uint16_t value)
{
/*    TIM_OC_InitTypeDef TIM_OCStruct;
    TIM_OCStruct.OCMode = TIM_OCMODE_PWM2;
    TIM_OCStruct.OutputState = TIM_OutputState_Enable;
    TIM_OCStruct.OCPolarity = TIM_OCPOLARITY_LOW;
    
    TIM_OCStruct.TIM_Pulse = 1000; // 25% duty cycle
    TIM_OC1Init(TIM2, &TIM_OCStruct);
    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
*/
    TIM_OC_InitTypeDef sConfigOC;

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);  
}
