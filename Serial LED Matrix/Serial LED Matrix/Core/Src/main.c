/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Serial LED Matrix
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

//LED matrix display, each bit represents an LED on or off for the row 
uint8_t disp1ay[4][8]={
{0x18,0xC,0x6,0x3,0x3,0x6,0xC,0x18},			//right arrow >
{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0}, 				//off
{0x18,0x30,0x60,0xC0,0xC0,0x60,0x30,0x18},//left arrow <
{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},				//off
};

void write_byte(uint8_t byte)
{			
		for(int i=0;i<8;i++)
		{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);  // Pull the CLK LOW
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, byte&0x80);// Write one BIT data MSB first
			byte = byte<<1;  // shift the data to the left
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);  // Pull the CLK HIGH		
		 }			
}

void write_matrix (uint8_t address, uint8_t data)
{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);   // Pull the CS pin LOW
    write_byte(address);  										 //  write address
    write_byte(data);												  //  write data
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);  // pull the CS HIGH
}

void matrix_init(void)
{
		write_matrix(0x09, 0x00);       //  no decoding
		write_matrix(0x0a, 0x03);       //  brightness intensity
		write_matrix(0x0b, 0x07);       //  scan limit = 8 LEDs
		write_matrix(0x0c, 0x01);       //  power down =0,normal mode = 1
		write_matrix(0x0f, 0x00);       //  no test display
}

void display_right(void)
{
	for (int j=2; j<4; j++)
		{			
			write_matrix (1 , disp1ay[j][0]);
			HAL_Delay (20);
			write_matrix (8 , disp1ay[j][7]);			
			HAL_Delay (20);
			write_matrix (2 , disp1ay[j][1]);
			HAL_Delay (20);
			write_matrix (7 , disp1ay[j][6]);
			HAL_Delay (20);
			write_matrix (3 , disp1ay[j][2]);
			HAL_Delay (20);
			write_matrix (6 , disp1ay[j][5]);
			HAL_Delay (20);
			write_matrix (4 , disp1ay[j][3]);
			HAL_Delay (20);
			write_matrix (5 , disp1ay[j][4]);
			HAL_Delay (520);
		}
}

void display_left(void)
{		
		for (int j=0; j<2; j++)
		{			
			write_matrix (1 , disp1ay[j][0]);
			HAL_Delay (20);
			write_matrix (8 , disp1ay[j][7]);			
			HAL_Delay (20);
			write_matrix (2 , disp1ay[j][1]);
			HAL_Delay (20);
			write_matrix (7 , disp1ay[j][6]);
			HAL_Delay (20);
			write_matrix (3 , disp1ay[j][2]);
			HAL_Delay (20);
			write_matrix (6 , disp1ay[j][5]);
			HAL_Delay (20);
			write_matrix (4 , disp1ay[j][3]);
			HAL_Delay (20);
			write_matrix (5 , disp1ay[j][4]);
			HAL_Delay (520);
		}
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
	matrix_init ();
  while (1)
  {		
		display_left();
		display_right();
  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, CS_Pin|CLK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(data_GPIO_Port, data_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : CS_Pin CLK_Pin */
  GPIO_InitStruct.Pin = CS_Pin|CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : data_Pin */
  GPIO_InitStruct.Pin = data_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(data_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
