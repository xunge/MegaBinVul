#include <stdint.h>
#include <stdbool.h>
#include <endian.h>

typedef uint64_t dma_addr_t;

typedef struct XHCIRing {
    dma_addr_t dequeue;
    bool ccs;
} XHCIRing;

typedef struct XHCIState {
    void *as;
} XHCIState;

typedef struct XHCITRB {
    uint64_t parameter;
    uint32_t status;
    uint32_t control;
} XHCITRB;

typedef enum TRBType {
    TR_LINK,
    TR_SETUP,
    TR_STATUS
} TRBType;

#define TRB_SIZE 16
#define TRB_C (1 << 0)
#define TRB_LK_TC (1 << 1)
#define TRB_TR_CH (1 << 4)
#define TRB_LINK_LIMIT 3

#define MEMTX_OK 0
#define MEMTXATTRS_UNSPECIFIED 0
#define LOG_GUEST_ERROR 0

#define TRB_TYPE(trb) ((trb.control >> 10) & 0x3f)

static inline uint64_t xhci_mask64(uint64_t addr) { return addr & ~0xf; }
static inline void le64_to_cpus(uint64_t *val) { *val = le64toh(*val); }
static inline void le32_to_cpus(uint32_t *val) { *val = le32toh(*val); }

int dma_memory_read(void *as, dma_addr_t addr, void *buf, int len, int attrs);
void qemu_log_mask(int mask, const char *fmt, ...);