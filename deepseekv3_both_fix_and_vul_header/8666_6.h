#include <stddef.h>
#include <stdint.h>

struct file {
    void *private_data;
};

struct mutex {
    int dummy;
};

struct ion_client {
    struct ion_device *dev;
    struct mutex lock;
};

struct ion_device {
    long (*custom_ioctl)(struct ion_client *, unsigned int, unsigned long);
};

struct ion_handle {
    int id;
};

struct ion_fd_data {
    int fd;
};

struct ion_allocation_data {
    size_t len;
    size_t align;
    unsigned int heap_id_mask;
    unsigned int flags;
    int handle;
};

struct ion_handle_data {
    int handle;
};

struct ion_custom_data {
    unsigned int cmd;
    unsigned long arg;
};

#define ION_IOC_ALLOC   0
#define ION_IOC_FREE    1
#define ION_IOC_SHARE   2
#define ION_IOC_MAP     3
#define ION_IOC_IMPORT  4
#define ION_IOC_SYNC    5
#define ION_IOC_CUSTOM  6

#define _IOC_WRITE      0U
#define _IOC_READ       1U
#define _IOC_SIZE(nr)   2U
#define _IOC_DIR(nr)    3U

#define ENOTTY          25
#define EFAULT          14
#define EINVAL          22

#define IS_ERR(x)       ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x)      ((long)(x))

static unsigned int ion_ioctl_dir(unsigned int cmd) { return 0; }
static struct ion_handle *ion_alloc(struct ion_client *client, size_t len, size_t align, unsigned int heap_id_mask, unsigned int flags) { return NULL; }
static struct ion_handle *ion_handle_get_by_id(struct ion_client *client, int id) { return NULL; }
static struct ion_handle *ion_handle_get_by_id_nolock(struct ion_client *client, int id) { return NULL; }
static void ion_free(struct ion_client *client, struct ion_handle *handle) {}
static void ion_free_nolock(struct ion_client *client, struct ion_handle *handle) {}
static void ion_handle_put(struct ion_handle *handle) {}
static void ion_handle_put_nolock(struct ion_handle *handle) {}
static int ion_share_dma_buf_fd(struct ion_client *client, struct ion_handle *handle) { return 0; }
static struct ion_handle *ion_import_dma_buf_fd(struct ion_client *client, int fd) { return NULL; }
static int ion_sync_for_device(struct ion_client *client, int fd) { return 0; }
static int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static void mutex_lock(struct mutex *lock) {}
static void mutex_unlock(struct mutex *lock) {}

#define __user