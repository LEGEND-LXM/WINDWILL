/**
  * 名称 ：lc_ws2812.c
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 2, 2021 5:15:10 PM
  */
#include "main.h"
#include "lc_ws2812.h"
#include "tim.h"
#include "dma.h"

uint16_t RGB_buffur1[RESET_PULSE + WS2812_DATA_LEN1] = { 0 };
uint16_t RGB_buffur2[RESET_PULSE + WS2812_DATA_LEN1] = { 0 };

uint16_t RGB_Array1[Middle_RGB_ARRAY_SIZE] = {0};
uint16_t RGB_Array2[Middle_RGB_ARRAY_SIZE] = {0};
uint16_t RGB_Array3[Middle_RGB_ARRAY_SIZE] = {0};


uint16_t RGB_Array_Send[RESET_PULSE + WS2812_DATA_LEN2] = {0};



void ws2812_set_RGB1(uint8_t R, uint8_t G, uint8_t B, uint16_t num)
{
    //指针偏移:需要跳过复位信号的N个0
    uint16_t* p = (RGB_buffur1 + RESET_PULSE) + (num * LED_DATA_LEN);

	for (uint16_t i = 0;i < 8;i++)
	{
		//填充数组
		p[i]      = (G << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 8]  = (R << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 16] = (B << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
	}
}

void ws2812_set_RGB2(uint8_t R, uint8_t G, uint8_t B, uint16_t num)
{
    //指针偏移:需要跳过复位信号的N个0
	uint16_t* p = (RGB_buffur2 + RESET_PULSE) + (num * LED_DATA_LEN);

	for (uint16_t i = 0;i < 8;i++)
	{
		//填充数组
		p[i]      = (G << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 8]  = (R << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 16] = (B << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
	}
}

void ws2812_set_RGB3(uint8_t R, uint8_t G, uint8_t B, uint16_t num)
{
	uint16_t* p = (RGB_Array_Send + RESET_PULSE) + (num * LED_DATA_LEN);

	for (uint16_t i = 0;i < 8;i++)
	{
		//填充数组
		p[i]      = (G << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 8]  = (R << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
		p[i + 16] = (B << i) & (0x80)?ONE_PULSE:ZERO_PULSE;
	}

}

void Array_Data_process(uint16_t count)
{
	uint8_t i;
	for( i = 0; i < 25 ; i++ )
	{
		if(RGB_Array1[i+/*+ 移位量*/count] == 1)
		{
			ws2812_set_RGB3(0x22, 0x00, 0x00, i);
			ws2812_set_RGB3(0x22, 0x00, 0x00, 100+i);
		} else {
			ws2812_set_RGB3(0x00, 0x00, 0x00, i);
			ws2812_set_RGB3(0x00, 0x00, 0x00, 100+i);
		}

		if(RGB_Array2[25-i-1+/*+ 移位量*/count] == 1)
		{
			ws2812_set_RGB3(0x22, 0x00, 0x00, 25+i);
			ws2812_set_RGB3(0x22, 0x00, 0x00, 75+i);
		} else {
			ws2812_set_RGB3(0x00, 0x00, 0x00, 25+i);
			ws2812_set_RGB3(0x00, 0x00, 0x00, 75+i);
		}

		if(RGB_Array3[i+/*+ 移位量*/count] == 1)
		{
			ws2812_set_RGB3(0x22, 0x00, 0x00, 50+i);
		} else {
			ws2812_set_RGB3(0x00, 0x00, 0x00, 50+i);
		}
	}
}



void ws2812_example1(TIM_HandleTypeDef *htim, uint32_t Channel)
{
    HAL_TIM_PWM_Start_DMA(htim, Channel, (uint32_t *)RGB_buffur1, (RESET_PULSE + WS2812_DATA_LEN1));

}

/**
   * 给数组添加数据
   * 红色数据
 * */
void array_set_red(void)
{
	uint8_t i = 0;

	for( i = 0; i < LED_NUM1; i++)
	{
		ws2812_set_RGB1(0x22, 0x00, 0x00, i);
	}
}

/**
   *给数组添加数据
 * 	清零数据
 * */
void array_set_rst(void)
{
	uint8_t i = 0;

	for( i = 0; i < LED_NUM1; i++)
	{
		ws2812_set_RGB2(0x00, 0x00, 0x00, i);
	}
}

/**
 *   给数组添加数据
 *  箭头数据
 * */
void array_set_data1(void)
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

	}
}

