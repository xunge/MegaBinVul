#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t hwaddr;

typedef struct SCSIDevice SCSIDevice;

typedef struct MPIMsgSCSIIORequest {
    uint8_t Bus;
    uint8_t TargetID;
    uint8_t LUN[2];
    uint32_t DataLength;
    uint32_t MsgContext;
    uint8_t CDB[16];
    uint8_t CDBLength;
    uint8_t SenseBufferLength;
    uint8_t Function;
    uint8_t Control;
} MPIMsgSCSIIORequest;

typedef struct MPIMsgSCSIIOReply {
    uint8_t TargetID;
    uint8_t Bus;
    uint8_t MsgLength;
    uint8_t Function;
    uint8_t CDBLength;
    uint8_t SenseBufferLength;
    uint32_t MsgContext;
    uint8_t SCSIState;
    uint16_t IOCStatus;
} MPIMsgSCSIIOReply;

typedef struct MPTSASRequest {
    MPIMsgSCSIIORequest scsi_io;
    struct MPTSASState *dev;
    struct {
        struct MPTSASRequest *tqe_next;
        struct MPTSASRequest *tqe_prev;
    } next;
    struct {
        size_t size;
    } qsg;
    struct {
        struct {
            size_t xfer;
            int mode;
        } cmd;
    } *sreq;
} MPTSASRequest;

typedef struct MPTSASState {
    struct {
        MPTSASRequest *tqh_first;
        MPTSASRequest **tqh_last;
    } pending;
} MPTSASState;

enum {
    MPI_SCSIIO_CONTROL_NODATATRANSFER,
    MPI_SCSIIO_CONTROL_WRITE,
    MPI_SCSIIO_CONTROL_READ,
    MPI_SCSIIO_CONTROL_DATADIRECTION_MASK
};

enum {
    SCSI_XFER_NONE,
    SCSI_XFER_TO_DEV,
    SCSI_XFER_FROM_DEV
};

enum {
    MPI_IOCSTATUS_INVALID_SGL,
    MPI_IOCSTATUS_SCSI_DATA_OVERRUN
};

enum {
    MPI_SCSI_STATE_NO_SCSI_STATUS
};

#define QTAILQ_INSERT_TAIL(head, elem, field) \
    do { \
        (elem)->field.tqe_next = NULL; \
        (elem)->field.tqe_prev = (head)->tqh_last; \
        *(head)->tqh_last = (elem); \
        (head)->tqh_last = &(elem)->field.tqe_next; \
    } while (0)

#define g_new0(type, size) ((type *)calloc(size, sizeof(type)))
#define g_new(type, size) ((type *)malloc((size) * sizeof(type)))
#define trace_mptsas_process_scsi_io_request(...)
#define trace_mptsas_sgl_overflow(...)
#define trace_mptsas_scsi_overflow(...)
#define mptsas_fix_scsi_io_endianness(...)
#define mptsas_scsi_device_find(...) 0
#define mptsas_build_sgl(...) 0
#define mptsas_free_request(...)
#define mptsas_fix_scsi_io_reply_endianness(...)
#define mptsas_reply(...)
#define scsi_req_new(...) ((void *)0)
#define scsi_req_enqueue(...) 0
#define scsi_req_continue(...)