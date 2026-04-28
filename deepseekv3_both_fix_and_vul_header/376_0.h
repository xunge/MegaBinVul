#include <stdint.h>

typedef uint32_t u32;

struct net {
    u32 hash_mix;
};

#ifdef CONFIG_NET_NS
#include <math.h>
#endif