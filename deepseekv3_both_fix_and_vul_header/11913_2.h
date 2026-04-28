#include <stdint.h>
#include <stdio.h>

struct usb_descriptor_header {
    uint8_t bLength;
    uint8_t bDescriptorType;
};

extern const char *usbcore_name;

#define KERN_ERR ""
#define printk printf