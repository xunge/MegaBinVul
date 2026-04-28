#include <stdint.h>

typedef struct PVSCSICmdDescSetupRings {
    uint64_t ringsStatePPN;
    uint32_t reqRingNumPages;
    uint32_t cmpRingNumPages;
    uint64_t reqRingPPNs[1];
    uint64_t cmpRingPPNs[1];
} PVSCSICmdDescSetupRings;

extern void trace_pvscsi_tx_rings_ppn(const char *, uint64_t);
extern void trace_pvscsi_tx_rings_num_pages(const char *, uint32_t);