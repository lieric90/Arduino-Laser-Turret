import keyboard
import serial

arduino = serial.Serial(port='COM3', baudrate= 9600, timeout=0, write_timeout = 0)

while True:
    if keyboard.read_key() == "a":
        arduino.write(b'a')
    if keyboard.read_key() == "d":
        arduino.write(b'd') 
    if keyboard.read_key() == "w":
        arduino.write(b'w')
    if keyboard.read_key() == "s":
        arduino.write(b's')