#include <stdint.h>
#include <string.h>

typedef uint32_t u32;

struct usb_endpoint_descriptor {
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
};

struct dwc3_trb {
    uint32_t field[4];
};

struct dwc3_request {
    uint64_t trb_dma;
    struct dwc3_trb *trb;
};

struct dwc3_ep {
    unsigned int flags;
    struct {
        struct usb_endpoint_descriptor *desc;
    } endpoint;
    uint32_t frame_number;
    uint32_t resource_index;
    int queued_requests;
    struct dwc3_request *started_list;
};

struct dwc3_gadget_ep_cmd_params {
    uint64_t param0;
    uint64_t param1;
};

#define DWC3_EP_BUSY            (1 << 0)
#define DWC3_EP_PENDING_REQUEST (1 << 1)

#define DWC3_DEPCMD_STARTTRANSFER   0x1
#define DWC3_DEPCMD_UPDATETRANSFER  0x2
#define DWC3_DEPCMD_PARAM(x)        ((x) << 8)

static inline uint32_t lower_32_bits(uint64_t x) {
    return (uint32_t)x;
}

static inline uint32_t upper_32_bits(uint64_t x) {
    return (uint32_t)(x >> 32);
}

static int dwc3_calc_trbs_left(struct dwc3_ep *dep) { return 0; }
static void dwc3_prepare_trbs(struct dwc3_ep *dep) {}
static struct dwc3_request *next_request(struct dwc3_request **list) { return NULL; }
static int dwc3_send_gadget_ep_cmd(struct dwc3_ep *dep, u32 cmd, struct dwc3_gadget_ep_cmd_params *params) { return 0; }
static void dwc3_gadget_giveback(struct dwc3_ep *dep, struct dwc3_request *req, int status) {}
static int dwc3_gadget_ep_get_transfer_index(struct dwc3_ep *dep) { return 0; }
static int usb_endpoint_xfer_isoc(struct usb_endpoint_descriptor *desc) { return 0; }
static void WARN_ON_ONCE(int condition) {}