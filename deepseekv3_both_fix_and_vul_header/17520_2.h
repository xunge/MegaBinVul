#include <stdint.h>
#include <stddef.h>

struct gspca_dev {
    void *dev;
    int iface;
    int alt;
    int usb_err;
    struct {
        int width;
        int height;
    } pixfmt;
};

struct sd {
    struct gspca_dev gspca_dev;
    int frame_rate;
    int clockdiv;
    int sensor;
};

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

struct usb_interface {
    int dummy;
};

enum {
    SEN_OV6620,
    SEN_OV6630,
    SEN_OV7610,
    SEN_OV7620,
    SEN_OV7620AE,
    SEN_OV7640,
    SEN_OV7648,
    SEN_OV76BE,
    SEN_OV7670,
    SEN_OV8610
};

#define EIO 5
#define ENODEV 19
#define OV511_RESET_OMNICE 0x08
#define R51x_FIFO_PSIZE 0
#define R511_CAM_UV_EN 0
#define R511_SNAP_UV_EN 0
#define R511_SNAP_OPTS 0
#define R511_CAM_PXCNT 0
#define R511_CAM_LNCNT 0
#define R511_CAM_PXDIV 0
#define R511_CAM_LNDIV 0
#define R511_CAM_OPTS 0
#define R511_SNAP_PXCNT 0
#define R511_SNAP_LNCNT 0
#define R511_SNAP_PXDIV 0
#define R511_SNAP_LNDIV 0
#define R511_COMP_EN 0
#define R511_COMP_LUT_EN 0
#define R51x_SYS_RESET 0

static int frame_rate;

static uint16_t le16_to_cpu(uint16_t x) { return x; }
static struct usb_interface *usb_ifnum_to_if(void *dev, int iface) { return NULL; }
static struct usb_host_interface *usb_altnum_to_altsetting(struct usb_interface *intf, int alt) { return NULL; }
static void gspca_err(struct gspca_dev *gspca_dev, const char *fmt, ...) {}
static void reg_w(struct sd *sd, int reg, int val) {}