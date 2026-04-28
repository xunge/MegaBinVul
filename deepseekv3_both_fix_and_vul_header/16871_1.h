#include <stdint.h>
#include <stddef.h>

#define NVME_NSID_BROADCAST 0xFFFFFFFF
#define NVME_DIRECTIVE_IDENTIFY 0x00
#define NVME_DIRECTIVE_DATA_PLACEMENT 0x01
#define NVME_DIRECTIVE_RETURN_PARAMS 0x00
#define NVME_INVALID_FIELD 0x02
#define NVME_DNR 0x8000

typedef struct NvmeCmd {
    uint32_t cdw10;
    uint32_t cdw11;
    uint32_t nsid;
} NvmeCmd;

typedef struct NvmeFDP {
    uint8_t enabled;
} NvmeFDP;

typedef struct NvmeEndGrp {
    NvmeFDP fdp;
} NvmeEndGrp;

typedef struct NvmeNamespace {
    NvmeEndGrp *endgrp;
} NvmeNamespace;

typedef struct NvmeRequest {
    NvmeCmd cmd;
} NvmeRequest;

typedef struct NvmeCtrl NvmeCtrl;

typedef struct NvmeDirectiveIdentify {
    uint32_t supported;
    uint32_t enabled;
    uint32_t persistent;
} NvmeDirectiveIdentify;

static inline uint32_t le32_to_cpu(uint32_t v) { return v; }
static NvmeNamespace *nvme_ns(NvmeCtrl *n, uint32_t nsid) { return NULL; }
static uint16_t nvme_c2h(NvmeCtrl *n, uint8_t *data, uint32_t len, NvmeRequest *req) { return 0; }
#define MIN(a, b) ((a) < (b) ? (a) : (b))