#include <stdint.h>

#define VMW_PAGE_SHIFT 12
#define PVSCSI_SETUP_RINGS_MAX_NUM_PAGES 32
#define PVSCSI_MAX_NUM_REQ_ENTRIES_PER_PAGE 1024
#define PVSCSI_MAX_NUM_CMP_ENTRIES_PER_PAGE 1024

#define MASK(n) ((1 << (n)) - 1)

typedef struct PVSCSIRingInfo {
    uint64_t rs_pa;
    uint32_t txr_len_mask;
    uint32_t rxr_len_mask;
    uint32_t consumed_ptr;
    uint32_t filled_cmp_ptr;
    uint64_t req_ring_pages_pa[PVSCSI_SETUP_RINGS_MAX_NUM_PAGES];
    uint64_t cmp_ring_pages_pa[PVSCSI_SETUP_RINGS_MAX_NUM_PAGES];
    uint32_t reqProdIdx;
    uint32_t reqConsIdx;
    uint32_t reqNumEntriesLog2;
    uint32_t cmpProdIdx;
    uint32_t cmpConsIdx;
    uint32_t cmpNumEntriesLog2;
} PVSCSIRingInfo;

typedef struct PVSCSICmdDescSetupRings {
    uint32_t reqRingNumPages;
    uint32_t cmpRingNumPages;
    uint32_t ringsStatePPN;
    uint32_t reqRingPPNs[PVSCSI_SETUP_RINGS_MAX_NUM_PAGES];
    uint32_t cmpRingPPNs[PVSCSI_SETUP_RINGS_MAX_NUM_PAGES];
} PVSCSICmdDescSetupRings;

static uint32_t pvscsi_log2(uint32_t input) {
    return input ? 31 - __builtin_clz(input) : 0;
}

static void trace_pvscsi_ring_init_data(uint32_t txr_len_log2, uint32_t rxr_len_log2) {}

static void smp_wmb(void) {
    __asm__ __volatile__("" ::: "memory");
}

#define RS_SET_FIELD(m, f, v) ((m)->f = (v))