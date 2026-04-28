#include <stdbool.h>
#include <stdint.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint64_t u64;

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_reg_state {
    struct tnum var_off;
    s32 s32_min_value;
    s32 s32_max_value;
    u32 u32_min_value;
    u32 u32_max_value;
};

#define S32_MIN INT32_MIN
#define S32_MAX INT32_MAX

static inline bool tnum_subreg_is_const(struct tnum t) { return false; }
static inline struct tnum tnum_subreg(struct tnum t) { return t; }
#define max(a, b) ((a) > (b) ? (a) : (b))