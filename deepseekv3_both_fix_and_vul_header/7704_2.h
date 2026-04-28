#include <stdio.h>
#include <stdlib.h>

struct file;
struct io_kiocb_ctx {
    void* refs;  // Opaque pointer since we can't define percpu_ref
};

struct io_kiocb {
    struct file *file;
    unsigned int flags;
    struct io_kiocb_ctx *ctx;
};

#define REQ_F_FIXED_FILE (1U << 0)

extern struct kmem_cache *req_cachep;

void fput(struct file *file);
void percpu_ref_put(void *ref);
void kmem_cache_free(struct kmem_cache *cachep, void *objp);