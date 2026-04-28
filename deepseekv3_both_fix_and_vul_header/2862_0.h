#include <stddef.h>

struct jsonparse_state {
    int depth;
    char *stack;
};