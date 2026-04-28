#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define SFQ_MAX_DEPTH 128
#define SFQ_MAX_FLOWS 128
#define SFQ_DEFAULT_HASH_DIVISOR 1024
#define SFQ_DEFAULT_FLOWS 128
#define SFQ_EMPTY_SLOT -1
#define SFQ_ALLOT_SIZE(quantum) ((quantum) + 1)
#define TIMER_DEFERRABLE 0
#define TCQ_F_CAN_BYPASS (1 << 0)
#define ENOMEM 12

struct Qdisc {
    unsigned int flags;
};

struct nlattr;
struct netlink_ext_ack;
struct tcf_block;
struct tcf_proto;

struct sfq_head {
    int next;
    int prev;
};

struct sfq_slot {
    /* slot fields */
};

struct sfq_sched_data {
    struct Qdisc *sch;
    struct {
        void (*function)(void*);
    } perturb_timer;
    struct tcf_block *block;
    struct tcf_proto *filter_list;
    struct sfq_head dep[SFQ_MAX_DEPTH + 1];
    int limit;
    int maxdepth;
    int cur_depth;
    struct sfq_slot *tail;
    unsigned int divisor;
    unsigned int maxflows;
    unsigned int quantum;
    unsigned int scaled_quantum;
    unsigned int perturb_period;
    uint32_t perturbation;
    int *ht;
    struct sfq_slot *slots;
};

static inline struct sfq_sched_data *qdisc_priv(struct Qdisc *sch) {
    return (struct sfq_sched_data *)(sch + 1);
}

static inline unsigned int psched_mtu(void *dev) {
    return 1500;
}

static inline void *qdisc_dev(struct Qdisc *sch) {
    return NULL;
}

static inline void timer_setup(void *timer, void (*function)(void*), int flags) {
}

static inline int tcf_block_get(struct tcf_block **block, struct tcf_proto **filter, 
                               struct Qdisc *sch, struct netlink_ext_ack *extack) {
    return 0;
}

static inline uint32_t prandom_u32(void) {
    return rand();
}

static void sfq_perturbation(void *timer) {
}

static int sfq_change(struct Qdisc *sch, struct nlattr *opt) {
    return 0;
}

static void *sfq_alloc(unsigned int size) {
    return malloc(size);
}

static inline void slot_queue_init(struct sfq_slot *slot) {
}

static inline void sfq_link(struct sfq_sched_data *q, int i) {
}