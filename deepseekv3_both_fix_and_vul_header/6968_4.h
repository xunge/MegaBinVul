#include <stdint.h>
#include <errno.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint8_t u8;

struct mctp_sock {
    int sk;
};

struct mctp_sk_key {
    unsigned long lock;
};

struct net {
    struct {
        unsigned long keys_lock;
    } mctp;
};

struct mctp_ioc_tag_ctl {
    u8 tag;
    u8 peer_addr;
    u8 flags;
};

#define MCTP_ADDR_ANY 0
#define MCTP_TAG_OWNER (1 << 0)
#define MCTP_TAG_PREALLOC (1 << 1)
#define MCTP_TRACE_KEY_DROPPED 0

static inline struct net *sock_net(int *sk) { return (struct net *)0; }
static inline int copy_from_user(void *dst, const void *src, size_t size) { return 0; }
static inline int copy_to_user(void *dst, const void *src, size_t size) { return 0; }
static inline struct mctp_sk_key *mctp_alloc_local_tag(struct mctp_sock *msk, u8 addr, u8 any, bool flag, u8 *tag) { return (struct mctp_sk_key *)0; }
static inline bool IS_ERR(const void *ptr) { return false; }
static inline int PTR_ERR(const void *ptr) { return 0; }
static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void __mctp_key_remove(struct mctp_sk_key *key, struct net *net, unsigned long flags, int trace) {}
static inline void mctp_key_unref(struct mctp_sk_key *key) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}

#define __user