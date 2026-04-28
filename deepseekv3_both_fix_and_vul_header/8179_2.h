#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define EC_MAX_MSG_BYTES 256
#define GFP_KERNEL 0
#define EFAULT 1
#define EINVAL 2
#define ENOMEM 3

struct cros_ec_dev {
    void *dev;
    void *ec_dev;
    int cmd_offset;
};

struct cros_ec_command {
    uint32_t version;
    uint32_t command;
    uint32_t outsize;
    uint32_t insize;
    uint32_t result;
    uint8_t data[];
};

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int copy_from_user(void *to, const void *from, size_t n) { memcpy(to, from, n); return 0; }
static inline int copy_to_user(void *to, const void *from, size_t n) { memcpy(to, from, n); return 0; }
static inline int max(int a, int b) { return a > b ? a : b; }

int cros_ec_cmd_xfer(void *ec_dev, struct cros_ec_command *msg);

#define __user