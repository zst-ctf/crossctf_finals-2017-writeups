#!/usr/bin/env python
## http://stackoverflow.com/a/11747381
## http://stackoverflow.com/questions/5297448/how-to-get-md5-sum-of-a-string

import hashlib
import sys
import string

target_hash = "efd766dd64a91ac3c57d34dd10c115e7486bc24da2f50cfee3941dd7f9dc5e70"
characters = string.ascii_letters + string.digits + string.punctuation
permutations = []

# Get all permutations possible with the characters
a = characters
for y in xrange(1):
    a = [x+i for i in characters for x in a]
permutations = a

# For each of the possibilities, run it through md5
# and check if it is equal to our target.
# Break out and print once it is correct
for each in permutations:
	print "Trying", each
    if hashlib.sha256(each).hexdigest() == target_hash:
        print each
        sys.exit()