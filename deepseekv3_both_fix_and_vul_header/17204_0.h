#include <stdlib.h>
#include <string.h>

struct response {
    const char *data;
    const char **headers;
};

#define xnew0(type) ((type *)calloc(1, sizeof(type)))
#define DO_REALLOC(ptr, size, newsize, type) \
    do { \
        size = newsize; \
        ptr = (type *)realloc(ptr, size * sizeof(type)); \
    } while (0)