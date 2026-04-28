#include <stddef.h>

struct completion {
    unsigned int dummy;
};

struct firmware {
    unsigned int size;
    const void *data;
};

struct device {
    int dummy;
};

struct usb_device {
    struct device dev;
    int dummy;
};

struct usb_interface {
    int dummy;
};

struct ieee80211_hw {
    void *priv;
    int dummy;
};

struct p54u_priv {
    struct usb_device *udev;
    struct completion fw_wait_load;
    int dummy;
};

struct p54u_fwlist {
    const char *fw;
    int dummy;
};

extern struct p54u_fwlist p54u_fwlist[10];
enum { __NUM_P54U_HWTYPES = 10 };

#define BUILD_BUG_ON(cond) ((void)0)
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
#define GFP_KERNEL 0
#define THIS_MODULE NULL

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static inline void init_completion(struct completion *c) {}
static inline int p54_find_type(struct p54u_priv *priv) { return 0; }
static inline void usb_get_dev(struct usb_device *udev) {}
static inline void usb_put_dev(struct usb_device *udev) {}
static inline int request_firmware_nowait(void *module, int uevent, const char *name,
                                        struct device *device, int gfp, void *context,
                                        void (*cb)(const struct firmware *fw, void *context)) { return 0; }
static inline void dev_info(struct device *dev, const char *fmt, ...) {}
static inline void dev_err(struct device *dev, const char *fmt, ...) {}

void p54u_load_firmware_cb(const struct firmware *fw, void *context);