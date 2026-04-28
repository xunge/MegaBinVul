#include <stdlib.h>

typedef struct Reprog {
    void *start;
} Reprog;

typedef void* (*regalloc)(void*, void*);
extern regalloc default_alloc;