#include <stdint.h>

#define JSONPARSE_MAX_DEPTH 100

struct jsonparse_state {
    char stack[JSONPARSE_MAX_DEPTH];
    int depth;
    int vtype;
};