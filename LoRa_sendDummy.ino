#include <LoRa.h>
#include "LoRa_freq.h"

double x_double;
double y_double;
String send_data;

float ch = C24;  //C24~C38

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
  
  x_double = 35.686483;
  y_double = 139.759248;
  send_data = "latitude  = " + String(x_double, 9) + ", longitude = " + String(y_double, 9);

  // send packet
  LoRa.beginPacket();  //パケットの送信を開始
  LoRa.print(send_data);
  LoRa.endPacket();  //パケットの送信を終了
  Serial.print("LoRa.beginPacket  →  ");  
  Serial.print(send_data);
  Serial.print(" , by ");
  Serial.print(ch/1000000);
  Serial.println("MHz");

  delay(1000);
}
