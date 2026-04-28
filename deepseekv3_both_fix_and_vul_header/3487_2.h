#include <stdint.h>
#include <stddef.h>
#include <sys/queue.h>

#define GOOD 0

typedef struct SCSIRequest SCSIRequest;
typedef struct SCSIDiskReq SCSIDiskReq;
typedef struct SCSIDiskState SCSIDiskState;

struct SCSIDiskState {
    void *bh;
    struct {
        TAILQ_HEAD(, SCSIRequest) requests;
    } qdev;
};

struct SCSIRequest {
    TAILQ_ENTRY(SCSIRequest) next;
};

struct SCSIDiskReq {
    SCSIRequest req;
    int status;
    struct {
        void *iov_base;
    } iov;
};

#define SCSI_REQ_STATUS_RETRY 0x1
#define SCSI_REQ_STATUS_RETRY_TYPE_MASK 0x6
#define SCSI_REQ_STATUS_RETRY_READ 0x2
#define SCSI_REQ_STATUS_RETRY_WRITE 0x4
#define SCSI_REQ_STATUS_RETRY_FLUSH 0x6

#define DO_UPCAST(type, field, ptr) \
    ((type *)((char *)(ptr) - offsetof(type, field)))

#define QTAILQ_FOREACH(var, head, field) \
    for ((var) = TAILQ_FIRST((head)); (var); (var) = TAILQ_NEXT((var), field))

void qemu_bh_delete(void *bh);
void scsi_read_data(SCSIRequest *req);
void scsi_write_data(SCSIRequest *req);
int scsi_disk_emulate_command(SCSIDiskReq *r, ...);
void scsi_req_complete(SCSIRequest *req, int status);