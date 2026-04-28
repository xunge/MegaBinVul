#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef uint64_t u64;

struct in6_addr {
    u8 addr[16];
};

struct siphash_key {
    u64 key[2];
};

struct net {
    struct {
        struct siphash_key ip_id_key;
    } ipv4;
};

#define SIPHASH_ALIGNMENT 8
#define unlikely(x) (x)
#define __aligned(x) __attribute__((aligned(x)))

static inline bool siphash_key_is_zero(const struct siphash_key *key) {
    return !key->key[0] && !key->key[1];
}

static inline u32 siphash(const void *data, size_t len, const struct siphash_key *key) {
    return 0;
}

static inline u32 __ipv6_addr_jhash(const struct in6_addr *a, u32 initval) {
    return 0;
}

static inline u32 net_hash_mix(const struct net *net) {
    return 0;
}

static u32 ip_idents_reserve(u32 hash, int segs) {
    return 0;
}

static void get_random_bytes(void *buf, size_t len) {
}