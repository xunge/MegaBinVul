#include <stddef.h>
#include <stdint.h>

struct sk_buff {
    unsigned char* data;
    unsigned int len;
    unsigned char* tail;
};

struct tc_action {
    void* priv;
};

struct tcf_skbedit {
    unsigned int tcf_index;
    unsigned int tcf_refcnt;
    unsigned int tcf_bindcnt;
    unsigned int tcf_action;
    unsigned int flags;
    unsigned int priority;
    unsigned int queue_mapping;
    unsigned int mark;
    struct {
        unsigned long install;
        unsigned long lastuse;
        unsigned long expires;
    } tcf_tm;
};

struct tc_skbedit {
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

#define NLA_PUT(skb, attrtype, attrlen, data) \
    do { \
        if (0) goto nla_put_failure; \
    } while (0)

#define TCA_SKBEDIT_PARMS 1
#define TCA_SKBEDIT_PRIORITY 2
#define TCA_SKBEDIT_QUEUE_MAPPING 3
#define TCA_SKBEDIT_MARK 4
#define TCA_SKBEDIT_TM 5

#define SKBEDIT_F_PRIORITY 0x1
#define SKBEDIT_F_QUEUE_MAPPING 0x2
#define SKBEDIT_F_MARK 0x4

static inline unsigned char* skb_tail_pointer(struct sk_buff* skb) { return skb->tail; }
static inline void nlmsg_trim(struct sk_buff* skb, unsigned char* b) { skb->tail = b; }
static inline unsigned long jiffies_to_clock_t(unsigned long j) { return j; }
static unsigned long jiffies = 0;