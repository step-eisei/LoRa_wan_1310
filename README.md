mkr wan 1310 (LoRa通信モジュール)のArduinoIDE用プログラム  
mkr wan 1310用のライブラリ「LoRa.h」が必要．  
インストール手順
- https://www.arduinolibraries.info/libraries/lo-ra から最新のバージョンのzipファイルをインストール
- ArduinoIDEのツールバーの「Sketch」→「Include Library」→「Add .ZIP Library...」から先ほどのzipファイルを選択  

「LoRa」は通信方式のこと  
「mkr wan 1310」はモジュール名  
- LoRa_sendINT.ino：0~9の数字を順に送信する．
- LoRa_sendGPS.ino：ラズパイからuartで座標情報を取得して，それを送信する．  
  　　　　　　　　　uartで送る座標情報は「緯度,経度」のようにカンマで区切ること．
- LoRa_receive.ino：送信機から送られてくる情報を取得して表示する．  
  　　　　　　　　　　 RSSI(受信強度)も同時に表示する．
- LoRa_freq.h：周波数設定用ヘッダーファイル．  
  　　　　　　　 特に気にしなくていい
