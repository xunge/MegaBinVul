#include <stdio.h>
#include <stdlib.h>

typedef int code_int;

#define CUR_BITS_FINISHED (-1)
#define MAXCODE(n_bits) ((1 << (n_bits)) - 1)

typedef struct {
    int cur_bits;
    long cur_accum;
    int n_bits;
    int free_ent;
    int maxcode;
    int clear_flg;
    int g_init_bits;
    code_int EOFCode;
} GifCtx;

extern int maxbits;
extern int maxmaxcode;
extern unsigned long masks[];
extern void char_out(unsigned int c, GifCtx *ctx);
extern void flush_char(GifCtx *ctx);