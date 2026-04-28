#include <stdlib.h>
#include <string.h>

struct bpf_prog {
    unsigned int len;
    void *bpf_func;
    int jited;
};

struct jit_ctx {
    unsigned int *offsets;
    struct bpf_prog *skf;
    unsigned int idx;
    unsigned int prologue_bytes;
    void *target;
};

#define GFP_KERNEL 0
#define kcalloc(n, size, flags) calloc(n, size)
#define kfree free
typedef void *ptr;

extern int bpf_jit_enable;
extern void *module_alloc(unsigned int size);
extern void flush_icache_range(void *start, void *end);
extern void bpf_jit_dump(unsigned int len, unsigned int alloc_size, int level, void *target);
extern int build_body(struct jit_ctx *ctx);
extern void build_prologue(struct jit_ctx *ctx);
extern void build_epilogue(struct jit_ctx *ctx);