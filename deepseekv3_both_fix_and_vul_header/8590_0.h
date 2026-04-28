#include <stdint.h>
#include <stdbool.h>

typedef uint64_t dma_addr_t;

#define PCI_DEVICE(obj) ((PCIDevice *)obj)
#define TRB_SIZE 16
#define TRB_LINK_LIMIT 256

typedef enum TRBType {
    TR_LINK,
    TR_SETUP,
    TR_STATUS
} TRBType;

typedef struct XHCIRing {
    dma_addr_t dequeue;
    bool ccs;
} XHCIRing;

typedef struct XHCITRB {
    uint64_t parameter;
    uint32_t status;
    uint32_t control;
} XHCITRB;

typedef struct PCIDevice PCIDevice;
typedef struct XHCIState XHCIState;

#define TRB_C (1 << 0)
#define TRB_LK_TC (1 << 1)
#define TRB_TR_CH (1 << 0)

static inline uint64_t xhci_mask64(uint64_t addr) {
    return addr & ~(uint64_t)0xf;
}

static inline void le64_to_cpus(uint64_t *val) {
    *val = le64toh(*val);
}

static inline void le32_to_cpus(uint32_t *val) {
    *val = le32toh(*val);
}

static inline TRBType TRB_TYPE(XHCITRB trb) {
    return (trb.control >> 10) & 0x3f;
}