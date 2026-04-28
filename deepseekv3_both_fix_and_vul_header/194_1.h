#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct uni_pagedir {
    uint16_t **uni_pgdir[32];
    unsigned long sum;
};

typedef unsigned short u_short;
typedef uint16_t u16;

#define ENOMEM 12
#define GFP_KERNEL 0

static void *kmalloc_array(size_t n, size_t size, int flags) {
    return calloc(n, size);
}