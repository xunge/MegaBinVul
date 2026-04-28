#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>

typedef struct sg_fd Sg_fd;
typedef struct sg_request Sg_request;
typedef struct sg_device Sg_device;
typedef struct request Request;

typedef struct {
    uint8_t status;
    uint8_t masked_status;
    uint8_t msg_status;
    uint8_t info;
    uint8_t host_status;
    uint8_t driver_status;
    uint32_t resid;
    uint8_t interface_id;
    uint32_t flags;
    uint16_t cmd_len;
    uint32_t duration;
} sg_io_hdr_t;

struct request {
    int timeout;
    unsigned char *cmd;
    unsigned char __cmd[0];
};

struct sg_fd {
    Sg_device *parentdp;
    int f_ref;
};

struct sg_request {
    sg_io_hdr_t header;
    struct {
        uint8_t cmd_opcode;
    } data;
    void *bio;
    Request *rq;
};

struct sg_device {
    int detaching;
    void *disk;
    struct {
        void *request_queue;
    } *device;
};

#define SG_FLAG_Q_AT_TAIL (1 << 0)
#define KERN_INFO 0
#define SCSI_LOG_TIMEOUT(level, args)
#define sg_printk(level, dev, fmt, ...)

#define atomic_read(v) (*(v))
#define jiffies (0)
#define jiffies_to_msecs(j) (j)
#define kref_get(ref) do {} while (0)

int sg_start_req(Sg_request *srp, unsigned char *cmnd);
void sg_finish_rem_req(Sg_request *srp);
void sg_rq_end_io(Request *rq, int error);
void blk_end_request_all(Request *rq, int error);
void blk_execute_rq_nowait(void *q, void *bd_disk, Request *rq, int at_head, void (*done)(Request *, int));

#define EIO 5
#define ENODEV 19

static inline void kfree(void *p) {
    free(p);
}