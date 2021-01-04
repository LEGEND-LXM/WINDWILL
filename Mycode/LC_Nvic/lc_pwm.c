/**
  * 名称 ：lc_pwm.c
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 4, 2021 3:39:21 PM
  */
#include "main.h"
#include "tim.h"
#include "lc_pwm.h"

void LC_Pwm_Init(void)
{
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);

  HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_4);
}

