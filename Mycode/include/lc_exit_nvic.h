/**
  * 名称 ：lc_exit_nvic.h
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 2, 2021 5:12:47 PM
  */
#ifndef INCLUDE_LC_EXIT_NVIC_H_
#define INCLUDE_LC_EXIT_NVIC_H_

#include "main.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void GPIO_State_Init(void);
void GPIO_State_Open(void);
void GPIO_Single_line(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);	// 继电器单开函数

#endif /* INCLUDE_LC_EXIT_NVIC_H_ */
