import readchar
import serial
import threading
import time

# My Arduino Duemilanove appears as /dev/tty.usbserial-A6008lDt
# My cheapo USB serial adapter appears as /dev/tty.usbserial-A50285BI
# I'm using cu instead of tty because that's what Arduino IDE does :shrug:

s = serial.Serial('/dev/cu.usbserial-A50285BI', baudrate=9600, timeout=0.1)
s_lock = threading.Lock()

def background_read_task():
    print("Beginning background task to poll the serial port...")
    while True:
        with s_lock:
            r = s.read_all()
            if r:
                print(f"Read from Arduino: {r}")
        time.sleep(0.05)

thread = threading.Thread(target=background_read_task, daemon=True)
thread.start()


while True:
    key = readchar.readkey()

    if key == 'q':
        print("Quitting! Thanks :)")
        break
    
    with s_lock:
        print(f'Pressed key: {key}. Sending to Arduino')
        s.write(key.encode('ascii'))

