#!/usr/bin/env python3
import requests, string,re,sys

SITE = "http://govtech-challenge.com/challenge/challenge1-second-puzzle.php?firstchallenge=base4"

characters = string.ascii_uppercase# + string.punctuation 
permutations = []

# Get all permutations possible with the characters
a = characters
for y in xrange(2):
	a = [x+i for i in characters for x in a]
permutations = a


for each in permutations:
	print("Trying " + each)
	r = requests.post(SITE,
		data={
			'answer': "GovTech{" + each + "}", 
		})
	reply = r.text
	if "Wrong answer" not in reply:
		print(reply)
		sys.exit()