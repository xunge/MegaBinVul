#include <stdatomic.h>
#include <stdint.h>
#include <string.h>

#define PEER_MAXDEPTH 40
#define RTAX_LOCK 12
#define INETPEER_METRICS_NEW 0xFFFF
#define AF_INET 2
#define GFP_ATOMIC 0

typedef uint32_t __be32;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct in6_addr {
    union {
        u8 u6_addr8[16];
        u16 u6_addr16[8];
        u32 u6_addr32[4];
    } in6_u;
};

struct inetpeer_addr {
    int family;
    union {
        __be32 a4;
        struct in6_addr a6;
    } addr;
};

struct inet_peer {
    struct inetpeer_addr daddr;
    atomic_int refcnt;
    atomic_int rid;
    atomic_int ip_id_count;
    unsigned long tcp_ts_stamp;
    u32 metrics[RTAX_LOCK];
    u32 rate_tokens;
    unsigned long rate_last;
    unsigned long pmtu_expires;
    unsigned long pmtu_orig;
    struct {
        unsigned long redirect_learned;
    };
};

struct inet_peer_base {
    int lock;
    int total;
};

extern struct inet_peer *peer_avl_empty;
extern void* peer_cachep;

typedef struct inet_peer *inet_peer_ptr;
typedef inet_peer_ptr *inet_peer_ptr_ptr;
typedef inet_peer_ptr_ptr *inet_peer_ptr_ptr_ptr;

void* kmem_cache_alloc(void* cachep, int flags);
void rcu_read_lock(void);
void rcu_read_unlock(void);
unsigned int read_seqbegin(const int *lock);
int read_seqretry(const int *lock, unsigned int seq);
void write_seqlock_bh(int *lock);
void write_sequnlock_bh(int *lock);
void atomic_inc(atomic_int *v);
void atomic_set(atomic_int *v, int i);
__be32 secure_ip_id(__be32 daddr);
__be32 secure_ipv6_id(struct in6_addr daddr);
struct inet_peer_base* family_to_base(int family);
struct inet_peer* lookup_rcu(const struct inetpeer_addr *daddr, struct inet_peer_base *base);
struct inet_peer* lookup(const struct inetpeer_addr *daddr, inet_peer_ptr_ptr stack, struct inet_peer_base *base);
int inet_peer_gc(struct inet_peer_base *base, inet_peer_ptr_ptr stack, inet_peer_ptr_ptr_ptr stackptr);
void link_to_pool(struct inet_peer *p, struct inet_peer_base *base);

#define __rcu