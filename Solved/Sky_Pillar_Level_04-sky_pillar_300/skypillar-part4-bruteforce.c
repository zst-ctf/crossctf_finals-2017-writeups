#include <stdio.h>
#include <stdint.h>


int32_t rabbit_hole(int32_t a1){
	int32_t result1 = 1;
	if (a1 > 0) {
		int32_t v1a = rabbit_hole(a1 - 2);
		result1 = rabbit_hole(a1 - 4) + v1a;
	}
	return result1;
}

void main(void) {
	int64_t v1;
	
	for (v1 = 0; v1 < 0xFFFFFFFF; v1++) {
		printf("Doing %d\n", v1);
		int32_t val = rabbit_hole(v1 / 8);
		int32_t result = (val == 0x3c50ea2);
		if (result) {
			printf("Found! %d\n", val);
			break;
		}
	}
}


