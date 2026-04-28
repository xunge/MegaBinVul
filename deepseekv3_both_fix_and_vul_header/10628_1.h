#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

#define OHCI_DPTR_MASK 0xfffffff0
#define OHCI_PAGE_MASK 0xfffff000
#define OHCI_OFFSET_MASK 0x00000fff

#define OHCI_BM(val, field) (((val) >> field##_SHIFT) & field##_MASK)
#define OHCI_SET_BM(val, field, new_val) \
    ((val) = ((val) & ~(field##_MASK << field##_SHIFT)) | \
             (((new_val) & field##_MASK) << field##_SHIFT))

#define USUB(a, b) ((int16_t)((a) - (b)))

#define TD_SF_SHIFT 0
#define TD_SF_MASK 0xffff
#define TD_FC_SHIFT 16
#define TD_FC_MASK 0x7f
#define TD_DI_SHIFT 21
#define TD_DI_MASK 0x7
#define TD_CC_SHIFT 28
#define TD_CC_MASK 0xf

#define ED_D_SHIFT 19
#define ED_D_MASK 0x3
#define ED_FA_SHIFT 0
#define ED_FA_MASK 0x7f
#define ED_EN_SHIFT 7
#define ED_EN_MASK 0xf

#define TD_PSW_CC_SHIFT 12
#define TD_PSW_CC_MASK 0xf
#define TD_PSW_SIZE_SHIFT 0
#define TD_PSW_SIZE_MASK 0xfff

#define OHCI_TD_DIR_IN 1
#define OHCI_TD_DIR_OUT 2
#define OHCI_TD_DIR_SETUP 0

#define OHCI_CC_NOERROR 0
#define OHCI_CC_DATAOVERRUN 5
#define OHCI_CC_DATAUNDERRUN 4
#define OHCI_CC_DEVICENOTRESPONDING 2
#define OHCI_CC_STALL 3
#define OHCI_CC_UNDEXPETEDPID 6

#define USB_TOKEN_IN 0x69
#define USB_TOKEN_OUT 0xe1
#define USB_TOKEN_SETUP 0x2d

#define USB_RET_SUCCESS 0
#define USB_RET_IOERROR -1
#define USB_RET_NODEV -2
#define USB_RET_NAK -3
#define USB_RET_STALL -4
#define USB_RET_ASYNC -5

enum DMA_DIRECTION {
    DMA_DIRECTION_TO_DEVICE,
    DMA_DIRECTION_FROM_DEVICE
};

struct ohci_ed {
    uint32_t flags;
    uint32_t head;
    uint32_t tail;
};

struct ohci_iso_td {
    uint32_t flags;
    uint32_t bp;
    uint32_t next;
    uint32_t be;
    uint16_t offset[8];
};

typedef struct USBDevice USBDevice;
typedef struct USBEndpoint USBEndpoint;
typedef struct OHCIState OHCIState;

struct OHCIState {
    uint16_t frame_number;
    uint32_t done;
    int done_count;
    uint8_t usb_buf[4096];
    struct {
        int status;
        int actual_length;
    } usb_packet;
};

static inline void trace_usb_ohci_iso_td_read_failed(uint32_t addr) {}
static inline void trace_usb_ohci_iso_td_head(uint32_t head, uint32_t tail, 
    uint32_t flags, uint32_t bp, uint32_t next, uint32_t be,
    uint16_t frame_number, uint16_t starting_frame,
    int frame_count, int16_t relative_frame_number) {}
static inline void trace_usb_ohci_iso_td_head_offset(
    uint16_t o0, uint16_t o1, uint16_t o2, uint16_t o3,
    uint16_t o4, uint16_t o5, uint16_t o6, uint16_t o7) {}
static inline void trace_usb_ohci_iso_td_relative_frame_number_neg(int16_t rel) {}
static inline void trace_usb_ohci_iso_td_relative_frame_number_big(int16_t rel, int fc) {}
static inline void trace_usb_ohci_iso_td_bad_direction(int dir) {}
static inline void trace_usb_ohci_iso_td_bad_bp_be(uint32_t bp, uint32_t be) {}
static inline void trace_usb_ohci_iso_td_bad_cc_not_accessed(uint16_t so, uint16_t no) {}
static inline void trace_usb_ohci_iso_td_bad_cc_overrun(uint16_t so, uint16_t no) {}
static inline void trace_usb_ohci_iso_td_so(uint16_t so, uint16_t eo, 
    uint32_t sa, uint32_t ea, const char *str, size_t len, int ret) {}
static inline void trace_usb_ohci_iso_td_data_overrun(int ret, size_t len) {}
static inline void trace_usb_ohci_iso_td_data_underrun(int ret) {}
static inline void trace_usb_ohci_iso_td_nak(int ret) {}
static inline void trace_usb_ohci_iso_td_bad_response(int ret) {}

static inline void ohci_die(OHCIState *ohci) {}

static inline int ohci_read_iso_td(OHCIState *ohci, uint32_t addr, 
                                  struct ohci_iso_td *td) { return 0; }
static inline int ohci_put_iso_td(OHCIState *ohci, uint32_t addr, 
                                 struct ohci_iso_td *td) { return 0; }
static inline int ohci_copy_iso_td(OHCIState *ohci, uint32_t start, uint32_t end,
                                  void *buf, size_t len, enum DMA_DIRECTION dir) { return 0; }
static inline USBDevice *ohci_find_device(OHCIState *ohci, int addr) { return NULL; }
static inline USBEndpoint *usb_ep_get(USBDevice *dev, int pid, int ep) { return NULL; }
static inline void usb_packet_setup(void *pkt, int pid, USBEndpoint *ep, 
                                  int stream, uint32_t addr, bool short_not_ok,
                                  bool int_req) {}
static inline void usb_packet_addbuf(void *pkt, void *buf, size_t len) {}
static inline void usb_handle_packet(USBDevice *dev, void *pkt) {}
static inline void usb_device_flush_ep_queue(USBDevice *dev, USBEndpoint *ep) {}