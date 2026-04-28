#include <stdint.h>
#include <time.h>

typedef uint32_t __be32;
typedef unsigned long jiffies_t;

struct sk_buff {
    unsigned char* data;
    unsigned char* tail;
    int len;
};

struct tc_action {
    void* priv;
};

struct tcf_tm {
    jiffies_t install;
    jiffies_t lastuse;
    jiffies_t expires;
};

struct tcf_nat {
    __be32 old_addr;
    __be32 new_addr;
    __be32 mask;
    uint32_t flags;
    uint32_t tcf_index;
    uint32_t tcf_action;
    uint32_t tcf_refcnt;
    uint32_t tcf_bindcnt;
    struct tcf_tm tcf_tm;
};

struct tc_nat {
    __be32 old_addr;
    __be32 new_addr;
    __be32 mask;
    uint32_t flags;
    uint32_t index;
    uint32_t action;
    uint32_t refcnt;
    uint32_t bindcnt;
};

struct tcf_t {
    clock_t install;
    clock_t lastuse;
    clock_t expires;
};

#define TCA_NAT_PARMS 1
#define TCA_NAT_TM 2

#define NLA_PUT(skb, type, len, data) 
#define nlmsg_trim(skb, b) 

static jiffies_t jiffies = 0;

static inline unsigned char* skb_tail_pointer(struct sk_buff *skb) {
    return skb->tail;
}

static inline clock_t jiffies_to_clock_t(jiffies_t j) {
    return (clock_t)j;
}