# The Great Bank Heist!
#### hardware - 400


### Challenge
> The arduino is generating OTPs! Can we use it to break a bank?
> The bank server is running at 127.0.0.1:1343.
> NOTE: You need to finish There is No Spoon first before you can attempt this challenge!

This challenge is a continuation of [Time to Take a Dump](../../Solved/Time_to_Take_a_Dump-hardware_200) and [There is No Spoon](../There_is_No_Spoon-hardware_250).

### Partial Solution (Post-Competition: 2017-07-30)
Note: These were done after looking at the [Arduino and the server OTP program source code](https://github.com/wongwaituck/crossctf-2017-finals-public/tree/master/hardware-challenges).

After entering the earlier flags in the Arduino, we see this in serial.

    Proceed to the next stage ;)
    <<CROSSCTF OTP DEMO>>
    Loading key from program memory...
    Decrypting key...
    Random challenge generated: 793802
    Full OTP generated: 37943a9c54278c8c3ecab87ec6093ab01d03048886dc1e01acc54d8ca003c5fc

OTPs are being generated after loading and decrypting key from program memory (EEPROM).

[Looking at the EEPROM dump, we see these 2 possibilities](../../Solved/Time_to_Take_a_Dump-hardware_200/Dump/backup-arduino-eeprom.hex.txt).
(The other bytes are all 0xFF, meaning it was unset)

	0240 796f7520 68617665 68652073 65637265  you havehe secre
	0250 65203c33 ffffffff ffffffff ffffffff  e <3............

and 
	
	0680 8cc607db 42a77edb 88cef517 f5eaf823  ....B.~........#

According to the source code, we need to decrypt the key from the EEPROM using XOR. We also need to take note of the key size
In the source code, we see this. (I'm not sure how to obtain these through the flash dump, and I feel it is frighteningly difficult to retrieve without the source code  `:(`)

	const unsigned char XOR_KEY = 0x69;
	...
	const int KEY_SIZE = 32;

Let's decrypt it.

	''.join( chr( ord(ch) ^ 0x69 ) for ch in list("you havehe secree <3")).encode('hex')
	''.join( chr( ord(ch) ^ 0x69 ) for ch in list( "8cc607db42a77edb88cef517f5eaf823".decode('hex') )).encode('hex')

We get 2 possible decrypted keys.
	
	10061c4901081f0c010c491a0c0a1b0c0c49555a
	e5af6eb22bce17b2e1a79c7e9c83914a

Unfortunately, it is none of them. (What in the world) 
For comparison, this is the one provided in the OTP program.

	e5af6eb22bce17b27fd55ed32d72c6d4e1a79c7e9c83914acf8f33f512ae6907

Anyway, assuming we can get the key, run [The_Great_Bank_Heist-OTP_Server.py](The_Great_Bank_Heist-OTP_Server.py) and we get the flag.


	> WELCOME TO CROSSCTF BANK OTP SERVER
	> Challenge issued: 949343
	> Please enter the OTP: 96df5dd7898f9daac3e018bc33b401b6798d3b8276c442c911f26c5a67ea0c9a
	> 
	> Challenge issued: 252090
	> Please enter the OTP: c347d4a513e860cb8757c2e5ec25415fe8bc855353374c0ca47362bc22c90dca
	> 
	> Challenge issued: 449048
	> Please enter the OTP: 3080bf726c5d2540e5cd0f390f6b75e4c0bd12f8de6776f7288be6706e3e26d5
	> 
	> Challenge issued: 629664
	> Please enter the OTP: 95baa636f06d81e9c5d79c3490dc0cba3b4123144f4f536255a4faab8c11ec34
	> 
	> Challenge issued: 931427
	> Please enter the OTP: ca9bc7c22b1d13d25655ef8608d6404b6d049228388faad141941f1e93931118
	> 
	> Challenge issued: 643597
	> Please enter the OTP: 2d37a722f4b42e9e03242222cb7cc333b12d3ac119f462811969719738725d2a
	> 
	> Challenge issued: 015334
	> Please enter the OTP: 0a13d43de86cfcfd8a6a89180383eea320889c539b93f395eedd1101c371fc78
	> 
	> Challenge issued: 390594
	> Please enter the OTP: 11ee96d321022c78435cd432ac2dfbba53e22c20609a7c5810adcb5c0a969aa9
	> 
	> Challenge issued: 359547
	> Please enter the OTP: 707bdeafd435f2253d98e37334a9d4cfb6a8dd2ba120fb5bc7f6b8d95355abd5
	> 
	> Challenge issued: 931175
	> Please enter the OTP: be11e7fac61118a9e5d065f86f37b15f5473310d77502c48ab38ff6bd2352ba8
	> 
	> CrossCTF{F1N@11y_0TP_1Z_Br0k3N}

