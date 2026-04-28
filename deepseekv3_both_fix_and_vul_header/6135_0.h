#include <stddef.h>

struct port_buffer {
    size_t len;
    size_t offset;
    size_t size;
};

struct port_stats {
    size_t bytes_received;
};

struct port {
    struct port_buffer *inbuf;
    void *in_vq;
    struct port_stats stats;
};

struct port_buffer *virtqueue_get_buf(void *vq, unsigned int *len);

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))