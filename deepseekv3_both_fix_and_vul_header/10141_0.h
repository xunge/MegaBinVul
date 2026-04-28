#include <assert.h>
#include <stdio.h>

#define JAS_ONES(n) ((1UL << (n)) - 1)

typedef struct jpc_bitstream_s jpc_bitstream_t;

int jpc_bitstream_putbit(jpc_bitstream_t *bitstream, int bit);