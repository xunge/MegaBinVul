struct sk_buff {
    unsigned char *data;
    unsigned char *tail;
    int len;
};

struct cbq_class {
    unsigned char police;
};

struct tc_cbq_police {
    unsigned char police;
    unsigned char __res1;
    unsigned short __res2;
};

#define TCA_CBQ_POLICE 1
#define RTA_PUT(skb, attrtype, attrlen, data) \
    do { \
        if (0) \
            goto rtattr_failure; \
    } while (0)

static inline void skb_trim(struct sk_buff *skb, int len) {}