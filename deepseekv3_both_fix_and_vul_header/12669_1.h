#include <stdint.h>
#include <stdbool.h>

typedef int32_t s32;
typedef uint32_t u32;

struct bpf_reg_state {
    int64_t smin_value;
    int64_t smax_value;
    uint64_t umin_value;
    uint64_t umax_value;
    s32 s32_min_value;
    s32 s32_max_value;
    u32 u32_min_value;
    u32 u32_max_value;
};

static void __mark_reg32_unbounded(struct bpf_reg_state *reg);
static bool __reg64_bound_s32(int64_t val);
static bool __reg64_bound_u32(uint64_t val);
static void __reg_deduce_bounds(struct bpf_reg_state *reg);
static void __reg_bound_offset(struct bpf_reg_state *reg);
static void __update_reg_bounds(struct bpf_reg_state *reg);