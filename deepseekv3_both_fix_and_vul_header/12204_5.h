#include <stddef.h>

struct usb_interface;
struct usb_device;
struct net_device {
    struct phy_device *phydev;
};
struct phy_device;

struct delayed_work {
    // 空结构体定义
};
struct timer_list {
    // 空结构体定义
};
struct urb {
    // 空结构体定义
};

struct lan78xx_net {
    unsigned long flags;
    struct net_device *net;
    struct delayed_work wq;
    struct timer_list stat_monitor;
    struct urb *urb_intr;
    void *deferred;
    void *napi;
};

#define EVENT_DEV_DISCONNECT 0
#define PHY_KSZ9031RNX 0
#define PHY_LAN8835 0