#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t siphash_key_t[2];

struct net {
    struct {
        siphash_key_t ip_id_key;
    } ipv4;
};

struct in6_addr {
    uint8_t s6_addr[16];
};

#define SIPHASH_ALIGNMENT 16
#define unlikely(x) (x)
#define __aligned(x) __attribute__((aligned(x)))

static int siphash_key_is_zero(const siphash_key_t *key) { return 0; }
static void get_random_bytes(void *buf, size_t nbytes) {}
static u32 siphash(const void *data, size_t len, const siphash_key_t *key) { return 0; }
static u32 ip_idents_reserve(u32 hash, int range) { return 0; }