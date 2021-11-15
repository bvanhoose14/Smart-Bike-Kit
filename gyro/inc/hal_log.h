/*
 * hal_log.h
 *
 *  Created on: May 18, 2021
 *      Author: Spencer
 */

#ifndef INC_HAL_LOG_H_
#define INC_HAL_LOG_H_

#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define PRINT_BUFFER_SIZE 100

UART_HandleTypeDef *huart;

void init_handle(UART_HandleTypeDef *huart_);

void HAL_printf_valist(const char *fmt, va_list argp);
void HAL_printf(const char *fmt, ...);

void logg(uint8_t level, const char *fmt, va_list argp);
void logI(const char* fmt, ...);
void logE(const char* fmt, ...);
void reverse(char* str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char* res, int afterpoint);

#endif /* INC_HAL_LOG_H_ */
