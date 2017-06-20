import serial
s = serial.Serial('/dev/tty.usbmodemFA131', 9600, timeout=5)

import string



characters = list(string.ascii_letters)#['a', 'b', 'c']
permutations = []

# Get all permutations possible with the characters
a = characters
for y in xrange(14):
    a = [x+i for i in characters for x in a]
permutations = a

# For each of the possibilities, run it through md5
# and check if it is equal to our target.
# Break out and print once it is correct

for each in permutations:
	while true:
		out = s.readline()
		print ">>", out
		if "Try again!" in out or "Encoded string " in out:
			pass
		elif "Enter the secret password to login: " in out:
			s.write(each)
			print "TRIED:", each
		else:
			print "Out at ", each
			sys.exit()


'''
hi
Encoded string is:	l5by9f/=
Try again!
Enter the secret password to login: 
'''