#include <stdlib.h>
#include <string.h>

typedef struct pyc_object {
    int type;
    char *data;
} pyc_object;

#define TYPE_NONE 0
#define R_NEW0(x) calloc(1, sizeof(x))
#define R_FREE(x) free(x)