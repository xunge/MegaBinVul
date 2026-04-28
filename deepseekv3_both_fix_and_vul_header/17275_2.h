#include <string.h>
#include <unistd.h>

#define SCSI_SENSE_BUFFERSIZE 96
#define IOCTL_RETRIES 3

struct scsi_device {
    int changed;
};

struct scsi_sense_hdr {
    unsigned char sense_key;
    unsigned char asc;
    unsigned char ascq;
};

struct packet_command {
    unsigned char *cmd;
    unsigned char *sense;
    unsigned char *buffer;
    int data_direction;
    int buflen;
    int timeout;
    int quiet;
    int stat;
};

typedef struct {
    struct scsi_device *device;
} Scsi_CD;

enum {
    UNIT_ATTENTION = 6,
    NOT_READY = 2,
    ILLEGAL_REQUEST = 5
};

#define KERN_INFO 0
#define ENODEV 19
#define ENOMEDIUM 123
#define EIO 5
#define EDRIVE_CANT_DO_THIS 1234

static inline int driver_byte(int result) { return 0; }

void sr_printk(int level, Scsi_CD *cd, const char *fmt, ...);
int scsi_block_when_processing_errors(struct scsi_device *sdev);
int scsi_execute(struct scsi_device *sdev, const unsigned char *cmd,
                 int data_direction, void *buffer, unsigned bufflen,
                 unsigned char *sense, struct scsi_sense_hdr *sshdr,
                 int timeout, int retries, int flags, int rw, int *resid);

static inline void ssleep(unsigned int seconds) {
    sleep(seconds);
}