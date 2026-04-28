#include <stdint.h>
#include <string.h>
#include <errno.h>

struct urb {
    void *context;
    int status;
    int actual_length;
};

struct usb_interface {
    struct {
        int dev;
    } dev;
};

struct wdm_device {
    int iuspin;
    unsigned long flags;
    struct usb_interface *intf;
    int rerr;
    int length;
    int wMaxCommand;
    int reslength;
    unsigned char *ubuf;
    unsigned char *inbuf;
    int wait;
};

#define WDM_RESPONDING 0
#define WDM_OVERFLOW 1
#define WDM_READ 2

#define spin_lock(x) (void)(x)
#define spin_unlock(x) (void)(x)
#define clear_bit(nr, addr) (void)(nr), (void)(addr)
#define set_bit(nr, addr) (void)(nr), (void)(addr)
#define test_bit(nr, addr) (0)
#define wake_up(x) (void)(x)
#define dev_dbg(dev, fmt, ...) (void)(dev), (void)(fmt)
#define dev_err(dev, fmt, ...) (void)(dev), (void)(fmt)