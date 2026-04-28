#include <string.h>
#include <errno.h>

#define MAX_XFER_SIZE 64
#define EOPNOTSUPP 95

typedef unsigned char u8;

struct mutex {
    int dummy;
};

struct cxusb_state {
    u8 data[MAX_XFER_SIZE];
};

struct dvb_usb_device {
    struct mutex data_mutex;
    struct cxusb_state *priv;
};

extern int dvb_usb_generic_write(struct dvb_usb_device *d, u8 *buf, int len);
extern int dvb_usb_generic_rw(struct dvb_usb_device *d, u8 *wbuf, int wlen, u8 *rbuf, int rlen, int delay_ms);

void warn(const char *fmt, ...);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);