#include <string.h>
#include <stdbool.h>

struct cec_log_addrs {
    unsigned char log_addr[16];
};

struct cec_adapter {
    void *lock;
    struct cec_log_addrs log_addrs;
    bool is_configured;
};

#define CEC_LOG_ADDR_INVALID 0xff
#define EFAULT 14

#define __user

static inline void mutex_lock(void *lock) {}
static inline void mutex_unlock(void *lock) {}
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }