######################################################
## FILE         :   fota.py
## DESCRIPTION  :   Python script to simulate the behaviour 
##                  of Esp8266 based on serial commands
## AUTHOR       :   Ahmed Sameh Saad
######################################################

import serial
import time
import requests

serial_port = "COM10"
baud_rate = 9600

ESP8266_Buffer = 0

def process_command(command):

    if command == b'AT\r\n':
        time.sleep(0.5)
        return b'OK\r\n'
        
    if command.startswith(b'AT+CWMODE='):
        time.sleep(0.5)
        return b'OK\r\n'
        
    if command.startswith(b'AT+CWJAP='):
        components = command[9:-1].split(b',')
        
        if len(components) == 2:
            ssid = components[0]
            password = components[1]
            return f'Command: AT+CWJAP, SSID: {ssid.decode()}, Password: {password.decode()}\r\n'.encode()
        
    if command.startswith(b'AT+CIPSTART='):
        components = command[12:-1].split(b',')
        
        if len(components) == 3:
            conType = components[0]
            remoteIp = components[1]
            remotePort = components[2]

            return f'Command: AT+CIPSTART, Type: {conType.decode()}, IP: {remoteIp.decode()}, Port: {remotePort.decode()},\r\n'.encode()

    if command.startswith(b'GET'):
        time.sleep(0.5)
        url = command.strip()[4:]
        response = requests.get(url)
        
        count = 0
        count2 = count

        for char in response.text:
           
            if (char == '\n'):
              #  print(count2)
                count+=1
                count2+=1
                
            ser.write(char.encode())
            
            if (count == 25):
                time.sleep(3)
                count = 0
                
        return f"DONE"#f"{response.text}"

try:
    ser = serial.Serial(serial_port, baud_rate, timeout=1)

    while True:
        command = ser.readline()
        if command:
            print("RX> ", command)
        
        response = process_command(command)

        if response:
            print("TX> ", response)
            if not command.startswith(b'GET'):
                ser.write(response)

finally:
    ser.close()
