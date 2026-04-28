#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef uint32_t u32;

struct net;
struct sk_buff;
struct nlattr;
struct netlink_ext_ack;

struct tcf_chain {
    void *block;
};

struct tcf_proto {
    void *root;
    struct tcf_chain *chain;
};

struct tcf_result {
    int dummy;
};

struct tcf_exts {
    int dummy;
};

struct work_struct {
    int dummy;
};

struct route4_head {
    void *table[256 + 1];
};

struct route4_filter {
    struct tcf_exts exts;
    struct tcf_result res;
    struct route4_filter *next;
    struct route4_bucket *bkt;
    struct tcf_proto *tp;
    u32 handle;
    u32 id;
    int iif;
    struct work_struct rwork;
};

struct route4_bucket {
    struct route4_filter *ht[256];
};

#define __rcu
#define TCA_ROUTE4_MAX 0
#define TCA_OPTIONS 0
#define TCA_ROUTE4_ACT 0
#define TCA_ROUTE4_POLICE 0
#define TCA_RATE 0
#define GFP_KERNEL 0
#define EINVAL 1
#define ENOBUFS 2

static const int route4_policy = 0;

static void *rtnl_dereference(void *p) { return p; }
static void rcu_assign_pointer(void *p, void *v) {}
static void tcf_block_netif_keep_dst(void *p) {}
static void tcf_unbind_filter(void *p, void *r) {}
static void tcf_exts_get_net(void *p) {}
static void tcf_queue_work(void *p, void *f) {}
static void tcf_exts_destroy(void *p) {}
static void route4_reset_fastmap(void *p) {}
static int nla_parse_nested_deprecated(void *a, int b, void *c, int d, void *e) { return 0; }
static int tcf_exts_init(void *a, void *b, int c, int d) { return 0; }
static int route4_set_parms(void *a, void *b, unsigned long c, void *d, u32 e, void *f, void *g, void *h, bool i, bool j, void *k) { return 0; }
static unsigned int from_hash(u32 h) { return h; }
static unsigned int to_hash(u32 h) { return h; }
static void *kzalloc(size_t size, int flags) { return malloc(size); }
static void kfree(void *p) { free(p); }
static void route4_delete_filter_work(void *work) {}