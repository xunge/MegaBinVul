#include <stdint.h>
#include <stdlib.h>

typedef struct intset {
    uint32_t encoding;
    uint32_t length;
    int8_t contents[];
} intset;

static uint32_t intrev32ifbe(uint32_t v);
void *zrealloc(void *ptr, size_t size);