#!/usr/bin/env python3

FLAG = "BCBCBADABCABBABDBDCDBDBABCBBBCADBCCABBDDBAACBCABBDADBCBBADBABDDB"

with open("letters.txt", "r") as f:
	txt = f.read()

def splitEveryN(line, n = 4):
	return [line[i:i+n] for i in range(0, len(line), n)]

flag_list = splitEveryN(FLAG)

for eachletter in flag_list:
    for line in txt.split("\n"):
        if eachletter in line:
        	# 7	ADBD
        	print(line.split("\t")[0], end="")
