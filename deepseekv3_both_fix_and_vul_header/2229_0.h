#include <stdlib.h>

typedef unsigned char xmlChar;
typedef struct _xmlHashTable xmlHashTable;
typedef xmlHashTable *xmlHashTablePtr;

struct _xmlHashTable {
    unsigned long size;
};