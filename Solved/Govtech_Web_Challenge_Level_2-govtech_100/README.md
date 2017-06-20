# Govtech Web Challenge
#### Level 2 - 100

### Challenge
> This is a game of Tic-Tac-Toe. There are some messages encoded in Tic-Tac-Toe format. Please help us decipher it!
[Challenge here](http://govtech-challenge.com/challenge/)

### Solution

We must first login with the first flag to see the page `fLaG{tech_Base4}`
([Screenshot of the page](screencapture-govtech-challenge-challenge-challenge1-second-puzzle.png))


This challenges uses XOR to get the hex ASCII of the letter (as seen in the truth table)

For the winning line for `a`, we take `1^4^3 = 4` and `0^7^6 = 1` to get `0x41`
For the winning line for `i`, we take `1^4^3 = 4` and `0^7^6 = 1` then add `8` to get `0x49` 
(Since the clue says `Circle = 0, Cross = 1`, we add a binary 1 to the 4th position,`1 << 3 = 8`)

Doing for all winning lines, we get the following

	47 6f 76 54 65 63 68 7b 41 46 43 7d
	GovTech{AFC}

But the flag is actually `GovTech{ABC}` when I bruteforced it. In short, the XOR table is slightly different because `1^1^1 = 1` but the last line shows `0`, hence we have to consider it.

*Note: The flag is not in the format of `CrossCTF{}`*

