
import sys

v1 = int(sys.argv[1])


def rabbit_hole(a1):
	result1 = 1
	if a1 > 0:
		v1a = rabbit_hole(a1 - 2)
		result1 = rabbit_hole(a1 - 4) + v1a
	return result1

print rabbit_hole(v1/8)
result = rabbit_hole(v1/8) == 0x3c50ea2
print result