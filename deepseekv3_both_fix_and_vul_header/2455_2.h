#include <stdio.h>
#include <string.h>
#include <sys/types.h>

struct device;
struct device_attribute;

struct platform_device {
    char *driver_override;
};

static inline struct platform_device *to_platform_device(struct device *dev) {
    return (struct platform_device *)dev;
}