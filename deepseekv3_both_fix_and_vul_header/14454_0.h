#include <stdlib.h>

typedef struct {
    int ga_itemsize;
    int ga_growsize;
} garray_T;

void ga_init(garray_T *gap);