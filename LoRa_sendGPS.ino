#include <LoRa.h>
#include "LoRa_freq.h"

double x_double;
double y_double;
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
    
    x_double = atof((Serial1.readStringUntil(',')).c_str());
    y_double = atof((Serial1.readStringUntil('\n')).c_str());
    send_data = "latitude  = " + String(x_double, 9) + ", longitude = " + String(y_double, 9); //小数点以下10桁で丸める

    // send packet
    LoRa.beginPacket();  //パケットの送信を開始
    LoRa.print(send_data);
    LoRa.endPacket();  //パケットの送信を終了
    Serial.print("LoRa.beginPacket  →  ");  
    Serial.print(send_data);
    Serial.print(" , by ");
    Serial.print(ch/1000000);
    Serial.println("MHz");
  }
}
