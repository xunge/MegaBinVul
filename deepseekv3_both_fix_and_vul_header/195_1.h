#include <stdlib.h>
#include <string.h>

struct uni_pagedir {
    unsigned short **uni_pgdir[32];
    unsigned long sum;
};

#define GFP_KERNEL 0
#define ENOMEM 12

static void *kmalloc_array(size_t n, size_t size, int flags) {
    return calloc(n, size);
}

static void kfree(void *p) {
    free(p);
}

typedef unsigned short u_short;
typedef unsigned short u16;