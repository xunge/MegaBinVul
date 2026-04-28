#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t __be32;
typedef uint32_t u32;

struct nfsd4_compoundargs {
    __be32 *p;
    __be32 *end;
    u32 pagelen;
    void **pagelist;
    __be32 tmp[1];
    __be32 *tmpp;
};

#define PAGE_SIZE 4096
#define XDR_QUADLEN(len) (((len) + 3) >> 2)
#define GFP_KERNEL 0

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline void *page_address(void *page) {
    return page;
}