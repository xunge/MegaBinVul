#include <stdint.h>
#include <stddef.h>

#define LG_RDESC 0x1
#define LG_RDESC_REL_ABS 0x2

#define USB_DEVICE_ID_LOGITECH_WHEEL 0xc294
#define USB_DEVICE_ID_LOGITECH_MOMO_WHEEL 0xc295
#define USB_DEVICE_ID_LOGITECH_MOMO_WHEEL2 0xc298
#define USB_DEVICE_ID_LOGITECH_VIBRATION_WHEEL 0xc299
#define USB_DEVICE_ID_LOGITECH_DFP_WHEEL 0xc293
#define USB_DEVICE_ID_LOGITECH_WII_WHEEL 0xc2a0

#define DF_RDESC_ORIG_SIZE 97
#define MOMO_RDESC_ORIG_SIZE 87
#define MOMO2_RDESC_ORIG_SIZE 87
#define FV_RDESC_ORIG_SIZE 87
#define DFP_RDESC_ORIG_SIZE 97

typedef uint8_t __u8;
typedef uint16_t __u16;

struct lg_drv_data {
    unsigned int quirks;
};

struct hid_device {
    uint16_t product;
};

struct usb_device_descriptor {
    uint16_t bcdDevice;
};

struct usb_device {
    struct usb_device_descriptor descriptor;
};

static __u8 df_rdesc_fixed[1];
static __u8 momo_rdesc_fixed[1];
static __u8 momo2_rdesc_fixed[1];
static __u8 fv_rdesc_fixed[1];
static __u8 dfp_rdesc_fixed[1];

static inline uint16_t le16_to_cpu(uint16_t val) {
    return val;
}

static inline struct usb_device* hid_to_usb_dev(struct hid_device* hdev) {
    return NULL;
}

static inline void hid_info(struct hid_device* hdev, const char* fmt, ...) {}
static inline void hid_err(struct hid_device* hdev, const char* fmt, ...) {}
static inline struct lg_drv_data* hid_get_drvdata(struct hid_device* hdev) {
    return NULL;
}