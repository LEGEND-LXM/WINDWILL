/**
  * 名称 ：lc_tim_nvic.h
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 4, 2021 9:25:05 AM
  */
#ifndef INCLUDE_LC_TIM_NVIC_H_
#define INCLUDE_LC_TIM_NVIC_H_

#include "main.h"

extern int16_t shift_count;

void LC_TimInterrupt_Init(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);



#endif /* INCLUDE_LC_TIM_NVIC_H_ */
