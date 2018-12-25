#ifndef _RANDOM_H_
#define _RANDOM_H_

typedef uint32_t u4;
typedef struct ranctx { u4 a; u4 b; u4 c; u4 d; } ranctx;

#define rot(x,k) (((x)<<(k))|((x)>>(32-(k))))

extern u4 ranval( ranctx *x );

extern void raninit( ranctx *x, u4 seed );

#endif /* _RANDOM_H_ */
