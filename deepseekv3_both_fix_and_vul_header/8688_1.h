#include <stdint.h>
#include <assert.h>

#define PVSCSI_MAX_SG_ELEM 128
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct PVSCSISGState {
    uint64_t dataAddr;
    uint32_t resid;
} PVSCSISGState;

typedef struct QEMUSGList {
    // Placeholder for QEMUSGList fields
} QEMUSGList;

typedef struct PVSCSIRequest {
    struct {
        uint64_t dataLen;
        void *context;
    } req;
    PVSCSISGState sg;
    QEMUSGList sgl;
} PVSCSIRequest;

void pvscsi_get_next_sg_elem(PVSCSISGState *sg);
void qemu_sglist_add(QEMUSGList *sgl, uint64_t addr, uint32_t len);
void trace_pvscsi_convert_sglist(void *context, uint64_t addr, uint32_t resid);