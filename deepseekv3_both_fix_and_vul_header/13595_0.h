#include <stddef.h>

struct rchan;
struct rchan_buf {
    struct rchan *chan;
    size_t subbufs_consumed;
    size_t bytes_consumed;
    size_t *padding;
};

struct rchan {
    size_t subbuf_size;
    size_t n_subbufs;
};