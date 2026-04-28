#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

struct sk_buff;
struct xfrm_state;

struct xfrm_dump_info {
    struct sk_buff *in_skb;
    struct sk_buff *out_skb;
    u32 nlmsg_seq;
    u32 nlmsg_flags;
};

#define NLMSG_DEFAULT_SIZE 1024
#define GFP_ATOMIC 0
#define ENOMEM 12
#define ERR_PTR(ptr) ((void*)(ptr))