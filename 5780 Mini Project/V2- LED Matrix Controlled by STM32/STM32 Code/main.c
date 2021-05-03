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
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
int checkgyro(void);

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
			HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, 0);  // Pull the CLK LOW
			HAL_GPIO_WritePin(data_GPIO_Port, data_Pin, byte&0x80);// Write one BIT data MSB first
			byte = byte<<1;  // shift the data to the left
			HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, 1);  // Pull the CLK HIGH		
		 }			
}

void write_matrix (uint8_t address, uint8_t data)
{
		HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, 0);   // Pull the CS pin LOW
    write_byte(address);  										 //  write address
    write_byte(data);												  //  write data
    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, 1);  // pull the CS HIGH
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
			HAL_Delay(20);
			write_matrix (8 , disp1ay[j][7]);			
			HAL_Delay(20);
			write_matrix (2 , disp1ay[j][1]);
			HAL_Delay(20);
			write_matrix (7 , disp1ay[j][6]);
			HAL_Delay(20);
			write_matrix (3 , disp1ay[j][2]);
			HAL_Delay(20);
			write_matrix (6 , disp1ay[j][5]);
			HAL_Delay(20);
			write_matrix (4 , disp1ay[j][3]);
			HAL_Delay(20);
			write_matrix (5 , disp1ay[j][4]);
			//if(checkgyro() == 1) return;
			HAL_Delay(400);
		}
}

void display_left(void)
{		
		for (int j=0; j<2; j++)
		{			
			write_matrix (1 , disp1ay[j][0]);
			HAL_Delay(20);
			write_matrix (8 , disp1ay[j][7]);			
			HAL_Delay(20);
			write_matrix (2 , disp1ay[j][1]);
			HAL_Delay(20);
			write_matrix (7 , disp1ay[j][6]);
			HAL_Delay(20);
			write_matrix (3 , disp1ay[j][2]);
			HAL_Delay(20);
			write_matrix (6 , disp1ay[j][5]);
			HAL_Delay(20);
			write_matrix (4 , disp1ay[j][3]);
			HAL_Delay(20);
			write_matrix (5 , disp1ay[j][4]);
			//if(checkgyro() == 1) return;
			HAL_Delay(400);
		}
}

void LED_off(void)
{
            write_matrix (1 , disp1ay[3][0]);
            HAL_Delay (20);
            write_matrix (8 , disp1ay[3][7]);
            HAL_Delay (20);
            write_matrix (2 , disp1ay[3][1]);
            HAL_Delay (20);
            write_matrix (7 , disp1ay[3][6]);
            HAL_Delay (20);
            write_matrix (3 , disp1ay[3][2]);
            HAL_Delay (20);
            write_matrix (6 , disp1ay[3][5]);
            HAL_Delay (20);
            write_matrix (4 , disp1ay[3][3]);
            HAL_Delay (20);
            write_matrix (5 , disp1ay[3][4]);
            
}

//void tx_char(char c);
//void tx_string(char* message);
//void rx_char(void);
int printStr(char*);
int leftSet;
int rightSet;
int leftTurn;
int rightTurn;
void printChar(char);
char read_i2c(void);
void set_read_i2c(char b);

volatile int rx_flag; // C-standard defines _Bool as smallest integer datatype (not an official type/keyword though)
volatile uint8_t data;

char val;
int16_t x = 0;
int16_t y = 0;
/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

	//Enable interrupt registers
	SYSCFG->EXTICR[0] = 0x2;
	SYSCFG->EXTICR[2] = 0xa;
	EXTI->IMR |= (1<<0);
	EXTI->IMR |= (1<<2);
	EXTI->RTSR |= (1<<0);
	EXTI->RTSR |= (1<<2);
	NVIC_EnableIRQ(EXTI0_1_IRQn);
	NVIC_EnableIRQ(EXTI2_3_IRQn);
	NVIC_EnableIRQ(I2C2_IRQn);
	NVIC_SetPriority(EXTI0_1_IRQn, 1);
	NVIC_SetPriority(EXTI2_3_IRQn, 1);
	NVIC_SetPriority(I2C2_IRQn, 1);
	
	MX_GPIO_Init();
	matrix_init ();
	
  /* Configure the system clock */
  SystemClock_Config();

	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGCOMPEN;
	
	// Uart configuration
	RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
	
	GPIOC->MODER |= (1 << 11) | (1 << 9);  //high bits for PC4 and PC5
	GPIOC->MODER &= ~((1 << 10) | (1 << 8)); //low bits
	GPIOC->AFR[0] |= (1 << 16); // set to AF1
	GPIOC->AFR[0] |= (1 << 20);
	USART3->BRR = HAL_RCC_GetHCLKFreq()/115200;
	USART3->CR1 |= (1 << 3); // enable TX
	USART3->CR1 |= (1 << 2); // enable RX
	
	// enable receive register not empty interrupt
	USART3->CR1 |= USART_CR1_RXNEIE;
	
	
	USART3->CR1 |= (1 << 0); // enable the USART3, all configurations are now read only
	// enable and set USART interrupt priority in NVIC
	//NVIC_EnableIRQ(USART3_4_IRQn);
	//NVIC_SetPriority(USART3_4_IRQn, 2);
	
	//GPIO SIGNAL Config
	GPIOC->MODER &= ~((1<<23));
	GPIOC->MODER &= ~((1<<22));
	GPIOC->PUPDR &= ~((1<<22));
	GPIOC->PUPDR |= (1<<23);
	GPIOA->MODER &= ~((1<<31));
	GPIOA->MODER &= ~((1<<30));
	GPIOA->PUPDR &= ~((1<<30));
	GPIOA->PUPDR |= (1<<31);
	//PC11-PA11 to input mode
	GPIOC->MODER |= (1<<8); //PC4 to ouptut
	GPIOC->MODER &= ~((1<<9));
	GPIOA->MODER |= (1<<8); //PA4 to output
	GPIOA->MODER &= ~((1<<9));
	
	// LED configuration
	GPIOC->MODER |= (1 << 18) | (1 << 16) |(1 << 14) | (1 << 12) ;        // Set PC6-PC9 to output mode
  GPIOC->OTYPER &= ~((1 << 9) | (1 << 8) | (1 << 7) | (1 << 6));      // Set push-pull output
  GPIOC->OSPEEDR &= ~((1 << 18) | (1 << 16) | (1 << 14) | (1 << 12));   // Set low speed
  GPIOC->PUPDR &= ~((1 << 15) | (1 << 14) | (1 << 13) | (1 << 12));   // Set no-pull up/down
	
	// I2C configuration
	GPIOB->MODER |= (1 << 27) | (1 << 23);  //high bits for PB11 - SDA and PB13 - SCL
	GPIOB->MODER &= ~((1 << 26) | (1 << 22)); //low bits
	GPIOB->OTYPER |= GPIO_OTYPER_OT_11; // set to open-drain
	GPIOB->OTYPER |= GPIO_OTYPER_OT_13;
	GPIOB->PUPDR |= (1 << 22) | (1 << 26);
	GPIOB->AFR[1] |= (1 << 12); // set to AF1 for PB11
	GPIOB->AFR[1] |= (5 << 20); // PB13 is AF5
	
	GPIOB->MODER |= (1 << 28); // PB14 output, push-pull, set pin high
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_14);
	GPIOB->BSRR |= (1 << 14);
	
	GPIOC->MODER |= (1 << 0); // PC0 output, push-pull, set pin high
	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT_0);
	GPIOC->ODR |= (1 << 0);
	
	
	
	// Configure the bus timing
	I2C2->TIMINGR = 0;
	I2C2->TIMINGR |= (1 << I2C_TIMINGR_PRESC_Pos); // 28
	I2C2->TIMINGR |= (0x13 << I2C_TIMINGR_SCLL_Pos); // 0 
	I2C2->TIMINGR |= (0xF << I2C_TIMINGR_SCLH_Pos); // 8
	I2C2->TIMINGR |= (0x2 << I2C_TIMINGR_SDADEL_Pos); // 16
	I2C2->TIMINGR |= (0x4 << I2C_TIMINGR_SCLDEL_Pos); // 20
	I2C2->CR1 |= I2C_CR1_PE; // peripheral enable
	
	// transaction setup
	// clear NBYTES and SADD bit fields
	I2C2->CR2 &= ~((0x7FUL << 16) | (0x3FFUL << 0));
	// Set NBYTES = 1 and SADD = 0x6B
	I2C2->CR2 |= ((1 << 16) | (0x6B << 1));
	
	// Set to write
	I2C2->CR2 &= ~I2C_CR2_RD_WRN;
	
	// send start to begin address frame
	I2C2->CR2 |= I2C_CR2_START;
	GPIOC->ODR |= (1 << 9);
	
	// Set up comms
	while(!(I2C2->ISR & (I2C_ISR_TXIS | I2C_ISR_NACKF))) {
		GPIOC->ODR |= (1 << 6);
	}
	if(I2C2->ISR & I2C_ISR_NACKF) {
		GPIOC->ODR |= (1 << 7);
		printStr("Received NACK...\n\r");
	}
	GPIOC->ODR &= ~(1 << 6);
	printStr("Received TXIS\n\r");
	GPIOC->ODR |= (1 << 8);
	// WHO_AM_I is 0x0F
	I2C2->TXDR = 0x0F;
	printStr("Waiting for TC...\n\r");
	while(!((I2C2->ISR & I2C_ISR_TC) || (I2C2->ISR & I2C_ISR_NACKF))){ 
		;
	}
	if(I2C2->ISR & I2C_ISR_NACKF) {
		GPIOC->ODR |= (1 << 7);
		printStr("Received NACK...\n\r");
	}
	printStr("Got TC\n\r");
	I2C2->CR2 &= ~((0x7FUL << 16) | (0x3FFUL << 0));
	// Set NBYTES = 1 and SADD = 0x6B
	I2C2->CR2 |= (1 << 16) | (0x6B << 1);
	
	// Set to Read
	I2C2->CR2 |= I2C_CR2_RD_WRN;
	I2C2->CR2 |= I2C_CR2_START;
	printStr("Waiting for RXNE\n\r");
	while(!((I2C2->ISR & I2C_ISR_RXNE) || (I2C2->ISR & I2C_ISR_NACKF))) {
		;
	}
	if(I2C2->ISR & I2C_ISR_NACKF) {
		GPIOC->ODR |= (1 << 7);
		printStr("Received NACK...\n\r");
	}
	printStr("Got RXNE \n\r");
	while(!((I2C2->ISR & I2C_ISR_TC) || (I2C2->ISR & I2C_ISR_NACKF))){ 
		;
	}
	if(I2C2->ISR & I2C_ISR_NACKF) {
		GPIOC->ODR |= (1 << 7);
		printStr("Received NACK...\n\r");
	}
	printStr("Got TC\n\r");
	char data = I2C2->RXDR;
	if (I2C2->RXDR == 0xD4) {
		GPIOC->ODR ^= (1 << 9);
		printStr("Success...\n\r");
	}
	
	
	GPIOC->ODR &= ~((1 << 9) | (1 << 8) | (1 << 7) | (1 << 6));
	
	//***************** end comm setup ***********************
	// Begin gyroscope setup
	// 1. Setup write to L3GD20 address
	I2C2->CR2 &= ~((0x7FUL << 16) | (0x3FFUL << 0));
	// Set NBYTES = 1 and SADD = 0x6B
	I2C2->CR2 |= (2 << 16) | (0x6B << 1);
	
	// Set to Write
	I2C2->CR2 &= ~I2C_CR2_RD_WRN;
	I2C2->CR2 |= I2C_CR2_START;
	while(!(I2C2->ISR & (I2C_ISR_TXIS | I2C_ISR_NACKF)));
	if(I2C2->ISR & I2C_ISR_NACKF) {
		printStr("Received NACK...\n\r");
	}
	printStr("Received TXIS\n\r");
	GPIOC->ODR ^= (1 << 9);
	// 2. Write register address to modify
	// CTRL_REG1 is 0x020
	I2C2->TXDR = 0x20;
	
	
	while(!(I2C2->ISR & (I2C_ISR_TXIS | I2C_ISR_NACKF)));
	if(I2C2->ISR & I2C_ISR_NACKF) {
		printStr("Received NACK...\n\r");
	}
	printStr("Received TXIS\n\r");
	GPIOC->ODR ^= (1 << 6);
	// 3. Write data to selected register
	// set PD, Xen, and Yen high
	char cr1 = 0xB;
	I2C2->TXDR = cr1;
	printStr("Writing to CTRL_REG1\n\r");
	while(!((I2C2->ISR & I2C_ISR_TC) || (I2C2->ISR & I2C_ISR_NACKF))) ;
	if(I2C2->ISR & I2C_ISR_NACKF) {
		printStr("Received NACK...\n\r");
	}
	printStr("Got TC\n\r");
	GPIOC->ODR ^= (1 << 7);
	printStr("Now init for reading\n\r");
	
	GPIOC->ODR &= ~((1 << 9) | (1 << 8) | (1 << 7) | (1 << 6));
	
	
	leftTurn = 0;
	rightTurn = 0;
	rightSet = 0;
	leftSet = 0;
	//GPIOC->ODR |= (1 << 8);
	//GPIOC->ODR |= (1 << 9);
  while (1)
  {
		//checkgyro();
		if(GPIOA->IDR & (1 << 15))
		{
			rightSet = 1;
		}
		else
		{
			rightSet = 0;
		}
		if(GPIOC->IDR & (1 << 11))
		{
			leftSet = 1;
		}
		else
		{
			leftSet = 0;
		}
		
		if(leftSet == 1)
		{
			
			GPIOC->ODR |= (1 << 8);
			GPIOC->ODR &= ~((1 << 9));
			checkgyro();
			display_left();
		}
		if(rightSet == 1)
		{
			GPIOC->ODR |= (1 << 9);
			GPIOC->ODR &= ~((1 << 8));
			checkgyro();
			display_right();
		}
		if(leftSet == 0)
		{
			GPIOC->ODR &= ~(1 << 8);
		}
		if(rightSet == 0)
		{
			GPIOC->ODR &= ~(1 << 9);
		}
		
		checkgyro();
//		HAL_Delay(100);
//		set_read_i2c(0xA8);
//	// 3. Restart and setup read to L3GD20 address
//		
//	// 4. Read data from register selected by previous write every 100 ms
//		val = read_i2c();
//		x = val;
//		val = read_i2c();
//		x |= (val << 8);
//		while(!((I2C2->ISR & I2C_ISR_TC) || (I2C2->ISR & I2C_ISR_NACKF))) ;
//		if(I2C2->ISR & I2C_ISR_NACKF) {
//			printStr("Received NACK...\n\r");
//		}
//		set_read_i2c(0xAA);
//		val = read_i2c();
//		y = val;
//		val = read_i2c();
//		y |= (val << 8);
//		while(!((I2C2->ISR & I2C_ISR_TC) || (I2C2->ISR & I2C_ISR_NACKF))) ;
//		if(I2C2->ISR & I2C_ISR_NACKF) {
//			printStr("Received NACK...\n\r");
//		}
//		if(leftSet == 1)
//		{
//		
//		if(x > 8000) {
//			leftSet = 0;
//			GPIOC->ODR |= (1 << 4);
//			HAL_Delay(1000);
//			GPIOC->ODR &= ~(1 << 4);
//			
//			//GPIOC->ODR |= (1 << 9);
//			//GPIOC->ODR &= ~(1 << 8);
//		}
//		}
//		else if(rightSet == 1)
//		{
//			if(x < -8000) {
//			//GPIOC->ODR |= (1 << 8);
//			rightSet = 0;
//			GPIOA->ODR |= (1 << 4);
//			HAL_Delay(1000);
//			GPIOA->ODR &= ~(1 << 4);
//			
//			//GPIOC->ODR &= ~(1 << 9);
//		}
//		}
//		else {
//			GPIOC->ODR &= ~(1 << 8);
//			GPIOC->ODR &= ~(1 << 9);
//		}
		
//		if(y > 1500) {
//			GPIOC->ODR |= (1 << 6);
//			GPIOC->ODR &= ~(1 << 7);
//		}
//		else if(y < -1500) {
//			GPIOC->ODR |= (1 << 7);
//			GPIOC->ODR &= ~(1 << 6);
//		}
//		else {
//			GPIOC->ODR &= ~(1 << 6);
//			GPIOC->ODR &= ~(1 << 7);
//		}
		
  }
  /* USER CODE END 3 */
}
int checkgyro(void)
{
	HAL_Delay(20);
		set_read_i2c(0xA8);
	// 3. Restart and setup read to L3GD20 address
		
	// 4. Read data from register selected by previous write every 100 ms
		val = read_i2c();
		x = val;
		val = read_i2c();
		x |= (val << 8);
		while(!((I2C2->ISR & I2C_ISR_TC) || (I2C2->ISR & I2C_ISR_NACKF))) ;
		if(I2C2->ISR & I2C_ISR_NACKF) {
			printStr("Received NACK...\n\r");
		}
		set_read_i2c(0xAA);
		val = read_i2c();
		y = val;
		val = read_i2c();
		y |= (val << 8);
		while(!((I2C2->ISR & I2C_ISR_TC) || (I2C2->ISR & I2C_ISR_NACKF))) ;
		if(I2C2->ISR & I2C_ISR_NACKF) {
			printStr("Received NACK...\n\r");
		}
		if(leftSet == 1)
		{
		
		if(x > 8000) {
			leftSet = 0;
			LED_off();
			GPIOC->ODR |= (1 << 4);
			HAL_Delay(1000);
			GPIOC->ODR &= ~(1 << 4);
			return 1;
			//GPIOC->ODR |= (1 << 9);
			//GPIOC->ODR &= ~(1 << 8);
		}
		}
		else if(rightSet == 1)
		{
			if(x < -8000) {
			//GPIOC->ODR |= (1 << 8);
			rightSet = 0;
			LED_off();
			GPIOA->ODR |= (1 << 4);
			HAL_Delay(1000);
			GPIOA->ODR &= ~(1 << 4);
			return 1;
			//GPIOC->ODR &= ~(1 << 9);
		}
		}
		
		return 0;
}
void EXTI0_1_IRQHandler(void)
{
	//leftSet = 1;
	EXTI->PR |= (1<<0);
}

void EXTI2_3_IRQHandler(void)
{
	//rightSet = 1;
	EXTI->PR |= (1<<2);
}

void I2C2_IRQHandler(void)
{
	checkgyro();
}

void set_read_i2c(char b) {
	// char b is address to read
	//Initialize gyro to read X and Y axis
	
	// 1. Setup write to L3GD20 address
	I2C2->CR2 &= ~((0x7FUL << 16) | (0x3FFUL << 0));
	// Set NBYTES = 1 and SADD = 0x6B
	I2C2->CR2 |= (1 << 16) | (0x6B << 1);
	
	// Set to Write
	I2C2->CR2 &= ~I2C_CR2_RD_WRN;
	I2C2->CR2 |= I2C_CR2_START;
	// --------- stuck in while
	while(!(I2C2->ISR & (I2C_ISR_TXIS | I2C_ISR_NACKF))) ;
	if(I2C2->ISR & I2C_ISR_NACKF) {
		printStr("Received NACK...\n\r");
	}
	printStr("Received TXIS\n\r");
	// 2. Write register address to read from
	// OUT_X&Y 
	I2C2->TXDR = b;
	printStr("Waiting for TC...\n\r");
	while(!((I2C2->ISR & I2C_ISR_TC) || (I2C2->ISR & I2C_ISR_NACKF))) ;
	if(I2C2->ISR & I2C_ISR_NACKF) {
		printStr("Received NACK...\n\r");
	}
	printStr("Got TC\n\r");
	
	
	
	// Read 2 bytes
	I2C2->CR2 &= ~((0x7FUL << 16) | (0x3FFUL << 0));
	I2C2->CR2 |= (2 << 16) | (0x6B << 1);
	
	// Set to Read
	I2C2->CR2 |= I2C_CR2_RD_WRN;
	I2C2->CR2 |= I2C_CR2_START;
}

char read_i2c(void) {
	
	while(!((I2C2->ISR & I2C_ISR_RXNE) || (I2C2->ISR & I2C_ISR_NACKF)));
	if(I2C2->ISR & I2C_ISR_NACKF) {
		printStr("Received NACK...\n\r");
	}
	char data = I2C2->RXDR;
	printStr("Got data\n\r");
	return data;
}


void USART3_4_IRQHandler(void) {
    if(USART3->ISR & USART_ISR_RXNE) { // Triggered by new data in RX register
        data = USART3->RDR;  // Automatically clears interrupt RXNE flag
        rx_flag = 1;
    }
}

int printStr(char* str) {
    char* start = str;
    while(*str) {  // Loop until null char encountered
        printChar(*str);
        str++;
    }
    return str-start; // Return number of bytes sent
}

void printChar(char c) {
    while(!(USART3->ISR & USART_ISR_TXE)); // Loop until the TX register is empty (TXE bit is set)
    USART3->TDR = c;
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

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CLK_GPIO_Port, CS_Pin|CLK_Pin, GPIO_PIN_RESET);

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
