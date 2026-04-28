#include <stdint.h>
#include <string.h>

#define SCSI_STATUS_CANCELLED 1
#define SCSI_STATUS_CHECK_CONDITION 2
#define ECANCELED 125
#define SG_ERR_DRIVER_SENSE 0x08

struct iscsi_context;

struct scsi_data_in {
    size_t size;
    uint8_t *data;
};

struct scsi_task {
    struct scsi_data_in datain;
    uint8_t sense[256];
};

struct sg_io_hdr {
    int driver_status;
    int host_status;
    int resid;
    int status;
    int sb_len_wr;
    int mx_sb_len;
    uint8_t *sbp;
};

typedef struct IscsiAIOCB {
    int status;
    struct scsi_task *task;
    struct sg_io_hdr *ioh;
    void *bh;
} IscsiAIOCB;

const char *iscsi_get_error(struct iscsi_context *iscsi);
int iscsi_translate_sense(uint8_t *sense);
void iscsi_schedule_bh(IscsiAIOCB *acb);
void error_report(const char *fmt, ...);