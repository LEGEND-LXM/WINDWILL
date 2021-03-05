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

/**
 * 	继电器单开函数
 * */
void GPIO_Single_line(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if( GPIOx ==  GPIOC )
	{
		switch( GPIO_Pin )
		{
			case Windwill_Middle_1_Pin :
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_4_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, Windwill_Middle_5_Pin, GPIO_PIN_RESET);
				break;

			case Windwill_Middle_2_Pin :
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_4_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, Windwill_Middle_5_Pin, GPIO_PIN_RESET);
				break;

			case Windwill_Middle_3_Pin :
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_3_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_4_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, Windwill_Middle_5_Pin, GPIO_PIN_RESET);
				break;

			case Windwill_Middle_4_Pin :
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOC, Windwill_Middle_4_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, Windwill_Middle_5_Pin, GPIO_PIN_RESET);
				break;
		}
	}
	if( GPIOx ==  GPIOA && GPIO_Pin == Windwill_Middle_5_Pin )
	{
		HAL_GPIO_WritePin(GPIOC, Windwill_Middle_1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, Windwill_Middle_2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, Windwill_Middle_3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, Windwill_Middle_4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, Windwill_Middle_5_Pin, GPIO_PIN_SET);
	}

}

/**
 * 	外部中断回调函数
 * 	GPIO_Pin ：中断线
 * */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	switch(GPIO_Pin)
	{
		case windwill_1_Pin : // 第①块被击中
		{
			if( windwill_num == 1 )
			{

				windwill_state = 1;
				ws2812_frame_send(&htim1, TIM_CHANNEL_1, Globle_State);		// 填充边框灯条
//				ws2812_rst_send( &htim8, TIM_CHANNEL_4);//***
				ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);		// 填充中间灯条
//				ws2812_Wait_Hit_frame_send(&htim1, TIM_CHANNEL_2, Globle_State);	// 下一片扇叶进入带打击状态
				windwill_num = 2;
				HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			}

		}
			break;

		case windwill_2_Pin : // 第②块被击中
		{
			if( windwill_num == 2 )
			{

				windwill_state = 1;
				ws2812_frame_send(&htim1, TIM_CHANNEL_2, Globle_State);		// 填充边框灯条
//				ws2812_rst_send( &htim8, TIM_CHANNEL_4);//***
				ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);		// 填充中间灯条
//				ws2812_Wait_Hit_frame_send(&htim1, TIM_CHANNEL_3, Globle_State);	// 下一片扇叶进入带打击状态
				windwill_num = 3;
				HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			}


		}
			break;

		case windwill_3_Pin : // 第③块被击中
		{
			if( windwill_num == 3 )
			{

				windwill_state = 1;
				ws2812_frame_send(&htim1, TIM_CHANNEL_3, Globle_State);		// 填充边框灯条
//				ws2812_rst_send( &htim8, TIM_CHANNEL_4);//***
				ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);		// 填充中间灯条
				windwill_num = 4;
				HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			}

		}
			break;

		case windwill_4_Pin : // 第④块被击中
		{
			if( windwill_num == 4 )
			{

				windwill_state = 1;
				ws2812_frame_send(&htim8, TIM_CHANNEL_2, Globle_State);		// 填充边框灯条
				ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);		// 填充中间灯条
//				ws2812_Wait_Hit_frame_send(&htim8, TIM_CHANNEL_3, Globle_State);	// 下一片扇叶进入带打击状态
				windwill_num = 5;
				HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			}

		}
			break;

		case windwill_5_Pin : // 第⑤块被击中
		{
			if( windwill_num == 5 )
			{

				windwill_state = 1;
				ws2812_frame_send(&htim8, TIM_CHANNEL_3, Globle_State);		// 填充边框灯条
//				ws2812_rst_send( &htim8, TIM_CHANNEL_4);//**
				ws2812_frame_send(&htim8, TIM_CHANNEL_4, Globle_State);		// 填充中间灯条
				windwill_strike_completed = 1;
				windwill_num = 1;
				HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			}
		}
			break;

		case Lineup_Switch_Pin:

			windwill_state = 0;				// 初始化打击状�?
			Globle_State = !Globle_State;
			ws2812_lamp_strip_Init();			// 初始化灯�?
			GPIO_State_Init();
			windwill_strike_completed = 0;	// 清除打击完成标志�?
			windwill_num = 1;					// 装甲板标号归0
			break;
	}


}

