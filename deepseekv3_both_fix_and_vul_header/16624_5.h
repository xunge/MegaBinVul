#include <sys/socket.h>
#include <sys/types.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

struct unix_stream_read_state {
    void *socket;
    int flags;
    size_t size;
    struct msghdr *msg;
    int (*recv_actor)(void *, int, int, struct unix_stream_read_state *);
};

struct scm_cookie {
    struct {
        pid_t pid;
        uid_t uid;
        gid_t gid;
    } creds;
    void *fp;
    unsigned long secid;
};

struct unix_sock {
    void *sk;
    pthread_mutex_t readlock;
    int recursion_level;
};

struct socket {
    void *sk;
    unsigned long flags;
};

struct sock {
    int sk_state;
    unsigned long sk_flags;
    void *sk_receive_queue;
    int sk_shutdown;
};

struct sk_buff {
    unsigned int len;
    void *sk;
    void *fp;
    unsigned int consumed;
    struct {
        struct scm_cookie scm;
        unsigned int consumed;
        pid_t pid;
        uid_t uid;
        gid_t gid;
        void *fp;
    } unix_cb;
};

#define UNIXCB(skb) ((skb)->unix_cb)

#define SOCK_PASSCRED 1
#define TCP_ESTABLISHED 1
#define RCV_SHUTDOWN 1
#define SOCK_DEAD 1

#define DECLARE_SOCKADDR(type, name, ptr) \
    type name = (type)(ptr)

#define min_t(type, x, y) ((type)(x) < (type)(y) ? (type)(x) : (type)(y))

static inline struct unix_sock *unix_sk(void *sk) { return (struct unix_sock *)sk; }
static inline int unix_skb_len(struct sk_buff *skb) { return skb->len; }
static inline bool unix_skb_scm_eq(struct sk_buff *skb, struct scm_cookie *scm) { return false; }
static inline void unix_copy_addr(struct msghdr *msg, void *sk) {}
static inline void unix_set_secdata(struct scm_cookie *scm, struct sk_buff *skb) {}
static inline void unix_detach_fds(struct scm_cookie *scm, struct sk_buff *skb) {}
static inline void scm_set_cred(struct scm_cookie *scm, pid_t pid, uid_t uid, gid_t gid) {}
static inline void scm_recv(void *sock, struct msghdr *msg, struct scm_cookie *scm, int flags) {}
static inline void scm_destroy(struct scm_cookie *scm) {}
static inline void *scm_fp_dup(void *fp) { return NULL; }
static inline int sock_rcvlowat(void *sk, int waitall, int size) { return 0; }
static inline long sock_rcvtimeo(void *sk, int noblock) { return 0; }
static inline long unix_stream_data_wait(void *sk, long timeo, struct sk_buff *last, unsigned int last_len) { return 0; }
static inline int sk_peek_offset(void *sk, int flags) { return 0; }
static inline void sk_peek_offset_bwd(void *sk, int len) {}
static inline void sk_peek_offset_fwd(void *sk, int len) {}
static inline int sock_error(void *sk) { return 0; }
static inline int signal_pending(void *p) { return 0; }
static inline int sock_intr_errno(long timeo) { return 0; }
static inline void consume_skb(struct sk_buff *skb) {}
static inline void skb_get(struct sk_buff *skb) {}
static inline void skb_unlink(struct sk_buff *skb, void *list) {}
static inline struct sk_buff *skb_peek(void *list) { return NULL; }
static inline struct sk_buff *skb_peek_next(struct sk_buff *skb, void *list) { return NULL; }
static inline void unix_state_lock(void *sk) {}
static inline void unix_state_unlock(void *sk) {}
static inline int sock_flag(void *sk, int flag) { return 0; }
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }

#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)
#define current ((void *)0)