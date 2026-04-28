#include <stddef.h>
#include <stdint.h>

#define HZ 1000
#define TCA_CBQ_OVL_STRATEGY 1
#define RTA_PUT(skb, attrtype, attrlen, data) \
    ({ if (0) goto rtattr_failure; 0; })

struct tc_cbq_ovl {
    uint8_t strategy;
    uint8_t priority2;
    uint8_t pad;
    uint32_t penalty;
};

struct sk_buff {
    unsigned char *data;
    unsigned char *tail;
    int len;
    void (*skb_trim)(struct sk_buff *, int);
};

struct cbq_class {
    uint8_t ovl_strategy;
    uint8_t priority2;
    unsigned long penalty;
};