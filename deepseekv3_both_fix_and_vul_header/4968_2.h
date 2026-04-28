#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define DJ_DEVICE_INDEX_MIN 1
#define DJ_DEVICE_INDEX_MAX 6
#define DEVICE_PAIRED_PARAM_SPFUNCTION 0
#define DEVICE_PAIRED_PARAM_EQUAD_ID_MSB 1
#define DEVICE_PAIRED_PARAM_EQUAD_ID_LSB 2
#define DEVICE_PAIRED_RF_REPORT_TYPE 3

#define SPFUNCTION_DEVICE_LIST_EMPTY 0x01
#define BUS_USB 0x03
#define GFP_KERNEL 0

struct device {
    struct device *parent;
};

struct usb_device {
    struct {
        uint16_t idVendor;
        uint16_t idProduct;
    } descriptor;
};

struct usb_interface {
};

struct hid_device {
    struct device dev;
    const void *ll_driver;
    int bus;
    uint16_t vendor;
    uint16_t product;
    char name[128];
    char phys[64];
    void *driver_data;
};

struct dj_report {
    unsigned char device_index;
    unsigned char report_params[32];
};

struct dj_device {
    struct hid_device *hdev;
    void *dj_receiver_dev;
    uint32_t reports_supported;
    unsigned char device_index;
};

struct dj_receiver_dev {
    struct hid_device *hdev;
    bool querying_devices;
    struct dj_device *paired_dj_devices[DJ_DEVICE_INDEX_MAX + 1];
};

extern const void logi_dj_ll_driver;
extern void *hid_allocate_device(void);
extern int hid_add_device(struct hid_device *hdev);
extern void hid_destroy_device(struct hid_device *hdev);
extern void *kzalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern uint16_t le16_to_cpu(uint16_t val);
extern uint32_t get_unaligned_le32(const void *p);
extern struct usb_interface *to_usb_interface(struct device *dev);
extern struct usb_device *interface_to_usbdev(struct usb_interface *intf);
extern int usb_make_path(struct usb_device *dev, char *buf, size_t size);
extern int snprintf(char *str, size_t size, const char *format, ...);
extern size_t strlcat(char *dst, const char *src, size_t size);
extern void dbg_hid(const char *fmt, ...);
extern void dev_err(struct device *dev, const char *fmt, ...);
extern int IS_ERR(const void *ptr);