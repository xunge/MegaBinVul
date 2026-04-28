#include <stdint.h>

struct sk_buff;
unsigned int skb_get_hash_perturb(const struct sk_buff *skb, unsigned int perturb);

struct sfq_sched_data {
    unsigned int perturbation;
    unsigned int divisor;
};