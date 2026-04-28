#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct usb_hcd {
    struct {
        void *controller;
    } self;
    void *hcd_priv;
};

struct spi_device {
    int dev;
};

struct urb {
    struct list_head urb_list;
    int unlinked;
    struct {
        struct {
            int bEndpointAddress;
            int bmAttributes;
        } desc;
    } *ep;
    void *dev;
    int interval;
};

struct usb_host_endpoint {
    struct list_head urb_list;
    struct {
        int bEndpointAddress;
        int bmAttributes;
    } desc;
};

struct max3421_hcd {
    unsigned long lock;
    int sched_pass;
    struct list_head ep_list;
    struct urb *curr_urb;
    int urb_done;
    unsigned int frame_number;
};

struct max3421_ep {
    struct list_head ep_list;
    struct usb_host_endpoint *ep;
    unsigned int last_active;
    int retransmit;
    int pkt_state;
};

#define SCHED_PASS_DONE 2
#define SCHED_PASS_PERIODIC 0
#define SCHED_PASS_NON_PERIODIC 1

#define PKT_STATE_SETUP 0
#define PKT_STATE_TRANSFER 1

#define USB_ENDPOINT_XFER_ISOC 0
#define USB_ENDPOINT_XFER_INT 1
#define USB_ENDPOINT_XFER_CONTROL 2
#define USB_ENDPOINT_XFER_BULK 3

static inline struct max3421_hcd *hcd_to_max3421(struct usb_hcd *hcd)
{
    return (struct max3421_hcd *)hcd->hcd_priv;
}

static inline int frame_diff(unsigned int a, unsigned int b)
{
    return (a - b) & 0x3FF;
}

static inline int usb_endpoint_type(const void *desc)
{
    return 0;
}

static inline int usb_endpoint_num(const void *desc)
{
    return 0;
}

static inline int usb_endpoint_xfer_control(const void *desc)
{
    return 0;
}

static inline void usb_settoggle(void *dev, int epnum, int dir, int value)
{
}

static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags)
{
}

static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags)
{
}

static inline void list_move_tail(struct list_head *entry, struct list_head *head)
{
}

static inline int list_empty(const struct list_head *head)
{
    return 0;
}

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_first_entry(ptr, type, member) \
    container_of((ptr)->next, type, member)

#define dev_dbg(dev, format, ...)