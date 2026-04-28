#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned long size_t;

#define RTL_USB_MAX_RX_COUNT 10
#define INTF_USB 0
#define ENOMEM 12
#define ENODEV 19
#define GFP_KERNEL 0
#define RTL_STATUS_INTERFACE_START 0

struct usb_interface {
    struct {
        int dev;
    } dev;
};

struct usb_device {
    struct {
        int dev;
    } dev;
};

struct usb_device_id;
struct device;

struct work_struct {
    int dummy;
};

struct completion {
    int dummy;
};

struct rtl_hal_cfg {
    struct {
        int (*read_chip_version)(void*);
        int (*read_eeprom_info)(void*);
        int (*init_sw_vars)(void*);
        void (*init_sw_leds)(void*);
    } *ops;
};

struct rtl_ops {
    int dummy;
};

struct rtl_usb_ops {
    int dummy;
};

struct rtl_priv {
    void *hw;
    u32 *usb_data;
    struct {
        int usb_lock;
    } locks;
    struct {
        struct work_struct fill_h2c_cmd;
        struct work_struct lps_change_work;
    } works;
    unsigned int usb_data_index;
    struct completion firmware_loading_complete;
    struct {
        int mac80211_registered;
    } mac80211;
    struct {
        int interface;
    } rtlhal;
    struct rtl_hal_cfg *cfg;
    struct rtl_usb_ops *intf_ops;
    unsigned long status;
};

struct rtl_usb_priv {
    struct {
        struct usb_interface *intf;
        struct usb_device *udev;
    } dev;
};

struct ieee80211_hw {
    struct rtl_priv *priv;
};

#define WARN_ONCE(condition, message)
#define pr_err(fmt, ...)
#define SET_IEEE80211_DEV(hw, dev)
#define spin_lock_init(lock)
#define INIT_WORK(work, func)
#define init_completion(comp)
#define complete(comp)
#define set_bit(nr, addr) ((*(addr)) |= (1UL << (nr)))

static inline void *ieee80211_alloc_hw(size_t size, struct rtl_ops *ops) { return malloc(size); }
static inline int ieee80211_register_hw(void *hw) { return 0; }
static inline struct rtl_usb_priv *rtl_usbpriv(void *hw) { return NULL; }
static inline void _rtl_usb_io_handler_init(struct device *dev, void *hw) {}
static inline int _rtl_usb_init(void *hw) { return 0; }
static inline void rtl_usb_init_sw(void *hw) {}
static inline int rtl_init_core(void *hw) { return 0; }
static inline void rtl_deinit_core(void *hw) {}
static inline void _rtl_usb_io_handler_release(void *hw) {}
static inline int rtl_fill_h2c_cmd_work_callback(struct work_struct *work) { return 0; }
static inline int rtl_lps_change_work_callback(struct work_struct *work) { return 0; }
static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static inline void usb_get_dev(struct usb_device *udev) {}
static inline void usb_put_dev(struct usb_device *udev) {}
static inline void usb_set_intfdata(struct usb_interface *intf, void *data) {}
static inline void *kcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }

struct rtl_ops rtl_ops;
struct rtl_usb_ops rtl_usb_ops;