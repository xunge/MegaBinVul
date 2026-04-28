#include <stdio.h>
#include <unistd.h>

typedef long ssize_t;

struct device;
struct device_attribute;

struct rbd_device {
    char *config_info;
};

#define CAP_SYS_ADMIN 0
#define EPERM 1

static inline int capable(int cap) { return 1; }
static inline struct rbd_device *dev_to_rbd_dev(struct device *dev) { return NULL; }