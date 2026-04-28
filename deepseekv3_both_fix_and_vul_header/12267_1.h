#include <stdbool.h>
#include <stdlib.h>

struct kmem_cache {
    unsigned int *random_seq;
};

struct rnd_state {
    unsigned int s1, s2, s3;
};

union freelist_init_state {
    struct rnd_state rnd_state;
    unsigned int *list;
    unsigned int count;
    unsigned int pos;
    unsigned int rand;
};

unsigned int get_random_int(void);
void prandom_seed_state(struct rnd_state *state, unsigned int seed);