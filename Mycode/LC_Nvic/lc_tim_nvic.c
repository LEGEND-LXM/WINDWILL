/**
  * 名称 ：lc_tim_nvic.c
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 4, 2021 9:25:27 AM
  */
#include "main.h"
#include "lc_tim_nvic.h"
#include "tim.h"
#include "lc_ws2812.h"
#include "lc_exit_nvic.h"


int16_t shift_count = 24;

void LC_TimInterrupt_Init(void)
{
	HAL_TIM_Base_Start_IT(&htim2);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if( htim->Instance == htim2.Instance )
	{
		if( windwill_strike_completed == 0 )
		{
			shift_count--;
			shift_count = (shift_count < 0) ? 24 : shift_count;
			Middle_Data_combination(shift_count);	// 组合数据
//			ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);		// 填充中间灯条
			switch( windwill_num )
			{
				case 1:		// 扇叶1中间流水
					//1.发送组合数据 -> 发送
					// 1.1 接通继电器
//					GPIO_State_Init();
					GPIO_Single_line(GPIOC, Windwill_Middle_1_Pin);
					// 1.2 启用PWM发送
					ws2812_middle_send(&htim8, TIM_CHANNEL_4, Globle_State);
					break;

				case 2:		// 扇叶2中间流水
//					ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);		// 填充中间灯条
					GPIO_Single_line(GPIOC, Windwill_Middle_2_Pin);
					ws2812_middle_send(&htim8, TIM_CHANNEL_4, Globle_State);
					break;

				case 3:		// 扇叶3中间流水
					GPIO_Single_line(GPIOC, Windwill_Middle_3_Pin);
					ws2812_middle_send(&htim8, TIM_CHANNEL_4, Globle_State);
					break;

				case 4:		// 扇叶4中间流水
					GPIO_Single_line(GPIOC, Windwill_Middle_4_Pin);
					ws2812_middle_send(&htim8, TIM_CHANNEL_4, Globle_State);
					break;

				case 5:		// 扇叶5中间流水
					GPIO_Single_line(GPIOA, Windwill_Middle_5_Pin);
					ws2812_middle_send(&htim8, TIM_CHANNEL_4, Globle_State);
					break;
			}
		}
	}

}
