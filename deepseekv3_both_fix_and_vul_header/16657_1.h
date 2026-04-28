#include <stdint.h>

typedef int32_t l_int32;
typedef uint32_t l_uint32;

static const l_int32 xpostab[8] = {1, 1, 0, -1, -1, -1, 0, 1};
static const l_int32 ypostab[8] = {0, -1, -1, -1, 0, 1, 1, 1};
static const l_int32 qpostab[8] = {0, 1, 2, 3, 4, 5, 6, 7};

#define GET_DATA_BIT(line, x) (((line)[(x) >> 5] >> (31 - ((x) & 31))) & 1)