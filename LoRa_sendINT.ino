#include <LoRa.h>
#include "LoRa_freq.h"

int send_data = 0;

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
  send_data += 1;
  if(send_data >= 10){
    send_data = 0;
  }
  
  // send packet
  LoRa.beginPacket();  //パケットの送信を開始
  LoRa.print(send_data);
  LoRa.endPacket();  //パケットの送信を終了
  Serial.print("LoRa.beginPacket  →  ");  
  Serial.println(send_data);
  Serial.print(" , by ");
  Serial.print(ch/1000000);
  Serial.print("MHz");
  Serial.println("LoRa.endPacket");
}
