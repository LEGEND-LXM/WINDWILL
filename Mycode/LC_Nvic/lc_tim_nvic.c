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

	if( windwill_strike_completed == 0 )
	{
		shift_count--;
		shift_count = (shift_count < 0) ? 24 : shift_count;
		switch( windwill_num )
		{
			case 1:		// 扇叶6中间流水
				Middle_Data_combination(shift_count);	// 组合数据
				//1.发送组合数据 -> 发送
				// 1.1 接通继电器
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_1_Pin, GPIO_PIN_SET);
				// 1.2 启用PWM发送
				ws2812_middle_send(&htim8, TIM_CHANNEL_4, Globle_State);
				break;

			case 2:		// 扇叶5中间流水
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_2_Pin, GPIO_PIN_SET);
				// 1.2 启用PWM发送
				ws2812_middle_send(&htim8, TIM_CHANNEL_4, Globle_State);
				break;

			case 3:		// 扇叶4中间流水
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_3_Pin, GPIO_PIN_SET);
				// 1.2 启用PWM发送
				ws2812_middle_send(&htim8, TIM_CHANNEL_4, Globle_State);
				break;

			case 4:		// 扇叶3中间流水
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_4_Pin, GPIO_PIN_SET);
				// 1.2 启用PWM发送
				ws2812_middle_send(&htim8, TIM_CHANNEL_4, Globle_State);
				break;

			case 5:		// 扇叶2中间流水
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_5_Pin, GPIO_PIN_SET);
				// 1.2 启用PWM发送
				ws2812_middle_send(&htim8, TIM_CHANNEL_4, Globle_State);
				windwill_strike_completed = 1;
				break;
		}
	} else {
		// 完成打击
		// 中间灯条闪烁（5s后重置）
		// 1.接通所有继电器
		GPIO_State_Open();
		// 2.交替发送复位、全亮信号
		if( shift_count%2 == 0 )
			ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);	// 填充单色
		else
			ws2812_rst_send(&htim8, TIM_CHANNEL_4);
	}
}
