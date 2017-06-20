import serial
s = serial.Serial('/dev/tty.usbmodemFD121', 9600, timeout=0.5)

import string


''''
characters = list(string.ascii_letters)#['a', 'b', 'c']
permutations = []

# Get all permutations possible with the characters
a = characters
for y in xrange(14):
    a = [x+i for i in characters for x in a]
permutations = a
'''
# For each of the possibilities, run it through md5
# and check if it is equal to our target.
# Break out and print once it is correct

CHECK = "vI2QjIy8q7mEvZ"
PRE="CrossCTF{"

#ascii_list = list(string.ascii_letters)
ascii_list = list(string.printable)
ascii_list_len = len(ascii_list)
count = 0
while True:
	out = s.readline()
	print ">>", out
	if count >= len(ascii_list):
		print "Bye!"
		sys.exit()

	each = ascii_list[count]
	if "Try again!" in out: #or "Encoded string " in out:
		count += 1
	elif "Enter the secret password to login: " in out:
		s.write(PRE+each + "}\n\r")
		print "TRIED:", each
	elif len(out.strip()) == 0:
		s.write("a\n\r")
	if CHECK in out:
		print "DERP! -> ", each


'''
hi
Encoded string is:	l5by9f/=
Try again!
Enter the secret password to login: 
'''