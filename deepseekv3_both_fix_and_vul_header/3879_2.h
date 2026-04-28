#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define CAP_SYS_ADMIN 21

struct device;
struct device_attribute;
struct rbd_device;

int capable(int cap);
ssize_t rbd_dev_refresh(struct rbd_device *rbd_dev);
struct rbd_device *dev_to_rbd_dev(struct device *dev);