#include <stdlib.h>

typedef struct dict dict;
typedef struct dictEntry dictEntry;

typedef struct dictIterator {
    dict *ht;
    long index;
    dictEntry *entry;
    dictEntry *nextEntry;
} dictIterator;