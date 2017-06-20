# Sky Pillar
#### [Level 04] - 100


### Challenge
> 192.168.0.31:1350 Please start from level 01

### Solution
[The binary is from level 1](skypillar)

We must first get to level 4 using the flags. (Other levels done by my team members)

Level 1 `I w@ann@ be the very best`
Level 2 was taken out due to a bug
Level 3 `0@3Af`

We first decompiled the binary using [Retargetable Decompiler](https://retdec.com/decompilation/).

The level 4 code was extracted and I decided to [bruteforce the input number using Python](skypillar-part4-bruteforce.py).

But it was too slow, so I [did it using C](skypillar-part4-bruteforce.c).

Compile it and 
		
	...
	Doing 582
	Doing 583
	Doing 584
	Found! 63245986

Hence, enter `584` to get the flag!
