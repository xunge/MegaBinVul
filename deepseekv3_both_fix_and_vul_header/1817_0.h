#include <stdint.h>

struct sfb_skb_cb {
    uint32_t hashes[2];
};

struct sfb_sched_data;

typedef uint32_t u32;

static void increment_one_qlen(u32 sfbhash, int index, struct sfb_sched_data *q);