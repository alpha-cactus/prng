#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "tele_rand.h"

//int16_t push_random(int16_t a, int16_t b, random_state_t *r);

#define CNT 9
u32 random_cnt[CNT];

int main(void) {
	tele_rand_t r;
	tele_rand_init(&r, 1123);

	for (u32 i=0; i<0xF; i++) {
		u32 v = tele_rand_next(&r);
		printf("%u:\t%u\n", v, v&1);
	}

	printf("\n");
	tele_rand_init(&r, 1123);

	for (u32 i=0; i<0xF; i++) {
		u32 v = tele_rand_next(&r);
		printf("%u:\t%u\n", v, v&1);
	}

	return 0;
}

/*
int16_t push_random(int16_t a, int16_t b, random_state_t *r) {
    int16_t min, max;

    if (a < b) {
        min = a;
        max = b;
    }
    else {
        min = b;
        max = a;
    }
    int32_t range = max - min + 1;
    if (range == 0 || min == max) return min;

    int32_t rrand = (int32_t)random_next(r);
    rrand = rrand % range + min;
    return rrand;
}
*/
