#include <stdbool.h>
#include <stdint.h>

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
    u64 umax_value;
    u64 umin_value;
    s64 smax_value;
    s64 smin_value;
};

#define BPF_JEQ 0
#define BPF_JNE 1
#define BPF_JSET 2
#define BPF_JGE 3
#define BPF_JGT 4
#define BPF_JSGE 5
#define BPF_JSGT 6
#define BPF_JLE 7
#define BPF_JLT 8
#define BPF_JSLE 9
#define BPF_JSLT 10

static inline bool __is_pointer_value(bool b, struct bpf_reg_state *reg) { return false; }
static inline void __mark_reg_known(struct bpf_reg_state *reg, u64 val) {}
static inline struct tnum tnum_and(struct tnum a, struct tnum b) { return a; }
static inline struct tnum tnum_or(struct tnum a, struct tnum b) { return a; }
static inline struct tnum tnum_const(u64 val) { return (struct tnum){0}; }
static inline bool is_power_of_2(u64 val) { return false; }
static inline u64 gen_hi_max(struct tnum var_off) { return 0; }
static inline u64 gen_hi_min(struct tnum var_off) { return 0; }
static inline bool cmp_val_with_extended_s64(s64 sval, struct bpf_reg_state *reg) { return false; }
static inline void __reg_deduce_bounds(struct bpf_reg_state *reg) {}
static inline void __reg_bound_offset(struct bpf_reg_state *reg) {}
static inline void __reg_bound_offset32(struct bpf_reg_state *reg) {}
static inline void __update_reg_bounds(struct bpf_reg_state *reg) {}

static inline u64 min(u64 a, u64 b) { return a < b ? a : b; }
static inline u64 max(u64 a, u64 b) { return a > b ? a : b; }