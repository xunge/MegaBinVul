#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock;
struct list_head {
    struct list_head *next, *prev;
};
struct rds_sock {
    struct list_head rs_notify_queue;
    int rs_cong_notify;
};
struct rds_header {
    uint32_t h_len;
    uint16_t h_sport;
};
struct rds_incoming {
    struct rds_connection *i_conn;
    struct rds_header i_hdr;
    uint32_t i_saddr;
};
struct rds_connection {
    struct rds_transport *c_trans;
    uint32_t c_faddr;
};
struct rds_transport {
    int (*inc_copy_to_user)(struct rds_incoming *, struct iovec *, size_t);
};
struct iovec;
struct wait_queue_head {
    int dummy;
};

#define rdsdebug(fmt, ...)
#define rds_sk_to_rs(sk) ((struct rds_sock *)(sk))
#define sock_rcvtimeo(sk, nonblock) ((nonblock) ? 0 : -1)
#define sk_sleep(sk) ((struct wait_queue_head *)0)
#define rds_notify_queue_get(rs, msg) (0)
#define rds_notify_cong(rs, msg) (0)
#define rds_next_incoming(rs, inc) (0)
#define rds_inc_put(inc)
#define rds_still_queued(rs, inc, peek) (0)
#define rds_stats_inc(stat)
#define rds_cmsg_recv(inc, msg) (0)
#define ntohs(x) (x)
#define be32_to_cpu(x) (x)
#define MAX_SCHEDULE_TIMEOUT LONG_MAX
#define EAGAIN 11
#define ETIMEDOUT 110
#define EFAULT 14

static inline int list_empty(const struct list_head *head)
{
    return head->next == head;
}

static inline long wait_event_interruptible_timeout(struct wait_queue_head wq,
                                                  int condition,
                                                  long timeout)
{
    (void)wq;
    (void)condition;
    return timeout;
}