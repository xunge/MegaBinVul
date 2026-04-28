#include <stdint.h>

typedef uint32_t __wsum;

#define CHECKSUM_COMPLETE 2
#define SOL_IP 0
#define IP_CHECKSUM 0

struct sk_buff {
    __wsum csum;
    int ip_summed;
    unsigned char* transport_header;
};

struct msghdr {
    // minimal definition for the function
};

static inline __wsum csum_sub(__wsum csum, __wsum addend) { return 0; }
static inline __wsum csum_partial(const void *buff, int len, __wsum sum) { return 0; }
static inline unsigned char* skb_transport_header(const struct sk_buff *skb) { return 0; }
void put_cmsg(struct msghdr*, int, int, int, void*);