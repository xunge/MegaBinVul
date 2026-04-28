#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

typedef unsigned int u32;

struct qib_devdata {
    void (*f_set_armlaunch)(struct qib_devdata *, int);
};

struct qib_ctxtdata {
    struct qib_devdata *dd;
    void *ppd;
    int poll_type;
};

struct qib_cmd {
    int type;
    union {
        struct {
            unsigned long spu_base_info;
            size_t spu_base_info_size;
        } user_info;
        int recv_ctrl;
        unsigned long ctxt_info;
        struct {
            unsigned long tid;
            unsigned int tidcnt;
            unsigned int length;
            unsigned long tidlist;
        } tid_info;
        unsigned int part_key;
        int poll_type;
        int armlaunch_ctrl;
        unsigned long sdma_inflight;
        unsigned long sdma_complete;
        unsigned long event_mask;
    } cmd;
};

struct qib_ctxt_info;
struct file;

#define QIB_CMD_ASSIGN_CTXT 0
#define QIB_CMD_USER_INIT 1
#define QIB_CMD_RECV_CTRL 2
#define QIB_CMD_CTXT_INFO 3
#define QIB_CMD_TID_UPDATE 4
#define QIB_CMD_TID_FREE 5
#define QIB_CMD_SET_PART_KEY 6
#define QIB_CMD_DISARM_BUFS 7
#define QIB_CMD_PIOAVAILUPD 8
#define QIB_CMD_POLL_TYPE 9
#define QIB_CMD_ARMLAUNCH_CTRL 10
#define QIB_CMD_SDMA_INFLIGHT 11
#define QIB_CMD_SDMA_COMPLETE 12
#define QIB_CMD_ACK_EVENT 13

#define EACCES 13
#define EINVAL 22
#define EFAULT 14

static inline bool ib_safe_file_access(struct file *fp) { return true; }
static struct qib_ctxtdata *ctxt_fp(struct file *fp) { return NULL; }
static int subctxt_fp(struct file *fp) { return 0; }
static void *user_sdma_queue_fp(struct file *fp) { return NULL; }

static int qib_assign_ctxt(struct file *fp, void *info) { return 0; }
static int qib_do_user_init(struct file *fp, void *info) { return 0; }
static int qib_get_base_info(struct file *fp, void *info, size_t size) { return 0; }
static int qib_manage_rcvq(struct qib_ctxtdata *rcd, int subctxt, int ctrl) { return 0; }
static int qib_ctxt_info(struct file *fp, void *info) { return 0; }
static int qib_tid_update(struct qib_ctxtdata *rcd, struct file *fp, void *info) { return 0; }
static int qib_tid_free(struct qib_ctxtdata *rcd, int subctxt, void *info) { return 0; }
static int qib_set_part_key(struct qib_ctxtdata *rcd, unsigned int key) { return 0; }
static int qib_disarm_piobufs_ifneeded(struct qib_ctxtdata *rcd) { return 0; }
static int disarm_req_delay(struct qib_ctxtdata *rcd) { return 0; }
static void qib_force_pio_avail_update(void *dd) {}
static int qib_sdma_get_inflight(void *queue, void *info) { return 0; }
static int qib_sdma_get_complete(void *ppd, void *queue, void *info) { return 0; }
static int qib_user_event_ack(struct qib_ctxtdata *rcd, int subctxt, unsigned long mask) { return 0; }

#define WARN_ON_ONCE(condition) (condition)
#define __user
#define copy_from_user(dest, src, size) (0)