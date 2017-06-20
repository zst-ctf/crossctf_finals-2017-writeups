# Time to Take a Dump
#### hardware - 200


### Challenge
> There seems to be something running on the FREE arduino!
I wonder if I can talk to it...

### Solution
An Arduino Mega 2560 was provided with a program.

Opening a serial monitor, we see this. We need to enter the secret password, the flag, to proceed to the next level.
	
	Enter the secret password to login: CrossCTF{\n\r
	Encoded string is:	vI2QjIy8q7mEo5Gjjf/=
	Try again!
	Enter the secret password to login: 

First we need to retrieve the firmware. I took a long time figuring out that the programmer must be set to `wiring` and not `arduino` with a baud rate of `115200`.

	cd ./Dump
	./copy-firmware.sh

Next, we need to get a hex dump of the flash memory.
	
	avr-objdump -s -m atmega2560 backup-arduino-flash.hex > backup-arduino-flash.hex.txt

From the dump, we can see a few strings relevant to this level.
- `CrassCTF{TH1Z_i5_tH3_3asi3s7_CTF_evar}` which is a fake flag
- `/+9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA` which is the custom base-64 alphabet table (Didn't know until someone else hinted it to me.)
- `vI2QjIy8q7mEvZ6MzMnLoM6FoJeejZuC9f/=` which is the encoded string

We need to [decode base-64 with a non-standard slphabet table](http://www.overclock.net/t/1475505/python-base64-encoding-with-a-non-standard-alphabet). (See `custom-base64.py`)

	$ custom-base64.py 
	CrossCTF{Bas364_1z_hard}

*Alternatively, use [this website](https://www.malwaretracker.com/decoder_base64.php)*
Custom key of `/+9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA`
And data of `vI2QjIy8q7mEvZ6MzMnLoM6FoJeejZuC9f/=`
