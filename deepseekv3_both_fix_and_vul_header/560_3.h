#include <string.h>

struct rds_sock {
    unsigned int rs_rx_traces;
    unsigned int rs_rx_trace[32 + 1];
};

struct rds_rx_trace_so {
    unsigned int rx_traces;
    unsigned int rx_trace_pos[32 + 1];
};

#define RDS_MSG_RX_DGRAM_TRACE_MAX 32
#define EFAULT 14

static inline int copy_from_user(void *to, const char *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

#define __user