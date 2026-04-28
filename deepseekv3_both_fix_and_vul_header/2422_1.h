#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define GFP_KERNEL 0
#define ENOMEM (-1)
#define ENOMSG (-2)
#define EINVAL (-3)

#define USB_DT_BOS_SIZE 5
#define USB_DT_BOS 0x0f
#define USB_DT_DEVICE_CAPABILITY 0x10
#define USB_CAP_TYPE_WIRELESS_USB 0x01
#define USB_CAP_TYPE_EXT 0x02
#define USB_SS_CAP_TYPE 0x03
#define USB_SSP_CAP_TYPE 0x0a
#define CONTAINER_ID_TYPE 0x04
#define USB_PTM_CAP_TYPE 0x05

struct device {
    const char *name;
};

struct usb_bos_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t wTotalLength;
    uint8_t bNumDeviceCaps;
};

struct usb_dev_cap_header {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDevCapabilityType;
};

struct usb_ext_cap_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDevCapabilityType;
    uint32_t bmAttributes;
};

struct usb_ss_cap_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDevCapabilityType;
    uint8_t bmAttributes;
    uint16_t wSpeedSupported;
    uint8_t bFunctionalitySupport;
    uint8_t bU1devExitLat;
    uint16_t bU2DevExitLat;
};

struct usb_ssp_cap_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDevCapabilityType;
    uint8_t bmAttributes;
    uint16_t wFunctionalitySupport;
    uint16_t wReserved;
    uint32_t bmSublinkSpeedAttr[1];
};

struct usb_ss_container_id_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDevCapabilityType;
    uint8_t bReserved;
    uint8_t ContainerID[16];
};

struct usb_ptm_cap_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bDevCapabilityType;
};

struct usb_host_bos {
    struct usb_bos_descriptor *desc;
    struct usb_ext_cap_descriptor *ext_cap;
    struct usb_ss_cap_descriptor *ss_cap;
    struct usb_ssp_cap_descriptor *ssp_cap;
    struct usb_ss_container_id_descriptor *ss_id;
    struct usb_ptm_cap_descriptor *ptm_cap;
};

struct usb_device {
    struct device dev;
    struct usb_host_bos *bos;
};

static inline uint16_t le16_to_cpu(uint16_t x) {
    return x;
}

static void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static void kfree(void *ptr) {
    free(ptr);
}

static void dev_err(struct device *dev, const char *fmt, ...) {}
static void dev_warn(struct device *dev, const char *fmt, ...) {}

int usb_get_descriptor(struct usb_device *dev, int type, int index, void *buf, int size);
void usb_release_bos_descriptor(struct usb_device *dev);