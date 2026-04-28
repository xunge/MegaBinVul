#include <stddef.h>
#include <stdint.h>

struct device {
    // Minimal device structure definition
    int dummy;
};

struct device_attribute {
    // Minimal device_attribute structure definition  
    int dummy;
};

struct idxd_wq {
    struct device conf_dev;
    struct idxd_device *idxd;
    unsigned long size;
    int state;
};

struct idxd_device {
    unsigned long flags;
    unsigned long max_wq_size;
    int state;
};

#define IDXD_FLAG_CONFIGURABLE 0
#define IDXD_DEV_ENABLED 1
#define IDXD_WQ_DISABLED 0

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define test_bit(nr, addr) ((*addr) & (1UL << (nr)))

#define EINVAL 22
#define EPERM 1

typedef int ssize_t;
typedef unsigned long size_t;

int kstrtoul(const char *s, unsigned int base, unsigned long *res);
unsigned long total_claimed_wq_size(struct idxd_device *idxd);