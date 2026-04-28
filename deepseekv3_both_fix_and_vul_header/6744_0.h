#include <ctype.h>
#include <errno.h>
#include <stddef.h>

#define FALSE 0
#define TRUE 1

static const int maxExponent = 511;
static double powersOf10[] = {
    1e1, 1e2, 1e4, 1e8, 1e16, 1e32, 1e64, 1e128, 1e256
};