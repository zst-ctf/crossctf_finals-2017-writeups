import serial
import string, sys, time
s = serial.Serial('/dev/tty.usbmodemFA131', 9600, timeout=1)



characters = string.ascii_letters + string.punctuation 
permutations = []

# Get all permutations possible with the characters
a = characters
for y in xrange(1):
	a = [x+i for i in characters for x in a]
permutations = a

def reverse(s):
	return s[::-1]
#        vI2QjIy8q7mEvZ6MzMnLoM6FoJeejZuC9f/=
CHECK = "vI2QjIy8q7mEvZ6Mz"
PRE="CrossCTF{Bas"

# For each of the possibilities, run it through md5
# and check if it is equal to our target.
# Break out and print once it is correct

for each in permutations:
	doable = True
	while doable:
		out = s.readline()
		print ">>", out
		if "Try again!" in out: #or "Encoded string " in out:
			doable = False
		elif "Enter the secret password to login: " in out:
			s.write(PRE+ (each) + "}\n\r")
			print "TRIED:", each
		elif len(out.strip()) == 0:
			s.write("a\n\r")
		if CHECK in out:
			print "DERP! -> ", each
			sys.exit()


'''
hi
Encoded string is:	l5by9f/=
Try again!
Enter the secret password to login: 
'''