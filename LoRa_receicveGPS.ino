#include <SPI.h>
#include <LoRa.h>
#include "fromL.h"

float ch = C24;  //C24~C38
int i = 0;

void setup() { //定型文
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(ch)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  int packetSize = LoRa.parsePacket();  //パケットを受信できたか確認．受信した場合はパケットのサイズを，できていない場合は0を返す

  if (packetSize) { //受信できているか確認
    Serial.print(i);
    i = i + 1;
    if(i >= 10){
      i = 0;
    }

    Serial.print(": Received packet : ");  //受信したことを知らせる

    while (LoRa.available()) {  //パケットに読みとれるバイトが残っている間，それを読み取り続ける
      Serial.print((char)LoRa.read());  //順にキャストしてプリント
    }
    Serial.print("  : by ");
    Serial.print(ch/1000000);
    Serial.print("MHz : with RSSI ");  //受信側のRSSI（受信強度）をプリント
    Serial.println(LoRa.packetRssi());  //同上
  }
}
