#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define HZ 1000
#define HH_FLOWS_CNT 1024
#define HHF_ARRAYS_CNT 2
#define HHF_ARRAYS_LEN 1024
#define WDRR_BUCKET_CNT 2
#define BITS_PER_BYTE 8
#define GFP_KERNEL 0
#define ENOMEM 12

struct list_head {
    struct list_head *next, *prev;
};

struct Qdisc {
    int limit;
};

struct hhf_sched_data {
    unsigned int quantum;
    uint32_t perturbation;
    struct list_head new_buckets;
    struct list_head old_buckets;
    unsigned int hhf_reset_timeout;
    unsigned int hhf_admit_bytes;
    unsigned int hhf_evict_timeout;
    unsigned int hhf_non_hh_weight;
    struct list_head *hh_flows;
    unsigned int hh_flows_limit;
    unsigned int hh_flows_overlimit;
    unsigned int hh_flows_total_cnt;
    unsigned int hh_flows_current_cnt;
    uint32_t *hhf_arrays[HHF_ARRAYS_CNT];
    unsigned long hhf_arrays_reset_timestamp;
    uint8_t *hhf_valid_bits[HHF_ARRAYS_CNT];
    struct wdrr_bucket *buckets;
};

struct wdrr_bucket {
    struct list_head bucketchain;
};

struct nlattr;
struct netlink_ext_ack;

typedef uint32_t u32;

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline u32 prandom_u32(void) { return rand(); }
static inline unsigned long hhf_time_stamp(void) { return (unsigned long)time(NULL); }
static inline void *kvcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }
static inline void *kvzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void *qdisc_dev(struct Qdisc *sch) { return NULL; }
static inline unsigned int psched_mtu(const void *dev) { return 1500; }
static inline int hhf_change(struct Qdisc *sch, struct nlattr *opt, struct netlink_ext_ack *extack) { return 0; }
static inline struct hhf_sched_data *qdisc_priv(struct Qdisc *sch) { 
    static struct hhf_sched_data data;
    return &data; 
}