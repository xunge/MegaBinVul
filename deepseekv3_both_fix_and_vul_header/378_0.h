#include <stdint.h>
#include <netinet/in.h>

struct in6_addr;
struct frag_hdr {
    uint32_t identification;
};

struct rt6_info {
    struct {
        struct in6_addr addr;
    } rt6i_dst, rt6i_src;
};

#define __read_mostly
#define htonl(x) (x)

static inline void net_get_random_once(void *buf, size_t len) {}
static inline uint32_t __ipv6_addr_jhash(const struct in6_addr *a, uint32_t seed) { return 0; }
static inline uint32_t ip_idents_reserve(uint32_t hash, int count) { return 0; }
typedef uint32_t u32;