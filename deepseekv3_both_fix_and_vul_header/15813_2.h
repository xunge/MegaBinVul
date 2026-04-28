#include <stdlib.h>

typedef struct dict dict;
typedef struct dictType dictType;

struct dict {
    dictType *type;
    void *privDataPtr;
};

static void _dictInit(dict *ht, dictType *type, void *privDataPtr) {
    ht->type = type;
    ht->privDataPtr = privDataPtr;
}