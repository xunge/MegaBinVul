#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef struct DWC2State {
    uint32_t *hreg1;
    struct DWC2Packet *packet;
    void *dma_as;
    uint8_t **usb_buf;
} DWC2State;

typedef struct USBDevice USBDevice;
typedef struct USBEndpoint USBEndpoint;

typedef struct USBPacket {
    int status;
    uint32_t actual_length;
} USBPacket;

typedef struct DWC2Packet {
    USBPacket packet;
    bool small;
    uint32_t devadr;
    uint32_t epnum;
    uint32_t epdir;
    uint32_t mps;
    uint32_t pid;
    uint32_t index;
    uint32_t pcnt;
    uint32_t len;
    uint32_t async;
    bool needs_service;
} DWC2Packet;

#define DWC2_MAX_XFER_SIZE 65536
#define LOG_GUEST_ERROR 1

#define HCCHAR_EPNUM 0x7F000000
#define HCCHAR_EPDIR 0x00000080
#define HCCHAR_EPTYPE 0x00000030
#define HCCHAR_MPS 0x000007FF
#define HCCHAR_CHENA 0x80000000

#define TSIZ_SC_MC_PID 0x18000000
#define TSIZ_SC_MC_PID_SETUP 0x18000000
#define TSIZ_PKTCNT 0x1FF80000
#define TSIZ_XFERSIZE 0x0007FFFF

#define USB_ENDPOINT_XFER_CONTROL 0
#define USB_ENDPOINT_XFER_BULK 2

#define USB_TOKEN_SETUP 0
#define USB_TOKEN_IN 1
#define USB_TOKEN_OUT 2

#define USB_RET_SUCCESS 0
#define USB_RET_NAK -1
#define USB_RET_STALL -2
#define USB_RET_ASYNC -3
#define USB_RET_BABBLE -4

#define HCINTMSK_RESERVED14_31 0xFFFFC000
#define HCINTMSK_CHHLTD 0x00000001
#define HCINTMSK_XFERCOMPL 0x00000002

#define DWC2_ASYNC_NONE 0
#define DWC2_ASYNC_INFLIGHT 1

static inline uint32_t get_field(uint32_t val, uint32_t mask) {
    return (val & mask) >> __builtin_ctz(mask);
}
static inline bool get_bit(uint32_t val, uint32_t bit) {
    return val & bit;
}
static inline void set_field(uint32_t *val, uint32_t field, uint32_t mask) {
    *val = (*val & ~mask) | ((field << __builtin_ctz(mask)) & mask);
}

static const char *pstatus[] = {"OK", "NAK", "STALL", "ASYNC", "BABBLE"};
static const char *types[] = {"CTRL", "ISO", "BULK", "INT"};
static const char *dirs[] = {"OUT", "IN"};
static const uint32_t pintr[] = {0, HCINTMSK_CHHLTD, HCINTMSK_CHHLTD, HCINTMSK_CHHLTD, HCINTMSK_CHHLTD};

static void dwc2_update_hc_irq(DWC2State *s, uint32_t index) {}

static void qemu_log_mask(int mask, const char *fmt, ...) {}
static void trace_usb_dwc2_handle_packet(int chan, USBDevice *dev, void *packet, uint32_t epnum, const char *type, const char *dir, uint32_t mps, uint32_t len, uint32_t pcnt) {}
static void trace_usb_dwc2_memory_read(uint32_t addr, uint32_t len) {}
static void trace_usb_dwc2_memory_write(uint32_t addr, uint32_t len) {}
static void trace_usb_dwc2_packet_status(const char *status, uint32_t actual) {}
static void trace_usb_dwc2_packet_error(const char *status) {}
static void trace_usb_dwc2_async_packet(void *packet, int chan, USBDevice *dev, uint32_t epnum, const char *dir, uint32_t len) {}
static void trace_usb_dwc2_packet_done(const char *status, uint32_t actual, uint32_t len, uint32_t pcnt) {}
static void trace_usb_dwc2_packet_next(const char *status, uint32_t len, uint32_t pcnt) {}

static void usb_packet_init(USBPacket *pkt) {}
static void usb_packet_setup(USBPacket *pkt, uint32_t pid, USBEndpoint *ep, uint32_t stream, uint32_t addr, bool out, bool setup) {}
static void usb_packet_addbuf(USBPacket *pkt, void *buf, uint32_t len) {}
static void usb_handle_packet(USBDevice *dev, USBPacket *pkt) {}
static void usb_device_flush_ep_queue(USBDevice *dev, USBEndpoint *ep) {}
static void usb_packet_cleanup(USBPacket *pkt) {}

typedef enum {
    MEMTX_OK,
    MEMTX_ERROR
} MEMTXResult;

static MEMTXResult dma_memory_read(void *as, uint32_t addr, void *buf, uint32_t len) { return MEMTX_OK; }
static MEMTXResult dma_memory_write(void *as, uint32_t addr, const void *buf, uint32_t len) { return MEMTX_OK; }