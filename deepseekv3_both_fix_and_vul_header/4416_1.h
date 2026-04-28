#include <stdlib.h>
#include <string.h>

#define EBUSY 16
#define ENOMEM 12
#define GFP_KERNEL 0
#define __GFP_NOWARN 0
#define PAGE_SIZE 4096

struct pipe_inode_info {
    unsigned int nrbufs;
    unsigned int curbuf;
    unsigned int buffers;
    struct pipe_buffer *bufs;
};

struct pipe_buffer {
    // 定义必要的成员
};

#define unlikely(x) (x)

static void *kcalloc(size_t n, size_t size, int flags) {
    return calloc(n, size);
}

static void kfree(void *p) {
    free(p);
}