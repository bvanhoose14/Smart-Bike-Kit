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
/* The main file for driving the LED matrix. The only things that a user should have to
 * manipulate from here are the LED colors (R1 G1 B1 R2 G2 B2), and row address (CBA).
 * The column written to is determined by the shift clock
 *
 */
#include "main.h"
#include <math.h>
#include "graphics.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void UpdateDisplay();
void WriteTopLeftPixel(GPIO_PinState s);
void WriteEvenPixels(GPIO_PinState s);
void WriteOddPixels(GPIO_PinState s);
void usdelay(unsigned int delay);
void msdelay(unsigned int delay);
void BlindMe();
void WriteImage(const unsigned int r[16], const unsigned int g[16], const unsigned int b[16]);
/* USER CODE END 0 */

uint16_t us_ticks;

//static int color_pins[6] = {R1_Pin, G1_Pin, B1_Pin, R2_Pin, G2_Pin, B2_Pin};
//static int color_ports[6] = {R1_GPIO_Port, G1_GPIO_Port, B1_GPIO_Port, R2_GPIO_Port, G2_GPIO_Port, B2_GPIO_Port};
const unsigned int N = 10;
/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{


  HAL_Init();
  SystemClock_Config();


  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;


  // Timer is running at ~500kHz
  TIM3->PSC = 0;
  TIM3->ARR = 168;
  TIM3->CR1 |= TIM_CR1_URS;
  TIM3->DIER |= TIM_DIER_UIE;
  TIM3->EGR |= TIM_EGR_UG;
  NVIC_EnableIRQ(TIM3_IRQn);
  NVIC_SetPriority(TIM3_IRQn, 1);
  int alt = 0;
  while (1)
  {
//	  BlindMe();
//	  WriteImage(R_BOX, G_BOX, B_BOX);
//	  msdelay(2);
//	  WriteImage(R_CIRCLE, G_CIRCLE, B_CIRCLE);
//	  msdelay(2);
//	  WriteImage(R_SMILE, G_SMILE, B_SMILE);
//	  msdelay(2);
//	  HAL_Delay(5);
//	  WriteTopLeftPixel(GPIO_PIN_SET);
//	  msdelay(10);
	  if (alt >= 0 && alt < 100)
		  WriteImage(R_L_ARR1, BLANK, BLANK);
	  else if (alt >= 100 && alt < 200)
		  WriteImage(R_L_ARR2, BLANK, BLANK);
	  else if (alt >= 200 && alt < 300)
		  WriteImage(R_R_ARR1, BLANK, BLANK);
	  else if (alt >= 300 && alt < 400)
		  WriteImage(R_R_ARR2, BLANK, BLANK);
	  else if (alt >= 400 && alt < 500)
		  WriteImage(R_BOX, G_BOX, B_BOX);
	  else {
		  WriteImage(R_SMILE, G_SMILE, B_SMILE);
		  if (alt > 600)
			  alt = 0;
	  }
	  msdelay(2);
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

//GPIO_PinState CheckBit(int val, int j) {
//	return (val & (1 << j)) ? GPIO_PIN_SET : GPIO_PIN_RESET;
//}

static inline GPIO_PinState CheckBit(unsigned int val, int j) {
	return (GPIO_PinState) ((val & (1 << j)) >> j);
}

void WriteImage(const unsigned int r[16], const unsigned int g[16], const unsigned int b[16]) {
	const GPIO_PinState s = GPIO_PIN_SET;
	const GPIO_PinState res = GPIO_PIN_RESET;

	for (int i = 0; i < 8; i++) {
		HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, res);
		for (int j = 0; j < 32; j++) {

			HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, res);
			usdelay(N);
			// here we could make s correspond to a bit in the uint16_t number
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, CheckBit(r[i], j));
//			usdelay(D);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, CheckBit(g[i], j));
//			usdelay(D);
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, CheckBit(b[i], j));
//			usdelay(D);
			HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, CheckBit(r[i+8], j));
//			usdelay(D);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, CheckBit(g[i+8], j));
//			usdelay(D);
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, CheckBit(b[i+8], j));
			usdelay(N); // time it takes to write to all pins is maybe enough wait
			// wait sCLK time
			HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, s);
			usdelay(N);
			// wait sCLK time
		}
		// assert blank
		HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, s);
		// set address
		HAL_GPIO_WritePin(PIN_C_GPIO_Port, PIN_C_Pin, (GPIO_PinState) (i & 0x4));
		HAL_GPIO_WritePin(PIN_B_GPIO_Port, PIN_B_Pin, (GPIO_PinState) (i & 0x2));
		HAL_GPIO_WritePin(PIN_A_GPIO_Port, PIN_A_Pin, (GPIO_PinState) (i & 0x1));
		// latch
		HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, s);
		HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, res);
		// wait N time
		usdelay(N*5);
	}
}

void BlindMe() {
	const GPIO_PinState s = GPIO_PIN_SET;
	const GPIO_PinState r = GPIO_PIN_RESET;
	HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, r);
	HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, r);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 32; j++) {

			HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, r);

			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, s);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, s);
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, s);
			HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, s);
			HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, s);
			HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, s);
			usdelay(1); // time it takes to write to all pins is maybe enough wait
			// wait sCLK time
			HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, s);
			usdelay(1);
			// wait sCLK time
		}
		// assert blank
		HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, s);
		// set address
		HAL_GPIO_WritePin(PIN_C_GPIO_Port, PIN_C_Pin, (GPIO_PinState) (i & 0x4));
		HAL_GPIO_WritePin(PIN_B_GPIO_Port, PIN_B_Pin, (GPIO_PinState) (i & 0x2));
		HAL_GPIO_WritePin(PIN_A_GPIO_Port, PIN_A_Pin, (GPIO_PinState) (i & 0x1));
		// latch
		HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, s);
		// deassert blank
		HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, r);
		// wait N time
		usdelay(N);
	}
}

void WriteOddPixels(GPIO_PinState s) {
	HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, GPIO_PIN_RESET);
	for (int i = 0; i < 32; i++) {

		HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, GPIO_PIN_RESET);
		if (i % 2 == 1) {
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, s);
		}
		else {
			HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
		}
		usdelay(1);
		// wait sCLK time
		HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, GPIO_PIN_SET);
		usdelay(1);
		// wait sCLK time
	}
	HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, GPIO_PIN_SET);
}

void WriteEvenPixels(GPIO_PinState s) {
	HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, GPIO_PIN_RESET);
	for (int i = 0; i < 32; i++) {

		HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, GPIO_PIN_RESET);
		if (i % 2 == 0) {
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, s);
		}
		else {
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
		}
		HAL_Delay(1);
		// wait sCLK time
		HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
		// wait sCLK time
	}
	HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, GPIO_PIN_SET);
}

void WriteTopLeftPixel(GPIO_PinState s) {
	HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, s);
	// wait sCLK time
	usdelay(2);
//	HAL_Delay(1);
	HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, GPIO_PIN_SET);
	usdelay(2);
//	HAL_Delay(1);
	// wait sCLK time
	HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	usdelay(2);
//	HAL_Delay(1);
	// wait sCLK time
	for (int i = 0; i < 31; i++) {
		HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, GPIO_PIN_SET);
		usdelay(2);
//		HAL_Delay(1);
		// wait sCLK time
		HAL_GPIO_WritePin(sCLK_GPIO_Port, sCLK_Pin, GPIO_PIN_RESET);
		usdelay(2);
//		HAL_Delay(1);
		// wait sCLK time
	}
	HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LAT_GPIO_Port, LAT_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(OE_GPIO_Port, OE_Pin, GPIO_PIN_RESET);


}

void UpdateRow(char row) {
//	char bitmask = 1;
	// transfer row bits to CBA order
//	HAL_GPIO_WritePin(PIN_C_GPIO_Port, PIN_C_Pin, (row & bitmask) );
//	HAL_GPIO_WritePin(PIN_B_GPIO_Port, PIN_B_Pin, ((row >> 1) & bitmask) );
//	HAL_GPIO_WritePin(PIN_A_GPIO_Port, PIN_A_Pin, ((row >> 2) & bitmask) );
//
//
//	// Currently updating both rows to only be white
//	for (int i = 0; i < 6; i++) {
//		HAL_GPIO_WritePin(color_ports[i], color_pins[i], 1);
//	}

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
  HAL_GPIO_WritePin(GPIOC, sCLK_Pin|B2_Pin|R2_Pin|PIN_B_Pin
                          |PIN_A_Pin|R1_Pin|G1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(PIN_C_GPIO_Port, PIN_C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, OE_Pin|LAT_Pin|B1_Pin|G2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : sCLK_Pin */
  GPIO_InitStruct.Pin = sCLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(sCLK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : B2_Pin R2_Pin PIN_B_Pin PIN_A_Pin
                           R1_Pin G1_Pin */
  GPIO_InitStruct.Pin = B2_Pin|R2_Pin|PIN_B_Pin|PIN_A_Pin
                          |R1_Pin|G1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PIN_C_Pin */
  GPIO_InitStruct.Pin = PIN_C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(PIN_C_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OE_Pin */
  GPIO_InitStruct.Pin = OE_Pin|LAT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OE_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LAT_Pin B1_Pin G2_Pin */
  GPIO_InitStruct.Pin = B1_Pin|G2_Pin;
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
