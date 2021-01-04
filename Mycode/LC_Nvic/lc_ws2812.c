/**
  * 名称 ：lc_ws2812.c
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 2, 2021 5:15:10 PM
  */
#include "main.h"
#include "tim.h"
#include "dma.h"

#include "lc_ws2812.h"
#include "lc_exit_nvic.h"

// 选择红蓝方
uint8_t Globle_State = 0;	// 0 代表红方； 1代表蓝方

// 红色数据
uint8_t red_value[3]  = {0x22, 0x00, 0x00};
// 蓝色数据
uint8_t blue_value[3] = {0x00, 0x00, 0x22};

// 保存红色边框数据数组（rgb_num 125）
uint16_t RGB_Blade_Red_buffur[RESET_PULSE + WS2812_DATA_LEN1] = { 0 };

// 保存蓝色边框数据数组（rgb_num 125）
uint16_t RGB_Blade_Blue_buffur[RESET_PULSE + WS2812_DATA_LEN1] = { 0 };

// 保存复位数据数组（rgb_num 125）
uint16_t RGB_Rst_buffur[RESET_PULSE + WS2812_DATA_LEN1] = { 0 };

// 保存中间灯条的数据（静态数据）
uint16_t RGB_Array1[Middle_RGB_ARRAY_SIZE] = {0};
uint16_t RGB_Array2[Middle_RGB_ARRAY_SIZE] = {0};
uint16_t RGB_Array3[Middle_RGB_ARRAY_SIZE] = {0};

// 保存即将需要发送的中间数组的数据(red)（上述三个的组合 25+25+25 ）
uint16_t RGB_Middle_Red_buffur[RESET_PULSE + WS2812_DATA_LEN2] = {0};

// 保存即将需要发送的中间数组的数据(blue)（上述三个的组合 25+25+25 ）
uint16_t RGB_Middle_Blue_buffur[RESET_PULSE + WS2812_DATA_LEN2] = {0};

// WS2812 初始化
void LC_Ws2812_Init(void)
{
	// 初始化边框数据（red&blue）
	array_set_init();
	// 初始化复位清零数据（rst）
	array_set_rst();
	// 初始化中间灯条数据
	Middle_Array_Init();

}

/**
   *   将颜色数据转换为占空比数据保存进数组中
 *
 * */
void ws2812_set_RGB_data_Init(uint8_t R, uint8_t G, uint8_t B, uint16_t num, uint8_t state)
{
    //指针偏移:需要跳过复位信号的N个0
	uint16_t* p;
	if( state == 0 )
		p = (RGB_Blade_Red_buffur  + RESET_PULSE) + (num * LED_DATA_LEN);
	else
		p = (RGB_Blade_Blue_buffur + RESET_PULSE) + (num * LED_DATA_LEN);

	for (uint16_t i = 0;i < 8;i++)
	{
		//填充数组
		p[i]      = (G << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 8]  = (R << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 16] = (B << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
	}
}

/**
 * 	将复位数据转换为占空比数据保存进数组中
 *
 * */
void ws2812_set_RGB_rst_Init(uint8_t R, uint8_t G, uint8_t B, uint16_t num)
{
    //指针偏移:需要跳过复位信号的N个0
	uint16_t* p = (RGB_Rst_buffur + RESET_PULSE) + (num * LED_DATA_LEN);

	for (uint16_t i = 0;i < 8;i++)
	{
		//填充数组
		p[i]      = (G << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 8]  = (R << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 16] = (B << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
	}
}

/**
    *   给数组添加数据
    *  箭头数据
 *
 * */
void Middle_Array_Init(void)
{
	uint8_t i;
	uint8_t j;
	for( i = 0; i < 50 ; i++ )
	{
		j = i % 7;
		switch(j)
		{
		case 0:
			RGB_Array1[i] = 0;
			RGB_Array2[i] = 1;
			RGB_Array3[i] = 1;
			break;

		case 1:
			RGB_Array1[i] = 0;
			RGB_Array2[i] = 1;
			RGB_Array3[i] = 1;
			break;

		case 2:
			RGB_Array1[i] = 1;
			RGB_Array2[i] = 1;
			RGB_Array3[i] = 1;
			break;

		case 3:
			RGB_Array1[i] = 0;
			RGB_Array2[i] = 1;
			RGB_Array3[i] = 1;
			break;

		case 4:
			RGB_Array1[i] = 0;
			RGB_Array2[i] = 0;
			RGB_Array3[i] = 1;
			break;
		default:
			RGB_Array1[i] = 0;
			RGB_Array2[i] = 0;
			RGB_Array3[i] = 0;
			break;

		}
	}
}

/**
 * 	中间灯条数据组合
 *
 * */
void Middle_Data_combination(uint16_t count)
{
	uint8_t i;
	for( i = 0; i < Middle_RGB_SIZE ; i++ )		// 填充数据
	{
		if(RGB_Array1[i+/*+ 移位量*/count] == 1)
		{
			ws2812_Middle_Data_fill( Middle_RGB_1_5+i);
			ws2812_Middle_Data_fill( Middle_RGB_5_5+i);
		} else {
			ws2812_Middle_Data_fill( Middle_RGB_1_5+i);
			ws2812_Middle_Data_fill( Middle_RGB_5_5+i);
		}

		if(RGB_Array2[25-i-1+/*+ 移位量*/count] == 1)
		{
			ws2812_Middle_Data_fill( Middle_RGB_2_5+i);
			ws2812_Middle_Data_fill( Middle_RGB_4_5+i);
		} else {
			ws2812_Middle_Data_fill( Middle_RGB_2_5+i);
			ws2812_Middle_Data_fill( Middle_RGB_4_5+i);
		}

		if(RGB_Array3[i+/*+ 移位量*/count] == 1)
		{
			ws2812_Middle_Data_fill( Middle_RGB_3_5+i);
		} else {
			ws2812_Middle_Data_fill( Middle_RGB_3_5+i);
		}
	}
}

/**
 *	风车中间灯条数组填充
 *
 * */
void ws2812_Middle_Data_fill( uint16_t num )
{
	uint16_t* p ;
	uint8_t R ;
	uint8_t G ;
	uint8_t B ;

	if( Globle_State == 0 )
	{
		p = (RGB_Middle_Red_buffur  + RESET_PULSE) + (num * LED_DATA_LEN);
		R = red_value[0];
		G = red_value[1];
		B = red_value[2];
	} else {
		p = (RGB_Middle_Blue_buffur + RESET_PULSE) + (num * LED_DATA_LEN);
		R = blue_value[0];
		G = blue_value[1];
		B = blue_value[2];
	}

	for (uint16_t i = 0;i < 8;i++)
	{
		//填充数组
		p[i]      = (G << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 8]  = (R << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 16] = (B << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
	}

}

/**
 * 	发送边框数据
 * 	state ：选择阵容 （0 ：红方；1 ：蓝方）
 * */
void ws2812_frame_send(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t state)
{
	if( state == 0 )
		HAL_TIM_PWM_Start_DMA(htim, Channel,
				(uint32_t *)RGB_Blade_Red_buffur, (RESET_PULSE + WS2812_DATA_LEN1));
	else
		HAL_TIM_PWM_Start_DMA(htim, Channel,
				(uint32_t *)RGB_Blade_Blue_buffur, (RESET_PULSE + WS2812_DATA_LEN1));
}

/**
 * 	发送中间灯条边框数据
 * */
void ws2812_middle_send(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t state)
{
	if( state == 0 )
			HAL_TIM_PWM_Start_DMA(htim, Channel,
					(uint32_t *)RGB_Middle_Red_buffur, (RESET_PULSE + WS2812_DATA_LEN1));
		else
			HAL_TIM_PWM_Start_DMA(htim, Channel,
					(uint32_t *)RGB_Middle_Blue_buffur, (RESET_PULSE + WS2812_DATA_LEN1));
}

/**
 * 	发送复位信号
 * */
void ws2812_rst_send(TIM_HandleTypeDef *htim, uint32_t Channel)
{
	HAL_TIM_PWM_Start_DMA(htim, Channel,
					(uint32_t *)RGB_Rst_buffur, (RESET_PULSE + WS2812_DATA_LEN1));
}

/**
   *   添加大风车边框颜色数据
   *   红蓝 数据同时初始化
 *
 * */
void array_set_init(void)
{
	uint8_t i = 0;

	for( i = 0; i < LED_NUM1; i++)
	{
		ws2812_set_RGB_data_Init(red_value[0] , red_value[1] , red_value[2] , i, 0);
		ws2812_set_RGB_data_Init(blue_value[0], blue_value[1], blue_value[2], i, 1);
	}
}

/**
 * 	添加大风车清零数据
 * 	需要逐一发送
 *
 * */
void array_set_rst(void)
{
	uint8_t i = 0;

	for( i = 0; i < LED_NUM1; i++)
	{
		ws2812_set_RGB_rst_Init(0x00, 0x00, 0x00, i);
	}
}

/**
 * 	PWM DMA中断传输结束回调函数
 * */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	windwill_state = 1;
	if ((htim->Instance == htim1.Instance) && (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)) {
		HAL_TIM_PWM_Stop_DMA(&htim1,TIM_CHANNEL_1);

	} else if ((htim->Instance == htim1.Instance) && (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)) {
		HAL_TIM_PWM_Stop_DMA(&htim1,TIM_CHANNEL_2);

	} else if ((htim->Instance == htim1.Instance) && (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)) {
		HAL_TIM_PWM_Stop_DMA(&htim1,TIM_CHANNEL_3);

	} else if ((htim->Instance == htim8.Instance) && (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)) {
		HAL_TIM_PWM_Stop_DMA(&htim8,TIM_CHANNEL_2);

	} else if ((htim->Instance == htim8.Instance) && (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)) {
		HAL_TIM_PWM_Stop_DMA(&htim8,TIM_CHANNEL_3);
	} else if((htim->Instance == htim8.Instance) && (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)) {
		HAL_TIM_PWM_Stop_DMA(&htim8,TIM_CHANNEL_4);
		GPIO_State_Init();
	}

}

