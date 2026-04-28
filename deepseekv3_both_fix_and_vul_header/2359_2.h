#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint16_t __be16;

#define EINVAL 22
#define ENODEV 19
#define ENETDOWN 100
#define IFF_UP 0x1
#define SOCK_DEAD 0x10

struct sock {
    int sk_err;
    unsigned int sk_flags;
    void (*sk_error_report)(struct sock *sk);
};

struct packet_sock {
    int fanout;
    int running;
    __be16 num;
    struct {
        __be16 type;
        struct net_device *dev;
    } prot_hook;
    int ifindex;
    void *bind_lock;
};

struct net_device {
    const char *name;
    int ifindex;
    unsigned int flags;
};

static inline void dev_hold(struct net_device *dev) {}
static inline void dev_put(struct net_device *dev) {}
static inline struct net_device *dev_get_by_name_rcu(void *net, const char *name) { return NULL; }
static inline struct net_device *dev_get_by_index_rcu(void *net, int ifindex) { return NULL; }
static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline void spin_lock(void *lock) {}
static inline void spin_unlock(void *lock) {}
static inline struct packet_sock *pkt_sk(struct sock *sk) { return NULL; }
static inline void __unregister_prot_hook(struct sock *sk, bool sync) {}
static inline void register_prot_hook(struct sock *sk) {}
static inline void packet_cached_dev_reset(struct packet_sock *po) {}
static inline void packet_cached_dev_assign(struct packet_sock *po, struct net_device *dev) {}
static inline void *sock_net(struct sock *sk) { return NULL; }
static inline bool sock_flag(struct sock *sk, int flag) { return false; }
static inline void sk_error_report(struct sock *sk) {}
static inline bool unlikely(bool x) { return x; }