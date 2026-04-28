#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint32_t __u32;
typedef uint8_t __u8;
typedef uint32_t __wsum;
typedef uint16_t __sum16;

struct in6_addr {
    uint8_t s6_addr[16];
};

struct flowi6 {
    struct in6_addr saddr;
    struct in6_addr daddr;
    __u8 flowi6_proto;
};

struct raw6_sock {
    int checksum;
    int offset;
};

struct ipv6_txoptions {
    int opt_flen;
};

struct sk_buff {
    __wsum csum;
    int len;
    struct sk_buff *next;
};

struct sk_buff_head {
    struct sk_buff *next;
};

struct cork {
    struct ipv6_txoptions *opt;
    struct {
        int length;
    } base;
};

struct sock {
    struct sk_buff_head sk_write_queue;
    struct cork cork;
};

#define unlikely(x) (x)
#define BUG_ON(x) 
#define CSUM_MANGLED_0 0xFFFF
#define IPPROTO_UDP 17

static inline __wsum csum_add(__wsum csum, __wsum addend) { return 0; }
static inline __wsum csum_sub(__wsum csum, __wsum addend) { return 0; }
static inline __sum16 csum_unfold(__wsum csum) { return 0; }
static inline __sum16 csum_ipv6_magic(const struct in6_addr *saddr,
                    const struct in6_addr *daddr,
                    __u32 len, __u8 proto, __wsum sum) { return 0; }
static inline struct sk_buff *skb_peek(const struct sk_buff_head *list) { return 0; }
static inline int skb_queue_len(const struct sk_buff_head *list) { return 0; }
static inline int skb_copy_bits(const struct sk_buff *skb, int offset, void *to, int len) { return 0; }
static inline int skb_store_bits(struct sk_buff *skb, int offset, const void *from, int len) { return 0; }
static inline int skb_transport_offset(const struct sk_buff *skb) { return 0; }
static inline int ip6_push_pending_frames(struct sock *sk) { return 0; }
static inline void ip6_flush_pending_frames(struct sock *sk) {}
static inline struct sock *inet_sk(const struct sock *sk) { return (struct sock *)sk; }
static inline struct sock *inet6_sk(const struct sock *sk) { return (struct sock *)sk; }

#define skb_queue_walk(queue, skb) \
    for (skb = (queue)->next; skb != (struct sk_buff *)(queue); skb = skb->next)