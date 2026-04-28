#include <stddef.h>
#include <stdlib.h>

struct inode {
    int i_rdev;
};

struct file {
    void *private_data;
};

struct usb_interface;
struct hid_device {
    struct hiddev *hiddev;
};

struct list_head {
    struct list_head *next, *prev;
};

struct hiddev {
    struct hid_device *hid;
    int exist;
    int open;
    int list_lock;
    int existancelock;
    struct list_head list;
};

struct hiddev_list {
    struct hiddev *hiddev;
    int thread_lock;
    struct list_head node;
};

#define ENODEV 19
#define ENOMEM 12
#define PM_HINT_FULLON 0
#define PM_HINT_NORMAL 0

static inline int iminor(struct inode *inode) { return inode->i_rdev; }
static inline void mutex_init(int *lock) {}
static inline void mutex_lock(int *lock) {}
static inline void mutex_unlock(int *lock) {}
static inline void spin_lock_irq(int *lock) {}
static inline void spin_unlock_irq(int *lock) {}
static inline void list_add_tail(struct list_head *new, struct list_head *head) {}

static struct usb_interface *usbhid_find_interface(int minor) { return NULL; }
static void *usb_get_intfdata(struct usb_interface *intf) { return NULL; }
static void *vzalloc(size_t size) { return calloc(1, size); }
static void vfree(void *ptr) { free(ptr); }
static int hid_hw_open(struct hid_device *hid) { return 0; }
static int hid_hw_power(struct hid_device *hid, int hint) { return 0; }