import serial, string, sys
from select import select

import socket
import re

s = socket.socket()
s.connect(('192.168.0.31', 1350))

while True:
    data = s.recv(4096)
    if data != "":
        print("RECV>" + data)
        if "Level 1" in data and "Enter code:" in data:
        	s.send("I w@nn@ be the very best")

        elif "Level 3" in data:
        	


'''
hi
Encoded string is:	l5by9f/=
Try again!
Enter the secret password to login: 
'''