#include <string.h>
#include <stdint.h>

struct sk_buff {
    unsigned char *tail;
    int len;
};

struct tc_action {
    void *priv;
};

struct tc_ratespec {
    uint32_t rate;
    uint32_t cell_log;
    uint32_t linklayer;
    uint16_t overhead;
    uint16_t mpu;
    uint32_t mtu;
};

struct qdisc_rate_table {
    struct tc_ratespec rate;
};

struct tcf_police {
    uint32_t tcf_index;
    uint32_t tcf_action;
    uint32_t tcfp_mtu;
    uint32_t tcfp_burst;
    uint32_t tcf_refcnt;
    uint32_t tcf_bindcnt;
    struct qdisc_rate_table *tcfp_R_tab;
    struct qdisc_rate_table *tcfp_P_tab;
    uint32_t tcfp_result;
    uint32_t tcfp_ewma_rate;
};

struct tc_police {
    uint32_t index;
    uint32_t action;
    uint32_t mtu;
    uint32_t burst;
    uint32_t refcnt;
    uint32_t bindcnt;
    struct tc_ratespec rate;
    struct tc_ratespec peakrate;
};

#define TCA_POLICE_TBF 1
#define TCA_POLICE_RESULT 2
#define TCA_POLICE_AVRATE 3

#define NLA_PUT(skb, type, len, data) 
#define NLA_PUT_U32(skb, type, value) 

static inline unsigned char *skb_tail_pointer(struct sk_buff *skb) {
    return skb->tail;
}

static inline void nlmsg_trim(struct sk_buff *skb, unsigned char *b) {
    skb->tail = b;
}