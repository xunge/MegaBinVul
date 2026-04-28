#include <stddef.h>
#include <stdint.h>

typedef uint32_t u32;

struct net;
struct sk_buff;
struct nlattr;
struct netlink_ext_ack;

struct tcf_proto {
    struct fw_head *root;
};

struct tcf_result {
    int dummy;
};

struct tcf_exts {
    int dummy;
};

struct fw_head {
    u32 mask;
    struct fw_filter *ht[256];
};

struct fw_filter {
    struct fw_filter *next;
    struct tcf_result res;
    struct tcf_exts exts;
    struct tcf_proto *tp;
    int ifindex;
    u32 id;
    void *rwork;
};

#define GFP_KERNEL 0
#define EINVAL 22
#define ENOBUFS 105

#define TCA_OPTIONS 1
#define TCA_FW_MAX 3
#define TCA_FW_ACT 1
#define TCA_FW_POLICE 2
#define TCA_FW_MASK 1

#define __rcu
#define RCU_INIT_POINTER(p, v) ((p) = (v))
#define rtnl_dereference(p) (p)
#define rcu_assign_pointer(p, v) ((p) = (v))

static const void *fw_policy;

static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *p) {}
static inline int nla_parse_nested_deprecated(void *a, int b, void *c, const void *d, void *e) { return 0; }
static inline u32 nla_get_u32(void *a) { return 0; }
static inline int tcf_exts_init(struct tcf_exts *e, struct net *n, int a, int b) { return 0; }
static inline void tcf_exts_destroy(struct tcf_exts *e) {}
static inline int fw_set_parms(struct net *n, struct tcf_proto *t, struct fw_filter *f, void *tb, void *tca, unsigned long b, u32 fl, struct netlink_ext_ack *e) { return 0; }
static inline void tcf_unbind_filter(struct tcf_proto *t, struct tcf_result *r) {}
static inline void tcf_exts_get_net(struct tcf_exts *e) {}
static inline void tcf_queue_work(void *w, void (*f)(void *)) {}
static inline unsigned int fw_hash(u32 id) { return id % 256; }
static inline void fw_delete_filter_work(void *arg) {}