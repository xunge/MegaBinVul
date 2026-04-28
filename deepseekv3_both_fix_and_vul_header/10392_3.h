#include <stdint.h>
#include <stdlib.h>

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint8_t u8;

#define GFP_NOIO 0
#define ENOMEM 12
#define PEGASUS_REQ_SET_REG 0
#define PEGASUS_REQT_WRITE 0
#define drv 0

struct usb_device;
struct net_device;

typedef struct pegasus_t {
    struct usb_device *usb;
    struct net_device *net;
} pegasus_t;

void *kmemdup(const void *src, size_t len, int gfp);
int usb_control_msg(void *usb_dev, unsigned int pipe, __u8 request, __u8 requesttype, __u16 value, __u16 index, void *data, __u16 size, int timeout);
void kfree(const void *obj);
void netif_dbg(void *pegasus, int level, void *net, const char *fmt, ...);
unsigned int usb_sndctrlpipe(void *usb_dev, unsigned int endpoint);