#!/usr/bin/env python3
import requests, string,re

SITE = "http://govtech-challenge.com/challenge/challenge1-first-puzzle.php"
ALP = string.printable

for letter in ALP:
    r = requests.post(SITE,
        data={
            'answer': letter, 
        })
    reply = r.text

    #Encoded input: BCBC 
    out = re.search("Encoded input: (....)", reply).group(1)
    print(letter + "\t"+out)