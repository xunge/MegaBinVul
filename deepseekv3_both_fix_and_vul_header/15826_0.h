#include <stdlib.h>

typedef struct dict dict;
typedef struct dictIterator dictIterator;

struct dictIterator {
    dict *ht;
    long index;
    void *entry;
    void *nextEntry;
};

void *hiredis_safe_malloc(size_t size);