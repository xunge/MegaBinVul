#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define HHF_ARRAYS_CNT 4
#define HHF_ARRAYS_LEN 1024
#define HHF_BIT_MASK 0x3FF
#define HHF_BIT_MASK_LEN 10
#define BITS_PER_LONG (sizeof(unsigned long) * 8)

typedef uint32_t u32;

enum wdrr_bucket_idx {
    WDRR_BUCKET_FOR_HH,
    WDRR_BUCKET_FOR_NON_HH
};

struct sk_buff {
    u32 len;
};

struct Qdisc {
    void *priv;
};

struct hh_flow_state {
    u32 hash_id;
    u32 hit_timestamp;
    struct hh_flow_state *next;
};

struct hhf_sched_data {
    u32 perturbation;
    u32 hhf_arrays_reset_timestamp;
    u32 hhf_reset_timeout;
    unsigned long hhf_valid_bits[HHF_ARRAYS_CNT][HHF_ARRAYS_LEN / BITS_PER_LONG];
    u32 hhf_arrays[HHF_ARRAYS_CNT][HHF_ARRAYS_LEN];
    u32 hhf_admit_bytes;
    struct hh_flow_state *hh_flows[HHF_ARRAYS_LEN];
    u32 hh_flows_total_cnt;
};

static inline struct hhf_sched_data *qdisc_priv(struct Qdisc *sch) {
    return (struct hhf_sched_data *)sch->priv;
}

static inline void bitmap_zero(unsigned long *addr, unsigned int size) {
    for (unsigned int i = 0; i < (size + BITS_PER_LONG - 1) / BITS_PER_LONG; i++) {
        addr[i] = 0;
    }
}

static inline bool test_bit(unsigned int nr, const unsigned long *addr) {
    return (addr[nr / BITS_PER_LONG] & (1UL << (nr % BITS_PER_LONG))) != 0;
}

static inline void __set_bit(unsigned int nr, unsigned long *addr) {
    addr[nr / BITS_PER_LONG] |= (1UL << (nr % BITS_PER_LONG));
}

static inline bool hhf_time_before(u32 a, u32 b) {
    return (int32_t)(a - b) < 0;
}

static u32 hhf_time_stamp(void) { return 0; }
static u32 skb_get_hash_perturb(const struct sk_buff *skb, u32 perturb) { return 0; }
static struct hh_flow_state *seek_list(u32 hash, struct hh_flow_state **head, struct hhf_sched_data *q) { return NULL; }
static struct hh_flow_state *alloc_new_hh(struct hh_flow_state **head, struct hhf_sched_data *q) { return NULL; }
static u32 qdisc_pkt_len(const struct sk_buff *skb) { return skb->len; }