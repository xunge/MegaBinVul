#include <stddef.h>
#include <string.h>

struct sk_buff {
    unsigned char *tail;
    unsigned int len;
};

struct tc_action {
    void *priv;
};

struct tcf_defact {
    unsigned int tcf_index;
    unsigned int tcf_refcnt;
    unsigned int tcf_bindcnt;
    unsigned int tcf_action;
    char *tcfd_defdata;
    struct {
        unsigned long install;
        unsigned long lastuse;
        unsigned long expires;
    } tcf_tm;
};

struct tc_defact {
    unsigned int index;
    unsigned int refcnt;
    unsigned int bindcnt;
    unsigned int action;
};

struct tcf_t {
    unsigned long install;
    unsigned long lastuse;
    unsigned long expires;
};

#define TCA_DEF_PARMS 1
#define TCA_DEF_DATA 2
#define TCA_DEF_TM 3

#define NLA_PUT(skb, type, len, data) 0
#define NLA_PUT_STRING(skb, type, str) 0
#define nlmsg_trim(skb, b) 

static inline unsigned char *skb_tail_pointer(struct sk_buff *skb) {
    return skb->tail;
}

static inline unsigned long jiffies_to_clock_t(unsigned long j) {
    return j;
}

extern unsigned long jiffies;