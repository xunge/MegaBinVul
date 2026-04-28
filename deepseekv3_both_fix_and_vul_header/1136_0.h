#include <stdint.h>

struct bpf_reg_state {
    uint64_t umin_value;
    uint64_t umax_value;
    uint32_t u32_min_value;
    uint32_t u32_max_value;
    int64_t smin_value;
    int64_t smax_value;
    int32_t s32_min_value;
    int32_t s32_max_value;
};

#define U32_MAX UINT32_MAX