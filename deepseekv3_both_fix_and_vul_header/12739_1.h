#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

typedef int32_t s32;
typedef uint32_t u32;

struct tnum {
    uint64_t value;
    uint64_t mask;
};

struct bpf_reg_state {
    struct tnum var_off;
    s32 s32_min_value;
    s32 s32_max_value;
    u32 u32_min_value;
    u32 u32_max_value;
};

static bool tnum_subreg_is_const(struct tnum var_off);
static struct tnum tnum_subreg(struct tnum var_off);
#define min(a, b) ((a) < (b) ? (a) : (b))
#define S32_MIN INT32_MIN
#define S32_MAX INT32_MAX