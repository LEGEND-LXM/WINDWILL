/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern uint8_t windwill_num ; 				// 待打击装甲板编号
extern uint8_t windwill_state ;				// 打击状�?�判定（0为待打击�??1为打击完毕）
extern uint8_t windwill_strike_completed ;	// 打击完成标志
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define windwill_4_Pin GPIO_PIN_4
#define windwill_4_GPIO_Port GPIOE
#define windwill_4_EXTI_IRQn EXTI4_IRQn
#define windwill_3_Pin GPIO_PIN_5
#define windwill_3_GPIO_Port GPIOE
#define windwill_3_EXTI_IRQn EXTI9_5_IRQn
#define windwill_5_Pin GPIO_PIN_6
#define windwill_5_GPIO_Port GPIOE
#define windwill_5_EXTI_IRQn EXTI9_5_IRQn
#define windwill_output_5_Pin GPIO_PIN_7
#define windwill_output_5_GPIO_Port GPIOI
#define windwill_output_4_Pin GPIO_PIN_6
#define windwill_output_4_GPIO_Port GPIOI
#define windwill_2_Pin GPIO_PIN_0
#define windwill_2_GPIO_Port GPIOF
#define windwill_2_EXTI_IRQn EXTI0_IRQn
#define windwill_output_2_Pin GPIO_PIN_9
#define windwill_output_2_GPIO_Port GPIOA
#define windwill_output_1_Pin GPIO_PIN_8
#define windwill_output_1_GPIO_Port GPIOA
#define windwill_1_Pin GPIO_PIN_1
#define windwill_1_GPIO_Port GPIOF
#define windwill_1_EXTI_IRQn EXTI1_IRQn
#define Windwill_Middle_2_Pin GPIO_PIN_0
#define Windwill_Middle_2_GPIO_Port GPIOC
#define Windwill_Middle_4_Pin GPIO_PIN_1
#define Windwill_Middle_4_GPIO_Port GPIOC
#define Lineup_Switch_Pin GPIO_PIN_2
#define Lineup_Switch_GPIO_Port GPIOB
#define Lineup_Switch_EXTI_IRQn EXTI2_IRQn
#define Windwill_Middle_None_Pin GPIO_PIN_4
#define Windwill_Middle_None_GPIO_Port GPIOA
#define Windwill_Middle_1_Pin GPIO_PIN_4
#define Windwill_Middle_1_GPIO_Port GPIOC
#define windwill_output_3_Pin GPIO_PIN_13
#define windwill_output_3_GPIO_Port GPIOE
#define Windwill_Middle_5_Pin GPIO_PIN_5
#define Windwill_Middle_5_GPIO_Port GPIOA
#define Windwill_Middle_3_Pin GPIO_PIN_5
#define Windwill_Middle_3_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_11
#define LED1_GPIO_Port GPIOE
#define LED2_Pin GPIO_PIN_14
#define LED2_GPIO_Port GPIOF
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
