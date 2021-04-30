#include <BluetoothSerial.h>
#include <SPI.h>
#include "LedMatrix.h"
#include "BluetoothSerial.h"
#define NUMBER_OF_DEVICES 4 //number of led matrix connect in series
#define CS_PIN 15
#define CLK_PIN 14
#define MISO_PIN 2 //we do not use this pin just fill to match constructor
#define MOSI_PIN 12

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

int FLASH = 0;
char DIR = 'o';
char IN = ' ';
int ACTIVE = 0;
LedMatrix ledMatrix = LedMatrix(NUMBER_OF_DEVICES, CLK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
BluetoothSerial SerialBT;

void setup() {
  pinMode(19,OUTPUT);
  pinMode(18,OUTPUT);
  digitalWrite(18,LOW);
  digitalWrite(19,LOW);
  pinMode(25,INPUT);
  pinMode(26,INPUT);
  ledMatrix.init();
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  
}

void loop() {
//  if (Serial.available()) {
//    SerialBT.write(Serial.read());
//    //DIR = Serial.read();
//  }
//  if (SerialBT.available()) {
//    Serial.write(SerialBT.read());
//  }

IN = SerialBT.read();
 
if(IN == 'r' || IN == 'o' || IN == 'l')
{
  DIR = IN;
 
  
}
if(ACTIVE == 1 && (IN == 'r' || IN == 'l'))
{
  digitalWrite(19,!digitalRead(19));
  digitalWrite(18,!digitalRead(18));
}
if(IN == 'r' && ACTIVE == 0)
{
  ACTIVE = 1;
  digitalWrite(19,HIGH);
  digitalWrite(18,LOW);
}
if(IN == 'l' && ACTIVE == 0)
{
  ACTIVE = 1;
  digitalWrite(18,HIGH);
  digitalWrite(19,LOW);
  
}
if(IN == 'o')
{
  digitalWrite(18,LOW);
  digitalWrite(19,LOW);
  ACTIVE = 0;
}

if(digitalRead(25) == HIGH)
{
  digitalWrite(18,LOW);
  digitalWrite(19,LOW);
  ACTIVE = 0;
  DIR = 'o';
  SerialBT.write('x');
  SerialBT.write(13);
  SerialBT.flush();
}
if(digitalRead(26) == HIGH)
{
  ACTIVE = 0;
  digitalWrite(19,LOW);
  digitalWrite(18,LOW);
  DIR = 'o';
  SerialBT.write('x');
  SerialBT.write(13);
  SerialBT.flush();
}

  ledMatrix.clear();
//  ledMatrix.setPixel(5,5);
//
//  ledMatrix.setPixel(0,0);
//
//  ledMatrix.setPixel(-5,-5);

  if(FLASH == 0)
  {
   if(DIR == 'r')
   {
      ledMatrix.setText("   >");
      ledMatrix.setTextAlignment(TEXT_ALIGN_LEFT);
      ledMatrix.scrollTextRight();
      ledMatrix.scrollTextRight();
      ledMatrix.scrollTextRight();
      ledMatrix.scrollTextRight();
      ledMatrix.scrollTextRight();
      ledMatrix.drawText();
      ledMatrix.commit();
   }
   else if(DIR == 'l')
   {
      ledMatrix.setText("<");
      ledMatrix.setTextAlignment(TEXT_ALIGN_LEFT);
      ledMatrix.drawText();
      ledMatrix.commit();
   }
   else
   {
      ledMatrix.setText(" ");
      ledMatrix.setTextAlignment(TEXT_ALIGN_LEFT);
      ledMatrix.drawText();
      ledMatrix.commit();
   }
   FLASH = 1;
   
  }
  else
  {
  ledMatrix.setText(" ");
  ledMatrix.setTextAlignment(TEXT_ALIGN_LEFT);
  ledMatrix.drawText();
  ledMatrix.commit();
  FLASH = 0;
  }


//    ledMatrix.scrollTextLeft();
//// 
//    ledMatrix.drawText();
//    ledMatrix.commit();
  delay(300);
}
