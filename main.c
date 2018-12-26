#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "types.h"

int16_t push_random(int16_t a, int16_t b, random_state_t *r);

int main(void) {
	random_state_t r;

	random_init(&r, 0xac, 0, 0x7ffe);

	for (u8 i=0; i<10; i++)
		printf("0x%x\n", push_random(0, 0x7fff, &r) & 1);


	return 0;
}

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

    //int32_t rrand = ((int32_t)random_next(r) << 15) + random_next(r);
		int16_t rrand = random_next(r);
    rrand = rrand % range + min;
    return rrand;
}
