/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "main.h"
#include "graphics.h"
#include "gyro_mpu6050.h"

I2C_HandleTypeDef hi2c1;



void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
void WriteImage(const unsigned int r[16], const unsigned int g[16], const unsigned int b[16]);
void usdelay(unsigned int delay);
void msdelay(unsigned int delay);

uint16_t us_ticks;
const unsigned int N = 9;

mpudata_t mpu_data;
mpu6050_cfg mpu_cfg = { .accel_range = MPU6050_RANGE_2_G, .bandwidth = MPU6050_BAND_260_HZ,
			.cycle_rate = MPU6050_CYCLE_5_HZ, .gyro_range = MPU6050_RANGE_500_DEG,
			.clock_select = MPU6050_INTR_8MHz
};

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_I2C1_Init();
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;


  // Timer is running at ~500kHz
  TIM3->PSC = 0;
  TIM3->ARR = 168;
  TIM3->CR1 |= TIM_CR1_URS;
  TIM3->DIER |= TIM_DIER_UIE;
  TIM3->EGR |= TIM_EGR_UG;
  NVIC_EnableIRQ(TIM3_IRQn);
  NVIC_SetPriority(TIM3_IRQn, 3);
  int alt = 0;
  int cleared = 0;
  int turning = 0;
  int ccount = 0;



  reset_mpu6050(&hi2c1);
  init_mpu6050(&hi2c1, &mpu_cfg);

  while (1) {
//	  HAL_StatusTypeDef status = read_mpu6050(&hi2c1, &mpu_data, &mpu_cfg);
//	  if (HAL_OK != status) {
//		  reset_mpu6050(&hi2c1);
//		  HAL_Delay(500);
//		  status = init_mpu6050(&hi2c1, &mpu_cfg);
//		  if (HAL_OK != status) {
//			  HAL_Delay(500);
//		  }
//	  } else {

	  // Assume when cleared, that within 5 loops the input pins will then be 0

	  if(HAL_GPIO_ReadPin(LEFT_A0_GPIO_Port, LEFT_A0_Pin) == GPIO_PIN_SET && cleared == 0) {
		  if(HAL_GPIO_ReadPin(BRAKE_A2_GPIO_Port, BRAKE_A2_Pin) == GPIO_PIN_SET)
			  if(alt >= 0 && alt < 50)
				  WriteImage(R_L_ARR1_BOX, G_BOX, B_BOX);
			  else {
				  WriteImage(R_L_ARR2_BOX, G_BOX, B_BOX);
				  if(alt > 100)
					  alt = 0;
			  }
		  else {
			  if(alt >= 0 && alt < 50)
				  WriteImage(R_L_ARR1, BLANK, BLANK);
			  else {
				  WriteImage(R_L_ARR2, BLANK, BLANK);
				  if(alt > 100)
					  alt = 0;
			  }
		  }

		  read_mpu6050(&hi2c1, &mpu_data, &mpu_cfg);

		  if(mpu_data.gyroZ < -150 && !turning) {
			  turning = 1;
		  }
		  else if(mpu_data.gyroZ > -100 && turning) {
			  turning = 0;
			  cleared = 1;
			  HAL_GPIO_WritePin(CLEAR_GPIO_Port, CLEAR_Pin, GPIO_PIN_SET);
		  }
	  }
	  else if(HAL_GPIO_ReadPin(RIGHT_A1_GPIO_Port, RIGHT_A1_Pin) == GPIO_PIN_SET && cleared == 0) {
		  if(HAL_GPIO_ReadPin(BRAKE_A2_GPIO_Port, BRAKE_A2_Pin) == GPIO_PIN_SET)
			  if(alt >= 0 && alt < 50)
				  WriteImage(R_R_ARR1_BOX, G_BOX, B_BOX);
			  else {
				  WriteImage(R_R_ARR2_BOX, G_BOX, B_BOX);
				  if(alt > 100)
					  alt = 0;
			  }
		  else {
			  if(alt >= 0 && alt < 50)
				  WriteImage(R_R_ARR1, BLANK, BLANK);
			  else {
				  WriteImage(R_R_ARR2, BLANK, BLANK);
				  if(alt > 100)
					  alt = 0;
			  }
		  }

		  read_mpu6050(&hi2c1, &mpu_data, &mpu_cfg);

		  if(mpu_data.gyroZ > 150 && !turning) {
			  turning = 1;
		  }
		  else if(mpu_data.gyroZ < 100 && turning) {
			  turning = 0;
			  cleared = 1;
			  HAL_GPIO_WritePin(CLEAR_GPIO_Port, CLEAR_Pin, GPIO_PIN_SET);
		  }
	  }
	  else if(HAL_GPIO_ReadPin(BRAKE_A2_GPIO_Port, BRAKE_A2_Pin) == GPIO_PIN_SET) {
		  WriteImage(R_BOX, G_BOX, B_BOX);
		  if(cleared)
			  ccount++;
	  }
	  else {
		  WriteImage(R_SMILE, G_SMILE, B_SMILE);
		  if(cleared)
			  ccount++;
	  }
	  if(ccount > 5) {
		  cleared = 0;
		  ccount = 0;
		  HAL_GPIO_WritePin(CLEAR_GPIO_Port, CLEAR_Pin, GPIO_PIN_RESET);
	  }
	  usdelay(1500);
	  alt++;

  }

}



// each tick of delay is about 2us
void usdelay(unsigned int delay) {
	TIM3->CR1 |= TIM_CR1_CEN;
	us_ticks = 0;
	while(us_ticks < delay)
		;
	TIM3->CR1 &= ~TIM_CR1_CEN;

}

void msdelay(unsigned int delay) {
	usdelay(delay*500);
}

void TIM3_IRQHandler(void) {
	TIM3->SR &= ~TIM_SR_UIF;
	us_ticks++;
}

static inline GPIO_PinState CheckBit(unsigned int val, int j) {
	return (GPIO_PinState) ((val & (1 << j)) >> j);
}

/*
 * Writes an image on the matrix. Expects 3 arrays with each bit representing an LED
 * Currently not using PWM which would allow the full color spectrum.
 */
void WriteImage(const unsigned int r[16], const unsigned int g[16], const unsigned int b[16]) {
	const GPIO_PinState s = GPIO_PIN_SET;
	const GPIO_PinState res = GPIO_PIN_RESET;

	for (int i = 0; i < 8; i++) {
		HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, res);
		// Set all RGB values
		for (int j = 0; j < 32; j++) {

			HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, res);
			usdelay(N);
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, CheckBit(r[i], j));
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, CheckBit(g[i], j));
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, CheckBit(b[i], j));
			HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, CheckBit(r[i+8], j));
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, CheckBit(g[i+8], j));
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, CheckBit(b[i+8], j));
			usdelay(N);
			HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, s);
			usdelay(N);
		}
		// assert blank
		HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, s);
		// set address
		HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, (GPIO_PinState) (i & 0x4));
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, (GPIO_PinState) (i & 0x2));
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, (GPIO_PinState) (i & 0x1));
		// latch
		HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, s);
		HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, res);
		// wait N time
		usdelay(N*5);
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, sCLK_Pin|B2_Pin|R2_Pin|B_Pin
                          |A_Pin|R1_Pin|G1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, OE_Pin|LAT_Pin|CLEAR_Pin|B1_Pin
                          |G2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : sCLK_Pin B2_Pin R2_Pin B_Pin
                           A_Pin R1_Pin G1_Pin */
  GPIO_InitStruct.Pin = sCLK_Pin|B2_Pin|R2_Pin|B_Pin
                          |A_Pin|R1_Pin|G1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LEFT_A0_Pin RIGHT_A1_Pin BRAKE_A2_Pin */
  GPIO_InitStruct.Pin = LEFT_A0_Pin|RIGHT_A1_Pin|BRAKE_A2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : C_Pin */
  GPIO_InitStruct.Pin = C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(C_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : OE_Pin LAT_Pin CLEAR_Pin B1_Pin
                           G2_Pin */
  GPIO_InitStruct.Pin = OE_Pin|LAT_Pin|CLEAR_Pin|B1_Pin
                          |G2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
