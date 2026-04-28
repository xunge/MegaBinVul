#include <stdint.h>
#include <stddef.h>

typedef struct SCSIDevice {
    // 基本SCSI设备结构
} SCSIDevice;

typedef struct SCSIRequest {
    // SCSI请求结构
} SCSIRequest;

typedef struct SCSIDiskState {
    SCSIDevice qdev;
    void *bs;
} SCSIDiskState;

typedef struct SCSIDiskReq {
    SCSIRequest req;
    struct {
        void *iov_base;
    } iov;
} SCSIDiskReq;

#define SCSI_DMA_BUF_SIZE 4096
#define DO_UPCAST(type, field, dev) ((type *)((char *)(dev) - offsetof(type, field)))

extern const struct SCSIReqOps scsi_disk_reqops;
void *qemu_blockalign(void *bs, int size);
SCSIRequest *scsi_req_alloc(const struct SCSIReqOps *ops, SCSIDevice *d,
                           uint32_t tag, uint32_t lun, void *hba_private);