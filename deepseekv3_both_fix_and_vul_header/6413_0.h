#include <stdlib.h>
#include <string.h>

typedef char *sds;

struct {
    sds cbuf;
} ldb;

size_t sdslen(sds s);
sds sdsdup(const sds s);
void sdsfree(sds s);
sds sdsnewlen(const void *init, size_t initlen);
void sdsfreesplitres(sds *tokens, int count);
void *zmalloc(size_t size);