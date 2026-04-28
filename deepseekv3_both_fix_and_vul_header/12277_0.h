#include <stddef.h>

struct pipe_inode_info;
struct pipe_buffer;
struct iov_iter {
    struct pipe_inode_info *pipe;
    size_t count;
    int idx;
    size_t iov_offset;
};

struct pipe_inode_info {
    struct pipe_buffer *bufs;
    unsigned int curbuf;
    unsigned int nrbufs;
    unsigned int buffers;
};

struct pipe_buffer {
    size_t offset;
    size_t len;
};

static inline int next_idx(int idx, struct pipe_inode_info *pipe)
{
    return (idx + 1) & (pipe->buffers - 1);
}

static inline void pipe_buf_release(struct pipe_inode_info *pipe, struct pipe_buffer *buf)
{
}

#define unlikely(x) (x)