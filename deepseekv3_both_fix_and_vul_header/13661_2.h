#include <stdint.h>
#include <stdlib.h>
#include <stdatomic.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef uint16_t __u16;
typedef uint8_t __u8;
typedef uintptr_t dma_addr_t;

#define GFP_KERNEL 0
#define ENOMEM 1
#define ENODEV 2
#define GS_MAX_RX_URBS 10
#define GSUSB_ENDPOINT_IN 1
#define GS_USB_BREQ_MODE 2
#define GS_CAN_MODE_LOOP_BACK 1
#define GS_CAN_MODE_LISTEN_ONLY 2
#define GS_CAN_MODE_ONE_SHOT 4
#define GS_CAN_MODE_TRIPLE_SAMPLE 8
#define GS_CAN_MODE_START 16
#define CAN_STATE_ERROR_ACTIVE 1
#define CAN_CTRLMODE_LOOPBACK 1
#define CAN_CTRLMODE_LISTENONLY 2
#define CAN_CTRLMODE_ONE_SHOT 4
#define CAN_CTRLMODE_3_SAMPLES 8
#define USB_DIR_OUT 0
#define USB_TYPE_VENDOR (2 << 5)
#define USB_RECIP_INTERFACE 1
#define URB_NO_TRANSFER_DMA_MAP (1 << 0)

struct net_device;
struct usb_device;
struct usb_interface;

struct urb {
    dma_addr_t transfer_dma;
    unsigned int transfer_flags;
};

struct usb_anchor {
    int dummy;
};

struct gs_can {
    struct gs_usb *parent;
    struct usb_device *udev;
    struct net_device *netdev;
    struct usb_interface *iface;
    struct {
        u32 ctrlmode;
        int state;
    } can;
    int channel;
};

struct gs_usb {
    _Atomic int active_channels;
    struct usb_anchor rx_submitted;
};

struct gs_host_frame {
    u8 data[64];
};

struct gs_device_mode {
    u32 flags;
    u32 mode;
};

void gs_usb_receive_bulk_callback(struct urb *urb);