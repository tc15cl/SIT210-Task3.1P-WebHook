/*
 * Project SIT210 Task3.1P - Webhook
 * Description: Create webhook between particle & thingspeak
 * Author: tjcook (214014891)
 * Date: 27/03/2020
 */


//Library for SI1145 UV sensor
#include <Adafruit_SI1145.h>

//reference Adafruit SI1145 UV sensor library class
Adafruit_SI1145 uv = Adafruit_SI1145();

//float variables for UV data
float UVVis;
float UVIR;
float UVIdx;


//Call UV sensor library method uv.begin()
void setup() 
{
  uv.begin();
}


//Call getUV and publish functions
void loop() 
{
    getUV();
    publishData(); 
}


//Function to read UV data from sensor
void getUV()
{
    UVVis = uv.readVisible();
    UVIR = uv.readIR();
    UVIdx = uv.readUV();
    UVIdx /= 100.0;
}


//Function to publish data every 30 seconds
void publishData()
{
  Particle.publish("UV", "{ \"UVVis\": \"" + String(UVVis) + "\"," +
   "\"UVIR\": \"" + String(UVIR) + "\"," +
    "\"UVIdx\": \"" + String(UVIdx) + "\"}", PRIVATE); 
  delay(30000);
} 


