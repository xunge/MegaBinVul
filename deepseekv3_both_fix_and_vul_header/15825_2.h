#include <stdlib.h>

typedef struct dict dict;
typedef struct dictType dictType;

struct dict {
    dictType *type;
    void *privDataPtr;
};

void _dictInit(dict *ht, dictType *type, void *privDataPtr);
void *hiredis_safe_malloc(size_t size);