/*
 * Distance and altitude sensor class
 *    dist:
 *      yellow -> 16   (rxd)
 *      white  -> 17   (txd)
 *      red    -> 5v
 *      black  -> gnd
 *      
 *    altitude:
 *      SDA    -> 21
 *      SCL    -> 22
 */

#include <Wire.h>
#include <Adafruit_MPL3115A2.h>

enum statesRX
{
    ST_RX_HEADER=0,
    ST_RX_DATA,
    ST_RX_PROCESSMSG    
};

Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

unsigned char data[4]={};

void setup()
{
    Serial.begin(9600); //OUTPUT
    Serial1.begin(9600, SERIAL_8N1, 17, 16);
}

void loop()
{
  if (! baro.begin()) {
    Serial.println("Couldnt find sensor");
    return;
  }
   readDistance();
   readAltitude();
   readTemp();
   readPres();
   Serial.println(" ");

   delay(1000);
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
