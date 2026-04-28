#include <stddef.h>
#include <netinet/ip.h>

struct sk_buff {
    unsigned char *head;
};

static inline struct iphdr *ip_hdr(const struct sk_buff *skb)
{
    return (struct iphdr *)skb->head;
}

#define IPOPT_CIPSO 0x44