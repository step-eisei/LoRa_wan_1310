import lora
import time
import struct
import sys

# チャンネル定義（C24~C38の周波数に相当する値をHz単位で指定）
channel_frequencies = {
    'C24': 920600000,  # 920.6 MHz
    'C25': 920800000,  # 920.8 MHz
    'C26': 921000000,  # 921.0 MHz
    'C27': 921200000,  # 921.2 MHz
    'C28': 921400000,  # 921.4 MHz
    'C29': 921600000,  # 921.6 MHz
    'C30': 921800000,  # 921.8 MHz
    'C31': 922000000,  # 922.0 MHz
    'C32': 922200000,  # 922.2 MHz
    'C33': 922400000,  # 922.4 MHz
    'C34': 922600000,  # 922.6 MHz
    'C35': 922800000,  # 922.8 MHz
    'C36': 923000000,  # 923.0 MHz
    'C37': 923200000,  # 923.2 MHz
    'C38': 923400000,  # 923.4 MHz
}

# 初期周波数設定
ch = channel_frequencies['C24']
i = 0

lr = lora.LoRa()

def printable(l):
    x = struct.unpack(str(len(l)) + 'b', l)
    y = ''
    for i in range(len(x)):
        if x[i] >= 0:
            y = y + chr(x[i])
    return y

def setFrequencyAndMode(freq):
    lr.write('config\r\n')
    lr.s.flush()
    time.sleep(0.2)
    lr.reset()
    time.sleep(1.5)

    # 周波数の設定
    sendcmd('rfreq %d\r\n' % freq)
    
    # スプレッディングファクタ(SF)を7に設定
    sendcmd('sf 7\r\n')
    
    # 帯域幅(BW)を125kHzに設定
    sendcmd('bw 125\r\n')

    sendcmd('w\r\n')

    lr.reset()
    print('LoRa module set to frequency: %.1f MHz, SF: 7, BW: 125kHz' % (freq / 1000000))
    time.sleep(1)

def sendcmd(cmd):
    lr.write(cmd)
    t = time.time()
    while (True):
        if (time.time() - t) > 5:
            print('panic: %s' % cmd)
            exit()
        line = lr.readline()
        if 'OK' in printable(line):
            return True
        elif 'NG' in printable(line):
            return False

def receivePacket():
    global i
    lr.write('listen\r\n')  # 受信モードに入る
    time.sleep(0.2)

    line = lr.readline(timeout=10)  # パケットを受信
    if len(line) > 0:
        i += 1
        if i >= 10:
            i = 0

        print(f'{i}: Received packet : {printable(line)}')

        # RSSI値を取得
        rssi = lr.get_rssi()
        print(f'  : by {ch / 1000000} MHz : with RSSI {rssi}')
    else:
        print("No packet received")

# メイン処理ループ
setFrequencyAndMode(ch)  # 初期周波数、SF、BWをセット

while True:
    receivePacket()
    time.sleep(1)
