#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define MAYBE_CHECK_SIZE_OVERFLOW(size, max, ret) \
    do { \
        if ((size) > (max)) { \
            return (ret); \
        } \
    } while (0)

#define LOCAL static