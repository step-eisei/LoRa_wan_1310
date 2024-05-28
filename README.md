mkr wan 1310 (LoRa通信モジュール)のArduinoIDE用プログラム  
mkr wan 1310用のライブラリ「LoRa.h」が必要．  
インストール手順
- https://www.arduinolibraries.info/libraries/lo-ra から最新のバージョンのzipファイルをインストール
- ArduinoIDEのツールバーの「Sketch」→「Include Library」→「Add .ZIP Library...」から先ほどのzipファイルを選択

「LoRa」は通信方式のこと  
「mkr wan 1310」はモジュール名  
- LoRa_sendGPS.ino：ラズパイからuartで座標情報を取得してそれを送信する．
  　　　　　　　　　　uartで送られてくる座標情報は「x座標,y座標」と，カンマで区切ること．
- LoRa_senGPS.h：周波数設定用ヘッダーファイル．
  　　　　　　　　特に気にしなくていい
- LoRa_receiveGPS.ino：送信機から送られてくる座標情報を取得する．
  　　　　　　　　　　　 RSSI(受信強度)も同時に表示する．
- LoRa_receive.h：LoRa_sendGPS.hと同じ
