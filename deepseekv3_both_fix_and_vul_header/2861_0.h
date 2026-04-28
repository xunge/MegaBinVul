#include <stddef.h>

#define JSON_TYPE_ERROR (-1)

struct jsonparse_state {
    int depth;
    char vtype;
    char *stack;
};