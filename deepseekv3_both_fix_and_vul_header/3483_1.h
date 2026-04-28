#include <stdint.h>
#include <assert.h>
#include <errno.h>
#include <stddef.h>

#define DO_UPCAST(type, field, obj) ((type *)((char *)(obj) - offsetof(type, field)))
#define DPRINTF(fmt, ...) do {} while (0)
#define BDRV_SECTOR_SIZE 512
#define SCSI_DMA_BUF_SIZE (1024 * 1024)
#define GOOD 0
#define SCSI_XFER_TO_DEV 1
#define BDRV_ACCT_READ 0
#define NULL ((void*)0)

typedef struct SCSIRequest {
    int mode;
    void *aiocb;
    void *dev;
    struct {
        int mode;
    } cmd;
} SCSIRequest;

typedef struct SCSIDiskReq {
    SCSIRequest req;
    uint32_t sector_count;
    uint32_t sector;
    struct {
        size_t iov_len;
    } iov;
    void *qiov;
    void *acct;
} SCSIDiskReq;

typedef struct SCSIDiskState {
    void *qdev;
    int tray_open;
    void *bs;
} SCSIDiskState;

void scsi_req_data(SCSIRequest *req, size_t len);
void scsi_req_complete(SCSIRequest *req, int status);
void scsi_read_complete(SCSIDiskReq *r, int ret);
uint32_t scsi_init_iovec(SCSIDiskReq *r);
void bdrv_acct_start(void *bs, void *acct, int64_t n, int type);
void *bdrv_aio_readv(void *bs, uint64_t sector, void *qiov, int n,
                     void (*cb)(void *opaque, int ret), void *opaque);
void qemu_iovec_init_external(void *qiov, void *iov, int niov);