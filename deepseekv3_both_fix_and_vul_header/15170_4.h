#include <sys/socket.h>
#include <netinet/in.h>
#include <stdint.h>
#include <stddef.h>
#include <errno.h>

#define TCP_ESTABLISHED 1
#define SOCK_LOCALROUTE 0x10000
#define SOCK_BROADCAST 0x20
#define SOCK_NOSPACE 2
#define RTCF_BROADCAST 0x40000000
#define RTO_ONLINK 0x1
#define MSG_PROBE 0x10

typedef uint32_t __be32;
typedef uint16_t __be16;
typedef uint8_t u8;
typedef uint8_t __u8;

struct kiocb;
struct msghdr;
struct sockaddr_in;

struct sk_buff_head {
    int dummy;
};

struct sock {
    int sk_state;
    int sk_bound_dev_if;
    unsigned long sk_socket;
};

struct dst_entry {
    struct dst_entry *dst;
};

struct flowi {
    int oif;
    union {
        struct {
            __be32 daddr;
            __be32 saddr;
            __be32 tos;
        } ip4_u;
    } nl_u;
    __u8 proto;
    union {
        struct {
            __be16 sport;
            __be16 dport;
        } ports;
    } uli_u;
    __be32 fl4_dst;
    __be16 fl_ip_dport;
    __be32 fl4_src;
    __be16 fl_ip_sport;
};

struct udphdr {
    __be16 source;
    __be16 dest;
    __be16 len;
    __be16 check;
};

struct ip_options {
    unsigned char optlen;
    unsigned char srr;
    unsigned char is_strictroute;
    __be32 faddr;
};

struct ipcm_cookie {
    __be32 addr;
    int oif;
    struct ip_options *opt;
};

struct rtable {
    struct dst_entry u;
    __be32 rt_dst;
    __be32 rt_src;
    unsigned rt_flags;
};

struct udp_sock {
    int corkflag;
    int pending;
    size_t len;
    struct sk_buff_head sk_write_queue;
};

struct inet_sock {
    __be32 daddr;
    __be32 saddr;
    __be16 dport;
    __be16 sport;
    struct ip_options *opt;
    __u8 tos;
    int mc_index;
    __be32 mc_addr;
    struct {
        struct flowi fl;
    } cork;
    int sk_bound_dev_if;
};

#define MULTICAST(x) (((x) & 0xf0000000) == 0xe0000000)
#define RT_TOS(tos) ((tos) & 0x1e)
#define LIMIT_NETDEBUG(x)
#define KERN_DEBUG ""
#define likely(x) (x)
#define unlikely(x) (x)

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline struct dst_entry *sk_dst_check(struct sock *sk, int flags) { return NULL; }
static inline void sk_dst_set(struct sock *sk, struct dst_entry *dst) {}
static inline struct dst_entry *dst_clone(struct dst_entry *dst) { return dst; }
static inline void dst_confirm(struct dst_entry *dst) {}
static inline void ip_rt_put(struct rtable *rt) {}
static inline void kfree(void *ptr) {}
static inline int ip_route_output_flow(struct rtable **rp, struct flowi *flp, struct sock *sk, int flags) { return 0; }
static inline void security_sk_classify_flow(struct sock *sk, struct flowi *fl) {}
static inline int ip_append_data(struct sock *sk, int (*getfrag)(void *, char *, int, int, int, struct sk_buff *), void *from, int length, int transhdrlen, struct ipcm_cookie *ipc, struct rtable *rt, unsigned int flags) { return 0; }
static inline void udp_flush_pending_frames(struct sock *sk) {}
static inline int udp_push_pending_frames(struct sock *sk, struct udp_sock *up) { return 0; }
static inline int ip_cmsg_send(struct msghdr *msg, struct ipcm_cookie *ipc) { return 0; }
static inline int ip_generic_getfrag(void *from, char *to, int offset, int len, int odd, struct sk_buff *skb) { return 0; }

#define UDP_INC_STATS_USER(field) do { } while (0)
#define UDP_MIB_OUTDATAGRAMS 0
#define UDP_MIB_SNDBUFERRORS 0
#define inet_sk(__sk) ((struct inet_sock *)__sk)
#define udp_sk(__sk) ((struct udp_sock *)__sk)
#define skb_queue_empty(list) (1)
#define test_bit(nr, addr) (0)
#define sock_flag(sk, flag) (0)