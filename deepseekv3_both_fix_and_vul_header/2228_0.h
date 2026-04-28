#include <stdlib.h>
#include <string.h>

typedef struct _xmlHashEntry xmlHashEntry;
typedef struct _xmlHashTable xmlHashTable;
typedef xmlHashTable *xmlHashTablePtr;

struct _xmlHashEntry {
    void *data;
    const char *name;
    const char *name2;
    const char *name3;
    xmlHashEntry *next;
};

struct _xmlHashTable {
    void *dict;
    int size;
    int nbElems;
    xmlHashEntry *table;
};

void *xmlMalloc(size_t size);
void xmlFree(void *ptr);