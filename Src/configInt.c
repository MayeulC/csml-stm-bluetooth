#include "configInt.h"
//#include "stm32f4xx_exti.h"
//#include "stm32f4xx_syscfg.h"
//#include "misc.h"
#include "configPWM.h"

// Inspiré de https://stm32f4-discovery.net/2014/08/stm32f4-external-interrupts-tutorial/

void configure_interruption ( void )
{
    /*
    // Set variables used
    GPIO_InitTypeDef GPIO_InitStruct;
    EXTI_InitTypeDef EXTI_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;
    
    // Enable clock for GPIOD
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    // Enable clock for SYSCFG
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    
    // Set pin as input
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOD, &GPIO_InitStruct);
    
    // Tell system that you will use PD0 for EXTI_Line0
    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource1);
    
    // PD0 is connected to EXTI_Line0
    EXTI_InitStruct.EXTI_Line = EXTI_Line1;
    // Enable interrupt
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    // Interrupt mode
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    // Triggers on rising and falling edge
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    // Add to EXTI
    EXTI_Init(&EXTI_InitStruct);
 
    // Add IRQ vector to NVIC
    // PD0 is connected to EXTI_Line0, which has EXTI0_IRQn vector
    NVIC_InitStruct.NVIC_IRQChannel = EXTI1_IRQn;
    // Set priority
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
    // Set sub priority
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
    // Enable interrupt
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    // Add to NVIC
    NVIC_Init(&NVIC_InitStruct);*/
}

/* Handle PD0 interrupt */
/*void EXTI1_IRQHandler(void) {
    // Make sure that interrupt flag is set
    if (EXTI_GetITStatus(EXTI_Line1) != RESET) {
	// Do your stuff when PD0 is changed
        configPWM(2000);
        HAL_Delay(1000);
        configPWM(1000);
        
	//Clear interrupt flag
        EXTI_ClearITPendingBit(EXTI_Line1);
    }
}
*/
