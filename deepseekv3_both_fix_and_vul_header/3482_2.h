#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/uio.h>

#define SCSI_DMA_BUF_SIZE 4096
#define GOOD 0
#define SCSI_REQ_STATUS_RETRY_WRITE 1

typedef struct SCSIRequest {
    void *dev;
    uint32_t tag;
    void *aiocb;
} SCSIRequest;

typedef struct QEMUIOVector {
    struct iovec *iov;
    int niov;
    size_t size;
} QEMUIOVector;

typedef struct SCSIDiskReq {
    SCSIRequest req;
    struct iovec iov;
    QEMUIOVector qiov;
    uint32_t sector;
    uint32_t sector_count;
    void *acct;
} SCSIDiskReq;

typedef struct SCSIDiskState {
    void *qdev;
    void *bs;
} SCSIDiskState;

#define DO_UPCAST(type, field, obj) \
    ((type *)((char *)(obj) - offsetof(type, field)))

#define DPRINTF(fmt, ...) do {} while (0)

void bdrv_acct_done(void *bs, void *acct);
int scsi_handle_rw_error(SCSIDiskReq *r, int ret, int status);
void scsi_req_complete(SCSIRequest *req, int status);
void scsi_init_iovec(SCSIDiskReq *r);
void scsi_req_data(SCSIRequest *req, uint32_t len);