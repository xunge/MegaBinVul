#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define SOCK_DONE 1
#define RCV_SHUTDOWN 1
#define TCP_CLOSE 7

struct pipe_inode_info;
struct socket {
    struct sock *sk;
    struct file *file;
};
struct sock {
    unsigned int sk_err;
    unsigned int sk_shutdown;
    unsigned int sk_state;
    struct sk_buff_head *sk_receive_queue;
};
struct file {
    int f_flags;
};
struct sk_buff_head;
struct task_struct;

#define current ((struct task_struct *)0)

#define unlikely(x) (x)

static inline void sock_rps_record_flow(struct sock *sk) {}
static inline void lock_sock(struct sock *sk) {}
static inline long sock_rcvtimeo(struct sock *sk, int nonblock) { return 0; }
static inline int __tcp_splice_read(struct sock *sk, struct tcp_splice_state *tss) { return 0; }
static inline int sock_flag(struct sock *sk, int flag) { return 0; }
static inline int sock_error(struct sock *sk) { return 0; }
static inline int skb_queue_empty(struct sk_buff_head *list) { return 1; }
static inline void sk_wait_data(struct sock *sk, long *timeo, void *ptr) {}
static inline int signal_pending(struct task_struct *p) { return 0; }
static inline int sock_intr_errno(long timeo) { return 0; }
static inline void release_sock(struct sock *sk) {}

struct tcp_splice_state {
    struct pipe_inode_info *pipe;
    size_t len;
    unsigned int flags;
};