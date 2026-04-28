#include <stddef.h>

struct usb_interface;
struct usb_device;
struct firmware;

struct completion {
    unsigned int done;
};

struct ieee80211_hw {
    void *priv;
};

struct p54u_priv {
    struct completion fw_wait_load;
    const struct firmware *fw;
};

void *usb_get_intfdata(struct usb_interface *intf);
void wait_for_completion(struct completion *);
void p54_unregister_common(struct ieee80211_hw *);
struct usb_device *interface_to_usbdev(struct usb_interface *);
void usb_put_dev(struct usb_device *);
void release_firmware(const struct firmware *);
void p54_free_common(struct ieee80211_hw *);