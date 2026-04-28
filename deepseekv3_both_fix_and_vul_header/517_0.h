#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int version;
    long start;
} xref_t;

#define ERR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)