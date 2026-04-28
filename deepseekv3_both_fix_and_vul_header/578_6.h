#include <errno.h>
#include <stddef.h>

struct firmware;
struct device {
    struct device *parent;
};
struct completion {
    unsigned int done;
};
struct usb_device {
    struct device dev;
};
struct usb_interface {
    struct device dev;
};
struct usb_driver;

struct p54u_priv {
    struct usb_device *udev;
    struct usb_interface *intf;
    const struct firmware *fw;
    struct completion fw_wait_load;
};

extern void complete(struct completion *);
extern void dev_err(struct device *, const char *, ...);
extern void device_lock(struct device *);
extern void device_unlock(struct device *);
extern void device_release_driver(struct device *);
extern void usb_put_dev(struct usb_device *);
extern void usb_put_intf(struct usb_interface *);
extern void usb_lock_device(struct usb_device *);
extern void usb_unlock_device(struct usb_device *);
extern void usb_driver_release_interface(struct usb_driver *, struct usb_interface *);
extern int p54u_start_ops(struct p54u_priv *priv);

extern struct usb_driver p54u_driver;