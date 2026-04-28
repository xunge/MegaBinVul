#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

struct pipe_inode_info {
    unsigned int buffers;
    unsigned int curbuf;
    unsigned int nrbufs;
    struct pipe_buffer *bufs;
};

struct pipe_buffer {
    unsigned long len;
    unsigned long offset;
    unsigned int flags;
    struct pipe_buf_operations *ops;
};

struct pipe_buf_operations {
    void (*get)(struct pipe_inode_info *, struct pipe_buffer *);
    void (*release)(struct pipe_inode_info *, struct pipe_buffer *);
};

struct fuse_copy_state {
    struct pipe_buffer *pipebufs;
    unsigned int nr_segs;
    struct pipe_inode_info *pipe;
    int move_pages;
};

struct fuse_dev {
    void *fc;
};

#define GFP_KERNEL 0
#define PIPE_BUF_FLAG_GIFT (1 << 0)
#define SPLICE_F_MOVE (1 << 0)

static inline void pipe_lock(struct pipe_inode_info *pipe) {}
static inline void pipe_unlock(struct pipe_inode_info *pipe) {}
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void BUG_ON(int cond) { if (cond) abort(); }