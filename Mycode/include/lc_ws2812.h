/**
  * 名称 ：lc_ws2812.h
  * 创建人 ：-LEGEND
  * 创建日期 ：Jan 2, 2021 5:14:59 PM
  */
#ifndef INCLUDE_LC_WS2812_H_
#define INCLUDE_LC_WS2812_H_

#include "main.h"


#define ONE_PULSE         (70-1)                           	//1 码计数个数
#define ZERO_PULSE        (35-1)                           	//0 码计数个数
#define RESET_PULSE       (40)                           	//80 复位电平个数（不能低于40）
#define LED_NUM1          (125)                            	//led 个数
#define LED_NUM2          (125)                            	//led 个数
#define LED_DATA_LEN      (24)                           	//led 长度，单个需要24个字节
#define WS2812_DATA_LEN1  (LED_NUM1*LED_DATA_LEN)        	//ws2812灯条需要的数组长度
#define WS2812_DATA_LEN2  (LED_NUM2*LED_DATA_LEN)        	//ws2812灯条需要的数组长度

#define Middle_RGB_SIZE						25				// 中间灯条灯珠数量
#define Middle_RGB_ARRAY_SIZE				50				// 中间灯条数组长度
#define Middle_RGB_1_5						0
#define Middle_RGB_2_5						Middle_RGB_SIZE*1
#define Middle_RGB_3_5						Middle_RGB_SIZE*2
#define Middle_RGB_4_5						Middle_RGB_SIZE*3
#define Middle_RGB_5_5						Middle_RGB_SIZE*4


// 选择红蓝方
extern uint8_t Globle_State ;	// 0 代表红方； 1代表蓝方
// 红色数据
extern uint8_t red_value[3] ;
// 蓝色数据
// 空白数据（全为0）
extern uint8_t rst_value[3] ;
extern uint8_t blue_value[3] ;
// 保存红色边框数据数组（rgb_num 125）
extern uint16_t RGB_Blade_Red_buffur[RESET_PULSE + WS2812_DATA_LEN1] ;
// 保存蓝色边框数据数组（rgb_num 125）
extern uint16_t RGB_Blade_Blue_buffur[RESET_PULSE + WS2812_DATA_LEN1] ;
// 保存复位数据数组（rgb_num 125）
extern uint16_t RGB_Rst_buffur[RESET_PULSE + WS2812_DATA_LEN1] ;
// 保存中间灯条的数据（静态数据）
extern uint16_t RGB_Array1[Middle_RGB_ARRAY_SIZE] ;
extern uint16_t RGB_Array2[Middle_RGB_ARRAY_SIZE] ;
extern uint16_t RGB_Array3[Middle_RGB_ARRAY_SIZE] ;
// 保存即将需要发送的中间数组的数据(red)（上述三个的组合 25+25+25 ）
extern uint16_t RGB_Middle_Red_buffur[RESET_PULSE + WS2812_DATA_LEN2] ;
// 保存即将需要发送的中间数组的数据(blue)（上述三个的组合 25+25+25 ）
extern uint16_t RGB_Middle_Blue_buffur[RESET_PULSE + WS2812_DATA_LEN2] ;



// WS2812 初始化
void LC_Ws2812_Init(void);

// 将颜色数据转换为占空比数据保存进数组中
void ws2812_set_RGB_data_Init(uint8_t R, uint8_t G, uint8_t B, uint16_t num, uint8_t state);

// 将复位数据转换为占空比数据保存进数组中
void ws2812_set_RGB_rst_Init(uint8_t R, uint8_t G, uint8_t B, uint16_t num);

//  给数组添加数据
void Middle_Array_Init(void);

// 初始化灯条
void ws2812_lamp_strip_Init(void);

// 中间灯条数据组合
void Middle_Data_combination(uint16_t count);

// 风车中间灯条数组填充
void ws2812_Middle_Data_fill( uint16_t num , uint8_t state);

// state ：选择阵容 （0 ：红方；1 ：蓝方）
void ws2812_frame_send(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t state);

// 发送中间灯条边框数据
void ws2812_middle_send(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t state);

// 发送复位信号
void ws2812_rst_send(TIM_HandleTypeDef *htim, uint32_t Channel);

// 添加大风车边框颜色数据
// 红蓝 数据同时初始化
void array_set_init(void);

// 添加大风车清零数据
void array_set_rst(void);

// PWM DMA中断传输结束回调函数
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);

// 打击完成后的响应函数
void ws2812_Mission_Accomplished(void);

#endif /* INCLUDE_LC_WS2812_H_ */
