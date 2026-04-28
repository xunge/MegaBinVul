#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct QEMUFile QEMUFile;

struct SCSIBus;

typedef struct SCSIRequest {
    struct SCSIBus *bus;
    struct {
        int mode;
    } cmd;
} SCSIRequest;

typedef struct SCSIBus {
    // bus fields would go here
} SCSIBus;

typedef struct VirtIOSCSI {
    SCSIBus bus;
} VirtIOSCSI;

typedef struct VirtIOSCSICommon {
    struct {
        uint32_t num_queues;
    } conf;
    void **cmd_vqs;
} VirtIOSCSICommon;

typedef struct VirtIOSCSIReq {
    struct {
        unsigned int in_num;
        unsigned int out_num;
        void *in_sg[32];
        void *out_sg[32];
    } elem;
    SCSIRequest *sreq;
} VirtIOSCSIReq;

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define VIRTIO_SCSI_COMMON(obj) \
    ((VirtIOSCSICommon *)obj)

#define qemu_get_be32s(f, p) 
#define qemu_get_buffer(f, p, size) 

void *g_malloc(size_t size);
void scsi_req_ref(SCSIRequest *req);
void virtio_scsi_parse_req(VirtIOSCSI *s, void *cmd_vq, VirtIOSCSIReq *req);

enum SCSIXferMode {
    SCSI_XFER_NONE,
    SCSI_XFER_FROM_DEV,
    SCSI_XFER_TO_DEV
};