#include <stddef.h>

typedef void* pointer;

typedef struct scheme {
    pointer NIL;
} scheme;

int is_pair(pointer p);
pointer cdr(pointer p);