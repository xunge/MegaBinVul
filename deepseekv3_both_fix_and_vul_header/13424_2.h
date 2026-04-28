#include <stdlib.h>
#include <stdio.h>

#define override
#define llvm_unreachable(msg) \
    do { \
        fprintf(stderr, "%s\n", msg); \
        abort(); \
    } while (0)