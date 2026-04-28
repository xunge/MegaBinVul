#include <stdint.h>
#include <stddef.h>

struct usb_interface;

struct wdm_device {
    uint32_t flags;
    void *wlock;
    void *rlock;
};

enum {
    WDM_OVERFLOW,
    WDM_RESETTING
};

#define clear_bit(nr, addr) ((*(addr)) &= ~(1UL << (nr)))
#define mutex_unlock(lock) ((void)0)

static struct wdm_device *wdm_find_device(struct usb_interface *intf) { return NULL; }
static int recover_from_urb_loss(struct wdm_device *desc) { return 0; }