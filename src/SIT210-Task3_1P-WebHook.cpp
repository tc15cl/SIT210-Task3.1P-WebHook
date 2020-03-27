/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "d:/GDRIVE/School/DEVIT_UNI/2020_T1/SIT210/OnTrack/SIT210-03.1P/SIT210-Task3_1P-WebHook/src/SIT210-Task3_1P-WebHook.ino"
// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_SI1145.h>

void setup();
void loop();
void getUV();
void publishData();
#line 4 "d:/GDRIVE/School/DEVIT_UNI/2020_T1/SIT210/OnTrack/SIT210-03.1P/SIT210-Task3_1P-WebHook/src/SIT210-Task3_1P-WebHook.ino"
const int MAXRETRY = 4; //
const uint32_t msSAMPLE_INTERVAL = 2500;
const uint32_t msMETRIC_PUBLISH = 30000;
const int TEMPPIN = D2;
const int FLOWPIN = A0;
const int MOIST1PIN = A1;

//UV: 
Adafruit_SI1145 uv = Adafruit_SI1145();

float UVVis;
float UVIR;
float UVIdx;
String thingSpeakAPIKey = "S27LXW5LQALI7PO4";

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



void publishData(){
  //Particle.publish( "UV", String(UVVis), 60, PRIVATE);
  Particle.publish("UV", "{ \"UVVis\": \"" + String(UVVis) + "\"," +
   "\"UVIR\": \"" + String(UVIR) + "\"," +
    "\"UVIdx\": \"" + String(UVIdx) + "\"," + 
     "\"key\": \"" + thingSpeakAPIKey + "\" }", PRIVATE);  
  delay(30000);
} 


