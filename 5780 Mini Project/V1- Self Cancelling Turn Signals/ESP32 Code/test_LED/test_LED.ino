#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>

#include <Adafruit_MPL3115A2.h>

#include <ESP32TimerInterrupt.h>
#include <ESP32_ISR_Timer.h>
#include "driver/pcnt.h"
#include <BluetoothSerial.h>
#include <SPI.h>
#include <Wire.h>
//#include "LedMatrix.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "BluetoothSerial.h"
//#include "timer.h"

#define ALT_DATA_PIN 21
#define ALT_CLOCK_PIN 22
#define OBJ_DET_RX_PIN 16
#define OBJ_DET_TX_PIN 17
#define LEFT_INPUT_PIN 10
#define RIGHT_INPUT_PIN 11
#define LEFT_OUTPUT_PIN 14
#define RIGHT_OUTPUT_PIN 15
#define CANCEL_PIN 10
#define MISO_PIN 2 //we do not use this pin just fill to match constructor
#define MOSI_PIN 12
#define TACH_PIN 35
#define PCNT_CTRL_PIN 4
hw_timer_t * timer = NULL;
bool lightlock = 0;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
int wheelsize = 29;
volatile int timecount = 0;
volatile int rotationtime = 1;
int previousrpm = 0;
//volatile int movespeed = 1;
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

enum statesRX
{
    ST_RX_HEADER=0,
    ST_RX_DATA,
    ST_RX_PROCESSMSG    
};
unsigned char data[4]={};
int FLASH = 0;
char DIR = 'o';
char IN = ' ';
int ACTIVE = 0;
//LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CLK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();
BluetoothSerial SerialBT;

//void IRAM_ATTR onTime() {
//   portENTER_CRITICAL_ISR(&timerMux);
//   timecount++;
//   portEXIT_CRITICAL_ISR(&timerMux);
//}

//Timecount is going to be in 1/100 of a second
//void IRAM_ATTR isr(){
//  if(timecount >= 15 && timecount <= 600)
//  {
//    
//    rotationtime = timecount;
//    //Serial.println(timecount);
//    //Serial.println(rotationtime);
//    timecount = 1; 
//    
//  }
//}

//rotationtime is in seconds/rotation
//first convert to rotations/second by taking 1/rotationtime
//then convert rotations/second to rpm by multiplying by 60
//Vehicle speed = Wheels RPM * Tire diameter * π * 60 / 63360
//int calculaterpm(int rotime){
//  
//  if(rotime < 500)
//  {
//     
//    float timed = ((float)rotime)/ 100.0;
//    float rps = 1/timed;
//    return (int)(60 * rps);
//    
//  }
//  else
//  {
//    return 0;
//  }
//  //Serial.println(rotationtime);
//   //Serial.println("rpm is " + movespeed);
//   //Serial.println("");
//}

int calculaterpm()
{
  pcnt_counter_clear(PCNT_UNIT_0);
  pcnt_counter_resume(PCNT_UNIT_0);
  TickType_t time_start = xTaskGetTickCount();
  int16_t count = 0;
  while((count < 1) && (xTaskGetTickCount()-time_start < 3000))
  {
    pcnt_get_counter_value(PCNT_UNIT_0, &count);
  }

  if(count == 0)
  {
    return 0;
  }
  pcnt_counter_pause(PCNT_UNIT_0);
  TickType_t time_end = xTaskGetTickCount()-time_start;

  float rpms = 1/(float)(int)time_end;
  float rps = rpms * 1000;
  float rpm = rps * 60;
  
  
  return (int)rpm;
  
}


void setup() {

  gpioInit();
  //ledMatrix.init();
  Serial.begin(9600);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial1.begin(9600, SERIAL_8N1, OBJ_DET_TX_PIN, OBJ_DET_RX_PIN);
  
//  timer = timerBegin(0, 80, true);
//  timerAttachInterrupt(timer, &onTime, true);
//  timerAlarmWrite(timer, 10000, true);
//  timerAlarmEnable(timer);
//  attachInterrupt(TACH_PIN, isr, RISING);

  pcntInit();
  
}

void gpioInit()
{

  pinMode(ALT_DATA_PIN, INPUT);
  pinMode(ALT_CLOCK_PIN, INPUT);
  pinMode(OBJ_DET_RX_PIN, INPUT);
  pinMode(OBJ_DET_TX_PIN, OUTPUT);
  pinMode(LEFT_INPUT_PIN, INPUT);
  pinMode(RIGHT_INPUT_PIN, INPUT);
  pinMode(LEFT_OUTPUT_PIN, OUTPUT);
  pinMode(RIGHT_OUTPUT_PIN, OUTPUT);
  pinMode(CANCEL_PIN, INPUT);
  pinMode(TACH_PIN, INPUT);
}


void pcntInit()
{
   pcnt_config_t pcnt_config = {0};
        // Set PCNT input signal and control GPIOs
        pcnt_config.pulse_gpio_num = TACH_PIN;
        pcnt_config.ctrl_gpio_num = PCNT_CTRL_PIN;
        pcnt_config.channel = PCNT_CHANNEL_0;
        pcnt_config.unit = PCNT_UNIT_0;
        // What to do on the positive / negative edge of pulse input?
        pcnt_config.pos_mode = PCNT_COUNT_INC;   // Count up on the positive edge
        pcnt_config.neg_mode = PCNT_COUNT_DIS;   // Keep the counter value on the negative edge
        // What to do when control input is low or high?
        pcnt_config.lctrl_mode = PCNT_MODE_KEEP; // Reverse counting direction if low
        pcnt_config.hctrl_mode = PCNT_MODE_KEEP;    // Keep the primary counter mode if high
        // Set the maximum and minimum limit values to watch
        pcnt_config.counter_h_lim = 400;
        pcnt_config.counter_l_lim = 0;

        pcnt_unit_config(&pcnt_config);

        pcnt_set_filter_value(PCNT_UNIT_0, 200);
        pcnt_filter_enable(PCNT_UNIT_0);
    
        pcnt_counter_pause(PCNT_UNIT_0);
        pcnt_counter_clear(PCNT_UNIT_0);
}

void doTachometerStuff()
{
  int rpm = calculaterpm();
  String spd = String(rpm);
  Serial.println(spd + " rpm");

  SerialBT.write('r');
  SerialBT.write('p');
  SerialBT.write('m');
  SerialBT.write(' ');
  for(int i = 0; i < spd.length(); i++)
  {
    SerialBT.write(spd[i]);
  }
  //Serial.println();
  SerialBT.write(13);
  SerialBT.flush();
}
void doAltimiterStuff()
{
  if (! baro.begin()) {
    Serial.println("Couldnt find sensor");
    return;
  }
   readAltitude();
   readTemp();
   readPres();
   Serial.println(" ");
}

void readPres(){
  float pascals = baro.getPressure();
  Serial.print("Pressure = ");
  Serial.print(pascals/3377); 
  Serial.println(" Inches (Hg)");  
}

void readTemp(){
  float tempC = baro.getTemperature();
  Serial.print("Temperature = ");
  Serial.print(tempC); 
  Serial.println(" °C"); 
}

void readAltitude(){
  float altm = baro.getAltitude();
  Serial.print("Elevation = ");
  Serial.print(altm);
  Serial.println(" m");
}

void readDistance(){
   static uint8_t
        stateRX = ST_RX_HEADER,
        rxIdx;
        
    if( Serial1.available() > 0 )
    {
        do
        {
            uint8_t ch = Serial1.read(); 
            switch( stateRX )
            {
                case    ST_RX_HEADER:
                    if( ch == 0xff )
                    {
                        rxIdx = 0;
                        data[rxIdx++] = ch;
                        stateRX = ST_RX_DATA;
                        
                    }//if
                    
                break; 

                case    ST_RX_DATA:
                        data[rxIdx++] = ch;
                        if( rxIdx == 4 )
                        stateRX = ST_RX_PROCESSMSG;
                break;

                case    ST_RX_PROCESSMSG:
                        uint8_t sum = 0;
                        for( uint8_t i=0; i<3; i++ )
                        sum = sum + data[i];

                        if( sum == data[3] ){
                            uint16_t distance = ((uint16_t)data[1] << 8) + data[2];
                            if( distance > 30 ){
                                Serial.print("Distance = ");
                                Serial.print(distance/10);
                                Serial.println(" cm");
                                return;
                            }
                            else{
                                Serial.println("Distance below lower limit.");     
                            }
                        }
                        else{
                            Serial.println("Msg checksum error.");
                        }
                        stateRX = ST_RX_HEADER;
                break;
                
            }//switch
            
        }while( Serial1.available() > 0 );
        
    }
}

void doTurnSignalStuff()
{
  //IN = SerialBT.read();
// 
//if(IN == 'r' || IN == 'o' || IN == 'l')
//{
//  DIR = IN;
// 
//  
//}
//if(ACTIVE == 1 && (IN == 'r' || IN == 'l'))
//{
//  digitalWrite(19,!digitalRead(19));
//  digitalWrite(18,!digitalRead(18));
//}
//if(IN == 'r' && ACTIVE == 0)
//{
//  ACTIVE = 1;
//  digitalWrite(19,HIGH);
//  digitalWrite(18,LOW);
//}
//if(IN == 'l' && ACTIVE == 0)
//{
//  ACTIVE = 1;
//  digitalWrite(18,HIGH);
//  digitalWrite(19,LOW);
//  
//}
//if(IN == 'o')
//{
//  digitalWrite(18,LOW);
//  digitalWrite(19,LOW);
//  ACTIVE = 0;
//}
//
//if(digitalRead(25) == HIGH)
//{
//  digitalWrite(18,LOW);
//  digitalWrite(19,LOW);
//  ACTIVE = 0;
//  DIR = 'o';
//  SerialBT.write('x');
//  SerialBT.write(13);
//  SerialBT.flush();
//}
//if(digitalRead(26) == HIGH)
//{
//  ACTIVE = 0;
//  digitalWrite(19,LOW);
//  digitalWrite(18,LOW);
//  DIR = 'o';
//  SerialBT.write('x');
//  SerialBT.write(13);
//  SerialBT.flush();
//}
//
//  
}


void loop() {
  doTachometerStuff();
  doAltimiterStuff();
  readDistance();
  doTurnSignalStuff();
//  if (Serial.available()) {
//    SerialBT.write(Serial.read());
//    //DIR = Serial.read();
//  }
//  if (SerialBT.available()) {
//    Serial.write(SerialBT.read());
//  }



  delay(200);
}
