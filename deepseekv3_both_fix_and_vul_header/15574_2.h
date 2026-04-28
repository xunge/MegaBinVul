#include <stdint.h>

typedef uint8_t u8;

struct net;
struct spinlock {
    int dummy;
};

struct tipc_key {
    u8 active;
    u8 passive;
    u8 pending;
};

struct tipc_crypto {
    struct spinlock lock;
    struct tipc_key key;
    void *aead[3];
    char *name;
};

struct tipc_net {
    struct tipc_crypto *crypto_tx;
};

static inline void spin_lock(struct spinlock *lock) {}
static inline void spin_unlock(struct spinlock *lock) {}

#define WARN_ON(cond) ((void)(cond))
#define pr_warn(fmt, ...) ((void)(fmt))

#define EKEYREVOKED 128

static inline struct tipc_net *tipc_net(struct net *net) { return 0; }
static inline int tipc_crypto_key_set_state(struct tipc_crypto *tx, u8 passive, u8 active, u8 pending) { return 0; }
static inline void tipc_crypto_key_detach(void *aead, struct spinlock *lock) {}