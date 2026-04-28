#include <stdint.h>
#include <assert.h>
#include <stddef.h>

typedef struct USBDevice {
    int attached;
} USBDevice;

typedef struct USBPort {
    USBDevice *dev;
} USBPort;

typedef struct USBEndpoint {
    USBDevice *dev;
} USBEndpoint;

typedef struct XHCITransfer {
    int running_retry;
    int timed_xfer;
    int iso_xfer;
    int complete;
    struct {
        USBEndpoint *ep;
        int status;
    } packet;
    void *trbs;
    unsigned int streamid;
} XHCITransfer;

typedef struct XHCIRing {
    uint64_t dequeue;
} XHCIRing;

typedef struct XHCIStreamContext {
    XHCIRing ring;
} XHCIStreamContext;

typedef enum {
    EP_HALTED,
    EP_RUNNING
} XHCIEPState;

typedef struct XHCISlot {
    USBPort *uport;
} XHCISlot;

typedef struct XHCIState {
    XHCISlot slots[256];
} XHCIState;

typedef struct XHCIEPContext {
    XHCIState *xhci;
    int kick_active;
    int slotid;
    int epid;
    XHCITransfer *retry;
    XHCIEPState state;
    unsigned int nr_pstreams;
    XHCIRing ring;
} XHCIEPContext;

typedef enum {
    USB_RET_NAK
} USBRetCode;

typedef enum {
    TRB_TYPE_NORMAL,
    TRB_TYPE_SETUP,
    TRB_TYPE_DATA,
    TRB_TYPE_STATUS
} TRBType;

#define DPRINTF(fmt, ...) 
#define trace_usb_xhci_ep_kick(slotid, epid, streamid)
#define trace_usb_xhci_xfer_retry(xfer)