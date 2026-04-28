#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

typedef struct simplestring {
    char* str;
    size_t len;
    size_t size;
} simplestring;

void simplestring_init_str(simplestring* target);