#include <stdint.h>
#include <stdbool.h>

typedef uint64_t hwaddr;

typedef struct MemTxAttrs {
    bool memory;
} MemTxAttrs;

#define MEMTXATTRS_UNSPECIFIED ((MemTxAttrs){ .memory = false })

struct PCIDevice {
    /* dummy structure */
    int dummy;
};

struct tulip_descriptor {
    uint32_t status;
    uint32_t control;
    uint32_t buf_addr1;
    uint32_t buf_addr2;
};

typedef struct TULIPState {
    struct PCIDevice dev;
    uint32_t csr[1];
} TULIPState;

#define CSR0_DBO (1 << 0)

void ldl_be_pci_dma(struct PCIDevice *dev, hwaddr addr, uint32_t *val, MemTxAttrs attrs);
void ldl_le_pci_dma(struct PCIDevice *dev, hwaddr addr, uint32_t *val, MemTxAttrs attrs);