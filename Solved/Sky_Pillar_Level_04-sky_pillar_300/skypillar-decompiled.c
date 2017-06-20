//
// This file was generated by the Retargetable Decompiler
// Website: https://retdec.com
// Copyright (c) 2017 Retargetable Decompiler <info@retdec.com>
//

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------------- Float Types Definitions ------------------

typedef float float32_t;
typedef double float64_t;

// ------------------------ Structures ------------------------

struct _IO_FILE {
    int32_t e0;
};

// ------------------- Function Prototypes --------------------

int32_t ayylmao(float32_t a1);
int32_t levelfive(void);
int32_t levelfour(void);
int32_t levelone(void);
int32_t levelthree(void);
int32_t magic(int32_t a1);
int32_t rabbit_hole(int32_t a1);

// --------------------- Global Variables ---------------------

int32_t g1 = 0; // ebp
struct _IO_FILE * g2 = NULL; // 0x804b060
int32_t g3 = 0; // 0x804b064

// ------------------------ Functions -------------------------

// Address range: 0x804873b - 0x804881f
int32_t levelone(void) {
    int32_t str2 = 0x40772049; // bp-73
    puts("====================================================================");
    puts("                          LEVEL 01                                  ");
    puts("====================================================================");
    printf("Enter code: ");
    int32_t str;
    fgets((char *)&str, 32, g2);
    strcspn((char *)&str, "\n");
    int32_t strcmp_rc = strcmp((char *)&str2, (char *)&str); // 0x80487f5
    if (*(int32_t *)20 != *(int32_t *)20) {
        // 0x8048819
        __stack_chk_fail();
        // branch -> 0x804881e
    }
    // 0x804881e
    return strcmp_rc == 0;
}

// Address range: 0x8048820 - 0x804886f
int32_t magic(int32_t a1) {
    int32_t v1 = 0x1000000 * a1;
    int32_t result = 0;
    if ((v1 || 0xffffff) >= 0x1ffffff) {
        int32_t v2 = v1 / 0x1000000; // 0x01014
        int32_t v3 = v2 % 2; // 0x804884e
        while (v2 >= 2) {
            // 0x8048847
            v2 /= 2;
            v3 += v2 % 2;
            // continue -> 0x8048847
        }
        // 0x8048854
        result = v3;
        // branch -> 0x804885a
    }
    // 0x804885a
    if (*(int32_t *)20 != *(int32_t *)20) {
        // 0x8048869
        __stack_chk_fail();
        // branch -> 0x804886e
    }
    // 0x804886e
    return result;
}

// Address range: 0x8048870 - 0x8048b5c
int32_t levelthree(void) {
    int32_t v1 = *(int32_t *)20; // 0x8048877
    puts("====================================================================");
    puts("                          LEVEL 03                                  ");
    puts("====================================================================");
    printf("Enter Code: ");
    int32_t v2;
    int32_t v3;
    int32_t v4;
    int32_t v5;
    int32_t v6;
    scanf("%c %c %c %c %c", &v6, &v5, &v4, &v3, &v2);
    int32_t v7 = magic(0x1000000 * v6 / 0x1000000); // 0x80488f0
    if (v7 != 3) {
        // 0x8048901
        if (v7 <= 3) {
            // 0x8048906
            if (v7 == 2) {
                // 0x8048930
                if (magic(0x1000000 * v5 / 0x1000000) == 1) {
                    goto lab_0x8048930;
                }
                // 0x80489ac
                // branch -> 0x8048b4a
            }
            // 0x8048b4a
            if (*(int32_t *)20 != v1) {
                // 0x8048b56
                __stack_chk_fail();
                // branch -> 0x8048b5b
            }
            // 0x8048b5b
            return 0;
        }
        // 0x804890d
        switch (v7) {
            case 4: {
                // 0x8048a46
                if (magic(0x1000000 * v5 / 0x1000000) == 2) {
                    goto lab_0x8048a5e_2;
                }
                // 0x8048abe
                // branch -> 0x8048b4a
                // 0x8048b4a
                if (*(int32_t *)20 != v1) {
                    // 0x8048b56
                    __stack_chk_fail();
                    // branch -> 0x8048b5b
                }
                // 0x8048b5b
                return 0;
            }
            case 5: {
                // 0x8048acf
                if (magic(0x1000000 * v5 / 0x1000000) == 5) {
                    goto lab_0x8048ae7_2;
                }
                // 0x8048b45
                // branch -> 0x8048b4a
                // 0x8048b4a
                if (*(int32_t *)20 != v1) {
                    // 0x8048b56
                    __stack_chk_fail();
                    // branch -> 0x8048b5b
                }
                // 0x8048b5b
                return 0;
            }
        }
        // 0x804891f
        // branch -> 0x8048b4a
        // 0x8048b4a
        if (*(int32_t *)20 != v1) {
            // 0x8048b56
            __stack_chk_fail();
            // branch -> 0x8048b5b
        }
        // 0x8048b5b
        return 0;
    }
  lab_0x80489bd_2:
    // 0x80489bd
    if (magic(0x1000000 * v5 / 0x1000000) != 3 || magic(0x1000000 * v4 / 0x1000000) != 5) {
        // 0x8048a35
        // branch -> 0x8048b4a
        // 0x8048b4a
        if (*(int32_t *)20 != v1) {
            // 0x8048b56
            __stack_chk_fail();
            // branch -> 0x8048b5b
        }
        // 0x8048b5b
        return 0;
    }
    // 0x80489ed
    if (magic(0x1000000 * v3 / 0x1000000) != 2) {
        // 0x8048a46
        if (magic(0x1000000 * v5 / 0x1000000) == 2) {
            goto lab_0x8048a5e_2;
        }
        // 0x8048abe
        // branch -> 0x8048b4a
        // 0x8048b4a
        if (*(int32_t *)20 != v1) {
            // 0x8048b56
            __stack_chk_fail();
            // branch -> 0x8048b5b
        }
        // 0x8048b5b
        return 0;
    }
    // 0x8048a05
    if (magic(0x1000000 * v2 / 0x1000000) != 2 || magic(0x1000000 * v5 / 0x1000000) != 1) {
        // 0x8048a21
        // branch -> 0x8048b4a
        // 0x8048b4a
        if (*(int32_t *)20 != v1) {
            // 0x8048b56
            __stack_chk_fail();
            // branch -> 0x8048b5b
        }
        // 0x8048b5b
        return 0;
    }
  lab_0x8048930:
    // 0x8048948
    if (magic(0x1000000 * v4 / 0x1000000) != 3) {
        // 0x8048acf
        if (magic(0x1000000 * v5 / 0x1000000) == 5) {
            goto lab_0x8048ae7_2;
        }
        // 0x8048b45
        // branch -> 0x8048b4a
        // 0x8048b4a
        if (*(int32_t *)20 != v1) {
            // 0x8048b56
            __stack_chk_fail();
            // branch -> 0x8048b5b
        }
        // 0x8048b5b
        return 0;
    }
    // 0x8048964
    if (magic(0x1000000 * v3 / 0x1000000) != 2) {
        // 0x80489a2
        // branch -> 0x8048b4a
        // 0x8048b4a
        if (*(int32_t *)20 != v1) {
            // 0x8048b56
            __stack_chk_fail();
            // branch -> 0x8048b5b
        }
        // 0x8048b5b
        return 0;
    }
    // 0x804897c
    if (magic(0x1000000 * v2 / 0x1000000) == 4) {
        // 0x8048998
        // branch -> 0x8048b4a
        // 0x8048b4a
        if (*(int32_t *)20 != v1) {
            // 0x8048b56
            __stack_chk_fail();
            // branch -> 0x8048b5b
        }
        // 0x8048b5b
        return 1;
    }
    // 0x8048a46
    if (magic(0x1000000 * v5 / 0x1000000) != 2) {
        // 0x8048abe
        // branch -> 0x8048b4a
        // 0x8048b4a
        if (*(int32_t *)20 != v1) {
            // 0x8048b56
            __stack_chk_fail();
            // branch -> 0x8048b5b
        }
        // 0x8048b5b
        return 0;
    }
  lab_0x8048a5e_2:
    // 0x8048a5e
    if (magic(0x1000000 * v4 / 0x1000000) != 1) {
        goto lab_0x80489bd_2;
    }
    // 0x8048a7a
    if (magic(0x1000000 * v3 / 0x1000000) != 5 || magic(0x1000000 * v2 / 0x1000000) == 1 || magic(0x1000000 * v5 / 0x1000000) != 5) {
        // 0x8048ab4
        // branch -> 0x8048b4a
        // 0x8048b4a
        if (*(int32_t *)20 != v1) {
            // 0x8048b56
            __stack_chk_fail();
            // branch -> 0x8048b5b
        }
        // 0x8048b5b
        return 0;
    }
  lab_0x8048ae7_2:
    // 0x8048ae7
    if (magic(0x1000000 * v4 / 0x1000000) != 3) {
        goto lab_0x8048930;
    }
    // 0x8048b03
    if (magic(0x1000000 * v3 / 0x1000000) == 5) {
        // 0x8048b1b
        if (magic(0x1000000 * v2 / 0x1000000) == 4) {
            goto lab_0x80489bd_2;
        }
        // 0x8048b37
        // branch -> 0x8048b4a
    }
    // 0x8048b4a
    if (*(int32_t *)20 != v1) {
        // 0x8048b56
        __stack_chk_fail();
        // branch -> 0x8048b5b
    }
    // 0x8048b5b
    return 0;
}

// Address range: 0x8048b5d - 0x8048bbf
int32_t rabbit_hole(int32_t a1) {
    int32_t result = 1;
    if (a1 > 0) {
        int32_t v1 = rabbit_hole(a1 - 2); // 0x8048b8c
        result = rabbit_hole(a1 - 4) + v1;
        // branch -> 0x8048baa
    }
    // 0x8048baa
    if (*(int32_t *)20 != *(int32_t *)20) {
        // 0x8048bb6
        __stack_chk_fail();
        // branch -> 0x8048bbb
    }
    // 0x8048bbb
    return result;
}

// Address range: 0x8048bc0 - 0x8048c5c
int32_t levelfour(void) {
    puts("====================================================================");
    puts("                          LEVEL 04                                  ");
    puts("====================================================================");
    printf("Enter Code: ");
    int32_t v1;
    scanf("%d", &v1);
    int32_t result = rabbit_hole(v1 / 8) == 0x3c50ea2;
    if (*(int32_t *)20 != *(int32_t *)20) {
        // 0x8048c56
        __stack_chk_fail();
        // branch -> 0x8048c5b
    }
    // 0x8048c5b
    return result;
}

// Address range: 0x8048c5d - 0x8048ce1
int32_t ayylmao(float32_t a1) {
    // 0x8048c5d
    if (*(int32_t *)20 != *(int32_t *)20) {
        // 0x8048cd9
        __stack_chk_fail();
        // branch -> 0x8048ce0
    }
    // 0x8048ce0
    int32_t v1;
    g1 = v1;
    return 0x5f3759df - (int32_t)a1 / 2;
}

// Address range: 0x8048ce2 - 0x8048e08
int32_t levelfive(void) {
    int32_t v1 = *(int32_t *)20; // 0x8048ce9
    int32_t v2 = 3; // bp-56
    puts("====================================================================");
    puts("                          LEVEL 05                                  ");
    puts("====================================================================");
    printf("Enter Code: ");
    // branch -> 0x8048d5f
    for (int32_t i = 0; i < 5; i++) {
        // 0x8048d5f
        scanf("%f", (float64_t *)((int32_t)&v2 + 4 + 8 * i));
        // continue -> 0x8048d5f
    }
    // 0x8048deb
    int32_t v3;
    int32_t v4 = &v3; // 0x8048d94
    int32_t v5 = 0;
    // branch -> 0x8048d91
    while (true) {
        int32_t v6 = 8 * v5; // 0x8048d94
        ayylmao(*(float32_t *)(v4 - 48 + v6));
        float64_t v7 = round(0.0); // 0x8048db4
        int32_t v8 = g1; // 0x8048dd8
        int32_t v9 = *(int32_t *)(v6 - 52 + v8); // 0x8048dd8
        int32_t v10 = v5 + 1; // 0x8048de7
        if ((int32_t)v7 == v9) {
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
        if (*(int32_t *)20 != v1) {
            // 0x8048e02
            __stack_chk_fail();
            // branch -> 0x8048e07
        }
        // 0x8048e07
        return 0;
    }
    // 0x8048df6
    if (*(int32_t *)20 != v1) {
        // 0x8048e02
        __stack_chk_fail();
        // branch -> 0x8048e07
    }
    // 0x8048e07
    return 1;
}

// Address range: 0x8048e09 - 0x8048fcf
int main(int argc, char ** argv) {
    // 0x8048e09
    if (ptrace(0) == -1) {
        // 0x8048e3a
        exit(0);
        // UNREACHABLE
    }
    // 0x8048e44
    setvbuf(g2, NULL, 2, 0);
    setvbuf((struct _IO_FILE *)g3, NULL, 2, 0);
    puts("                                 Welcome to                                    ");
    puts(" ______     __  __     __  __        ______   __     __         __         ______     ______");
    puts("/\\  ___\\   /\\ \\/ /    /\\ \\_\\ \\      /\\  == \\ /\\ \\   /\\ \\       /\\ \\       /\\  __ \\   /\\  == \\");
    puts("\\ \\___  \\  \\ \\  _\"-.  \\ \\____ \\     \\ \\  _-/ \\ \\ \\  \\ \\ \\____  \\ \\ \\____  \\ \\  __ \\  \\ \\  __<");
    puts(" \\/\\_____\\  \\ \\_\\ \\_\\  \\/\\_____\\     \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\");
    puts("  \\/_____/   \\/_/\\/_/   \\/_____/      \\/_/     \\/_/   \\/_____/   \\/_____/   \\/_/\\/_/   \\/_/ /_/");
    puts("================================================================================");
    puts("                    Home of the legendary Pokemon, Rayquaza                          ");
    puts("================================================================================");
    puts("There are 5 Levels to climb. Each level requires a specifc code to unlock the next level.");
    puts("Your goal is to reach the top, and catch the legendary Rayquaza... Good luck!");
    if (levelone() == 0) {
        // 0x8048f40
        exit(0);
        // UNREACHABLE
    }
    // 0x8048f25
    puts("CrossCTF{xxxxxxxxxxxxxxxxx}");
    if (levelthree() == 0) {
        // 0x8048f65
        exit(0);
        // UNREACHABLE
    }
    // 0x8048f4a
    puts("CrossCTF{xxxxxxxxxxxxxxxxx}");
    if (levelfour() == 0) {
        // 0x8048f8a
        exit(0);
        // UNREACHABLE
    }
    // 0x8048f6f
    puts("CrossCTF{xxxxxxxxxxxxxxxxx}");
    if (levelfive() == 0) {
        // 0x8048fb7
        exit(0);
        // UNREACHABLE
    }
    // 0x8048f94
    puts("CrossCTF{xxxxxxxxxxxxxxxxx}");
    if (*(int32_t *)20 != *(int32_t *)20) {
        // 0x8048fc1
        __stack_chk_fail();
        // branch -> 0x8048fc6
    }
    // 0x8048fc6
    return 0;
}

// --------------- Dynamically Linked Functions ---------------

// void __stack_chk_fail(void);
// void exit(int status);
// char * fgets(char * restrict s, int n, FILE * restrict stream);
// int printf(const char * restrict format, ...);
// long int ptrace(enum __ptracerequest __request, ...);
// int puts(const char * s);
// double round(double);
// int scanf(const char * restrict format, ...);
// int setvbuf(FILE * restrict stream, char * restrict buf, int modes, size_t n);
// int strcmp(const char * s1, const char * s2);
// size_t strcspn(const char * s, const char * reject);

// --------------------- Meta-Information ---------------------

// Detected compiler/packer: gcc (5.4.0)
// Detected functions: 8
// Decompiler release: v2.2.1 (2016-09-07)
// Decompilation date: 2017-06-18 03:13:50