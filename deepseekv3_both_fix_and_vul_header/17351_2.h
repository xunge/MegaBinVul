#include <string.h>
#include <errno.h>

struct device {
    const char *name;
};

struct usb_bus {
    const char *bus_name;
    unsigned int busnum;
};

struct usb_device {
    struct device dev;
    struct usb_bus *bus;
    struct usb_device *parent;
    unsigned int portnum;
    unsigned int devnum;
    struct {
        unsigned char bDeviceClass;
    } descriptor;
};

struct stub_device {
    // placeholder structure
    int dummy;
};

struct bus_id_priv {
    int status;
    int shutdown_busid;
    struct stub_device *sdev;
    struct usb_device *udev;
};

struct usb_dev_state {
    // placeholder structure
    int dummy;
};

enum {
    STUB_BUSID_REMOV,
    STUB_BUSID_OTHER,
    STUB_BUSID_ALLOC
};

#define USB_CLASS_HUB 0x09
#define ENODEV 19
#define ENOXIO 6
#define ENOMEM 12

static inline const char *dev_name(const struct device *dev) { return dev->name; }
static inline void dev_dbg(const struct device *dev, const char *fmt, ...) {}
static inline void dev_info(const struct device *dev, const char *fmt, ...) {}
static inline void dev_err(const struct device *dev, const char *fmt, ...) {}
static inline void dev_set_drvdata(struct device *dev, void *data) {}
static inline void usb_put_dev(struct usb_device *udev) {}

static inline struct bus_id_priv *get_busid_priv(const char *busid) { return NULL; }
static inline int stub_device_alloc(struct usb_device *udev) { return 0; }
static inline void stub_device_free(struct stub_device *sdev) {}
static inline int stub_add_files(struct device *dev) { return 0; }
static inline int usb_hub_claim_port(struct usb_device *parent, int portnum, struct usb_dev_state *owner) { return 0; }
static inline void usb_hub_release_port(struct usb_device *parent, int portnum, struct usb_dev_state *owner) {}