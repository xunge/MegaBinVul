#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define PERIODIC_ACTIVE 1
#define ITD_BUFPTR_DIRECTION 0x1
#define ITD_BUFPTR_DEVADDR 0x7F
#define ITD_BUFPTR_EP 0xF
#define ITD_BUFPTR_MAXPKT 0x7FF
#define ITD_BUFPTR_MULT 0x3
#define ITD_XACT_ACTIVE (1 << 31)
#define ITD_XACT_PGSEL 0x7
#define ITD_XACT_OFFSET_MASK 0xFFF
#define ITD_XACT_LENGTH 0x7FF
#define BUFF_SIZE 4096
#define ITD_BUFPTR_MASK 0xFFFFF000
#define ITD_XACT_IOC (1 << 15)
#define ITD_XACT_XACTERR (1 << 29)
#define ITD_XACT_BABBLE (1 << 30)
#define USB_TOKEN_IN 0x69
#define USB_TOKEN_OUT 0xE1
#define USB_ENDPOINT_XFER_ISOC 0x0
#define USB_RET_SUCCESS 0
#define USB_RET_IOERROR -1
#define USB_RET_NODEV -2
#define USB_RET_BABBLE -3
#define USB_RET_NAK -4
#define USBSTS_ERRINT (1 << 2)
#define USBSTS_INT (1 << 0)

typedef struct USBDevice USBDevice;

typedef struct USBEndpoint {
    uint32_t type;
} USBEndpoint;

typedef struct QEMUSGList {
    // Minimal definition for compilation
    void *sg;
    int nsg;
} QEMUSGList;

typedef struct USBPacket {
    int status;
    uint32_t actual_length;
} USBPacket;

typedef struct EHCIState {
    int periodic_sched_active;
    QEMUSGList isgl;
    USBPacket ipacket;
    void *device;
    void *as;
} EHCIState;

typedef struct EHCIitd {
    uint32_t bufptr[3];
    uint32_t transact[8];
} EHCIitd;

static inline uint32_t get_field(uint32_t value, uint32_t mask) {
    return (value & mask) >> __builtin_ctz(mask);
}

static inline void set_field(uint32_t *value, uint32_t field, uint32_t mask) {
    *value = (*value & ~mask) | ((field << __builtin_ctz(mask)) & mask);
}

static USBDevice *ehci_find_device(EHCIState *ehci, uint32_t devaddr) {
    return NULL;
}

static USBEndpoint *usb_ep_get(USBDevice *dev, uint32_t pid, uint32_t endp) {
    return NULL;
}

static void qemu_sglist_init(QEMUSGList *sgl, void *dev, int alloc_hint, void *as) {}
static void qemu_sglist_add(QEMUSGList *sgl, uint32_t addr, uint32_t len) {}
static void qemu_sglist_destroy(QEMUSGList *sgl) {}

static void usb_packet_setup(USBPacket *p, uint32_t pid, USBEndpoint *ep,
                           uint32_t stream, uint32_t addr, bool short_not_ok,
                           bool int_req) {}
static void usb_packet_map(USBPacket *p, QEMUSGList *sgl) {}
static void usb_packet_unmap(USBPacket *p, QEMUSGList *sgl) {}
static void usb_handle_packet(USBDevice *dev, USBPacket *p) {}

static void ehci_raise_irq(EHCIState *ehci, uint32_t intr) {}

#define DPRINTF(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)