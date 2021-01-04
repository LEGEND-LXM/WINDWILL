/**
  * 名称 ：lc_exit_nvic.c
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 2, 2021 5:14:33 PM
  */
#include "main.h"
#include "tim.h"
#include "lc_exit_nvic.h"
#include "lc_ws2812.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	switch(GPIO_Pin)
	{
		case windwill_1_Pin : // 第①块被击中
		{

			// 1.判断是否为需要打击的扇叶
			// 2.对应扇叶灯条亮
			// 3.中间灯条常亮
//			HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t *)RGB_Array_Send, (RESET_PULSE + WS2812_DATA_LEN2));
//			ws2812_example1(&htim1, TIM_CHANNEL_1);
			HAL_TIM_Base_Start_IT(&htim2);
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}
			break;

		case windwill_2_Pin : // 第②块被击中
		{
//			if( windwill_num == 2 && windwill_state != 1 )
//			{
//				ws2812_example1(&htim1, TIM_CHANNEL_2);
//			}
			HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t *)RGB_buffur2, (RESET_PULSE + WS2812_DATA_LEN1));
			ws2812_example1(&htim1, TIM_CHANNEL_2);
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}
			break;

		case windwill_3_Pin : // 第③块被击中
		{
//			if( windwill_num == 3 && windwill_state != 1 )
//			{
//
//			}
			ws2812_example1(&htim1, TIM_CHANNEL_3);
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}
			break;

		case windwill_4_Pin : // 第④块被击中
		{
//			if( windwill_num == 4 && windwill_state != 1 )
//			{
//
//			}
			ws2812_example1(&htim8, TIM_CHANNEL_2);
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}
			break;

		case windwill_5_Pin : // 第⑤块被击中
		{
//			if( windwill_num == 5 && windwill_state != 1 )
//			{
//
//			}
			ws2812_example1(&htim8, TIM_CHANNEL_3);
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}
			break;


	}


}

