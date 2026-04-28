#include <stdint.h>

typedef uint64_t hwaddr;

#define PVSCSI_MAX_NUM_PAGES_REQ_RING 1
#define PVSCSI_MAX_NUM_REQ_ENTRIES_PER_PAGE 1

#define RS_GET_FIELD(mgr, field) ((mgr)->field)

typedef struct PVSCSIRingReqDesc {
    uint64_t context;
    uint64_t dataAddr;
    uint64_t dataLen;
    uint64_t senseAddr;
    uint32_t senseLen;
    uint32_t flags;
    uint32_t vcpuHint;
    uint8_t lun[8];
    uint8_t tag[8];
    uint8_t bus;
    uint8_t target;
    uint8_t function;
    uint8_t cdbLen;
    uint8_t cdb[16];
    uint8_t _pad[48];
} PVSCSIRingReqDesc;

typedef struct PVSCSIRingInfo {
    uint32_t reqProdIdx;
    uint32_t consumed_ptr;
    uint32_t txr_len_mask;
    hwaddr *req_ring_pages_pa;
} PVSCSIRingInfo;