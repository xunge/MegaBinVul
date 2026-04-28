#include <stdint.h>
#include <string.h>

#define DID_NO_CONNECT 0x01
#define DID_OK 0x00
#define DID_ERROR 0x02
#define SCSI_MLQUEUE_HOST_BUSY 0x01
#define SCSI_SENSE_BUFFERSIZE 96
#define STEX_CDB_LENGTH 16
#define MODE_SENSE_10 0x5A
#define REPORT_LUNS 0xA0
#define TEST_UNIT_READY 0x00
#define INQUIRY 0x12
#define PASSTHRU_CMD 0xE0
#define PASSTHRU_GET_DRVVER 0x01
#define PASSTHRU_SIGNATURE 'P'
#define INQUIRY_EVPD 0x01
#define MU_STATE_NOCONNECT 0
#define MU_STATE_STARTED 1
#define MSG_DATA_DIR_IN 0
#define MSG_DATA_DIR_OUT 1
#define MSG_DATA_DIR_ND 2
#define ST_VER_MAJOR 1
#define ST_VER_MINOR 0
#define ST_OEM 0
#define ST_BUILD_VER 0
#define DMA_FROM_DEVICE 1
#define DMA_TO_DEVICE 2
#define st_shasta 0

typedef uint16_t u16;

struct req_msg {
    unsigned char lun;
    unsigned char target;
    unsigned char cdb[STEX_CDB_LENGTH];
    unsigned char data_dir;
    unsigned char variable[0];
};

struct scsi_cmnd {
    unsigned char *cmnd;
    unsigned char *sense_buffer;
    unsigned int result;
    unsigned int sc_data_direction;
    struct {
        struct Scsi_Host *host;
        unsigned int id;
        unsigned int lun;
        unsigned int channel;
    } *device;
};

struct Scsi_Host {
    unsigned int max_id;
    unsigned int max_lun;
    unsigned int can_queue;
    unsigned int host_no;
    char hostdata[0];
};

struct st_hba {
    unsigned int mu_status;
    unsigned int cardtype;
    struct Scsi_Host *host;
    void *hostdata;
    struct req_msg *(*alloc_rq)(struct st_hba *);
    int (*map_sg)(struct st_hba *, struct req_msg *, void *);
    void (*send)(struct st_hba *, struct req_msg *, u16);
    struct {
        struct scsi_cmnd *cmd;
        int sense_bufflen;
        unsigned char *sense_buffer;
        int sg_count;
    } *ccb;
};

struct st_drvver {
    unsigned int major;
    unsigned int minor;
    unsigned int oem;
    unsigned int build;
    char signature[1];
    unsigned int console_id;
    unsigned int host_no;
};

static char console_inq_page[36];

static inline int unlikely(int condition) {
    return condition;
}

void scsi_done(struct scsi_cmnd *cmd);
size_t scsi_sg_copy_from_buffer(struct scsi_cmnd *cmd, void *buf, size_t len);
void stex_invalid_field(struct scsi_cmnd *cmd, void (*done)(struct scsi_cmnd *));
struct {
    unsigned int tag;
} *scsi_cmd_to_rq(struct scsi_cmnd *cmd);