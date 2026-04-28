#include <assert.h>
#include <stddef.h>

struct iov_iter {
    int type;
    struct pipe_inode_info *pipe;
    int idx;
    int iov_offset;
    size_t count;
};

struct pipe_inode_info {
    unsigned int curbuf;
    unsigned int nrbufs;
    unsigned int buffers;
};

#define ITER_PIPE 0
#define BUG_ON(cond) assert(!(cond))