#include <stddef.h>
#include <time.h>

struct tcf_t {
    unsigned long install;
    unsigned long lastuse;
    unsigned long expires;
};

struct sk_buff {
    unsigned char* tail;
    int len;
    unsigned char* (*skb_tail_pointer)(struct sk_buff*);
};

struct tc_action {
    void* priv;
};

struct tcf_mirred {
    struct tcf_t tcf_tm;
    int tcf_index;
    int tcf_action;
    int tcf_refcnt;
    int tcf_bindcnt;
    int tcfm_eaction;
    int tcfm_ifindex;
};

struct tc_mirred {
    int index;
    int action;
    int refcnt;
    int bindcnt;
    int eaction;
    int ifindex;
};

#define TCA_MIRRED_PARMS 1
#define TCA_MIRRED_TM 2
#define NLA_PUT(skb, type, len, data) (0)
#define nlmsg_trim(skb, b) ((void)0)
#define jiffies ((unsigned long)0)
#define jiffies_to_clock_t(x) ((clock_t)(x))

static inline unsigned char* skb_tail_pointer(struct sk_buff* skb) {
    return skb->tail;
}