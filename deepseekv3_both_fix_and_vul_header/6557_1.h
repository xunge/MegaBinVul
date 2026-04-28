#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

#define BPF_OP(code) ((code) & 0xf0)
#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_ALU64 0x07
#define BPF_ADD 0x00
#define BPF_SUB 0x10
#define BPF_AND 0x50
#define BPF_OR 0x40
#define BPF_XOR 0xa0

#define PTR_TO_MAP_VALUE_OR_NULL 1
#define CONST_PTR_TO_MAP 2
#define PTR_TO_PACKET_END 3
#define PTR_TO_STACK 4

#define S64_MIN INT64_MIN
#define S64_MAX INT64_MAX
#define U64_MAX UINT64_MAX

#define EINVAL 22
#define EACCES 13

typedef int64_t s64;
typedef uint64_t u64;
typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_verifier_env {
    struct bpf_reg_state *cur_regs;
    void *cur_state;
    bool allow_ptr_leaks;
    u32 id_gen;
};

struct bpf_insn {
    u8 code;
    u8 dst_reg;
};

struct bpf_reg_state {
    int type;
    s64 smin_value;
    s64 smax_value;
    u64 umin_value;
    u64 umax_value;
    struct tnum var_off;
    s32 off;
    u32 id;
    u32 range;
};

static const char *bpf_alu_string[] = {
    [BPF_ADD >> 4] = "+",
    [BPF_SUB >> 4] = "-",
    [BPF_AND >> 4] = "&",
    [BPF_OR >> 4] = "|",
    [BPF_XOR >> 4] = "^"
};

static inline bool signed_add_overflows(s64 a, s64 b) {
    return ((b > 0) && (a > S64_MAX - b)) ||
           ((b < 0) && (a < S64_MIN - b));
}

static inline bool signed_sub_overflows(s64 a, s64 b) {
    return ((b > 0) && (a < S64_MIN + b)) ||
           ((b < 0) && (a > S64_MAX + b));
}

static inline struct tnum tnum_add(struct tnum a, struct tnum b) {
    u64 chi = a.value + b.value;
    u64 clo = (a.value + b.value) - chi;
    return (struct tnum){ .value = chi, .mask = a.mask | b.mask | clo };
}

static inline struct tnum tnum_sub(struct tnum a, struct tnum b) {
    u64 chi = a.value - b.value;
    u64 clo = (a.value - b.value) - chi;
    return (struct tnum){ .value = chi, .mask = a.mask | b.mask | clo };
}

static inline bool tnum_is_const(struct tnum t) {
    return !t.mask;
}

static inline bool reg_is_pkt_pointer(const struct bpf_reg_state *reg) {
    return reg->type == PTR_TO_PACKET_END;
}

static inline void __update_reg_bounds(struct bpf_reg_state *reg) {}
static inline void __reg_deduce_bounds(struct bpf_reg_state *reg) {}
static inline void __reg_bound_offset(struct bpf_reg_state *reg) {}

static inline struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env) {
    return env->cur_regs;
}

static inline void print_verifier_state(struct bpf_verifier_env *env, void *state) {}
static inline void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {}