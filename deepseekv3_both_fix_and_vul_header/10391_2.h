#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t u8;
typedef uint8_t __u8;
typedef uint16_t __u16;

#define GFP_NOIO 0
#define ENOMEM 12
#define PEGASUS_REQ_GET_REGS 0
#define PEGASUS_REQT_READ 0
#define netif_dbg(dev, type, netdev, fmt, ...) 
#define drv 0

struct usb_device;
struct net_device;

typedef struct pegasus {
    struct usb_device *usb;
    struct net_device *net;
} pegasus_t;

void* kmalloc(size_t size, int flags);
void kfree(void* ptr);
int usb_control_msg(void* usb_dev, unsigned int pipe, __u8 request, __u8 requesttype, __u16 value, __u16 index, void* data, __u16 size, int timeout);
unsigned int usb_rcvctrlpipe(void* usb_dev, unsigned int endpoint);