#include <stdint.h>
#include <stddef.h>

#define WORK_ENABLE 0
#define RTL8152_UNPLUG 1
#define RTL8152_LINK_CHG 2
#define INTR_LINK 0x01
#define GFP_ATOMIC 0
#define ECONNRESET 104
#define ESHUTDOWN 108
#define ENOENT 2
#define EPROTO 71
#define EOVERFLOW 75
#define ENODEV 19

#define intr "intr"

typedef uint16_t __le16;

struct net_device {
    // dummy definition
};

struct work_struct {
    // dummy definition  
};

struct delayed_work {
    struct work_struct work;
};

struct r8152 {
    unsigned long flags;
    struct net_device *netdev;
    struct delayed_work schedule;
};

struct urb {
    int status;
    void *context;
    __le16 *transfer_buffer;
};

static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline void set_bit(int nr, volatile unsigned long *addr) {}
static inline int netif_carrier_ok(const struct net_device *dev) { return 0; }
static inline void netif_device_detach(struct net_device *dev) {}
static inline void netif_stop_queue(struct net_device *dev) {}
static inline void schedule_delayed_work(struct delayed_work *work, unsigned long delay) {}
static inline int usb_submit_urb(struct urb *urb, int mem_flags) { return 0; }
static inline void rtl_set_unplug(struct r8152 *tp) {}
static inline void netif_info(const struct r8152 *tp, const char *type, struct net_device *dev, const char *fmt, ...) {}
static inline void netif_err(const struct r8152 *tp, const char *type, struct net_device *dev, const char *fmt, ...) {}
static inline uint16_t __le16_to_cpu(uint16_t val) { return val; }
#define fallthrough ((void)0)