#include <stdint.h>
#include <errno.h>

struct usb_host_interface {
    struct {
        struct {
            uint16_t wMaxPacketSize;
        } desc;
    } endpoint[1];
};

struct usb_interface_cache {
    struct usb_host_interface altsetting[2];
};

struct usb_config_descriptor {
    struct usb_interface_cache *intf_cache[1];
};

struct usb_device {
    struct usb_config_descriptor *actconfig;
};

struct gspca_dev {
    struct usb_device *dev;
    int iface;
    int curr_mode;
};

struct sd {
    struct gspca_dev *gspca_dev;
    struct {
        int *min_packet_size;
    } *sensor;
};

static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint16_t cpu_to_le16(uint16_t x) { return x; }
int usb_set_interface(void *dev, int iface, int alt);
void gspca_err(struct gspca_dev *gspca_dev, const char *fmt, ...);