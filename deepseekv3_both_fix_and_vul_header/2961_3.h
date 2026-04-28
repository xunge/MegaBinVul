#include <stddef.h>
#include <stdint.h>

#define IUCV_DISCONN 0
#define MSG_DONTWAIT 0
#define MSG_OOB 0
#define MSG_PEEK 0
#define MSG_TRUNC 0
#define MSG_EOR 0
#define EOPNOTSUPP 0
#define RCV_SHUTDOWN 0
#define EFAULT 0
#define SOL_IUCV 0
#define SCM_IUCV_TRGCLS 0
#define CB_TRGCLS_LEN 0
#define CB_TRGCLS(skb) NULL
#define AF_IUCV_TRANS_HIPER 0
#define AF_IUCV_FLAG_WIN 0
#define SOCK_STREAM 1
#define SOCK_SEQPACKET 2

struct kiocb {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct sk_buff {
    unsigned int len;
    struct sk_buff *next;
};

struct sk_buff_head {
    struct sk_buff *next;
    struct sk_buff *prev;
};

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct msghdr {
    struct iovec *msg_iov;
    int msg_flags;
    int msg_namelen;
};

struct socket {
    struct sock *sk;
};

struct sock {
    int sk_state;
    int sk_type;
    int sk_shutdown;
    struct sk_buff_head sk_receive_queue;
    void (*sk_state_change)(struct sock *sk);
};

struct iucv_message_q {
    struct list_head list;
    int lock;
};

struct iucv_sock {
    struct sk_buff_head backlog_skb_q;
    struct iucv_message_q message_q;
    int msg_recv;
    int msglimit;
    int transport;
};

static inline struct iucv_sock *iucv_sk(struct sock *sk) { return (struct iucv_sock *)sk; }
static void iucv_sock_close(struct sock *sk) {}
static int iucv_process_message_q(struct sock *sk) { return 0; }
static int iucv_send_ctrl(struct sock *sk, int flag) { return 0; }
static struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err) { return NULL; }
static int skb_copy_datagram_iovec(struct sk_buff *skb, int offset, struct iovec *to, int len) { return 0; }
static int put_cmsg(struct msghdr *msg, int level, int type, int len, void *data) { return 0; }
static void kfree_skb(struct sk_buff *skb) {}
static void skb_pull(struct sk_buff *skb, unsigned int len) {}
static int sock_queue_rcv_skb(struct sock *sk, struct sk_buff *skb) { return 0; }
static void skb_queue_head(struct sk_buff_head *list, struct sk_buff *skb) {}
static struct sk_buff *skb_dequeue(struct sk_buff_head *list) { return NULL; }
static int skb_queue_empty(struct sk_buff_head *list) { return 1; }
static void spin_lock_bh(int *lock) {}
static void spin_unlock_bh(int *lock) {}
static int list_empty(struct list_head *list) { return 1; }
static void WARN_ON(int condition) {}
static void sk_state_change(struct sock *sk) {}
static void atomic_inc(int *v) { (*v)++; }
static int atomic_read(int *v) { return *v; }
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))