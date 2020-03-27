// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_SI1145.h>

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
String thingSpeakChan = "1026924";

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
    "\"UVIdx\": \"" + String(UVIdx) + "\"," + 
     "\"key\": \"" + thingSpeakAPIKey + "\" +
      "\"channel\": \"" + thingSpeakChan + "\"}", PRIVATE);  
  delay(30000);
} 


