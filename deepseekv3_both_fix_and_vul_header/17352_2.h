#include <stddef.h>

struct device {
    // minimal device structure needed
};

struct usb_device {
    struct device dev;
    struct usb_device *parent;
    int portnum;
};

struct stub_device {
    struct usb_device *udev;
};

struct bus_id_priv {
    struct stub_device *sdev;
    int status;
};

struct usb_dev_state {
    // minimal structure needed
};

struct task_struct {
    // minimal structure needed
};

extern struct task_struct *current;

enum {
    STUB_BUSID_ALLOC,
    STUB_BUSID_ADDED
};

extern const char *dev_name(const struct device *dev);
extern void dev_dbg(const struct device *dev, const char *fmt, ...);
extern void dev_err(const struct device *dev, const char *fmt, ...);
extern void *dev_get_drvdata(const struct device *dev);
extern void dev_set_drvdata(struct device *dev, void *data);
extern void BUG(void);
extern struct bus_id_priv *get_busid_priv(const char *busid);
extern void stub_remove_files(struct device *dev);
extern int usb_hub_release_port(struct usb_device *parent, int portnum, struct usb_dev_state *usb_dev_state);
extern int usbip_in_eh(struct task_struct *task);
extern void shutdown_busid(struct bus_id_priv *busid_priv);
extern void usb_put_dev(struct usb_device *udev);
extern void stub_device_free(struct stub_device *sdev);