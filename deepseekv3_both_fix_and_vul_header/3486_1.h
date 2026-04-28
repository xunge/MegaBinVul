#include <stdint.h>
#include <stddef.h>
#include <sys/uio.h>

typedef struct SCSIDiskReq SCSIDiskReq;
typedef struct SCSIDiskState SCSIDiskState;

struct SCSIDiskReq {
    struct {
        void *dev;
    } req;
    struct iovec iov;
    uint32_t buflen;
    uint32_t sector_count;
    struct {
        size_t size;
    } qiov;
    void *iov_base;
};

struct SCSIDiskState {
    void *bs;
    void *qdev;
};

#define DO_UPCAST(type, field, obj) ((type *)((char *)(obj) - offsetof(type, field)))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SCSI_DMA_BUF_SIZE 4096

void *qemu_blockalign(void *bs, uint32_t size);
void qemu_iovec_init_external(struct { size_t size; } *qiov, struct iovec *iov, int niov);