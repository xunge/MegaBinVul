#include <stdbool.h>
#include <stdint.h>

#define NF_ACCEPT 1
#define NF_DROP 0 
#define NF_STOLEN 2
#define EINPROGRESS 115
#define CONFIG_NF_CONNTRACK 1
#define IS_ENABLED(x) (x)

struct net;
struct sk_buff {
    void *nfct;
};

struct nf_hook_state {
    struct net *net;
    int hook;
};

struct nf_conn {};

static inline bool nf_ct_is_template(const struct nf_conn *ct) { return false; }
static inline unsigned int nf_ct6_defrag_user(unsigned int hook, struct sk_buff *skb) { return 0; }
static inline int nf_ct_frag6_gather(struct net *net, struct sk_buff *skb, unsigned int user) { return 0; }