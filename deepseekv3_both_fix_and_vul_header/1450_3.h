#include <stddef.h>

struct kref {
    int dummy;
};
struct mutex {
    int dummy;
};
struct usb_function_instance {
    int dummy;
};
struct usb_function {
    struct usb_function_instance *fi;
};

struct printer_dev {
    struct kref kref;
};
struct f_printer_opts {
    struct usb_function_instance func_inst;
    struct mutex lock;
    int refcnt;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static inline struct printer_dev *func_to_printer(struct usb_function *f) {
    return (struct printer_dev *)f;
}
void printer_dev_free(struct kref *kref);
void kref_put(struct kref *kref, void (*release)(struct kref *kref));
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);