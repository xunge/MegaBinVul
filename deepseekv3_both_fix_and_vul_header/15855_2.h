#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define GFP_KERNEL 0
#define HZ 100
#define EINVAL 22
#define ENOMEM 12
#define SFQ_ALLOT_SIZE(x) (x)
#define SFQ_MAX_FLOWS 0
#define SFQ_MAX_DEPTH 0

typedef uint32_t u32;

struct Qdisc {
    struct {
        unsigned int qlen;
    } q;
};

struct sfq_sched_data {
    unsigned int quantum;
    unsigned int scaled_quantum;
    unsigned int perturb_period;
    unsigned int maxflows;
    unsigned int divisor;
    unsigned int maxdepth;
    struct red_parms *red_parms;
    unsigned int flags;
    unsigned int headdrop;
    unsigned int limit;
    void *perturb_timer;
    unsigned int perturbation;
};

struct nlattr {
    unsigned int nla_len;
};

struct tc_sfq_qopt {
    unsigned int quantum;
    unsigned int perturb_period;
    unsigned int flows;
    unsigned int divisor;
    unsigned int limit;
};

struct tc_sfq_qopt_v1 {
    unsigned int qth_min;
    unsigned int qth_max;
    unsigned int Wlog;
    unsigned int Plog;
    unsigned int Scell_log;
    unsigned int max_P;
    unsigned int depth;
    unsigned int flags;
    unsigned int headdrop;
};

struct red_parms {
    // Empty struct for compilation
};

struct sk_buff {
    // Empty struct for compilation
};

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *p) { free(p); }
static inline int is_power_of_2(unsigned int n) { return n && !(n & (n - 1)); }
static inline void *nla_data(const struct nlattr *nla) { return (void *)(nla + 1); }
static inline size_t nla_attr_size(int payload) { return payload; }
static inline int red_check_params(unsigned int qth_min, unsigned int qth_max, unsigned int Wlog) { return 1; }
static inline void red_set_parms(struct red_parms *p, unsigned int qth_min, unsigned int qth_max, unsigned int Wlog, unsigned int Plog, unsigned int Scell_log, void *null, unsigned int max_P) {}
static inline void sch_tree_lock(struct Qdisc *sch) {}
static inline void sch_tree_unlock(struct Qdisc *sch) {}
static inline void swap(struct red_parms **a, struct red_parms **b) { struct red_parms *tmp = *a; *a = *b; *b = tmp; }
static inline unsigned int sfq_drop(struct Qdisc *sch, struct sk_buff **to_free) { return 0; }
static inline void rtnl_kfree_skbs(struct sk_buff *head, struct sk_buff *tail) {}
static inline void qdisc_tree_reduce_backlog(struct Qdisc *sch, unsigned int n, unsigned int len) {}
static inline void del_timer(void *timer) {}
static inline void mod_timer(void *timer, unsigned long expires) {}
static inline unsigned int prandom_u32(void) { return rand(); }
static unsigned long jiffies = 0;
static inline struct sfq_sched_data *qdisc_priv(struct Qdisc *sch) { return (struct sfq_sched_data *)sch; }

#define min_t(type, x, y) ((x) < (y) ? (x) : (y))