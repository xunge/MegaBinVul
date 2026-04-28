#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct keyword {
    char *string;
    int active;
    struct keyword *sub;
} keyword_t;

typedef struct vector {
    size_t size;
    void **data;
} vector_t;

size_t vector_size(vector_t *v);
void *vector_slot(vector_t *v, size_t idx);