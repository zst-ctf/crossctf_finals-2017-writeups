#!/usr/bin/env python
import serial, string, sys
 
f = open("output.txt", "w")
s = serial.Serial('/dev/tty.usbmodemFD121', 9600, timeout=5)
while True:
	out = s.readline().strip()
	print ">>", out
	f.write(out)
	f.flush()