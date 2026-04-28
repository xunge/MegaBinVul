#include <stddef.h>
#include <stdint.h>

#define __user

struct file {
    void *private_data;
    unsigned int f_flags;
    int f_mode;
};

struct Scsi_Host {
    int host_no;
    int cmd_per_lun;
    int queue_depth;
    int unchecked_isa_dma;
    struct {
        int emulated;
    } *hostt;
};

struct scsi_device {
    struct Scsi_Host *host;
    int channel;
    int id;
    int lun;
    int type;
    void *request_queue;
    int queue_depth;
};

typedef struct sg_device Sg_device;
typedef struct sg_fd Sg_fd;
typedef struct sg_request Sg_request;

struct sg_device {
    int detaching;
    struct scsi_device *device;
    int sg_tablesize;
    struct {
        char *disk_name;
    } *disk;
    int index;
    char sgdebug;
};

struct sg_fd {
    Sg_device *parentdp;
    int timeout_user;
    int timeout;
    int low_dma;
    struct {
        int bufflen;
    } reserve;
    int mmap_called;
    int cmd_q;
    int keep_orphan;
    int next_cmd_len;
    int force_packid;
    struct {
        Sg_request *headrp;
        void *rq_list_lock;
        void *read_wait;
    };
};

struct sg_request {
    int done;
    int orphan;
    int sg_io_owned;
    struct {
        int pack_id;
        unsigned int duration;
        int masked_status;
        int host_status;
        int driver_status;
        void *usr_ptr;
    } header;
    Sg_request *nextrp;
};

typedef struct sg_scsi_id {
    int host_no;
    int channel;
    int scsi_id;
    int lun;
    int scsi_type;
    short h_cmd_per_lun;
    short d_queue_depth;
    int unused[2];
} sg_scsi_id_t;

typedef struct sg_req_info {
    char req_state;
    char orphan;
    char sg_io_owned;
    char problem;
    int pack_id;
    void *usr_ptr;
    unsigned int duration;
} sg_req_info_t;

typedef struct Scsi_Ioctl_Command {
    void *data;
} Scsi_Ioctl_Command;

#define SZ_SG_IO_HDR 64
#define SZ_SG_REQ_INFO sizeof(sg_req_info_t)
#define SG_MAX_QUEUE 16
#define SG_MAX_CDB_SIZE 16
#define O_RDWR 02
#define O_ACCMODE 03
#define ENXIO 6
#define ENODEV 19
#define EFAULT 14
#define EIO 5
#define EINVAL 22
#define EBUSY 16
#define ENOMEM 12
#define EPERM 1
#define ERESTARTSYS 512
#define USER_HZ 100
#define HZ 1000
#define INT_MAX 2147483647
#define WRITE_6 0x0a
#define SCSI_GENERIC_MAJOR 21
#define MKDEV(major, minor) ((major) << 20 | (minor))
#define VERIFY_WRITE 1
#define O_NDELAY 04000

#define SG_IO 1
#define SG_SET_TIMEOUT 2
#define SG_GET_TIMEOUT 3
#define SG_SET_FORCE_LOW_DMA 4
#define SG_GET_LOW_DMA 5
#define SG_GET_SCSI_ID 6
#define SG_SET_FORCE_PACK_ID 7
#define SG_GET_PACK_ID 8
#define SG_GET_NUM_WAITING 9
#define SG_GET_SG_TABLESIZE 10
#define SG_SET_RESERVED_SIZE 11
#define SG_GET_RESERVED_SIZE 12
#define SG_SET_COMMAND_Q 13
#define SG_GET_COMMAND_Q 14
#define SG_SET_KEEP_ORPHAN 15
#define SG_GET_KEEP_ORPHAN 16
#define SG_NEXT_CMD_LEN 17
#define SG_GET_VERSION_NUM 18
#define SG_GET_ACCESS_COUNT 19
#define SG_GET_REQUEST_TABLE 20
#define SG_EMULATED_HOST 21
#define SG_SET_DEBUG 22
#define BLKSECTGET 23
#define BLKTRACESETUP 24
#define BLKTRACESTART 25
#define BLKTRACESTOP 26
#define BLKTRACETEARDOWN 27
#define SCSI_IOCTL_GET_IDLUN 28
#define SCSI_IOCTL_GET_BUS_NUMBER 29
#define SCSI_IOCTL_PROBE_HOST 30
#define SG_GET_TRANSFORM 31
#define SG_SCSI_RESET 32
#define SCSI_IOCTL_SEND_COMMAND 33

#define atomic_read(v) (*(v))
#define read_lock_irqsave(lock, flags) do { flags = 0; } while (0)
#define read_unlock_irqrestore(lock, flags) do {} while (0)
#define write_lock_irq(lock) do {} while (0)
#define write_unlock_irq(lock) do {} while (0)
#define wait_event_interruptible(wq, condition) 0
#define GFP_KERNEL 0
#define KERN_INFO 0
#define SCSI_LOG_TIMEOUT(level, fmt, ...)

extern int sg_version_num;
extern int max_sectors_bytes(void *);
extern int sg_new_write(Sg_fd *, struct file *, void *, size_t, int, int, int, Sg_request **);
extern int sg_new_read(Sg_fd *, void *, size_t, Sg_request *);
extern int srp_done(Sg_fd *, Sg_request *);
extern int sg_res_in_use(Sg_fd *);
extern void sg_remove_scat(Sg_fd *, void *);
extern void sg_build_reserve(Sg_fd *, int);
extern int sg_allow_access(struct file *, unsigned char *);
extern int sg_scsi_ioctl(void *, void *, int, void *);
extern int scsi_ioctl(struct scsi_device *, int, void *);
extern int scsi_block_when_processing_errors(struct scsi_device *);
extern int scsi_ioctl_block_when_processing_errors(struct scsi_device *, unsigned int, int);
extern int blk_trace_setup(void *, char *, int, void *, char *);
extern int blk_trace_startstop(void *, int);
extern int blk_trace_remove(void *);
extern int access_ok(int, void *, size_t);
extern int get_user(int, int *);
extern int put_user(int, int *);
extern int __put_user(int, short *);
extern int __copy_to_user(void *, void *, size_t);
extern int copy_from_user(void *, void *, size_t);
extern void *kmalloc(size_t, int);
extern void kfree(void *);
extern void *memset(void *, int, size_t);
extern unsigned long jiffies;
extern unsigned int jiffies_to_msecs(unsigned long);

typedef int s64;
typedef int fmode_t;

static inline s64 mult_frac(s64 x, s64 numerator, s64 denominator)
{
    return (x * numerator) / denominator;
}

#define min_t(type, x, y) ({ \
    type __min1 = (x); \
    type __min2 = (y); \
    __min1 < __min2 ? __min1 : __min2; \
})

static int sg_printk(int level, Sg_device *sdp, const char *fmt, ...)
{
    return 0;
}