#include <stdint.h>
#include <stdlib.h>

typedef uint32_t u32;

struct sfb_bin {
    u32 perturbation;
};

struct sfb_sched_data {
    struct sfb_bin *bins;
};

static u32 prandom_u32(void) {
    return rand();
}