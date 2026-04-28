#include <stddef.h>

struct usb_interface {
    struct {
        struct {
            unsigned char bNumEndpoints;
        } desc;
        struct {
            struct {
                unsigned char bEndpointAddress;
            } desc;
        } endpoint[8];
    } *altsetting;
    struct {
        int dev;
    } dev;
};

struct usb_device {
    int dev;
    int reset_resume;
};

struct usb_device_id {};

struct ieee80211_hw {
    void *priv;
    int extra_tx_headroom;
};

struct sk_buff_head {};
struct sk_buff {};

struct usb_anchor {};

struct p54u_priv {
    struct ieee80211_hw *dev;
    struct usb_device *udev;
    struct usb_interface *intf;
    struct sk_buff_head rx_queue;
    struct usb_anchor submitted;
    enum {
        P54U_INVALID_HW,
        P54U_3887,
        P54U_NET2280
    } hw_type;
    struct {
        void (*open)(struct ieee80211_hw *);
        void (*stop)(struct ieee80211_hw *);
        unsigned int tx_hdr_len;
        int (*tx)(struct ieee80211_hw *, struct sk_buff *);
    } common;
    int (*upload_fw)(struct ieee80211_hw *);
};

enum {
    P54U_PIPE_DATA,
    P54U_PIPE_MGMT,
    P54U_PIPE_BRG,
    P54U_PIPE_DEV,
    P54U_PIPE_INT,
    P54U_PIPE_NUMBER,
    USB_DIR_IN = 0x80
};

struct lm87_tx_hdr {
    int dummy;
};

struct net2280_tx_hdr {
    int dummy;
};

#define SET_IEEE80211_DEV(dev, intf_dev) 
#define dev_err(dev, fmt, ...) 
#define ENOMEM (-1)
#define CONFIG_PM 0

static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return (struct usb_device *)intf; }
static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {}
static inline void skb_queue_head_init(struct sk_buff_head *list) {}
static inline void init_usb_anchor(struct usb_anchor *anchor) {}
static inline void usb_get_dev(struct usb_device *udev) {}
static inline void usb_put_dev(struct usb_device *udev) {}

extern struct ieee80211_hw *p54_init_common(size_t);
extern void p54_free_common(struct ieee80211_hw *);
extern int p54u_device_reset(struct ieee80211_hw *);
extern int p54u_load_firmware(struct ieee80211_hw *, struct usb_interface *);
extern int p54u_upload_firmware_3887(struct ieee80211_hw *);
extern int p54u_upload_firmware_net2280(struct ieee80211_hw *);
extern int p54u_tx_lm87(struct ieee80211_hw *, struct sk_buff *);
extern int p54u_tx_net2280(struct ieee80211_hw *, struct sk_buff *);
extern void p54u_open(struct ieee80211_hw *);
extern void p54u_stop(struct ieee80211_hw *);