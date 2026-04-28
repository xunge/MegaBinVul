#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef uint16_t u16;
typedef uint8_t u8;
typedef uint32_t u32;
typedef uint32_t __be32;

struct tipc_msg;
struct tipc_net {
    struct tipc_crypto *crypto_tx;
};

struct tipc_crypto {
    int lock;
    struct tipc_aead_key *skey;
    u16 key_gen;
    struct {
        void *keys;
    } key;
    u8 skey_mode;
    bool nokey;
    void *work;
    void *wq;
    char *name;
    struct tipc_net *net;
};

struct tipc_aead_key {
    u32 keylen;
    char alg_name[16];
    u8 key[512];
};

#define TIPC_AEAD_KEYLEN_MIN 16
#define TIPC_AEAD_KEY_SIZE_MAX 512
#define TIPC_AEAD_ALG_NAME 16
#define GFP_ATOMIC 0
#define unlikely(x) (x)
#define likely(x) (x)
#define mb() __asm__ __volatile__("": : :"memory")

static inline struct tipc_net *tipc_net(struct tipc_net *net) { return net; }
static inline u16 msg_key_gen(struct tipc_msg *hdr) { return 0; }
static inline u16 msg_data_sz(struct tipc_msg *hdr) { return 0; }
static inline u8 *msg_data(struct tipc_msg *hdr) { return NULL; }
static inline u8 msg_key_mode(struct tipc_msg *hdr) { return 0; }
static inline size_t tipc_aead_key_size(struct tipc_aead_key *key) { return 0; }
static inline void spin_lock(int *lock) { (void)lock; }
static inline void spin_unlock(int *lock) { (void)lock; }
static inline void *kmalloc(size_t size, int flags) { (void)size; (void)flags; return NULL; }
static inline void kfree(void *ptr) { (void)ptr; }
static inline bool queue_delayed_work(void *wq, void *work, int delay) { (void)wq; (void)work; (void)delay; return false; }
static inline uint32_t ntohl(uint32_t netlong) { return netlong; }
#define pr_debug(fmt, ...) (void)0
#define pr_err(fmt, ...) (void)0