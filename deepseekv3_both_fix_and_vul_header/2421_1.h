#include <stdbool.h>
#include <string.h>

struct device;

struct usb_interface {
    struct device *dev;
};

struct usb_cdc_parsed_header {
    bool phonet_magic_present;
    struct usb_cdc_union_desc *usb_cdc_union_desc;
    struct usb_cdc_header_desc *usb_cdc_header_desc;
    struct usb_cdc_mdlm_detail_desc *usb_cdc_mdlm_detail_desc;
    struct usb_cdc_mdlm_desc *usb_cdc_mdlm_desc;
    struct usb_cdc_ether_desc *usb_cdc_ether_desc;
    struct usb_cdc_country_functional_desc *usb_cdc_country_functional_desc;
    struct usb_cdc_acm_descriptor *usb_cdc_acm_descriptor;
    struct usb_cdc_call_mgmt_descriptor *usb_cdc_call_mgmt_descriptor;
    struct usb_cdc_dmm_desc *usb_cdc_dmm_desc;
    struct usb_cdc_ncm_desc *usb_cdc_ncm_desc;
    struct usb_cdc_mbim_desc *usb_cdc_mbim_desc;
    struct usb_cdc_mbim_extended_desc *usb_cdc_mbim_extended_desc;
};

struct usb_cdc_union_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_header_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_ether_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_mdlm_detail_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_mdlm_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_country_functional_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_acm_descriptor {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_call_mgmt_descriptor {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_dmm_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_ncm_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_mbim_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

struct usb_cdc_mbim_extended_desc {
    unsigned char bLength;
    unsigned char bDescriptorType;
    unsigned char bDescriptorSubType;
};

#define USB_DT_CS_INTERFACE 0x24
#define USB_CDC_UNION_TYPE 0x06
#define USB_CDC_COUNTRY_TYPE 0x07
#define USB_CDC_HEADER_TYPE 0x00
#define USB_CDC_ACM_TYPE 0x02
#define USB_CDC_ETHERNET_TYPE 0x0F
#define USB_CDC_CALL_MANAGEMENT_TYPE 0x01
#define USB_CDC_DMM_TYPE 0x14
#define USB_CDC_MDLM_TYPE 0x12
#define USB_CDC_MDLM_DETAIL_TYPE 0x13
#define USB_CDC_NCM_TYPE 0x1A
#define USB_CDC_MBIM_TYPE 0x1B
#define USB_CDC_MBIM_EXTENDED_TYPE 0x1C
#define CDC_PHONET_MAGIC_NUMBER 0xAB

#define EINVAL 22

typedef unsigned char u8;

static inline void dev_err(const struct device *dev, const char *fmt, ...) {}
static inline void dev_dbg(const struct device *dev, const char *fmt, ...) {}