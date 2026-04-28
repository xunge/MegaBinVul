#include <stdbool.h>
#include <stdint.h>

typedef int32_t s32;

struct tnum {
    uint32_t value;
    uint32_t mask;
};

struct bpf_reg_state {
    struct tnum var_off;
    uint32_t u32_min_value;
    uint32_t u32_max_value;
    s32 s32_min_value;
    s32 s32_max_value;
};

#define S32_MIN INT32_MIN
#define S32_MAX INT32_MAX

static bool tnum_subreg_is_const(struct tnum t) { return false; }
static struct tnum tnum_subreg(struct tnum t) { return t; }