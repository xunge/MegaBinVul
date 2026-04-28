#include <stdlib.h>
#include <string.h>

typedef unsigned short u16;

typedef struct rtl8150_t {
    void *udev;
} rtl8150_t;

#define GFP_NOIO 0
#define ENOMEM 12
#define RTL8150_REQ_GET_REGS 0
#define RTL8150_REQT_READ 0

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int usb_control_msg(void *udev, void *pipe, int request, int requesttype, int value, int index, void *data, int size, int timeout) { return 0; }
static inline void *usb_rcvctrlpipe(void *udev, int endpoint) { return NULL; }