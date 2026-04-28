#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <scsi/sg.h>
#include <scsi/scsi.h>

#define SCSI_CDB_MAX_SIZE 16
#define EINPROGRESS 115

enum scsi_xfer_dir {
    SCSI_XFER_NONE,
    SCSI_XFER_READ,
    SCSI_XFER_WRITE
};

struct BlockAIOCB {
    int dummy;
};

struct BlockDriverState {
    void *opaque;
};

struct IscsiLun {
    struct iscsi_context *iscsi;
    int lun;
    void *opaque;
};

struct iscsi_context {
    int dummy;
};

struct iscsi_data {
    void *data;
    size_t size;
};

struct scsi_task {
    enum scsi_xfer_dir xfer_dir;
    int cdb_size;
    unsigned char cdb[SCSI_CDB_MAX_SIZE];
    size_t expxferlen;
};

struct scsi_iovec {
    void *iov_base;
    size_t iov_len;
};

struct IscsiAIOCB {
    struct BlockAIOCB common;
    struct IscsiLun *iscsilun;
    void *bh;
    int status;
    void *buf;
    struct sg_io_hdr *ioh;
    struct scsi_task *task;
};

typedef void (*BlockCompletionFunc)(void *opaque, int ret);
typedef struct BlockAIOCB BlockAIOCB;
typedef struct BlockDriverState BlockDriverState;
typedef struct IscsiLun IscsiLun;
typedef struct IscsiAIOCB IscsiAIOCB;

extern void *iscsi_aiocb_info;
extern IscsiAIOCB *qemu_aio_get(void *aiocb_info, BlockDriverState *bs, BlockCompletionFunc *cb, void *opaque);
extern void qemu_aio_unref(IscsiAIOCB *acb);
extern void error_report(const char *fmt, ...);
extern const char *iscsi_get_error(struct iscsi_context *iscsi);
extern void iscsi_ioctl_handle_emulated(IscsiAIOCB *acb, unsigned long int req, void *buf);
extern void iscsi_aio_ioctl_cb(struct iscsi_context *iscsi, int status, void *command_data, void *private_data);
extern int iscsi_scsi_command_async(struct iscsi_context *iscsi, int lun, struct scsi_task *task, void (*cb)(struct iscsi_context *, int, void *, void *), struct iscsi_data *data, void *private_data);
extern void scsi_free_scsi_task(struct scsi_task *task);
extern void scsi_task_add_data_in_buffer(struct scsi_task *task, size_t len, void *buf);
extern void scsi_task_set_iov_in(struct scsi_task *task, struct scsi_iovec *iov, int count);
extern void scsi_task_set_iov_out(struct scsi_task *task, struct scsi_iovec *iov, int count);
extern void iscsi_set_events(IscsiLun *iscsilun);