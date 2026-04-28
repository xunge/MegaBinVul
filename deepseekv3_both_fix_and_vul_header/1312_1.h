#include <stdbool.h>
#include <stdint.h>

struct bpf_verifier_env;
struct bpf_reg_state;

struct tnum {
    uint64_t value;
    uint64_t mask;
};

struct bpf_insn {
    uint8_t code;
    uint8_t dst_reg;
};

struct bpf_reg_state {
    int64_t smin_value;
    int64_t smax_value;
    uint64_t umin_value;
    uint64_t umax_value;
    struct tnum var_off;
};

static inline bool tnum_is_const(struct tnum t) {
    return !t.mask;
}

static inline struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env) {
    return 0;
}

static inline void coerce_reg_to_size(struct bpf_reg_state *reg, int size) {}
static inline void __mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *reg) {}
static inline void mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *regs, int regno) {}
static inline void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {}
static inline int sanitize_val_alu(struct bpf_verifier_env *env, struct bpf_insn *insn) { return 0; }
static inline void scalar_min_max_add(struct bpf_reg_state *dst, struct bpf_reg_state *src) {}
static inline void scalar_min_max_sub(struct bpf_reg_state *dst, struct bpf_reg_state *src) {}
static inline void scalar_min_max_mul(struct bpf_reg_state *dst, struct bpf_reg_state *src) {}
static inline void scalar_min_max_and(struct bpf_reg_state *dst, struct bpf_reg_state *src) {}
static inline void scalar_min_max_or(struct bpf_reg_state *dst, struct bpf_reg_state *src) {}
static inline void scalar_min_max_lsh(struct bpf_reg_state *dst, struct bpf_reg_state *src) {}
static inline void scalar_min_max_rsh(struct bpf_reg_state *dst, struct bpf_reg_state *src) {}
static inline void scalar_min_max_arsh(struct bpf_reg_state *dst, struct bpf_reg_state *src, uint64_t bitness) {}
static inline void __mark_reg_known(struct bpf_reg_state *reg, uint64_t val) {}
static inline void __reg_deduce_bounds(struct bpf_reg_state *reg) {}
static inline void __reg_bound_offset(struct bpf_reg_state *reg) {}

#define BPF_OP(code) ((code) & 0xf0)
#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_ALU 0x04
#define BPF_ALU64 0x07
#define BPF_ADD 0x00
#define BPF_SUB 0x10
#define BPF_MUL 0x20
#define BPF_AND 0x50
#define BPF_OR 0x40
#define BPF_LSH 0x60
#define BPF_RSH 0x70
#define BPF_ARSH 0x80

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int64_t s64;