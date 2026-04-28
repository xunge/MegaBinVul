#include <sys/socket.h>
#include <netinet/in.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>

typedef uint32_t __be32;
typedef uint16_t __be16;

struct socket {
    struct sock *sk;
};

struct sock {
    long sk_allocation;
};

struct rds_sock {
    __be32 rs_conn_addr;
    __be16 rs_conn_port;
    __be32 rs_bound_addr;
    struct rds_connection *rs_conn;
    int rs_bound_port;
    int rs_seen_congestion;
    void *rs_transport;
};

struct rds_message {
    struct {
        void *op_sg;
        int op_active;
    } data;
    struct {
        int op_active;
    } rdma;
    struct {
        int op_active;
    } atomic;
    __be32 m_daddr;
    void *m_rdma_cookie;
};

struct rds_connection {
    __be32 c_faddr;
    struct {
        void *xmit_rdma;
        void *xmit_atomic;
    } *c_trans;
    void *c_fcong;
    void *c_send_w;
};

#define DECLARE_SOCKADDR(type, name, addr) type name = (type)(addr)
#define GFP_KERNEL 0
#define MAX_SCHEDULE_TIMEOUT LONG_MAX
#define PAGE_SIZE 4096
#define EOPNOTSUPP 95
#define EINVAL 22
#define ENOTCONN 107
#define EMSGSIZE 90
#define ENOMEM 12
#define EAGAIN 11
#define ETIMEDOUT 110
#define MSG_CMSG_COMPAT 0x80000000
#define KERN_NOTICE 5

#define rds_sk_to_rs(sk) ((struct rds_sock *)(sk))
#define sock_sndtimeo(sk, nonblock) ((nonblock) ? 0 : MAX_SCHEDULE_TIMEOUT)
#define lock_sock(sk) do { } while (0)
#define release_sock(sk) do { } while (0)
#define rds_sk_sndbuf(rs) (0)
#define rds_rm_size(msg, len) (0)
#define rds_message_alloc(size, flags) NULL
#define ceil(x, y) (((x) + (y) - 1) / (y))
#define rds_message_alloc_sgs(rm, num) NULL
#define rds_message_copy_from_user(rm, iter) (0)
#define sock_net(sk) NULL
#define rds_conn_create_outgoing(net, bound_addr, daddr, transport, allocation) NULL
#define IS_ERR(ptr) (0)
#define PTR_ERR(ptr) (0)
#define rds_cmsg_send(rs, rm, msg, allocated_mr) (0)
#define rds_conn_connect_if_down(conn) do { } while (0)
#define rds_cong_wait(fcong, dport, nonblock, rs) (0)
#define rds_send_queue_rm(rs, conn, rm, bound_port, dport, queued) (0)
#define rds_stats_inc(stat) do { } while (0)
#define sk_sleep(sk) NULL
#define wait_event_interruptible_timeout(wq, condition, timeout) (0)
#define rdsdebug(fmt, ...)
#define rds_send_xmit(conn) (0)
#define queue_delayed_work(wq, work, delay) do { } while (0)
#define rds_message_put(rm) do { } while (0)
#define rds_rdma_unuse(rs, cookie, drop) do { } while (0)
#define rds_rdma_cookie_key(cookie) (0)
#define printk_ratelimited(fmt, ...)