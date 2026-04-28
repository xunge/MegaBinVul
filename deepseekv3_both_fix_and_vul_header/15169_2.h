#include <sys/socket.h>
#include <netinet/in.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint32_t __be32;
typedef uint16_t __be16;
typedef uint8_t u8;

struct kiocb;
struct msghdr;
struct sk_buff_head {
    struct sk_buff_head *next;
    struct sk_buff_head *prev;
};

struct sock {
    int sk_state;
    int sk_bound_dev_if;
    unsigned long sk_socket[2];
    struct sk_buff_head sk_write_queue;
    unsigned long sk_flags;
};

struct inet_sock {
    __be32 daddr;
    __be32 saddr;
    __be16 dport;
    __be16 sport;
    u8 tos;
    struct {
        int srr;
        int is_strictroute;
        __be32 faddr;
    } *opt;
    int mc_index;
    __be32 mc_addr;
    struct {
        struct {
            __be32 fl4_dst;
            __be32 fl4_src;
            __be16 fl_ip_dport;
            __be16 fl_ip_sport;
        } fl;
    } cork;
};

struct udp_sock {
    int corkflag;
    int pending;
    size_t len;
};

struct ipcm_cookie {
    struct {
        int srr;
        int is_strictroute;
        __be32 faddr;
    } *opt;
    __be32 addr;
    int oif;
};

struct rtable {
    unsigned int rt_flags;
    __be32 rt_src;
    __be32 rt_dst;
    struct {
        struct rtable *dst;
    } u;
};

struct flowi {
    int oif;
    union {
        struct {
            __be32 daddr;
            __be32 saddr;
            u8 tos;
        } ip4_u;
    } nl_u;
    int proto;
    union {
        struct {
            __be16 sport;
            __be16 dport;
        } ports;
    } uli_u;
};

struct udphdr {
    __be16 source;
    __be16 dest;
    __be16 len;
    __be16 check;
};

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

#define TCP_ESTABLISHED 1
#define RTO_ONLINK 0x01
#define RTCF_BROADCAST 0x04
#define MSG_PROBE 0x10
#define SOCK_LOCALROUTE 0
#define SOCK_BROADCAST 1
#define SOCK_NOSPACE 2
#define UDP_MIB_OUTDATAGRAMS 0
#define UDP_MIB_SNDBUFERRORS 1
#define KERN_DEBUG 7
#define ENETUNREACH 101
#define ENOBUFS 105
#define EMSGSIZE 90
#define EOPNOTSUPP 95
#define EINVAL 22
#define EAFNOSUPPORT 97
#define EDESTADDRREQ 89
#define EACCES 13

static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static inline struct udp_sock *udp_sk(const struct sock *sk) { return (struct udp_sock *)sk; }

#define lock_sock(sk) do { } while (0)
#define release_sock(sk) do { } while (0)
#define sk_dst_check(sk, flags) NULL
#define sk_dst_set(sk, dst) do { } while (0)
#define dst_clone(dst) NULL
#define dst_confirm(dst) do { } while (0)
#define ip_route_output_flow(rt, fl, sk, nowait) (-ENETUNREACH)
#define ip_append_data(sk, getfrag, iov, len, hlen, ipc, rt, flags) (-ENOBUFS)
#define udp_flush_pending_frames(sk) do { } while (0)
#define udp_push_pending_frames(sk, up) (-ENOBUFS)
#define ip_rt_put(rt) do { } while (0)
#define kfree(ptr) do { } while (0)
#define ip_cmsg_send(msg, ipc) (0)
#define ip_generic_getfrag NULL
#define security_sk_classify_flow(sk, fl) do { } while (0)
#define sock_flag(sk, flag) 0
#define test_bit(bit, addr) 0
#define UDP_INC_STATS_USER(stat) do { } while (0)
#define LIMIT_NETDEBUG(fmt, ...) do { } while (0)
#define RT_TOS(tos) ((tos) & 0x1E)
#define MULTICAST(addr) (((addr) & 0xF0000000) == 0xE0000000)