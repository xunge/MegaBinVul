#include <signal.h>
#include <poll.h>
#include <pthread.h>

struct usb_interface {
    int minor;
    void *dev;
};

struct urb;
struct usb_class_driver;
struct fasync_struct;

struct kref {
    int count;
};

struct usb_yurex {
    struct usb_interface *interface;
    struct urb *urb;
    pthread_mutex_t io_mutex;
    struct fasync_struct *async_queue;
    int waitq;
    struct kref kref;
};

extern struct usb_class_driver yurex_class;
extern struct usb_yurex *usb_get_intfdata(struct usb_interface *);
extern void usb_set_intfdata(struct usb_interface *, void *);
extern void usb_deregister_dev(struct usb_interface *, struct usb_class_driver *);
extern void usb_poison_urb(struct urb *);
extern void kill_fasync(struct fasync_struct **, int, int);
extern void wake_up_interruptible(int *);
extern void kref_put(struct kref *, void (*)(struct kref *));
extern void yurex_delete(struct kref *);
extern int dev_info(void *, const char *, ...);

#define mutex_lock(x) pthread_mutex_lock(x)
#define mutex_unlock(x) pthread_mutex_unlock(x)