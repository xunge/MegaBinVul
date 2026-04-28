#include <sys/socket.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

typedef uint32_t u32;

struct kiocb;
struct socket {
    struct sock *sk;
};

struct sock {
    int sk_type;
    int sk_state;
    int sk_err;
    int sk_shutdown;
    struct {
        struct {
            unsigned long lock;
        } sk_receive_queue;
        struct {
            void *tail;
        } sk_backlog;
    };
    unsigned int sk_flags;
};

struct llc_sock {
    u32 copied_seq;
    int cmsg_flags;
};

struct sk_buff {
    unsigned int len;
};

struct sockaddr_llc {
    unsigned short sllc_family;
    unsigned char sllc_arphrd;
    unsigned char sllc_test;
    unsigned char sllc_xid;
    unsigned char sllc_ua;
    unsigned char sllc_sap;
};

#define TCP_LISTEN 10
#define TCP_CLOSE 7
#define RCV_SHUTDOWN 1
#define SOCK_DONE 1

#define ENOTCONN 107
#define EAGAIN 11
#define EFAULT 14

static struct task_struct {
    char comm[16];
} *current;

static inline struct llc_sock *llc_sk(struct sock *sk) { return (struct llc_sock *)sk; }
static inline int sock_flag(struct sock *sk, int flag) { return sk->sk_flags & flag; }
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline int unlikely(int x) { return x; }
static inline long sock_rcvtimeo(struct sock *sk, int nonblock) { return 0; }
static inline int sock_rcvlowat(struct sock *sk, int waitall, size_t len) { return 0; }
static inline int signal_pending(struct task_struct *p) { return 0; }
static inline int sock_intr_errno(long timeo) { return 0; }
static inline int skb_peek(void *queue) { return 0; }
static inline int sock_error(struct sock *sk) { return 0; }
static inline void sk_wait_data(struct sock *sk, long *timeo) {}
static inline void net_dbg_ratelimited(const char *fmt, ...) {}
static inline int task_pid_nr(struct task_struct *p) { return 0; }
static inline int skb_copy_datagram_iovec(struct sk_buff *skb, u32 offset, void *iov, unsigned long used) { return 0; }
static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void sk_eat_skb(struct sock *sk, struct sk_buff *skb, bool flag) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline int llc_ui_skb_cb(struct sk_buff *skb) { return 0; }
static inline void llc_cmsg_rcv(struct msghdr *msg, struct sk_buff *skb) {}