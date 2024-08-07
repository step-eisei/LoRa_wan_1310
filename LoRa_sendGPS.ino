#include <LoRa.h>
#include "LoRa_freq.h"

String GPS_x;
String GPS_y;
String send_data;

float ch = C24;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  Serial.println("LoRa sender");
  if (!LoRa.begin(ch)) {  //C24~C38
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  if(Serial1.available() > 0){
    
    GPS_x = Serial1.readStringUntil(',');
    GPS_y = Serial1.readStringUntil('\n');
    send_data = "latitude  = " + GPS_x + ", longitude = " + GPS_y;

    // send packet
    LoRa.beginPacket();  //パケットの送信を開始
    LoRa.print(send_data);
    LoRa.endPacket();  //パケットの送信を終了
    Serial.print("LoRa.beginPacket  →  ");  
    Serial.print(send_data);
    Serial.print(" , by ");
    Serial.print(ch/1000000);
    Serial.print("MHz");
    //Serial.println("LoRa.endPacket");
  }
}
