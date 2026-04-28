#include <stddef.h>

struct usb_interface;
struct net_device;

struct mcba_priv {
    struct net_device *netdev;
};

void usb_set_intfdata(struct usb_interface *intf, void *data);
void* usb_get_intfdata(struct usb_interface *intf);
void netdev_info(struct net_device *dev, const char *fmt, ...);
void unregister_candev(struct net_device *dev);
void free_candev(struct net_device *dev);
void mcba_urb_unlink(struct mcba_priv *priv);