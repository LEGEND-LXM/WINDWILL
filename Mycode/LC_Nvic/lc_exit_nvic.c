/**
  * 名称 ：lc_exit_nvic.c
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 2, 2021 5:14:33 PM
  */
#include "main.h"
#include "tim.h"
#include "lc_exit_nvic.h"
#include "lc_ws2812.h"

/**
 * 	继电器全关
 * */
void GPIO_State_Init(void)
{
	HAL_GPIO_WritePin(GPIOC, Windwill_Middle_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, Windwill_Middle_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, Windwill_Middle_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, Windwill_Middle_4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, Windwill_Middle_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, Windwill_Middle_None_Pin, GPIO_PIN_RESET);
}

/**
 * 	继电器全开
 * */
void GPIO_State_Open(void)
{
	HAL_GPIO_WritePin(GPIOC, Windwill_Middle_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, Windwill_Middle_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, Windwill_Middle_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, Windwill_Middle_4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, Windwill_Middle_5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, Windwill_Middle_None_Pin, GPIO_PIN_SET);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	switch(GPIO_Pin)
	{
		case windwill_1_Pin : // 第①块被击中
		{
			if( windwill_num == 1 )
			{
				windwill_num = 2;
				windwill_state = 1;
				ws2812_frame_send(&htim1, TIM_CHANNEL_1, Globle_State);
				//1. 中间灯条常亮
				GPIO_State_Init();
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_1_Pin, GPIO_PIN_SET);
				ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);	// 填充单色
			}
			else {
				windwill_num = 1;
				//2. 所有灯条初始化
				GPIO_State_Open();
				ws2812_rst_send(&htim8, TIM_CHANNEL_4);
			}

			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}
			break;

		case windwill_2_Pin : // 第②块被击中
		{
			if( windwill_num == 2 )
			{
					windwill_state = 1;
					windwill_num = 3;
					ws2812_frame_send(&htim1, TIM_CHANNEL_2, Globle_State);
					//1. 中间灯条常亮
					GPIO_State_Init();
					HAL_GPIO_WritePin(GPIOC, Windwill_Middle_2_Pin, GPIO_PIN_SET);
					ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);	// 填充单色
					HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			}
			else {
				windwill_num = 1;
				//2. 所有灯条初始化
				GPIO_State_Open();
				ws2812_rst_send(&htim8, TIM_CHANNEL_4);
			}


		}
			break;

		case windwill_3_Pin : // 第③块被击中
		{
			if( windwill_num == 3 )
			{
					windwill_state = 1;
					windwill_num = 4;
					ws2812_frame_send(&htim1, TIM_CHANNEL_3, Globle_State);
					//1. 中间灯条常亮
					GPIO_State_Init();
					HAL_GPIO_WritePin(GPIOC, Windwill_Middle_3_Pin, GPIO_PIN_SET);
					ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);	// 填充单色
			}
			else {
				windwill_num = 1;
				//2. 所有灯条初始化
				GPIO_State_Open();
				ws2812_rst_send(&htim8, TIM_CHANNEL_4);
			}

			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}
			break;

		case windwill_4_Pin : // 第④块被击中
		{
			if( windwill_num == 4 )
			{
					windwill_state = 1;
					windwill_num = 5;
					ws2812_frame_send(&htim8, TIM_CHANNEL_2, Globle_State);
					//1. 中间灯条常亮
					GPIO_State_Init();
					HAL_GPIO_WritePin(GPIOC, Windwill_Middle_4_Pin, GPIO_PIN_SET);
					ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);	// 填充单色
			}
			else {
				windwill_num = 1;
				//2. 所有灯条初始化
				GPIO_State_Open();
				ws2812_rst_send(&htim8, TIM_CHANNEL_4);
			}

			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}
			break;

		case windwill_5_Pin : // 第⑤块被击中
		{
			if( windwill_num == 5 )
			{
					windwill_state = 1;
					ws2812_frame_send(&htim8, TIM_CHANNEL_3, Globle_State);
					windwill_strike_completed = 1;
					//1. 中间灯条常亮
					GPIO_State_Init();
					HAL_GPIO_WritePin(GPIOC, Windwill_Middle_5_Pin, GPIO_PIN_SET);
					ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);	// 填充单色
			}
			else {
				windwill_num = 1;
				//2. 所有灯条初始化
				GPIO_State_Open();
				ws2812_rst_send(&htim8, TIM_CHANNEL_4);
			}

			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}
			break;
	}


}

