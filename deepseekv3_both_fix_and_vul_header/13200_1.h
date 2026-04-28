#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

typedef int nxt_int_t;

struct nxt_str_s {
    u_char  *start;
    size_t  length;
};

typedef struct nxt_str_s nxt_str_t;

struct njs_vm_s {
    void *mem_pool;
};

typedef struct njs_vm_s njs_vm_t;

#define NXT_OK 0
#define NXT_ERROR -1

#define NJS_MODULE_START ""
#define NJS_MODULE_END ""

#define nxt_length(s) (sizeof(s) - 1)

static inline void *nxt_mp_alloc(void *pool, size_t size) {
    return malloc(size);
}

static inline void nxt_mp_free(void *pool, void *p) {
    free(p);
}

static inline u_char *nxt_cpymem(u_char *dst, const u_char *src, size_t n) {
    return (u_char *)memcpy(dst, src, n) + n;
}