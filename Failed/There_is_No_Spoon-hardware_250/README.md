# Time to Take a Dump
#### hardware - 200


### Challenge
> This hardware seems to be more than meets the eye! Please help me figure out what it is doing!
NOTE: You need to fnish Time to Take a Dump first before you can attempt this challenge!

### Partial Solution
This is a continuation of [Time to Take a Dump](../Solved/Time_to_Take_a_Dump-hardware_200).
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
