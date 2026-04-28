#include <stdint.h>
#include <arpa/inet.h>

struct nft_expr;
struct nft_pktinfo;

struct nft_regs {
    uint32_t data[16];  // Fixed size array instead of flexible array
};

struct nft_byteorder {
    unsigned int sreg;
    unsigned int dreg;
    unsigned int size;
    unsigned int len;
    unsigned int op;
};

enum {
    NFT_BYTEORDER_NTOH,
    NFT_BYTEORDER_HTON
};

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint64_t u64;
typedef uint32_t __be32;
typedef uint16_t __be16;
typedef uint64_t __be64;
typedef uint32_t __u32;
typedef uint16_t __u16;
typedef uint64_t __u64;

#define __force

static inline uint64_t nft_reg_load64(const uint32_t *src) {
    return *(const uint64_t *)src;
}

static inline void nft_reg_store64(uint32_t *dst, uint64_t val) {
    *(uint64_t *)dst = val;
}

static inline const struct nft_byteorder *nft_expr_priv(const struct nft_expr *expr) {
    return (const struct nft_byteorder *)expr;
}

#define be64_to_cpu(x) ntohll(x)
#define cpu_to_be64(x) htonll(x)

static inline uint64_t ntohll(uint64_t x) {
    return ((uint64_t)ntohl(x & 0xFFFFFFFF) << 32) | ntohl(x >> 32);
}

static inline uint64_t htonll(uint64_t x) {
    return ((uint64_t)htonl(x & 0xFFFFFFFF) << 32) | htonl(x >> 32);
}