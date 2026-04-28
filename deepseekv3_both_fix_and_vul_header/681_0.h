#include <string.h>
#include <stddef.h>

#define MAP_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
#define MINIMUM(a, b) ((a) < (b) ? (a) : (b))
#define ULL_ALIGNMENT_WIDTH sizeof(unsigned long long)
#define UL_ALIGNMENT_WIDTH sizeof(unsigned long)
#define U_ALIGNMENT_WIDTH sizeof(unsigned)