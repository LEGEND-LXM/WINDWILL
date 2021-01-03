/**
  * 名称 ：lc_ws2812.h
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 2, 2021 5:14:59 PM
  */
#ifndef INCLUDE_LC_WS2812_H_
#define INCLUDE_LC_WS2812_H_

#include "main.h"


#define ONE_PULSE        (70-1)                           //1 码计数个数
#define ZERO_PULSE       (35-1)                           //0 码计数个数
#define RESET_PULSE      (40)                           //80 复位电平个数（不能低于40）
#define LED_NUM1         (103)                            //led 个数
#define LED_NUM2         (25)                            //led 个数
#define LED_DATA_LEN     (24)                           //led 长度，单个需要24个字节
#define WS2812_DATA_LEN1  (LED_NUM1*LED_DATA_LEN)        //ws2812灯条需要的数组长度
#define WS2812_DATA_LEN2  (LED_NUM2*LED_DATA_LEN)        //ws2812灯条需要的数组长度

extern uint16_t RGB_buffur1[RESET_PULSE + WS2812_DATA_LEN1];
extern uint16_t RGB_buffur2[RESET_PULSE + WS2812_DATA_LEN1];

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
void ws2812_set_RGB1(uint8_t R, uint8_t G, uint8_t B, uint16_t num);
void ws2812_set_RGB2(uint8_t R, uint8_t G, uint8_t B, uint16_t num);
void ws2812_example1(TIM_HandleTypeDef *htim, uint32_t Channel);
void array_set_red(void);
void array_set_rst(void);

#endif /* INCLUDE_LC_WS2812_H_ */
