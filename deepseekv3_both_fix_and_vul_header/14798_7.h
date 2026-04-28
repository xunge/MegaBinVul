#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/uio.h>

#define SG_DEFAULT_RETRIES 1
#define BLK_MAX_CDB 16
#define MAX_UIOVEC 1024
#define GFP_KERNEL 0
#define GFP_ATOMIC 0
#define KERN_INFO 0
#define ENOMEM 1
#define EINVAL 2
#define WRITE 0
#define READ 1
#define SG_DXFER_TO_DEV 0
#define SG_DXFER_FROM_DEV 1
#define SG_DXFER_TO_FROM_DEV 2
#define SG_DXFER_NONE 3
#define SG_DXFER_UNKNOWN 4
#define SG_FLAG_DIRECT_IO 1
#define SG_INFO_DIRECT_IO 1

typedef struct sg_io_hdr {
    int dxfer_len;
    int dxfer_direction;
    unsigned int iovec_count;
    unsigned char *dxferp;
    unsigned char cmd_len;
    unsigned char flags;
    unsigned char info;
} sg_io_hdr_t;

typedef struct Sg_scatter_hold {
    unsigned long bufflen;
    void **pages;
    int page_order;
    int k_use_sg;
    int dio_in_use;
} Sg_scatter_hold;

typedef struct device_host {
    int unchecked_isa_dma;
} device_host;

typedef struct device {
    void *request_queue;
    device_host *host;
} device;

typedef struct parentdp {
    device *device;
} parentdp;

typedef struct Sg_fd {
    Sg_scatter_hold reserve;
    parentdp *parentdp;
} Sg_fd;

typedef struct Sg_request {
    sg_io_hdr_t header;
    Sg_fd *parentfp;
    Sg_scatter_hold data;
    unsigned char *sense_b;
    void *rq;
    void *bio;
} Sg_request;

struct request {
    unsigned char *cmd;
    unsigned char cmd_len;
    void *sense;
    void *end_io_data;
    int retries;
    void *bio;
};

struct request_queue;
struct rq_map_data {
    void **pages;
    int page_order;
    int nr_entries;
    int offset;
    int null_mapped;
    int from_user;
};

struct iov_iter {
    // Simplified iov_iter structure
    int dummy;
};

#define unlikely(x) (x)

#define min(a, b) ((a) < (b) ? (a) : (b))

extern int sg_allow_dio;
extern int (*sg_printk)(int level, void *dev, const char *fmt, ...);
extern int (*blk_rq_aligned)(void *q, unsigned long addr, unsigned int len);
extern void *(*blk_get_request)(void *q, int rw, int gfp_mask);
extern void (*blk_rq_set_block_pc)(void *rq);
extern int (*blk_rq_map_user)(void *q, void *rq, struct rq_map_data *md, void *ubuf, unsigned int len, int gfp_mask);
extern int (*blk_rq_map_user_iov)(void *q, void *rq, struct rq_map_data *md, struct iov_iter *i, int gfp_mask);
extern int (*import_iovec)(int rw, void *buf, unsigned long nr_segs, unsigned int fast_segs, struct iovec **iov, struct iov_iter *i);
extern void (*iov_iter_truncate)(struct iov_iter *i, size_t count);
extern void *(*kzalloc)(size_t size, int flags);
extern void (*kfree)(const void *objp);
extern void *(*memdup_user)(const void *src, size_t len);
extern size_t (*iov_length)(const struct iovec *iov, unsigned long nr_segs);
extern void (*iov_iter_init)(struct iov_iter *i, int rw, struct iovec *iov, unsigned long nr_segs, size_t count);
extern int (*sg_res_in_use)(Sg_fd *sfp);
extern int (*sg_link_reserve)(Sg_fd *sfp, Sg_request *srp, int len);
extern int (*sg_build_indirect)(Sg_scatter_hold *req_schp, Sg_fd *sfp, int len);
extern int IS_ERR(const void *ptr);
extern long PTR_ERR(const void *ptr);
extern void SCSI_LOG_TIMEOUT(int level, int result);

#define min_t(type, x, y) ({ \
    type __min1 = (x); \
    type __min2 = (y); \
    __min1 < __min2 ? __min1 : __min2; })