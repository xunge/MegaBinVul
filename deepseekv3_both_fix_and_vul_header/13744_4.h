#include <stdlib.h>
#include <errno.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct hid_device {
    struct hiddev *hiddev;
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

struct file {
    void *private_data;
};

struct inode;
struct usb_interface;

#define ENODEV 19
#define ENOMEM 12
#define PM_HINT_FULLON 0
#define PM_HINT_NORMAL 0

static void *vzalloc(size_t size) { return calloc(1, size); }
static void vfree(void *ptr) { free(ptr); }
static void mutex_init(int *mutex) { *mutex = 0; }
static void mutex_lock(int *mutex) { (void)mutex; }
static void mutex_unlock(int *mutex) { (void)mutex; }
static void spin_lock_irq(int *lock) { (void)lock; }
static void spin_unlock_irq(int *lock) { (void)lock; }
static void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}
static int iminor(struct inode *inode) { (void)inode; return 0; }
static struct usb_interface *usbhid_find_interface(int minor) { (void)minor; return NULL; }
static struct hid_device *usb_get_intfdata(struct usb_interface *intf) { (void)intf; return NULL; }
static int hid_hw_open(struct hid_device *hid) { (void)hid; return 0; }
static int hid_hw_power(struct hid_device *hid, int hint) { (void)hid; (void)hint; return 0; }