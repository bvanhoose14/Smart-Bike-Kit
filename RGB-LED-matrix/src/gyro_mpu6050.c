#include "gyro_mpu6050.h"
#include "stdio.h"

HAL_StatusTypeDef reset_mpu6050(I2C_HandleTypeDef *hi2c) {
	HAL_StatusTypeDef ret;
	// https://stackoverflow.com/questions/6390331/why-use-array-size-1-instead-of-pointer
	uint8_t buf[1];
//	HAL_printf("Resetting MPU6050\r\n");

	// reset internal registers
	buf[0] = (1 << 7); // setting bit 7 (device_reset) to 1 resets all internal registers to default
	ret = HAL_I2C_Mem_Write(hi2c, MPU_I2C_ADDR, MPU6050_PWR_MGMT_1, 1, buf, 1,
				HAL_MAX_DELAY);

	if (HAL_OK != ret) {
//		HAL_printf("Resetting MPU6050 registers error: %d\r\n", ret);
		return ret;
	}

	// Now reset signal paths
	buf[0] = 0b11; // clears all three signal paths
	ret = HAL_I2C_Mem_Write(hi2c, MPU_I2C_ADDR, MPU6050_SIGNAL_PATH_RESET, 1, buf, 1,
			HAL_MAX_DELAY);

	if (HAL_OK != ret) {
//		HAL_printf("Resetting MPU6050 signal paths error: %d\r\n", ret);
		return ret;
	}

	return ret;
}

HAL_StatusTypeDef init_mpu6050(I2C_HandleTypeDef *hi2c, mpu6050_cfg *cfg) {
	HAL_StatusTypeDef status = HAL_OK;
//	HAL_printf("Initializing MPU6050\r\n");


	uint8_t buf[1];
	status = HAL_I2C_Mem_Read(hi2c, MPU_I2C_ADDR, MPU6050_WHO_AM_I, 1, buf, 1,
			HAL_MAX_DELAY);

	if (MPU6050_DEVICE_ID != buf[0]) {
//		HAL_printf("Device no match. Expected: %d, Actual: %d\r\n", MPU6050_DEVICE_ID, buf[0]);
		return status;
	}

	status = set_cycle_rate(hi2c, cfg->cycle_rate);

	if (HAL_OK != status) {
//		HAL_printf("I2C failed on set_cycle_rate error: %d\r\n", status);
		return status;
	}

	status = set_filter_bandwidth(hi2c, cfg->bandwidth);

	if (HAL_OK != status) {
//		HAL_printf("I2C failed on set_filter_bandwidth error: %d\r\n", status);
		return status;
	}

	status = set_accel_range(hi2c, cfg->accel_range);

	if (HAL_OK != status) {
//		HAL_printf("I2C failed on set_accel_range error: %d\r\n", status);
		return status;
	}

	status = set_gyro_range(hi2c, cfg->gyro_range);

	if (HAL_OK != status) {
//		HAL_printf("I2C failed on set_gyro_range error: %d\r\n", status);
		return status;
	}

	status = set_clock(hi2c, cfg->clock_select);

	if (HAL_OK != status) {
//		HAL_printf("I2C failed on set_clock error: %d\r\n", status);
		return status;
	}

//	HAL_printf("MPU6050 initialized successfully\r\n");

	return status;
}

HAL_StatusTypeDef set_clock(I2C_HandleTypeDef *hi2c, mpu6050_clock_select_t clk_sel) {
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[1];
	buf[0] = clk_sel;

	status = HAL_I2C_Mem_Write(hi2c, MPU_I2C_ADDR, MPU6050_PWR_MGMT_1, 1, buf, 1,
			HAL_MAX_DELAY);

	return status;
}

mpu6050_clock_select_t get_clock(I2C_HandleTypeDef *hi2c) {
//	HAL_printf("get MPU6050 clock...\r\n");
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[1];

	status = HAL_I2C_Mem_Read(hi2c, MPU_I2C_ADDR, MPU6050_PWR_MGMT_1, 1, buf, 1,
			HAL_MAX_DELAY);

	if (HAL_OK != status) {
//		HAL_printf("Error getting clock selection from MPU6050...\r\n");
	}

	mpu6050_clock_select_t clk_select = (buf[0] << 5) >> 5;
	return clk_select;
}

HAL_StatusTypeDef set_gyro_range(I2C_HandleTypeDef *hi2c, mpu6050_gyro_range_t gyro_range) {
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[1];
	buf[0] = gyro_range << 3;

	status = HAL_I2C_Mem_Write(hi2c, MPU_I2C_ADDR, MPU6050_GYRO_CONFIG, 1, buf, 1,
			HAL_MAX_DELAY);

	return status;
}

mpu6050_gyro_range_t get_gyro_range(I2C_HandleTypeDef *hi2c) {
//	HAL_printf("get MPU6050 gyro_range...\r\n");
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[1];

	status = HAL_I2C_Mem_Read(hi2c, MPU_I2C_ADDR, MPU6050_GYRO_CONFIG, 1, buf, 1,
			HAL_MAX_DELAY);


	mpu6050_gyro_range_t gyro_range = (buf[0] << 3) >> 6;

	if (HAL_OK != status) {
//		HAL_printf("Error getting gyro range from MPU6050...\r\n");
	}

	return gyro_range;
}

HAL_StatusTypeDef set_accel_range(I2C_HandleTypeDef *hi2c, mpu6050_accel_range_t accel_range) {
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[1];
	buf[0] = accel_range << 3;

	status = HAL_I2C_Mem_Write(hi2c, MPU_I2C_ADDR, MPU6050_ACCEL_CONFIG, 1, buf, 1,
			HAL_MAX_DELAY);

	return status;
}

mpu6050_accel_range_t get_accel_range(I2C_HandleTypeDef *hi2c) {
//	HAL_printf("get MPU6050 accel_range...\r\n");
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[1];

	status = HAL_I2C_Mem_Read(hi2c, MPU_I2C_ADDR, MPU6050_ACCEL_CONFIG, 1, buf, 1,
			HAL_MAX_DELAY);

	mpu6050_accel_range_t accel_range = (buf[0] << 3) >> 6;

	if (HAL_OK != status) {
//		HAL_printf("Error getting accel range from MPU6050...\r\n");
	}

	return accel_range;
}

HAL_StatusTypeDef set_filter_bandwidth(I2C_HandleTypeDef *hi2c, mpu6050_bandwidth_t bandwidth) {

	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[1];
	buf[0] = bandwidth;

	status = HAL_I2C_Mem_Write(hi2c, MPU_I2C_ADDR, MPU6050_CONFIG, 1, buf, 1,
			HAL_MAX_DELAY);

	return status;
}

mpu6050_bandwidth_t get_filter_bandwidth(I2C_HandleTypeDef *hi2c) {
//	HAL_printf("get MPU6050 bandwidth...\r\n");
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[1];

	status = HAL_I2C_Mem_Read(hi2c, MPU_I2C_ADDR, MPU6050_CONFIG, 1, buf, 1,
			HAL_MAX_DELAY);

	mpu6050_bandwidth_t bandwidth = (buf[0] << 5) >> 5;

	if (HAL_OK != status) {
//		HAL_printf("Error getting filter bandwidth from MPU6050...\r\n");
	}

	return bandwidth;
}

/**
 * @brief Set low-power wake-up cycle rate for the frequency of wake-ups in the
 * 			accelerometer only low power mode.
 * @param hi2c -- HAL I2C handle pointer
 * @param rate -- cycle rate as enum
 * @retval status -- HAL defined error status
 */
HAL_StatusTypeDef set_cycle_rate(I2C_HandleTypeDef *hi2c, mpu6050_cycle_rate_t rate) {
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[1];
	buf[0] = (rate << 6);

	status = HAL_I2C_Mem_Write(hi2c, MPU_I2C_ADDR, MPU6050_PWR_MGMT_2, 1, buf, 1,
			HAL_MAX_DELAY);

	return status;
}

/**
 * @brief Get cycle rate for low power mode
 * @param hi2c -- HAL I2C handle pointer
 * @retval rate -- cycle rate as enum
 */
mpu6050_cycle_rate_t get_cycle_rate(I2C_HandleTypeDef *hi2c) {
//	HAL_printf("get MPU6050 cycle_rate...\r\n");
	HAL_StatusTypeDef status = HAL_OK;
	uint8_t buf[1];


	status = HAL_I2C_Mem_Read(hi2c, MPU_I2C_ADDR, MPU6050_PWR_MGMT_2, 1, buf, 1,
			HAL_MAX_DELAY);

	mpu6050_cycle_rate_t rate = buf[0] >> 6;

	if (HAL_OK != status) {
//		HAL_printf("Error getting cycle rate from MPU6050...\r\n");
	}

	return rate;
}

HAL_StatusTypeDef read_mpu6050(I2C_HandleTypeDef *hi2c, mpudata_t *mpu_data,
		mpu6050_cfg *mpu_cfg) {
	HAL_StatusTypeDef status;
	uint8_t buf[14];
	buf[0] = MPU6050_ACCEL_OUT;

//	HAL_printf("Reading MPU6050...\r\n");

	status = HAL_I2C_Mem_Read(hi2c, MPU_I2C_ADDR, MPU6050_ACCEL_OUT, 1, buf, 14,
			HAL_MAX_DELAY);
	if (HAL_OK != status) {
//		HAL_printf("MPU6050 reading error: %d\r\n", status);
	} else {
		int16_t rawGyroZ = buf[0] << 8 | buf[1];
		int16_t rawGyroY = buf[2] << 8 | buf[3];
		int16_t rawGyroX = buf[4] << 8 | buf[5];

		int16_t rawTemp = buf[6] << 8 | buf[7];

		int16_t rawAccZ = buf[8] << 8 | buf[9];
	    int16_t rawAccY = buf[10] << 8 | buf[11];
	    int16_t rawAccX = buf[12] << 8 | buf[13];

		mpu_data->temp = (((rawTemp / 340.0) + 36.53)*100);

		float accel_scale = 1;
		if (mpu_cfg->accel_range == MPU6050_RANGE_16_G)
			accel_scale = 2048;
		else if (mpu_cfg->accel_range == MPU6050_RANGE_8_G)
			accel_scale = 4096;
		else if (mpu_cfg->accel_range == MPU6050_RANGE_4_G)
			accel_scale = 8192;
		else if (mpu_cfg->accel_range == MPU6050_RANGE_2_G)
			accel_scale = 16384;

		mpu_data->accX = (int16_t)(((float)rawAccX) / accel_scale * GRAVITY * 100);
		mpu_data->accY = (int16_t)(((float)rawAccY) / accel_scale * GRAVITY * 100);
		mpu_data->accZ = (int16_t)(((float)rawAccZ) / accel_scale * GRAVITY * 100);

		float gyro_scale = 1;
		if (mpu_cfg->gyro_range == MPU6050_RANGE_250_DEG)
			gyro_scale = 131;
		else if (mpu_cfg->gyro_range == MPU6050_RANGE_500_DEG)
			gyro_scale = 65.5;
		else if (mpu_cfg->gyro_range == MPU6050_RANGE_1000_DEG)
			gyro_scale = 32.8;
		else if (mpu_cfg->gyro_range == MPU6050_RANGE_2000_DEG)
			gyro_scale = 16.4;

		mpu_data->gyroX = (int16_t)(((float)rawGyroX) / gyro_scale * DPS_TO_RADS * 100);
		mpu_data->gyroY = (int16_t)(((float)rawGyroY) / gyro_scale * DPS_TO_RADS * 100);
		mpu_data->gyroZ = (int16_t)(((float)rawGyroZ) / gyro_scale * DPS_TO_RADS * 100);
	}
	return status;
}

void update_str(mpudata_t *mpu_data, mpu_display_t *mpu_display) {
	sprintf(mpu_display->accX, "%d.%02u", ((int)mpu_data->accX / 100), ((unsigned int)mpu_data->accX % 100));
	sprintf(mpu_display->accY, "%d.%02u", ((int)mpu_data->accY / 100), ((unsigned int)mpu_data->accY % 100));
	sprintf(mpu_display->accZ, "%d.%02u", ((int)mpu_data->accZ / 100), ((unsigned int)mpu_data->accZ % 100));

	sprintf(mpu_display->temp, "%d.%02u", ((int)mpu_data->temp / 100), ((unsigned int)mpu_data->temp % 100));

	sprintf(mpu_display->gyroX, "%d.%02u", ((int)mpu_data->gyroX / 100), ((unsigned int)mpu_data->gyroX % 100));
	sprintf(mpu_display->gyroY, "%d.%02u", ((int)mpu_data->gyroY / 100), ((unsigned int)mpu_data->gyroY % 100));
	sprintf(mpu_display->gyroZ, "%d.%02u", ((int)mpu_data->gyroZ / 100), ((unsigned int)mpu_data->gyroZ % 100));
}
