#include <stdio.h>
#include <stddef.h>

#define IFNAMSIZ 16
#define RX_CHECK_DLC 0x01

struct seq_file {
    void *private;
};

struct sock {
    void *sk_socket;
};

struct list_head {
    struct list_head *next, *prev;
};

struct bcm_sock {
    unsigned long dropped_usr_msgs;
    int ifindex;
    struct list_head rx_ops;
    struct list_head tx_ops;
};

struct ktime {
    long long tv64;
};

struct bcm_op {
    struct list_head list;
    unsigned int can_id;
    int ifindex;
    int nframes;
    unsigned long frames_abs;
    unsigned long frames_filtered;
    unsigned int flags;
    struct ktime kt_ival1;
    struct ktime kt_ival2;
};

static inline struct bcm_sock *bcm_sk(const struct sock *sk) { return NULL; }
static const char *bcm_proc_getifname(char *ifname, int ifindex) { return NULL; }
static int seq_printf(struct seq_file *m, const char *fmt, ...) { return 0; }
static void seq_putc(struct seq_file *m, char c) {}
static long long ktime_to_us(struct ktime kt) { return kt.tv64; }

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)))