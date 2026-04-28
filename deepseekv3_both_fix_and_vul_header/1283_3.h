#include <stdatomic.h>
#include <stdlib.h>

struct mdev_device {
    void *dev;
};

struct mbochs_type {
    unsigned long mbytes;
};

struct mdev_state {
    void *vdev;
    struct mbochs_type *type;
    void *pages;
    void *vconfig;
};

extern atomic_ulong mbochs_avail_mbytes;
extern unsigned long mbochs_used_mbytes;

void *dev_get_drvdata(const void *dev);
void vfio_unregister_group_dev(void *vdev);