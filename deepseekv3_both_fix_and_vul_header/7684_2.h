#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct HDACodecBus {
    // Minimal definition to make it complete
    int dummy;
} HDACodecBus;

typedef struct PCIBus {
    // Minimal definition to make it complete
    int dummy;
} PCIBus;

typedef struct HDACodecDevice {
    struct {
        HDACodecBus *parent_bus;
    } qdev;
    uint32_t cad;
} HDACodecDevice;

typedef struct IntelHDAState {
    HDACodecBus codecs;
    uint32_t ics;
    uint32_t irr;
    uint32_t rirb_ctl;
    uint32_t rirb_sts;
    uint32_t rirb_wp;
    uint32_t rirb_lbase;
    uint32_t rirb_ubase;
    uint32_t rirb_count;
    uint32_t rirb_cnt;
    uint32_t corb_rp;
    uint32_t corb_wp;
    PCIBus pci;
} IntelHDAState;

typedef uint64_t hwaddr;

typedef struct {
    bool memory;
} MemTxAttrs;

typedef enum {
    MEMTX_OK,
    MEMTX_ERROR
} MemTxResult;

#define MEMTXATTRS_UNSPECIFIED ((MemTxAttrs) {0})

#define ICH6_IRS_BUSY    (1 << 0)
#define ICH6_IRS_VALID   (1 << 1)
#define ICH6_RBCTL_DMA_EN (1 << 0)
#define ICH6_RBCTL_OVERRUN_EN (1 << 1)
#define ICH6_RBCTL_IRQ_EN (1 << 2)
#define ICH6_RBSTS_OVERRUN (1 << 0)
#define ICH6_RBSTS_IRQ (1 << 1)

#define HDA_BUS(bus) ((HDACodecBus *)(bus))
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

static inline MemTxResult stl_le_pci_dma(PCIBus *pci, hwaddr addr, uint32_t val, MemTxAttrs attrs) {
    return MEMTX_OK;
}

static inline hwaddr intel_hda_addr(uint32_t lbase, uint32_t ubase) {
    return (hwaddr)ubase << 32 | lbase;
}

static inline void intel_hda_update_irq(IntelHDAState *d) {
}

static inline void dprint(IntelHDAState *d, int level, const char *fmt, ...) {
}