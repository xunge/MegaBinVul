#include <stdlib.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;

struct usb_device;
struct firmware;

struct hexline {
    u16 addr;
    u8 len;
    u8 chk;
    u8 data[256];
};

struct cypress_type {
    u16 cpu_cs_register;
};

extern struct cypress_type cypress[];
extern int usb_cypress_writemem(struct usb_device *udev, u16 addr, u8 *buf, u8 len);
extern int dvb_usb_get_hexline(const struct firmware *fw, struct hexline *hx, int *pos);
extern void deb_fw(const char *fmt, ...);
extern void err(const char *fmt, ...);

#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22
#define EIO 5

static inline void *kmalloc(size_t size, int flags) {
    (void)flags;
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}