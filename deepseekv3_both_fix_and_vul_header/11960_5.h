#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef uint64_t u64;

struct Qdisc {
    u32 handle;
    void *dev_queue;
    struct {
        int qlen;
    } q;
};

struct netlink_ext_ack;
struct nlattr;

struct list_head {
    struct list_head *next, *prev;
};

struct Qdisc_class_common {
    u32 classid;
};

struct hfsc_class {
    struct Qdisc_class_common cl_common;
    struct hfsc_sched *sched;
    struct hfsc_class *cl_parent;
    struct list_head children;
    struct list_head siblings;
    struct Qdisc *qdisc;
    void *block;
    void *filter_list;
    void *bstats;
    void *rate_est;
    void *vt_tree;
    void *cf_tree;
    int level;
    u32 cl_flags;
};

struct hfsc_sched {
    void *clhash;
    struct hfsc_class root;
};

struct tc_service_curve {
    u32 m1;
    u32 d;
    u32 m2;
};

enum {
    TCA_HFSC_UNSPEC,
    TCA_HFSC_RSC,
    TCA_HFSC_FSC,
    TCA_HFSC_USC,
    TCA_HFSC_MAX = TCA_HFSC_USC
};

enum {
    TCA_OPTIONS,
    TCA_RATE
};

#define HFSC_RSC 0x1
#define HFSC_FSC 0x2
#define HFSC_USC 0x4

#define TC_H_ROOT 0xFFFFFFFF
#define TC_H_MAJ(x) ((x) >> 16)
#define GFP_KERNEL 0
#define EINVAL 22
#define EEXIST 17
#define ENOENT 2
#define ENOBUFS 105

#define INIT_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)
#define RB_ROOT (void*)0

struct nla_policy {
    int type;
    int len;
};

static const struct nla_policy hfsc_policy[TCA_HFSC_MAX + 1];

struct pfifo_qdisc_ops {
    // dummy structure
};

struct noop_qdisc {
    // dummy structure
};

extern struct pfifo_qdisc_ops pfifo_qdisc_ops;
extern struct noop_qdisc noop_qdisc;

static inline struct hfsc_sched *qdisc_priv(struct Qdisc *sch) { return NULL; }
static int nla_parse_nested_deprecated(void *tb, int maxtype, void *nla, const struct nla_policy *policy, void *extack) { return 0; }
static void *nla_data(void *nla) { return NULL; }
static u64 psched_get_time(void) { return 0; }
static int gen_replace_estimator(void *bstats, void *cpu_bstats, void *rate_est, void *lock, bool running, void *opt) { return 0; }
static void sch_tree_lock(struct Qdisc *sch) {}
static void hfsc_change_rsc(struct hfsc_class *cl, struct tc_service_curve *rsc, u64 time) {}
static void hfsc_change_fsc(struct hfsc_class *cl, struct tc_service_curve *fsc) {}
static void hfsc_change_usc(struct hfsc_class *cl, struct tc_service_curve *usc, u64 time) {}
static int qdisc_peek_len(struct Qdisc *qdisc) { return 0; }
static void update_ed(struct hfsc_class *cl, int len) {}
static void init_ed(struct hfsc_class *cl, int len) {}
static void update_vf(struct hfsc_class *cl, int len, u64 time) {}
static void init_vf(struct hfsc_class *cl, int len) {}
static void sch_tree_unlock(struct Qdisc *sch) {}
static struct hfsc_class *hfsc_find_class(u32 id, struct Qdisc *sch) { return NULL; }
static void *kzalloc(size_t size, int flags) { return NULL; }
static int tcf_block_get(void **block, void **filter_list, struct Qdisc *sch, struct netlink_ext_ack *extack) { return 0; }
static void kfree(void *ptr) {}
static int gen_new_estimator(void *bstats, void *cpu_bstats, void *rate_est, void *lock, bool running, void *opt) { return 0; }
static void tcf_block_put(void *block) {}
static struct Qdisc *qdisc_create_dflt(void *dev_queue, void *ops, u32 classid, void *extack) { return NULL; }
static void qdisc_hash_add(struct Qdisc *qdisc, bool invisible) {}
static void qdisc_class_hash_insert(void *clhash, void *cl) {}
static void list_add_tail(void *entry, void *head) {}
static void qdisc_purge_queue(struct Qdisc *qdisc) {}
static void hfsc_adjust_levels(struct hfsc_class *parent) {}
static void qdisc_class_hash_grow(struct Qdisc *sch, void *clhash) {}