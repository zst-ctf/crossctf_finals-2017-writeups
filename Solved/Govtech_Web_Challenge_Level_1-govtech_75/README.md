# Govtech Web Challenge
#### Level 1 - 75

### Challenge
> Here's a crypto warmup for you!
[Challenge here](http://govtech-challenge.com/challenge/)

### Solution

This is seen on the webpage ([Cached pdf here](govtech-challenge.com_challenge_challenge1-first-puzzle.pdf)):

	The encodeded flag is: 
	BCBCBADABCABBABDBDCDBDBABCBBBCADBCCABBDDBAACBCABBDADBCBBADBABDDB 
	Clue 1: The first four characters are "fLaG".

	Any input entered will be encoded and displayed to help the challenger.

	Input flag:	_________________ [Submit]

It seems that every 4 letters represents an input letter. Since "Any input entered will be encoded and displayed to help the challenger", we can bruteforce each printable ASCII char to get the output (See `getLetters.py`)

	$ python3 getLetters.py > letters.txt

Now, we have a lookup table of each char. Let's take the input flag and decode it.

	$ python3 getFlag.py
	fLaG{tech_Base4}

*Note: The flag is not in the format of `CrossCTF{}`*