#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <stddef.h>

#define BPF_ALU64 0x07
#define BPF_ADD 0x00
#define BPF_SUB 0x10
#define BPF_MUL 0x20
#define BPF_AND 0x50
#define BPF_OR 0x40
#define BPF_LSH 0x60
#define BPF_RSH 0x70

#define S64_MIN INT64_MIN
#define S64_MAX INT64_MAX
#define U64_MAX UINT64_MAX
#define U32_MAX UINT32_MAX

typedef uint8_t u8;
typedef int64_t s64;
typedef uint64_t u64;

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_reg_state {
    s64 smin_value;
    s64 smax_value;
    u64 umin_value;
    u64 umax_value;
    struct tnum var_off;
};

struct bpf_verifier_env;
struct bpf_insn {
    u8 code;
    u8 dst_reg;
};

static inline u8 BPF_OP(u8 code) { return code & 0xf0; }
static inline u8 BPF_CLASS(u8 code) { return code & 0x07; }

static inline bool tnum_is_const(struct tnum t) { return t.mask == 0; }
static inline struct tnum tnum_add(struct tnum a, struct tnum b) { return (struct tnum){0}; }
static inline struct tnum tnum_sub(struct tnum a, struct tnum b) { return (struct tnum){0}; }
static inline struct tnum tnum_mul(struct tnum a, struct tnum b) { return (struct tnum){0}; }
static inline struct tnum tnum_and(struct tnum a, struct tnum b) { return (struct tnum){0}; }
static inline struct tnum tnum_or(struct tnum a, struct tnum b) { return (struct tnum){0}; }
static inline struct tnum tnum_lshift(struct tnum a, u64 shift) { return (struct tnum){0}; }
static inline struct tnum tnum_rshift(struct tnum a, u64 shift) { return (struct tnum){0}; }
static struct tnum tnum_unknown = {0, U64_MAX};

static inline bool signed_add_overflows(s64 a, s64 b) { return false; }
static inline bool signed_sub_overflows(s64 a, s64 b) { return false; }

static inline void coerce_reg_to_32(struct bpf_reg_state *reg) {}
static inline void __mark_reg_unbounded(struct bpf_reg_state *reg) {}
static inline void __update_reg_bounds(struct bpf_reg_state *reg) {}
static inline void __mark_reg_known(struct bpf_reg_state *reg, u64 val) {}
static inline void mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *regs, u8 reg) {}
static inline void __reg_deduce_bounds(struct bpf_reg_state *reg) {}
static inline void __reg_bound_offset(struct bpf_reg_state *reg) {}

static inline struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env) { return NULL; }

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))