#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;

struct cam {
    struct {
        u32 priv;
    } cam_mode[16];
};

struct gspca_dev {
    struct cam cam;
    void *dev;
    int iface;
    int alt;
    int curr_mode;
};

struct sd {
    struct gspca_dev gspca_dev;
    struct {
        struct {
            int max_packet_size[16];
        } *sensor;
    };
};

struct usb_host_interface {
    struct {
        int bNumEndpoints;
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

#define ENODEV 19
#define BIT(nr) (1UL << (nr))
#define PB0100_CROP_TO_VGA 0x01
#define PB0100_SUBSAMPLE 0x02
#define PB_ROWSPEED 0x0f
#define PB_RSTART 0x08
#define PB_CSTART 0x09
#define PB_RWSIZE 0x0a
#define PB_CWSIZE 0x0b
#define PB_CONTROL 0x00
#define STV_Y_CTRL 0x01
#define STV_X_CTRL 0x02
#define STV_SCAN_RATE 0x03
#define D_STREAM 0x01

static struct usb_interface *usb_ifnum_to_if(void *dev, int iface) { return NULL; }
static struct usb_host_interface *usb_altnum_to_altsetting(struct usb_interface *intf, int alt) { return NULL; }
static uint16_t le16_to_cpu(uint16_t val) { return val; }
static int stv06xx_write_sensor(struct sd *sd, int reg, int val) { return 0; }
static int stv06xx_write_bridge(struct sd *sd, int reg, int val) { return 0; }
static void gspca_dbg(struct gspca_dev *gspca_dev, int level, const char *fmt, ...) {}