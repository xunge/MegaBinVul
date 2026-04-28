#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define MIC_MAX_DESC_BLK_SIZE 256
#define MIC_MAX_VRINGS 8
#define MIC_VIRTIO_ADD_DEVICE 0
#define MIC_VIRTIO_COPY_DESC 1
#define MIC_VIRTIO_CONFIG_CHANGE 2
#define GFP_KERNEL 0
#define EFAULT 1
#define EINVAL 2
#define ENOMEM 3
#define ENOIOCTLCMD 4

struct file {
    void *private_data;
};

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct mic_device_desc {
    unsigned int num_vq;
    size_t config_len;
};

struct mic_copy_desc {
    size_t out_len;
};

struct vop_info {
    int vop_mutex;
    struct list_head vdev_list;
};

struct vop_vdev {
    struct vop_info *vi;
    int vdev_mutex;
    struct list_head list;
    struct mic_device_desc *dd;
};

static inline void mutex_lock(int *mutex) { *mutex = 1; }
static inline void mutex_unlock(int *mutex) { *mutex = 0; }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int copy_from_user(void *to, const void *from, size_t n) { memcpy(to, from, n); return 0; }
static inline int copy_to_user(void *to, const void *from, size_t n) { memcpy(to, from, n); return 0; }
static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

#define __user

static size_t mic_aligned_desc_size(const struct mic_device_desc *dd) { return 0; }
static size_t mic_desc_size(const struct mic_device_desc *dd) { return 0; }
static int vop_virtio_add_device(struct vop_vdev *vdev, struct mic_device_desc *dd_config) { return 0; }
static int vop_vdev_inited(struct vop_vdev *vdev) { return 0; }
static int vop_virtio_copy_desc(struct vop_vdev *vdev, struct mic_copy_desc *copy) { return 0; }
static int vop_virtio_config_change(struct vop_vdev *vdev, void *buf) { return 0; }

typedef void *user_ptr_t;