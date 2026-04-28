#include <stdint.h>
#include <stddef.h>

#define MAX_INET_PROTOS 256

typedef uint32_t u32;
typedef uint8_t u8;

struct sk_buff {
    unsigned char *data;
    unsigned int len;
    struct {
        struct ipv6hdr *ipv6h;
    } nh;
};

struct in6_addr {
    uint8_t s6_addr[16];
};

struct ipv6hdr {
    uint8_t nexthdr;
    struct in6_addr saddr;
    struct in6_addr daddr;
};

struct inet6_protocol {
    void (*err_handler)(struct sk_buff *, void *, int, int, int, u32);
};

struct sock;
struct hlist_head {
    struct sock *first;
};

extern struct inet6_protocol *inet6_protos[MAX_INET_PROTOS];
extern int raw_v6_lock;
extern struct hlist_head raw_v6_htable[MAX_INET_PROTOS];

static inline int pskb_may_pull(struct sk_buff *skb, unsigned int len) { return 1; }
static inline int ipv6_ext_hdr(uint8_t nexthdr) { return 0; }
static inline int ipv6_skip_exthdr(struct sk_buff *skb, int offset, uint8_t *nexthdrp, ...) { return 0; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline struct inet6_protocol *rcu_dereference(void *p) { return p; }
static inline void read_lock(int *lock) {}
static inline void read_unlock(int *lock) {}
static inline struct sock *sk_head(struct hlist_head *head) { return NULL; }
static inline struct sock *__raw_v6_lookup(struct sock *sk, uint8_t nexthdr, const struct in6_addr *daddr, const struct in6_addr *saddr) { return NULL; }
static inline void rawv6_err(struct sock *sk, struct sk_buff *skb, void *data, int type, int code, int offset, u32 info) {}
static inline struct sock *sk_next(struct sock *sk) { return NULL; }