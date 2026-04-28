#include <stdint.h>

#define ENODEV 19

struct usb_host_interface {
    struct {
        uint8_t bNumEndpoints;
    } desc;
    struct {
        struct {
            uint16_t wMaxPacketSize;
        } desc;
    } endpoint[1];
};

struct usb_interface_cache {
    int num_altsetting;
    struct usb_host_interface altsetting[2];
};

struct gspca_dev {
    struct {
        struct {
            struct usb_interface_cache **intf_cache;
        } *actconfig;
    } *dev;
    int curr_mode;
};

struct sd {
    struct gspca_dev *gspca_dev;
    struct {
        int *max_packet_size;
    } *sensor;
};

static uint16_t cpu_to_le16(uint16_t x) {
    return x;
}