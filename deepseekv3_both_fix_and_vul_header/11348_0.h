#include <stdlib.h>

#define JPC_CEILDIVPOW2(x, y) (((x) + (1 << (y)) - 1) >> (y))
#define QMFB_JOINBUFSIZE 128
#define JPC_QMFB_COLGRPSIZE 1

typedef int jpc_fix_t;

void *jas_alloc3(size_t, size_t, size_t);
void jas_free(void *);