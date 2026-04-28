#include <stdint.h>
#include <stdbool.h>

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint8_t u8;

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_reg_state {
    struct tnum var_off;
    u64 umin_value;
    u64 umax_value;
    s64 smin_value;
    s64 smax_value;
};

bool __is_pointer_value(bool b, struct bpf_reg_state *reg);
void __mark_reg_known(struct bpf_reg_state *reg, u64 val);
u64 gen_hi_min(struct tnum var_off);
u64 gen_hi_max(struct tnum var_off);
bool cmp_val_with_extended_s64(s64 val, struct bpf_reg_state *reg);
void __reg_deduce_bounds(struct bpf_reg_state *reg);
void __reg_bound_offset(struct bpf_reg_state *reg);
void __reg_bound_offset32(struct bpf_reg_state *reg);
void __update_reg_bounds(struct bpf_reg_state *reg);
struct tnum tnum_and(struct tnum a, struct tnum b);
struct tnum tnum_or(struct tnum a, struct tnum b);
struct tnum tnum_const(u64 value);
bool is_power_of_2(u64 n);

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

enum {
    BPF_JEQ,
    BPF_JNE,
    BPF_JSET,
    BPF_JGE,
    BPF_JGT,
    BPF_JSGE,
    BPF_JSGT,
    BPF_JLE,
    BPF_JLT,
    BPF_JSLE,
    BPF_JSLT
};