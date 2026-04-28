#include <stddef.h>
#include <stdint.h>

struct device;
struct usb_phy;

struct usb_hcd {
    uintptr_t rsrc_start;
    size_t rsrc_len;
    void *regs;
    unsigned int has_tt;
    unsigned int power_budget;
    struct usb_phy *phy;
};

struct ehci_hcd {
    void *caps;
    unsigned int has_hostpc;
};

struct ci13xxx {
    struct device *dev;
    struct {
        uintptr_t phys;
        size_t size;
        void *abs;
        void *cap;
        unsigned int lpm;
    } hw_bank;
    struct {
        unsigned int power_budget;
        unsigned int flags;
    } *platdata;
    struct usb_phy *transceiver;
    struct usb_hcd *hcd;
};

extern const struct hc_driver ci_ehci_hc_driver;
extern int usb_disabled(void);
extern struct usb_hcd *usb_create_hcd(const struct hc_driver *driver, struct device *dev, const char *bus_name);
extern int usb_add_hcd(struct usb_hcd *hcd, unsigned int irqnum, unsigned long irqflags);
extern void usb_put_hcd(struct usb_hcd *hcd);
extern void hw_write(struct ci13xxx *ci, uint32_t reg, uint32_t mask, uint32_t val);
extern const char *dev_name(struct device *dev);
extern void dev_set_drvdata(struct device *dev, void *data);
extern struct ehci_hcd *hcd_to_ehci(struct usb_hcd *hcd);

#define ENODEV 19
#define ENOMEM 12
#define USBMODE_CI_SDIS 0x01
#define CI13XXX_DISABLE_STREAMING (1 << 0)
#define OP_USBMODE 0