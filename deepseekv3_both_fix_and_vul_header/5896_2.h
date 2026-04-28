#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define GFP_KERNEL 0

typedef uint8_t u8;

struct bpf_prog {
    unsigned int len;
    void *bpf_func;
    bool jited;
};

struct bpf_binary_header {
    unsigned long pages;
};

struct jit_context {
    int cleanup_addr;
};

extern bool bpf_jit_enable;
extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern int do_jit(struct bpf_prog *prog, int *addrs, u8 *image, int oldproglen, struct jit_context *ctx);
extern void bpf_jit_binary_free(struct bpf_binary_header *hdr);
extern struct bpf_binary_header *bpf_jit_binary_alloc(unsigned int proglen, u8 **image_ptr, unsigned int alignment, void (*fill)(void *));
extern void bpf_jit_dump(unsigned int prog_len, unsigned int proglen, unsigned int pass, u8 *image);
extern void bpf_flush_icache(struct bpf_binary_header *hdr, void *ptr);
extern void set_memory_ro(unsigned long addr, int numpages);
extern void jit_fill_hole(void *area);
extern int pr_err(const char *fmt, ...);