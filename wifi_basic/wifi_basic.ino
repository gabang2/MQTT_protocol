#include <SoftwareSerial.h> 

int RX = 2;
int TX = 3;
SoftwareSerial ESP_wifi(RX, TX); 

void setup() { 
  Serial.begin(9600);  //아두이노 우노 보드레이트 115200
  ESP_wifi.begin(9600);   //와이파이 모듈 보드레이트 115200
  ESP_wifi.setTimeout(5000); 
  delay(1000); 
} 

void loop() { 
  if (Serial.available()){ 
    ESP_wifi.write(Serial.read()); 
  } 
  if (ESP_wifi.available()) { 
    Serial.write(ESP_wifi.read()); 
  }
}
