#include <stdint.h>
#include <stddef.h>

#define MAX3421_REG_HRSL 0
#define MAX3421_REG_HCTL 0
#define MAX3421_REG_PERADDR 0
#define MAX3421_HRSL_RCVTOGRD_BIT 0
#define MAX3421_HRSL_SNDTOGRD_BIT 0
#define MAX3421_HCTL_RCVTOG0_BIT 0
#define MAX3421_HCTL_SNDTOG0_BIT 0
#define BIT(n) (1 << (n))

typedef uint8_t u8;

struct usb_device {
    int devnum;
};

struct usb_hcd {
};

struct max3421_hcd {
    struct usb_device *loaded_dev;
    int loaded_epnum;
};

static inline struct max3421_hcd *hcd_to_max3421(struct usb_hcd *hcd) { return NULL; }
static inline u8 spi_rd8(struct usb_hcd *hcd, int reg) { return 0; }
static inline void spi_wr8(struct usb_hcd *hcd, int reg, u8 val) {}
static inline void usb_settoggle(struct usb_device *dev, int epnum, int dir, int toggle) {}
static inline int usb_gettoggle(struct usb_device *dev, int epnum, int dir) { return 0; }