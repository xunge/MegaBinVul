#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SDS_MAX_PREALLOC (1024*1024)
#define SDS_TYPE_5 0
#define SDS_TYPE_8 1
#define SDS_TYPE_MASK 7

typedef char* sds;

struct __attribute__ ((__packed__)) sdshdr5 {
    unsigned char flags;
    char buf[];
};
struct __attribute__ ((__packed__)) sdshdr8 {
    uint8_t len;
    uint8_t alloc;
    unsigned char flags;
    char buf[];
};

size_t sdsavail(sds s);
size_t sdslen(sds s);
size_t sdsHdrSize(char type);
char sdsReqType(size_t string_size);
void* s_realloc(void *ptr, size_t size);
void* s_malloc(size_t size);
void s_free(void *ptr);
void sdssetlen(sds s, size_t newlen);
void sdssetalloc(sds s, size_t newlen);