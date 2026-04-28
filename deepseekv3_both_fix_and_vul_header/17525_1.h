#include <stdint.h>

struct gspca_dev {
    void *dev;
    int iface;
    int alt;
};

struct sd {
    struct gspca_dev gspca_dev;
    struct {
        int (*start)(struct sd *);
    } *sensor;
};

struct usb_interface;
struct usb_host_interface {
    struct {
        uint16_t wMaxPacketSize;
        uint8_t bNumEndpoints;
    } desc;
    struct {
        struct {
            uint16_t wMaxPacketSize;
        } desc;
    } endpoint[1];
};

#define STV_ISO_SIZE_L 0
#define STV_ISO_ENABLE 0
#define D_STREAM 0
#define EIO 5
#define ENODEV 19

static int stv06xx_write_bridge(struct sd *sd, int reg, int val);
static void gspca_err(struct gspca_dev *gspca_dev, const char *fmt, ...);
static void gspca_dbg(struct gspca_dev *gspca_dev, int level, const char *fmt, ...);
static struct usb_interface *usb_ifnum_to_if(void *dev, int iface);
static struct usb_host_interface *usb_altnum_to_altsetting(struct usb_interface *intf, int alt);
static uint16_t le16_to_cpu(uint16_t val);