#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>
#include <pthread.h>

#define SZ_SG_HEADER sizeof(struct sg_header)
#define SG_MAX_CDB_SIZE 16
#define ENXIO 6
#define ENODEV 19
#define EIO 5
#define EFAULT 14
#define EDOM 33
#define KERN_INFO "INFO"
#define KERN_WARNING "WARNING"
#define SG_DXFER_TO_DEV 1
#define SG_DXFER_FROM_DEV 2
#define SG_DXFER_TO_FROM_DEV 3
#define SG_DXFER_NONE 4

struct sg_header {
    int reply_len;
    int twelve_byte;
    int pack_id;
};

struct file {
    void *private_data;
    int f_flags;
};

typedef struct sg_io_hdr sg_io_hdr_t;

struct sg_io_hdr {
    char interface_id;
    unsigned char cmd_len;
    unsigned short iovec_count;
    unsigned short mx_sb_len;
    int dxfer_direction;
    int dxfer_len;
    void *dxferp;
    void *sbp;
    int timeout;
    int flags;
    int pack_id;
    void *usr_ptr;
};

typedef struct Sg_device {
    atomic_int detaching;
    void *device;
} Sg_device;

typedef struct Sg_fd {
    Sg_device *parentdp;
    pthread_mutex_t f_mutex;
    int next_cmd_len;
    int timeout;
} Sg_fd;

typedef struct Sg_request {
    sg_io_hdr_t header;
} Sg_request;

struct task_struct {
    char comm[16];
};

#define __user
#define SCSI_LOG_TIMEOUT(level, expr) expr
#define COMMAND_SIZE(op) ((op) < 0xc0 ? 6 : 12)

typedef long loff_t;
typedef long ssize_t;

extern struct task_struct *current;
extern int sg_check_file_access(struct file *filp, const char *func);
extern Sg_request *sg_add_request(Sg_fd *sfp);
extern void sg_remove_request(Sg_fd *sfp, Sg_request *srp);
extern int sg_new_write(Sg_fd *sfp, struct file *filp, const char *buf, size_t count, int blocking, int read_only, int force_packid, sg_io_hdr_t *hdr);
extern int sg_common_write(Sg_fd *sfp, Sg_request *srp, unsigned char *cmnd, int timeout, int blocking);
extern int sg_printk(const char *level, Sg_device *sdp, const char *fmt, ...);
extern int scsi_block_when_processing_errors(void *sdev);
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern int get_user(unsigned char *to, const void *from);
extern int printk_ratelimited(const char *fmt, ...);
extern int atomic_read(const atomic_int *v);
extern int pthread_mutex_lock(pthread_mutex_t *mutex);
extern int pthread_mutex_unlock(pthread_mutex_t *mutex);

#define mutex_lock pthread_mutex_lock
#define mutex_unlock pthread_mutex_unlock