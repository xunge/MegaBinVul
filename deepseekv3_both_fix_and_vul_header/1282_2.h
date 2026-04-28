#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>

#define MBOCHS_CONFIG_SPACE_SIZE 0x1000
#define MBOCHS_EDID_BLOB_OFFSET 0x1000
#define PAGE_SHIFT 12
#define GFP_KERNEL 0
#define ENOMEM 12
#define ENOSPC 28

struct device {
    // dummy device structure
};

struct mdev_device {
    struct device dev;
    // other members
};

struct page {
    // dummy page structure
};

struct vfio_device {
    // dummy vfio_device structure
    struct device *dev;
};

struct vfio_device_ops {
    // dummy ops structure
};

struct mutex {
    // dummy mutex structure
};

struct list_head {
    // dummy list_head structure
};

struct mbochs_type {
    const char *name;
    int mbytes;
    int max_x;
    int max_y;
};

struct mdev_state {
    struct vfio_device vdev;
    void *vconfig;
    uint64_t memsize;
    unsigned long pagecount;
    struct page **pages;
    struct {
        int max_xres;
        int max_yres;
        uint32_t edid_offset;
        size_t edid_max_size;
    } edid_regs;
    uint8_t edid_blob[128];
    struct mutex ops_lock;
    struct mdev_device *mdev;
    struct list_head dmabufs;
    int next_id;
    const struct mbochs_type *type;
};

extern const struct mbochs_type mbochs_types[];
extern atomic_int mbochs_avail_mbytes;
extern int mbochs_used_mbytes;
extern int max_mbytes;
extern const struct vfio_device_ops mbochs_dev_ops;

void *kzalloc(size_t size, int flags);
void *kcalloc(size_t n, size_t size, int flags);
void kfree(const void *objp);
void dev_info(struct device *dev, const char *fmt, ...);
void mutex_init(struct mutex *lock);
void INIT_LIST_HEAD(struct list_head *list);
int vfio_register_group_dev(struct vfio_device *vdev);
void vfio_init_group_dev(struct vfio_device *vdev, struct device *dev, const struct vfio_device_ops *ops);
void dev_set_drvdata(struct device *dev, void *data);
int mdev_get_type_group_id(struct mdev_device *mdev);
struct device *mdev_dev(struct mdev_device *mdev);
void mbochs_create_config_space(struct mdev_state *mdev_state);
void mbochs_reset(struct mdev_state *mdev_state);