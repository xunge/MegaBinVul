#include <stdlib.h>

#define DICT_OK 1
#define DICT_ERR 0

typedef struct dictEntry {
    void *key;
    void *val;
    struct dictEntry *next;
} dictEntry;

typedef struct dict {
    dictEntry **table;
    unsigned long size;
    unsigned long used;
} dict;

int _dictKeyIndex(dict *ht, void *key);
void dictSetHashKey(dict *ht, dictEntry *entry, void *key);
void dictSetHashVal(dict *ht, dictEntry *entry, void *val);