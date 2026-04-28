#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef char *sds;

#define SDS_TYPE_5 0
#define SDS_TYPE_8 1
#define SDS_TYPE_MASK 7
#define SDS_MAX_PREALLOC (1024*1024)

size_t sdsavail(sds s);
size_t sdslen(sds s);
size_t sdsHdrSize(char type);
char sdsReqType(size_t len);
void sdssetlen(sds s, size_t len);
void sdssetalloc(sds s, size_t len);
void *s_realloc(void *ptr, size_t size);
void *s_malloc(size_t size);
void s_free(void *ptr);