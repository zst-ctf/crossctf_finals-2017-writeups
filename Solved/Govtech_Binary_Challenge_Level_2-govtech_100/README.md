# Govtech Binary Challenge 
#### Level 2 - 100

### Challenge
> There's more!
[File here](../Govtech_Binary_Challenge_Level_1-govtech_75/dist.zip)

### Solution

(This challenge uses the [same files as in Govtech Binary Challenge Level 1](../Govtech_Binary_Challenge_Level_1-govtech_75/dist-decompiled))

Referring to the `march_on` method in `NothingImportantHere.java`, we can see it takes a long time due to thread sleeps, randomised timings.
We can remove these unneeded code. See [solve.java](solve.java).

Compile it and run

	$ javac solve.java
	$ java solve

	<Output trimmed>

	Now on 29030
	Now on 29031
	flag2{000006e2cf249106e954a67d8865c7b2}

*Note: The flag is not in the format of `CrossCTF{}` which is really misleading.*