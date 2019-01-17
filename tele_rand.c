#include "tele_rand.h"

#define znew (r->z=36969*(r->z&65535)+(r->z>>16))
#define wnew (r->w=18000*(r->w&65535)+(r->w>>16))
#define MWC ((znew<<16)+wnew )
#define SHR3 (r->jsr^=(r->jsr<<17), r->jsr^=(r->jsr>>13), r->jsr^=(r->jsr<<5))
#define CONG (r->jcong=69069*r->jcong+1234567)
#define KISS ((MWC^CONG)+SHR3)

void tele_rand_init(tele_rand_t *r, u32 seed)
{
	r->z = 1823672;
	r->w = 19827873;
	r->jsr = 199887;
	r->jcong = seed;
	r->seed = seed;
}

u32 tele_rand_next(tele_rand_t *r)
{
	return KISS;
}
