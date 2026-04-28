#include <stddef.h>
#include <stdint.h>

#define SCSI_REQ_STATUS_RETRY_READ 0

typedef struct SCSIRequest {
    void *dev;
    uint32_t tag;
    void *aiocb;
} SCSIRequest;

typedef struct SCSIDiskReq {
    SCSIRequest req;
    struct {
        size_t size;
    } qiov;
    struct {
        size_t iov_len;
    } iov;
    int sector;
    int sector_count;
    void *bs;
    void *acct;
} SCSIDiskReq;

typedef struct SCSIDiskState {
    void *qdev;
    void *bs;
} SCSIDiskState;

#define DO_UPCAST(type, field, obj) \
    ((type *) ((char *)(obj) - offsetof(type, field)))

#define DPRINTF(fmt, ...) do {} while (0)

int scsi_handle_rw_error(SCSIDiskReq *r, int error, int status);
void scsi_req_data(SCSIRequest *req, size_t size);
void bdrv_acct_done(void *bs, void *acct);