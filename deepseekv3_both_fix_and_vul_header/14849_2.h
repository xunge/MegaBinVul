#include <stddef.h>

struct sk_buff_head;
struct skb_shared_info {
    struct sk_buff *frag_list;
};
struct sk_buff {
    struct sk_buff *next;
    unsigned int len;
    unsigned int data_len;
    void *sk;
    struct skb_shared_info *shinfo;
};
struct sctp_ulpevent;

#define GFP_ATOMIC 0
#define SCTP_MIB_REASMUSRMSGS 0

static inline struct skb_shared_info *skb_shinfo(struct sk_buff *skb) { return skb->shinfo; }
static inline int skb_cloned(struct sk_buff *skb) { return 0; }
static inline struct sk_buff *skb_copy(struct sk_buff *skb, int priority) { return NULL; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline void __skb_unlink(struct sk_buff *skb, struct sk_buff_head *list) {}
static inline struct sctp_ulpevent *sctp_skb2event(struct sk_buff *skb) { return NULL; }
static inline void SCTP_INC_STATS(int stat) {}