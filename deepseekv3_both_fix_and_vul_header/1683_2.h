#include <stdbool.h>
#include <stdatomic.h>
#include <stddef.h>

struct usb_interface;

struct delayed_work {
    // dummy definition
    int dummy;
};

struct kref {
    // dummy definition
    int dummy;
};

struct ufx_data {
    bool virtualized;
    atomic_int usb_active;
    int fb_count;
    struct delayed_work free_framebuffer_work;
    struct kref kref;
};

extern struct ufx_data *usb_get_intfdata(struct usb_interface *interface);
extern void usb_set_intfdata(struct usb_interface *interface, void *data);
extern void schedule_delayed_work(struct delayed_work *work, unsigned long delay);
extern void kref_put(struct kref *kref, void (*release)(struct kref *kref));
extern void ufx_free(struct kref *kref);
extern void pr_debug(const char *fmt, ...);
extern void atomic_set(atomic_int *obj, int desired);
extern void mutex_lock(int *mutex);
extern void mutex_unlock(int *mutex);

static int disconnect_mutex;