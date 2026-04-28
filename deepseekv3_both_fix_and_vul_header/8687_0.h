#include <stdint.h>
#include <stdbool.h>

#define PVSCSI_SETUP_RINGS_MAX_NUM_PAGES 32
#define PVSCSI_COMMAND_PROCESSING_FAILED 0
#define PVSCSI_COMMAND_PROCESSING_SUCCEEDED 1
#define TRUE 1

typedef struct PVSCSICmdDescSetupRings {
    uint32_t reqRingNumPages;
    uint32_t cmpRingNumPages;
} PVSCSICmdDescSetupRings;

typedef struct PVSCSIRingInfo {
    int dummy;
} PVSCSIRingInfo;

typedef struct PVSCSIState {
    void *curr_cmd_data;
    PVSCSIRingInfo rings;
    bool rings_info_valid;
} PVSCSIState;

void trace_pvscsi_on_cmd_arrived(const char *cmd);
void pvscsi_dbg_dump_tx_rings_config(PVSCSICmdDescSetupRings *rc);
int pvscsi_ring_init_data(PVSCSIRingInfo *rings, PVSCSICmdDescSetupRings *rc);