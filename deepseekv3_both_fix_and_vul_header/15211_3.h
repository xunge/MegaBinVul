#include <stdint.h>

typedef uint32_t u32;

struct nlmsghdr {
    u32 nlmsg_len;
    u32 nlmsg_type;
    u32 nlmsg_flags;
    u32 nlmsg_seq;
    u32 nlmsg_pid;
};

struct sk_buff;
void *skb_put(struct sk_buff *skb, unsigned int len);

#define NLMSG_ALIGN(len) (((len) + 3) & ~3)
#define NLMSG_LENGTH(len) ((len) + sizeof(struct nlmsghdr))

typedef struct nlmsghdr nlmsghdr;