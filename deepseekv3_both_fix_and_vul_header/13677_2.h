#include <stdint.h>
#include <stdlib.h>

typedef struct urb {
    int dummy;
} urb;

typedef struct usb_device {
    int dummy;
} usb_device;

typedef struct usb_anchor {
    int dummy;
} usb_anchor;

typedef struct ieee80211_hw {
    void *priv;
} ieee80211_hw;

struct rtl8xxxu_priv {
    struct usb_device *udev;
    struct usb_anchor int_anchor;
    void *int_buf;
    unsigned int pipe_interrupt;
};

typedef uint32_t u32;

#define USB_INTR_CONTENT_LENGTH 0
#define REG_USB_HIMR 0
#define USB_HIMR_CPWM 0
#define GFP_KERNEL 0
#define ENOMEM 0

void rtl8xxxu_int_complete(struct urb *urb);
u32 rtl8xxxu_read32(struct rtl8xxxu_priv *priv, int reg);
void rtl8xxxu_write32(struct rtl8xxxu_priv *priv, int reg, u32 val);

struct urb *usb_alloc_urb(int, int);
void usb_fill_int_urb(struct urb *, struct usb_device *, unsigned int, 
                     void *, int, void *, void *, int);
void usb_anchor_urb(struct urb *, struct usb_anchor *);
int usb_submit_urb(struct urb *, int);
void usb_unanchor_urb(struct urb *);
void usb_free_urb(struct urb *);