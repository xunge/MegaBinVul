#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#define PATH_MAX 4096
#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12

typedef unsigned int gfp_t;

struct device {
    // dummy structure
};

struct device_attribute {
    // dummy structure  
};

struct platform_device {
    char *driver_override;
    // other members omitted
};

static inline struct platform_device *to_platform_device(struct device *dev) {
    return (struct platform_device *)dev;
}

static inline char *kstrndup(const char *s, size_t max, gfp_t gfp) {
    return strndup(s, max);
}

static inline void kfree(const void *objp) {
    free((void *)objp);
}