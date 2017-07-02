import serial, string, sys
from select import select

def readline():
    """Reads a line of input from user non-blockingly
 
    Returns:
        False or input if exists
    """
    i, o, e = select([sys.stdin], [], [], 0.0001)
    for s in i:
        if s == sys.stdin:
            input = sys.stdin.readline()
            return input
    return False
 
s = serial.Serial('/dev/tty.usbmodemFA131', 9600, timeout=1)

# CrossCTF{Bas364_1z_hard}
# there is an unprintable char 0x0a at the back
secret = "43726f73734354467b4261733336345f317a5f686172647d0a".decode("hex")
out = s.readline()
s.write(secret)

while True:
	out = s.readline()
	print ">>", out
	if "Enter the secret password to login:" in out:
		s.write(secret)
		print secret

	if "You now have 3 seconds to press enter to skip:" in out:
		s.write("\n")
		#pass
	if "You now have 10 seconds to key in the flag:" in out:
		#s.write("efd766dd64a91ac3c57d34dd10c115e7486bc24da2f50cfee3941dd7f9dc5e70" + "\n")
		s.write("CrossCTF{oS_Hoch_wov_fifty_cha}" + "\n")
		# TO GET: efd766dd64a91ac3c57d34dd10c115e7486bc24da2f50cfee3941dd7f9dc5e70


		# SHA256 
		# crack -> 94F94C9C97BFA92BD267F70E2ABD266B069428C282F30AD521D486A069918925
		# https://www.onlinehashcrack.com/hash-generator.php#res


	std_in = readline()
	if std_in is not False:
		s.write(std_in)


'''
hi
Encoded string is:	l5by9f/=
Try again!
Enter the secret password to login: 
'''