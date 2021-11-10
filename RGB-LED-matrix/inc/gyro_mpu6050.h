#ifndef __GYRO_MPU6050_H
#define __GYRO_MPU6050_H
#define MPU6050_I2CADDR_DEFAULT 0x68 ///< MPU6050 default i2c address w/ AD0 high
#define MPU6050_DEVICE_ID 0x68 ///< The correct MPU6050_WHO_AM_I value

#define MPU6050_SELF_TEST_X 0x0D ///<  bits 7-5 are XA_TEST[4-2] and bits 4-0 are XG_TEST[4-0]
#define MPU6050_SELF_TEST_Y 0x0E ///<  bits 7-5 are YA_TEST[4-2] and bits 4-0 are YG_TEST[4-0]
#define MPU6050_SELF_TEST_Z 0x0F ///<  bits 7-5 are ZA_TEST[4-2] and bits 4-0 are ZG_TEST[4-0]
#define MPU6050_SELF_TEST_A 0x10 ///<  bits 7-6 reserved, 5-4 XA_TEST[1-0], 3-2 YA_TEST[1-0], 1-0 ZA_TEST[1-0]
#define MPU6050_SMPLRT_DIV 0x19  ///< sample rate divisor register
#define MPU6050_CONFIG 0x1A      ///< General configuration register bits 5-3 EXT_SYN_SET[2:0], bits 2-0 DLPF_CFG[2:0]
#define MPU6050_GYRO_CONFIG 0x1B ///< Gyro specfic configuration register, only bits 4-3 are FS_SEL[1:0]
#define MPU6050_ACCEL_CONFIG 0x1C ///< Accelerometer specific configration register, bits[7:3] XA_ST, YA_ST, ZA_ST, AFS_SEL[1:0]
#define MPU6050_INT_PIN_CONFIG 0x37    ///< Interrupt pin configuration register
#define MPU6050_INT_EN 0x38 		///< Int enable register, bit4 is FIFO_OFLOW_EN, bit3 is I2C_MST_INT_EN, bit0 DATA_RDY_EN
#define MPU6050_INT_STATUS 			///< Int status register, bit0 is DATA_RDY_INT

#define MPU6050_WHO_AM_I 0x75          ///< Divice ID register
#define MPU6050_SIGNAL_PATH_RESET 0x68 ///< Signal path reset register
#define MPU6050_USER_CTRL 0x6A         ///< FIFO and I2C Master control register
#define MPU6050_PWR_MGMT_1 0x6B        ///< Primary power/sleep control register
#define MPU6050_PWR_MGMT_2 0x6C ///< Secondary power/sleep control register
#define MPU6050_TEMP_H 0x41     ///< Temperature data high byte register
#define MPU6050_TEMP_L 0x42     ///< Temperature data low byte register
#define MPU6050_ACCEL_OUT 0x3B  ///< base address for accelerometer data reads
#define MPU6050_GYRO_OUT 0x43	///< base address for gyro data reads


#define GRAVITY (9.80665F)
#define DPS_TO_RADS (0.017453293F)

#include "stm32f4xx_hal.h"

static const uint8_t MPU_I2C_ADDR = 0x68 << 1;  // Use 8-bit address

//**************************************************** enums **********************************************************************

/**
 * @brief FSYNC output values
 *
 * Allowed values for `setFsyncSampleOutput`.
 */
typedef enum fsync_out {
  MPU6050_FSYNC_OUT_DISABLED,
  MPU6050_FSYNC_OUT_TEMP,
  MPU6050_FSYNC_OUT_GYROX,
  MPU6050_FSYNC_OUT_GYROY,
  MPU6050_FSYNC_OUT_GYROZ,
  MPU6050_FSYNC_OUT_ACCELX,
  MPU6050_FSYNC_OUT_ACCELY,
  MPU6050_FSYNC_OUT_ACCEL_Z,
} mpu6050_fsync_out_t;

/**
 * @brief Clock source options
 *
 * Allowed values for `setClock`.
 */
typedef enum clock_select {
  MPU6050_INTR_8MHz,
  MPU6050_PLL_GYROX,
  MPU6050_PLL_GYROY,
  MPU6050_PLL_GYROZ,
  MPU6050_PLL_EXT_32K,
  MPU6050_PLL_EXT_19MHz,
  MPU6050_STOP = 7,
} mpu6050_clock_select_t;

/**
 * @brief Accelerometer range options
 *
 * Allowed values for `setAccelerometerRange`.
 */
typedef enum {
  MPU6050_RANGE_2_G = 0b00,  ///< +/- 2g (default value)
  MPU6050_RANGE_4_G = 0b01,  ///< +/- 4g
  MPU6050_RANGE_8_G = 0b10,  ///< +/- 8g
  MPU6050_RANGE_16_G = 0b11, ///< +/- 16g
} mpu6050_accel_range_t;

/**
 * @brief Gyroscope range options
 *
 * Allowed values for `setGyroRange`.
 */
typedef enum {
  MPU6050_RANGE_250_DEG,  ///< +/- 250 deg/s (default value)
  MPU6050_RANGE_500_DEG,  ///< +/- 500 deg/s
  MPU6050_RANGE_1000_DEG, ///< +/- 1000 deg/s
  MPU6050_RANGE_2000_DEG, ///< +/- 2000 deg/s
} mpu6050_gyro_range_t;

/**
 * @brief Digital low pass filter bandthwidth options
 *
 * Allowed values for `setFilterBandwidth`.
 */
typedef enum {
  MPU6050_BAND_260_HZ, ///< Docs imply this disables the filter
  MPU6050_BAND_184_HZ, ///< 184 Hz
  MPU6050_BAND_94_HZ,  ///< 94 Hz
  MPU6050_BAND_44_HZ,  ///< 44 Hz
  MPU6050_BAND_21_HZ,  ///< 21 Hz
  MPU6050_BAND_10_HZ,  ///< 10 Hz
  MPU6050_BAND_5_HZ,   ///< 5 Hz
} mpu6050_bandwidth_t;

/**
 * @brief Periodic measurement options
 *
 * Allowed values for `setCycleRate`.
 */
typedef enum {
  MPU6050_CYCLE_1_25_HZ, ///< 1.25 Hz
  MPU6050_CYCLE_5_HZ,    ///< 5 Hz
  MPU6050_CYCLE_20_HZ,   ///< 20 Hz
  MPU6050_CYCLE_40_HZ,   ///< 40 Hz
} mpu6050_cycle_rate_t;


typedef struct {
	mpu6050_cycle_rate_t cycle_rate;
	mpu6050_bandwidth_t bandwidth;
	mpu6050_gyro_range_t gyro_range;
	mpu6050_accel_range_t accel_range;
	mpu6050_clock_select_t clock_select;
	//mpu6050_fsync_out_t fsync_out; always use default for now
}mpu6050_cfg;

typedef struct {
	float accX;
	float accY;
	float accZ;
	float temp;
	float gyroX;
	float gyroY;
	float gyroZ;
} mpudata_t;

typedef struct {
	char accX[14];
	char accY[14];
	char accZ[14];
	char temp[14];
	char gyroX[14];
	char gyroY[14];
	char gyroZ[14];
}mpu_display_t;

// *********************************************** functions ******************************************************************


mpu6050_accel_range_t get_accel_range(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef set_accel_range(I2C_HandleTypeDef *hi2c, mpu6050_accel_range_t accel_range);

mpu6050_gyro_range_t get_gyro_range(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef set_gyro_range(I2C_HandleTypeDef *hi2c, mpu6050_gyro_range_t gyro_range);

HAL_StatusTypeDef set_clock(I2C_HandleTypeDef *hi2c, mpu6050_clock_select_t clk_sel);
mpu6050_clock_select_t get_clock(I2C_HandleTypeDef *hi2c);

HAL_StatusTypeDef set_filter_bandwidth(I2C_HandleTypeDef *hi2c, mpu6050_bandwidth_t bandwidth);
mpu6050_bandwidth_t get_filter_bandwidth(I2C_HandleTypeDef *hi2c);

HAL_StatusTypeDef set_cycle_rate(I2C_HandleTypeDef *hi2c, mpu6050_cycle_rate_t rate);
mpu6050_cycle_rate_t get_cycle_rate(I2C_HandleTypeDef *hi2c);

HAL_StatusTypeDef init_mpu6050(I2C_HandleTypeDef *hi2c, mpu6050_cfg *cfg);
HAL_StatusTypeDef reset_mpu6050(I2C_HandleTypeDef *hi2c);

HAL_StatusTypeDef read_mpu6050(I2C_HandleTypeDef *hi2c, mpudata_t *mpu_data, mpu6050_cfg *mpu_cfg);
void update_str(mpudata_t *mpu_data, mpu_display_t *mpu_display);

//void setSampleRateDivisor(uint8_t);
//uint8_t getSampleRateDivisor(void);
//void setFsyncSampleOutput(mpu6050_fsync_out_t fsync_output);
//mpu6050_fsync_out_t getFsyncSampleOutput(void);
//void setInterruptPinPolarity(bool active_low);
//bool enableSleep(bool enable);
//bool enableCycle(bool enable);

#endif
