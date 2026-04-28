#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

typedef struct tree_t {
    struct tree_t *child;
    struct tree_t *next;
    uchar *data;
} tree_t;