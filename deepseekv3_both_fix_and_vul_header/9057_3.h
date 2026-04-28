#include <poll.h>
#include <sys/socket.h>
#include <stddef.h>

#define POLLIN      0x001
#define POLLPRI     0x002
#define POLLOUT     0x004
#define POLLERR     0x008
#define POLLHUP     0x010
#define POLLNVAL    0x020
#define POLLRDNORM  0x040
#define POLLRDBAND  0x080
#define POLLWRNORM  0x100
#define POLLWRBAND  0x200
#define POLLMSG     0x400
#define POLLRDHUP   0x2000

#define SHUTDOWN_MASK 0x3
#define RCV_SHUTDOWN 1
#define SOCK_SELECT_ERR_QUEUE 0x8
#define SOCK_ASYNC_NOSPACE 1

#define TCP_CLOSE 7
#define TCP_SYN_SENT 2

struct file;
struct socket {
    struct sock *sk;
    unsigned long flags;
};
struct sock {
    int sk_err;
    unsigned int sk_shutdown;
    int sk_type;
    int sk_state;
    struct {
        struct sk_buff *next;
        struct sk_buff *prev;
    } sk_error_queue;
    struct {
        struct sk_buff *next;
        struct sk_buff *prev;
    } sk_receive_queue;
    struct socket *sk_socket;
};
struct sk_buff {
    struct sk_buff *next;
    struct sk_buff *prev;
};
struct poll_table_struct;
typedef struct poll_table_struct poll_table;
struct unix_sock {
    struct sock sk;
    struct {
        int wait;
    } peer_wait;
};

static inline void sock_poll_wait(struct file *file, void *wait_address, poll_table *p) {}
static inline int sock_flag(const struct sock *sk, int flag) { return 0; }
static inline void *sk_sleep(struct sock *sk) { return NULL; }
static inline int skb_queue_empty(const void *list) { return 1; }
static inline unsigned int poll_requested_events(const poll_table *p) { return 0; }
static inline int unix_writable(struct sock *sk) { return 0; }
static inline void unix_state_lock(struct sock *sk) {}
static inline void unix_state_unlock(struct sock *sk) {}
static inline struct sock *unix_peer(struct sock *sk) { return NULL; }
static inline int unix_recvq_full(struct sock *sk) { return 0; }
static inline int unix_dgram_peer_wake_me(struct sock *sk, struct sock *other) { return 0; }
static inline void set_bit(int nr, volatile void *addr) {}
static inline struct sock *unix_peer_get(struct sock *sk) { return NULL; }
static inline void sock_put(struct sock *sk) {}
static inline struct unix_sock *unix_sk(struct sock *sk) { return (struct unix_sock *)sk; }