#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

#define float32_t float
#define float64_t double
// Address range: 0x8048c5d - 0x8048ce1
int32_t ayylmao(float32_t a1) {
    // 0x8048ce0
    return 0x5f3759df - (int32_t) a1 / 2;
}


int32_t levelfive(void) {
    int32_t v1 = 20; // 0x8048ce9
    int32_t v2 = 3; // bp-56
    // branch -> 0x8048d5f
    /*
    for (int32_t i = 0; i < 5; i++) {
        // 0x8048d5f
        printf("Doing %d with current val = %p\n", i, *(&v2 + 4 + 8 * i));
        scanf("%f", (float64_t *)(&v2 + 4 + 8 * i));
        printf("Doing %d with after val = %p\n", i, *(&v2 + 4 + 8 * i));

        // continue -> 0x8048d5f
    }*/
    // 0x8048deb
    int32_t v3;
    int32_t v4 = &v3; // 0x8048d94
    int32_t v5 = 0;
    // branch -> 0x8048d91
    while (true) {
        int32_t v6 = 8 * v5; // 0x8048d94
        
        int32_t g1 = ayylmao(*(float32_t *)(v4 - 48 + v6));
        float64_t v7 = round(0.0); // 0x8048db4
        int32_t v8 = g1; // 0x8048dd8

        int32_t v9 = *(int32_t *)(v6 - 52 + v8); // 0x8048dd8
        int32_t v10 = v5 + 1; // 0x8048de7
        printf("v9=%d\n",v9);
        printf("v10=%d\n",v10);
        printf("v6=%d\n",v6);

        if (v7 == v9) {
            // 0x8048deb
            if (v10 >= 5) {
                // break -> 0x8048df6
                break;
            }
            v4 = v8;
            v5 = v10;
            // continue -> 0x8048d91
            continue;
        }
        // 0x8048df6
        // 0x8048e07
        return 0;
    }
    // 0x8048df6
    // 0x8048e07
    return 1;
}


int main(void)
{
    setbuf(stdout, NULL);
    levelfive();
    return 0;
}