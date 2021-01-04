/**
  * 名称 ：lc_tim_nvic.c
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 4, 2021 9:25:27 AM
  */
#include "main.h"
#include "lc_tim_nvic.h"
#include "tim.h"
#include "lc_ws2812.h"


int16_t shift_count = 24;

void LC_TimInterrupt_Init()
{
	HAL_TIM_Base_Start_IT(&htim2);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	shift_count--;
	shift_count = (shift_count < 0) ? 24 : shift_count;
	Array_Data_process(shift_count);
	HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t *)RGB_Array_Send, (RESET_PULSE + WS2812_DATA_LEN2));
}
