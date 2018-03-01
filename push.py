import serial
import requests

b = serial.Serial('/dev/cu.usbmodem1411')
while True:
    s = b.readline()
    x,y = s.rstrip('\n\r').split(',')
    di = {
        'a': str(x),
        'b': str(y)
    }
    print(requests.get('https://jeevan.glitch.me/insert', params=di).text)

