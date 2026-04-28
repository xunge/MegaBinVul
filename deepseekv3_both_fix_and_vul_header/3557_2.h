#include <stdint.h>
#include <unistd.h>

typedef uint32_t __u32;
typedef uint16_t __u16;

struct nlmsghdr {
    __u32 nlmsg_len;
    __u16 nlmsg_type;
    __u16 nlmsg_flags;
    __u32 nlmsg_seq;
    __u32 nlmsg_pid;
};

struct sk_buff {
    unsigned int len;
};

#define CAP_NET_ADMIN 12
#define EPERM 1
#define EINVAL 22

#define RCV_SKB_FAIL(code) do { return; } while (0)

static inline struct nlmsghdr *nlmsg_hdr(struct sk_buff *skb) {
    return (struct nlmsghdr *)skb;
}

static inline int capable(int cap) {
    return 1;
}