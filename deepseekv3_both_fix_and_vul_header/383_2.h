#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;

struct siphash_key {
    uint64_t key[2];
};

struct iphdr {
    uint8_t protocol;
    uint16_t id;
    uint32_t saddr;
    uint32_t daddr;
};

struct net {
    struct {
        struct siphash_key ip_id_key;
    } ipv4;
};

static u32 ip_idents_hashrnd;

u32 ip_idents_reserve(u32 hash, int segs);
u32 net_hash_mix(const struct net *net);
void net_get_random_once(void *buf, size_t len);
bool siphash_key_is_zero(const struct siphash_key *key);
u32 siphash_3u32(u32 first, u32 second, u32 third, const struct siphash_key *key);
u32 jhash_3words(u32 a, u32 b, u32 c, u32 initval);
uint16_t htons(uint16_t hostshort);
void get_random_bytes(void *buf, int nbytes);
#define unlikely(x) (x)
#define __read_mostly
#define __force