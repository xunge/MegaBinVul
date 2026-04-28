#include <stddef.h>
#include <string.h>
#include <sys/time.h>
#include <stdint.h>

#define MAX_NFRAMES 256
#define CFSIZ sizeof(struct can_frame)
#define MHSIZ sizeof(struct bcm_msg_head)
#define OPSIZ sizeof(struct bcm_op)

#define TX_CP_CAN_ID   0x0004
#define TX_RESET_MULTI_IDX 0x0008
#define SETTIMER       0x0010
#define STARTTIMER     0x0020
#define TX_ANNOUNCE    0x0040

#define ENODEV 19
#define EINVAL 22
#define E2BIG  7
#define ENOMEM 12

#define GFP_KERNEL 0
#define CLOCK_MONOTONIC 1
#define HRTIMER_MODE_REL 1

typedef uint8_t u8;

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct can_frame {
    unsigned int can_id;
    unsigned char can_dlc;
    unsigned char data[8];
};

struct bcm_msg_head {
    unsigned int nframes;
    unsigned int can_id;
    unsigned int flags;
    struct timeval ival1, ival2;
    unsigned int count;
};

struct bcm_sock {
    struct list_head tx_ops;
};

struct hrtimer {
    void (*function)(struct hrtimer *);
    int64_t tv64;
    int state;
};

struct tasklet_struct {
    void (*func)(unsigned long);
    unsigned long data;
};

struct ktime_t {
    int64_t tv64;
};

struct bcm_op {
    struct list_head list;
    unsigned int can_id;
    int ifindex;
    unsigned int nframes;
    unsigned int currframe;
    struct can_frame *frames;
    struct can_frame *last_frames;
    struct can_frame sframe;
    struct sock *sk;
    struct hrtimer timer, thrtimer;
    struct tasklet_struct tsklet;
    struct ktime_t kt_ival1, kt_ival2;
    struct timeval ival1, ival2;
    unsigned int flags;
    unsigned int count;
};

struct sock {};
struct msghdr {
    struct iovec *msg_iov;
};
struct iovec {
    void *iov_base;
    size_t iov_len;
};

static inline struct bcm_sock *bcm_sk(const struct sock *sk) {
    return (struct bcm_sock *)sk;
}

static struct bcm_op *bcm_find_op(struct list_head *ops, unsigned int can_id, int ifindex) {
    struct bcm_op *op;
    for (op = (struct bcm_op *)ops->next; op != (struct bcm_op *)ops; op = (struct bcm_op *)op->list.next) {
        if ((op->can_id == can_id) && (op->ifindex == ifindex))
            return op;
    }
    return NULL;
}

static void *kzalloc(size_t size, int flags) { return NULL; }
static void kfree(void *ptr) {}
static void *kmalloc(size_t size, int flags) { return NULL; }
static int memcpy_fromiovec(unsigned char *dst, struct iovec *iov, size_t len) { return 0; }
static void hrtimer_init(struct hrtimer *timer, int clock, int mode) {}
static void hrtimer_start(struct hrtimer *timer, struct ktime_t time, int mode) {}
static void hrtimer_cancel(struct hrtimer *timer) {}
static void tasklet_init(struct tasklet_struct *t, void (*func)(unsigned long), unsigned long data) {}
static void bcm_tx_timeout_handler(struct hrtimer *timer) {}
static void bcm_tx_timeout_tsklet(unsigned long data) {}
static void bcm_can_tx(struct bcm_op *op) {}
static struct ktime_t timeval_to_ktime(struct timeval tv) { 
    struct ktime_t kt = {.tv64 = tv.tv_sec * 1000000000LL + tv.tv_usec * 1000LL};
    return kt;
}
static void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}