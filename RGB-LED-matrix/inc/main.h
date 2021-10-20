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

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define sCLK_Pin GPIO_PIN_1
#define sCLK_GPIO_Port GPIOC
#define B2_Pin GPIO_PIN_2
#define B2_GPIO_Port GPIOC
#define R2_Pin GPIO_PIN_3
#define R2_GPIO_Port GPIOC
#define PIN_C_Pin GPIO_PIN_7
#define PIN_C_GPIO_Port GPIOA
#define PIN_B_Pin GPIO_PIN_4
#define PIN_B_GPIO_Port GPIOC
#define PIN_A_Pin GPIO_PIN_5
#define PIN_A_GPIO_Port GPIOC
#define OE_Pin GPIO_PIN_10
#define OE_GPIO_Port GPIOB
#define LAT_Pin GPIO_PIN_11
#define LAT_GPIO_Port GPIOB
#define R1_Pin GPIO_PIN_6
#define R1_GPIO_Port GPIOC
#define G1_Pin GPIO_PIN_7
#define G1_GPIO_Port GPIOC
#define B1_Pin GPIO_PIN_8
#define B1_GPIO_Port GPIOB
#define G2_Pin GPIO_PIN_9
#define G2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
