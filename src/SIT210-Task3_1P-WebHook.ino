/*
 * Project SIT210 Task3.1P - Webhook
 * Description: Create webhook between particle & thingspeak
 * Author: tjcook (214014891)
 * Date: 27/03/2020
 */


//Library for SI1145 UV sensor
#include <Adafruit_SI1145.h>

//reference Adafruit SI1145 UV sesnor library
Adafruit_SI1145 uv = Adafruit_SI1145();

//float variables for UV data
float UVVis;
float UVIR;
float UVIdx;


void setup() {
  while(! uv.begin()) {
    Serial.println("Didn't find Si1145");
    delay(1000);
  }

  Serial.println("OK!");
}

void loop() {
    getUV();
    publishData();
        
}


void getUV(){
    UVVis = uv.readVisible();
    UVIR = uv.readIR();
    UVIdx = uv.readUV();
    UVIdx /= 100.0;
}


//Function to publish 
void publishData(){
  Particle.publish("UV", "{ \"UVVis\": \"" + String(UVVis) + "\"," +
   "\"UVIR\": \"" + String(UVIR) + "\"," +
    "\"UVIdx\": \"" + String(UVIdx) + "\"}", PRIVATE); 
     //"\"key\": \"" + thingSpeakAPIKey + "\" +
      //"\"channel\": \"" + thingSpeakChan + "\"}", PRIVATE);  
  delay(30000);
} 


