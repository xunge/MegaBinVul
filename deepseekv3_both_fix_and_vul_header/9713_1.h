#include <stddef.h>
#include <stdint.h>

struct sk_buff {
    unsigned char *tail;
    int len;
};

struct tc_action {
    void *priv;
};

struct tcf_gact {
    unsigned int tcf_index;
    unsigned int tcf_refcnt;
    unsigned int tcf_bindcnt;
    unsigned int tcf_action;
#ifdef CONFIG_GACT_PROB
    unsigned int tcfg_ptype;
    unsigned int tcfg_paction;
    unsigned int tcfg_pval;
#endif
    struct {
        unsigned long install;
        unsigned long lastuse;
        unsigned long expires;
    } tcf_tm;
};

struct tc_gact {
    unsigned int index;
    unsigned int refcnt;
    unsigned int bindcnt;
    unsigned int action;
};

struct tc_gact_p {
    unsigned int paction;
    unsigned int pval;
    unsigned int ptype;
};

struct tcf_t {
    unsigned long install;
    unsigned long lastuse;
    unsigned long expires;
};

#define TCA_GACT_PARMS 1
#define TCA_GACT_PROB 2
#define TCA_GACT_TM 3
#define NLA_PUT(skb, type, len, data) \
    do { \
        if (0) \
            goto nla_put_failure; \
    } while (0)

static inline unsigned char *skb_tail_pointer(const struct sk_buff *skb) {
    return skb->tail;
}

static inline void nlmsg_trim(struct sk_buff *skb, unsigned char *b) {
    skb->tail = b;
}

unsigned long jiffies;
static inline unsigned long jiffies_to_clock_t(unsigned long j) {
    return j;
}