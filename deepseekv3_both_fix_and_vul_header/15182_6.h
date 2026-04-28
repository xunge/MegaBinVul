#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define SOCK_ZAPPED 0x1000000
#define SOCK_BROADCAST 0x20
#define TCP_ESTABLISHED 1
#define RTF_GATEWAY 0x2
#define IFF_LOOPBACK 0x8
#define GFP_KERNEL 0
#define ATADDR_BCAST 255
#define ATADDR_ANYNODE 0
#define DDP_MAXSZ 586
#define MSG_CMSG_COMPAT 0x80000000

struct kiocb;
struct socket {
    struct sock *sk;
};
struct sock {
    int sk_state;
    int sk_no_check;
    unsigned long sk_flags;
};
struct atalk_sock {
    unsigned char dest_port;
    unsigned char dest_node;
    unsigned short dest_net;
    unsigned short src_net;
    unsigned char src_node;
    unsigned char src_port;
};
struct atalk_addr {
    unsigned short s_net;
    unsigned char s_node;
};
struct sockaddr_at {
    unsigned short sat_family;
    unsigned char sat_port;
    struct atalk_addr sat_addr;
};
struct sk_buff {
    struct sock *sk;
    struct net_device *dev;
    unsigned char *head;
    unsigned char *data;
};
struct net_device {
    char *name;
    unsigned short hard_header_len;
    unsigned short flags;
    unsigned char *dev_addr;
};
struct ddpehdr {
    unsigned short deh_len_hops;
    unsigned short deh_dnet;
    unsigned short deh_snet;
    unsigned char deh_dnode;
    unsigned char deh_snode;
    unsigned char deh_dport;
    unsigned char deh_sport;
    unsigned short deh_sum;
};
struct atalk_route {
    struct net_device *dev;
    unsigned short flags;
    struct atalk_addr gateway;
};
struct ddp_dl {
    int header_length;
    void (*request)(struct ddp_dl *, struct sk_buff *, unsigned char *);
};
extern struct ddp_dl *ddp_dl;

static inline struct atalk_sock *at_sk(struct sock *sk) { return (struct atalk_sock *)sk; }
static inline int sock_flag(struct sock *sk, int flag) { return sk->sk_flags & flag; }
static inline void SOCK_DEBUG(struct sock *sk, const char *fmt, ...) {}
static inline int atalk_autobind(struct sock *sk) { return 0; }
static inline struct atalk_route *atrtr_find(struct atalk_addr *addr) { return NULL; }
static inline struct sk_buff *sock_alloc_send_skb(struct sock *sk, int size, int flags, int *err) { return NULL; }
static inline void skb_reserve(struct sk_buff *skb, int len) {}
static inline unsigned char *skb_put(struct sk_buff *skb, unsigned int len) { return NULL; }
static inline int memcpy_fromiovec(unsigned char *kdata, struct iovec *iov, int len) { return 0; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline unsigned short atalk_checksum(struct sk_buff *skb, int len) { return 0; }
static inline struct sk_buff *skb_copy(struct sk_buff *skb, int priority) { return NULL; }
static inline int aarp_send_ddp(struct net_device *dev, struct sk_buff *skb, struct atalk_addr *sa, void *hwaddr) { return 0; }
static inline void skb_orphan(struct sk_buff *skb) {}