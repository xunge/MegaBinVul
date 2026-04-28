#include <stdlib.h>
#include <string.h>

typedef unsigned short u16;
typedef struct rtl8150_t {
    void *udev;
} rtl8150_t;

#define GFP_NOIO 0
#define ENOMEM 12
#define RTL8150_REQ_SET_REGS 0
#define RTL8150_REQT_WRITE 0

static void *kmemdup(const void *src, size_t len, int flags) {
    void *dst = malloc(len);
    if (dst)
        memcpy(dst, src, len);
    return dst;
}

static void kfree(void *ptr) {
    free(ptr);
}

static int usb_control_msg(void *udev, int pipe, int request, int requesttype,
                          int value, int index, void *data, int size, int timeout) {
    return 0;
}

static int usb_sndctrlpipe(void *udev, int endpoint) {
    return 0;
}