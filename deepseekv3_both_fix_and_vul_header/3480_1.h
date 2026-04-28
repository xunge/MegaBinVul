#include <stdint.h>
#include <assert.h>
#include <errno.h>
#include <stddef.h>

#define BDRV_SECTOR_SIZE 512
#define BDRV_ACCT_WRITE 0
#define SCSI_XFER_TO_DEV 0
#define DPRINTF(fmt, ...) do {} while (0)

typedef struct SCSIRequest {
    void *aiocb;
    struct {
        int mode;
    } cmd;
    void *dev;
} SCSIRequest;

typedef struct {
    size_t size;
} QEMUIOVector;

typedef struct {
    size_t iov_len;
} iovec;

typedef struct SCSIDiskReq {
    SCSIRequest req;
    QEMUIOVector qiov;
    iovec iov;
    void *acct;
    uint64_t sector;
    void *bs;
} SCSIDiskReq;

typedef struct SCSIDiskState {
    void *qdev;
    int tray_open;
    void *bs;
} SCSIDiskState;

#define DO_UPCAST(type, field, dev) \
    ((type *) ((char *)(dev) - offsetof(type, field)))

void scsi_write_complete(SCSIDiskReq *r, int ret);
void bdrv_acct_start(void *bs, void *acct, uint32_t n, int type);
void *bdrv_aio_writev(void *bs, uint64_t sector, void *qiov, uint32_t n,
                     void (*cb)(SCSIDiskReq *, int), SCSIDiskReq *r);
void qemu_iovec_init_external(void *qiov, void *iov, int n);