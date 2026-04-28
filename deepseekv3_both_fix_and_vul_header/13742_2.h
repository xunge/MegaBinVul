#include <stddef.h>

struct usb_interface;
struct usb_device {
    struct {
        int dev;
    } dev;
};
struct ieee802154_hw;
struct urb;
struct anchor {
    int dummy;
};
struct delayed_work {
    int dummy;
};

struct atusb {
    struct usb_device *usb_dev;
    int shutdown;
    struct delayed_work work;
    struct ieee802154_hw *hw;
    struct urb *tx_urb;
    struct anchor rx_urbs;
};

void *usb_get_intfdata(struct usb_interface *interface);
void dev_dbg(void *dev, const char *fmt, const char *func);
void cancel_delayed_work_sync(struct delayed_work *work);
void usb_kill_anchored_urbs(struct anchor *anchor);
void atusb_free_urbs(struct atusb *atusb);
void usb_kill_urb(struct urb *urb);
void usb_free_urb(struct urb *urb);
void ieee802154_unregister_hw(struct ieee802154_hw *hw);
void ieee802154_free_hw(struct ieee802154_hw *hw);
void usb_set_intfdata(struct usb_interface *interface, void *data);
void usb_put_dev(struct usb_device *dev);
void pr_debug(const char *fmt, const char *func);