#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t __u16;

struct pegasus {
    void *usb;
    void *net;
};

typedef struct pegasus pegasus_t;

#define PEGASUS_REQ_SET_REGS 0
#define PEGASUS_REQT_WRITE 0
#define GFP_NOIO 0
#define ENOMEM 12
#define drv 0

static inline void *kmemdup(const void *src, size_t len, unsigned gfp) {
    void *p = malloc(len);
    if (p) memcpy(p, src, len);
    return p;
}

static inline void kfree(void *p) {
    free(p);
}

static inline int usb_control_msg(void *usb, void *pipe, int request, int requesttype,
                                 int value, int index, void *data, int size, int timeout) {
    return 0;
}

static inline void *usb_sndctrlpipe(void *usb, int endpoint) {
    return NULL;
}

#define netif_dbg(dev, level, netdev, fmt, ...)