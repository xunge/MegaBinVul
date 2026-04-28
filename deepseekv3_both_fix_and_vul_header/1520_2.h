#include <stdint.h>
#include <stdbool.h>

#define CSR0_DBO (1 << 0)

typedef uint64_t hwaddr;

typedef struct {
    bool memory;
} MemTxAttrs;

#define MEMTXATTRS_UNSPECIFIED (MemTxAttrs){ .memory = false }

struct tulip_descriptor {
    uint32_t status;
    uint32_t control;
    uint32_t buf_addr1;
    uint32_t buf_addr2;
};

typedef struct {
    uint32_t csr[32];
    struct {
        void *dev;
    } dev;
} TULIPState;

static inline void stl_be_pci_dma(void *dev, hwaddr addr, uint32_t val, MemTxAttrs attrs) {}
static inline void stl_le_pci_dma(void *dev, hwaddr addr, uint32_t val, MemTxAttrs attrs) {}