#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define PERIODIC_ACTIVE 1
#define ITD_BUFPTR_DIRECTION 0x1
#define ITD_BUFPTR_DEVADDR 0x7F
#define ITD_BUFPTR_EP 0xF
#define ITD_BUFPTR_MAXPKT 0x7FF
#define ITD_BUFPTR_MULT 0x3
#define ITD_BUFPTR_MASK 0xFFFFF000
#define ITD_XACT_ACTIVE 0x1
#define ITD_XACT_PGSEL 0x3
#define ITD_XACT_OFFSET_MASK 0xFFF
#define ITD_XACT_LENGTH 0x7FF
#define ITD_XACT_IOC 0x1
#define ITD_XACT_XACTERR 0x1
#define ITD_XACT_BABBLE 0x1
#define BUFF_SIZE 4096
#define USB_TOKEN_IN 0x1
#define USB_TOKEN_OUT 0x0
#define USB_ENDPOINT_XFER_ISOC 0x1
#define USB_RET_SUCCESS 0
#define USB_RET_IOERROR -1
#define USB_RET_NODEV -2
#define USB_RET_BABBLE -3
#define USB_RET_NAK -4
#define USBSTS_ERRINT 0x1
#define USBSTS_INT 0x1

typedef struct EHCIState {
    int periodic_sched_active;
    void *device;
    void *as;
    struct {
        int status;
        int actual_length;
    } ipacket;
    struct {
        int dummy;
    } isgl;
} EHCIState;

typedef struct EHCIitd {
    uint32_t bufptr[3];
    uint32_t transact[8];
} EHCIitd;

typedef struct USBDevice {
    int dummy;
} USBDevice;

typedef struct USBEndpoint {
    int type;
} USBEndpoint;

static inline uint32_t get_field(uint32_t value, uint32_t mask) {
    return value & mask;
}

static inline void set_field(uint32_t *ptr, uint32_t value, uint32_t mask) {
    *ptr = (*ptr & ~mask) | (value & mask);
}

#define DPRINTF(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

static USBDevice *ehci_find_device(EHCIState *ehci, uint32_t devaddr) {
    return NULL;
}

static USBEndpoint *usb_ep_get(USBDevice *dev, uint32_t pid, uint32_t endp) {
    return NULL;
}

static void usb_packet_setup(void *p, uint32_t pid, USBEndpoint *ep,
                            uint32_t stream, uint32_t addr, bool short_not_ok,
                            bool int_req) {}

static void usb_packet_map(void *p, void *sgl) {}

static void usb_handle_packet(USBDevice *dev, void *p) {}

static void usb_packet_unmap(void *p, void *sgl) {}

static void qemu_sglist_init(void *sgl, void *dev, int n, void *as) {}

static void qemu_sglist_add(void *sgl, uint32_t addr, uint32_t len) {}

static void qemu_sglist_destroy(void *sgl) {}

static void ehci_raise_irq(EHCIState *ehci, uint32_t status) {}