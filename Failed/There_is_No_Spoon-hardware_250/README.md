# Time to Take a Dump
#### hardware - 200


### Challenge
> This hardware seems to be more than meets the eye! Please help me figure out what it is doing!
NOTE: You need to fnish Time to Take a Dump first before you can attempt this challenge!

### Partial Solution
This is a continuation of [Time to Take a Dump](../../Solved/Time_to_Take_a_Dump-hardware_200).
Now we have gotten the flag `CrossCTF{Bas364_1z_hard}`, we can enter it. 

	Enter the secret password to login: CrossCTF{Bas364_1z_hard}
	Encoded string is:	
	Try again!

Hmm, it didn't work. If we look at the decoded hex string, there seems to be an unprintable character `0x0a` at the back

	43726f73734354467b4261733336345f317a5f686172647d0a

Enter that decoded hex into the arduino using PySerial and we can proceed to this challenge.

We get this output `You now have 3 seconds to press enter to skip:`. After skipping, we get this  `You now have 10 seconds to key in the flag:`

If I enter any string, it appears to be SHA256 hashed. Seeing the Arduino flash memory dump, we need to reverse the hash of `efd766dd64a91ac3c57d34dd10c115e7486bc24da2f50cfee3941dd7f9dc5e70` to proceed.

***This challenge was not solved as I got stuck here, since I didn't know how to reverse this hash.***

### Solution (Edit: 2017-07-02)
Now with the [Arduino program's source code](https://github.com/wongwaituck/crossctf-2017-finals-public/tree/master/hardware-challenges) up, I understand how it was intended to be solved.

When it comes to `You now have 3 seconds to press enter to skip:`, don't skip and wait for this message in the Klingon language to appear.

	 wa' 
	  pagh 
	  'oS Hoch wov
	 loSmaH loS 'emDaq De' mej vegh cha'maH Soch 'emDaq De' mej vegh

Run it through Bing translator, which happens to have Klingon - English:
	
	One
	zero
	All marker light
	fifty two behind the apparent exit go through it was the apparent go through thirty-the exit

Now, from this we understand that we there is something on the Arduino's digital pin 52 and pin 30. Upon conencting LEDs, we can see a long sequence of rapid blinking.

I used an Arduino Uno to detect the pulses using falling edge. The interrupt pins available on the Uno are pins 2 and 3. (See [`falling-edge-detector.ino`](./solver/falling-edge-detector.ino))
I connected Mega Pin 30 to Uno Pin 2 and Mega Pin 52 to Uno Pin 3.

Let's start reading the pulses and write the result to a file. Run `There_is_No_Spoon.py` and [`ReadSerialToFile.py`](./solver/ReadSerialToFile.py)
After about 5 min, I got the result in [`output.txt`](./solver/output.txt)
Since there are 2 LEDs, we do not know which one is 1 and 0. So try both combinations, and the following is the working one. 
	
	cat output.txt | tr "A" "0" | tr "B" "1" > output2.txt 

Finally, with [`output2.txt`](./solver/output2.txt), paste it into [any spoon interpreter](http://www.dcode.fr/spoon) and we get the flag
	
	CrossCTF{0n3z_N_Z3r0z}