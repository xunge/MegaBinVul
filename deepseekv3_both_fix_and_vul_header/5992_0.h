#include <stdint.h>

struct xhci_trb {
    uint64_t qwTrb0;
    uint32_t dwTrb2;
    uint32_t dwTrb3;
};

struct pci_xhci_opregs {
    uint64_t crcr;
    struct xhci_trb *cr_p;
};

struct pci_xhci_vdev {
    struct pci_xhci_opregs opregs;
};

#define XHCI_CRCR_LO_CRR    (1 << 3)
#define XHCI_CRCR_LO_RCS    (1 << 0)
#define XHCI_CRCR_LO_CA     (1 << 2)
#define XHCI_TRB_3_CYCLE_BIT (1 << 0)
#define XHCI_TRB_3_TC_BIT    (1 << 1)
#define XHCI_TRB_3_TYPE_GET(x) (((x) >> 10) & 0x3f)
#define XHCI_TRB_3_TYPE_SET(x) ((x) << 10)
#define XHCI_TRB_3_SLOT_SET(x) ((x) << 24)
#define XHCI_TRB_2_ERROR_SET(x) ((x) << 24)
#define XHCI_TRB_EVENT_CMD_COMPLETE 0x20
#define XHCI_TRB_ERROR_SUCCESS 0

#define XHCI_TRB_TYPE_LINK 0x06
#define XHCI_TRB_TYPE_ENABLE_SLOT 0x09
#define XHCI_TRB_TYPE_DISABLE_SLOT 0x0A
#define XHCI_TRB_TYPE_ADDRESS_DEVICE 0x0B
#define XHCI_TRB_TYPE_CONFIGURE_EP 0x0C
#define XHCI_TRB_TYPE_EVALUATE_CTX 0x0D
#define XHCI_TRB_TYPE_RESET_EP 0x0E
#define XHCI_TRB_TYPE_STOP_EP 0x0F
#define XHCI_TRB_TYPE_SET_TR_DEQUEUE 0x10
#define XHCI_TRB_TYPE_RESET_DEVICE 0x11
#define XHCI_TRB_TYPE_FORCE_EVENT 0x12
#define XHCI_TRB_TYPE_NEGOTIATE_BW 0x13
#define XHCI_TRB_TYPE_SET_LATENCY_TOL 0x14
#define XHCI_TRB_TYPE_GET_PORT_BW 0x15
#define XHCI_TRB_TYPE_FORCE_HEADER 0x16
#define XHCI_TRB_TYPE_NOOP_CMD 0x17

#define XHCI_GET_SLOT(xdev, trb, slot, cmderr) \
    do { \
        slot = 0; \
        cmderr = XHCI_TRB_ERROR_SUCCESS; \
    } while (0)

#define UPRINTF(level, fmt, ...) 

#define LDBG 0
#define LFTL 1
#define ENAVAIL (-1)