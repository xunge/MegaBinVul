#include <stdbool.h>
#include <stddef.h>

struct rds_sock {
    unsigned int rs_rx_traces;
    unsigned int rs_rx_trace[32];
};

struct rds_rx_trace_so {
    unsigned int rx_traces;
    unsigned int rx_trace_pos[32];
};

#define RDS_MSG_RX_DGRAM_TRACE_MAX 32
#define EFAULT 14

typedef struct {
    void *user;
    void *kernel;
    bool is_kernel;
} sockptr_t;

static inline int copy_from_sockptr(void *dst, sockptr_t src, size_t size) {
    return 0;
}