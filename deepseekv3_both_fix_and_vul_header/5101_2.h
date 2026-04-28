#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int64_t s64;

#define S64_MIN INT64_MIN
#define S64_MAX INT64_MAX
#define U64_MAX UINT64_MAX
#define U32_MAX UINT32_MAX

struct bpf_verifier_env;
struct bpf_reg_state;

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_reg_state {
    struct tnum var_off;
    s64 smin_value;
    s64 smax_value;
    u64 umin_value;
    u64 umax_value;
};

struct bpf_insn {
    u8 code;
    u8 dst_reg;
    u32 imm;
};

#define BPF_ALU64 0x07
#define BPF_ALU 0x04
#define BPF_ADD 0x00
#define BPF_SUB 0x10
#define BPF_MUL 0x20
#define BPF_AND 0x50
#define BPF_OR 0x40
#define BPF_LSH 0x60
#define BPF_RSH 0x70
#define BPF_ARSH 0x80

static inline u8 BPF_OP(u32 code) { return code & 0xf0; }
static inline u8 BPF_CLASS(u32 code) { return code & 0x07; }

static inline bool tnum_is_const(struct tnum t) { return !t.mask; }
static inline struct tnum tnum_add(struct tnum a, struct tnum b) { return (struct tnum){a.value + b.value, a.mask + b.mask}; }
static inline struct tnum tnum_sub(struct tnum a, struct tnum b) { return (struct tnum){a.value - b.value, a.mask - b.mask}; }
static inline struct tnum tnum_mul(struct tnum a, struct tnum b) { return (struct tnum){a.value * b.value, a.mask * b.mask}; }
static inline struct tnum tnum_and(struct tnum a, struct tnum b) { return (struct tnum){a.value & b.value, a.mask & b.mask}; }
static inline struct tnum tnum_or(struct tnum a, struct tnum b) { return (struct tnum){a.value | b.value, a.mask | b.mask}; }
static inline struct tnum tnum_lshift(struct tnum a, u8 shift) { return (struct tnum){a.value << shift, a.mask << shift}; }
static inline struct tnum tnum_rshift(struct tnum a, u8 shift) { return (struct tnum){a.value >> shift, a.mask >> shift}; }
static inline struct tnum tnum_arshift(struct tnum a, u8 shift) { return (struct tnum){(s64)a.value >> shift, (s64)a.mask >> shift}; }

static inline bool signed_add_overflows(s64 a, s64 b) { return ((a > 0) && (b > 0) && (a > S64_MAX - b)) || ((a < 0) && (b < 0) && (a < S64_MIN - b)); }
static inline bool signed_sub_overflows(s64 a, s64 b) { return ((a > 0) && (b < 0) && (a > S64_MAX + b)) || ((a < 0) && (b > 0) && (a < S64_MIN + b)); }

static inline u64 min(u64 a, u64 b) { return a < b ? a : b; }
static inline u64 max(u64 a, u64 b) { return a > b ? a : b; }

static inline void __mark_reg_unknown(struct bpf_reg_state *reg) { reg->var_off = (struct tnum){0, 0}; reg->smin_value = S64_MIN; reg->smax_value = S64_MAX; reg->umin_value = 0; reg->umax_value = U64_MAX; }
static inline void __mark_reg_unbounded(struct bpf_reg_state *reg) { reg->smin_value = S64_MIN; reg->smax_value = S64_MAX; reg->umin_value = 0; reg->umax_value = U64_MAX; }
static inline void __mark_reg_known(struct bpf_reg_state *reg, u64 val) { reg->var_off = (struct tnum){val, 0}; reg->smin_value = val; reg->smax_value = val; reg->umin_value = val; reg->umax_value = val; }
static inline void __update_reg_bounds(struct bpf_reg_state *reg) {}
static inline void __reg_deduce_bounds(struct bpf_reg_state *reg) {}
static inline void __reg_bound_offset(struct bpf_reg_state *reg) {}

static inline struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env) { return NULL; }
static inline void mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *regs, u32 regno) {}
static inline void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {}
static inline int sanitize_val_alu(struct bpf_verifier_env *env, struct bpf_insn *insn) { return 0; }
static inline void coerce_reg_to_size(struct bpf_reg_state *reg, int size) {}