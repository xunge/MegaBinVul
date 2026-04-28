#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

typedef int64_t s64;
typedef uint64_t u64;
typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
typedef int16_t s16;

#define S64_MIN    INT64_MIN
#define S64_MAX    INT64_MAX
#define U64_MAX    UINT64_MAX
#define EACCES     13
#define EINVAL     22

enum {
    BPF_ALU64 = 0x07,
    BPF_ADD = 0x00,
    BPF_SUB = 0x10,
    BPF_AND = 0x50,
    BPF_OR = 0x40,
    BPF_XOR = 0xa0,
};

enum bpf_reg_type {
    PTR_TO_MAP_VALUE_OR_NULL,
    CONST_PTR_TO_MAP,
    PTR_TO_PACKET_END,
    PTR_TO_SOCKET,
    PTR_TO_SOCKET_OR_NULL,
    PTR_TO_MAP_VALUE,
    PTR_TO_STACK,
};

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_reg_state {
    enum bpf_reg_type type;
    int id;
    s32 off;
    u32 raw;
    struct tnum var_off;
    s64 smin_value;
    s64 smax_value;
    u64 umin_value;
    u64 umax_value;
};

struct bpf_insn {
    u8 code;
    u8 dst_reg;
    u8 src_reg;
    s16 off;
    s32 imm;
};

struct bpf_func_state {
    struct bpf_reg_state *regs;
};

struct bpf_verifier_state {
    struct bpf_func_state **frame;
    int curframe;
};

struct bpf_verifier_env {
    struct bpf_verifier_state *cur_state;
    bool allow_ptr_leaks;
    u32 id_gen;
};

#define BPF_OP(code)  ((code) & 0xf0)
#define BPF_CLASS(code) ((code) & 0x07)

static inline bool signed_add_overflows(s64 a, s64 b) {
    return ((b > 0) && (a > S64_MAX - b)) ||
           ((b < 0) && (a < S64_MIN - b));
}

static inline bool signed_sub_overflows(s64 a, s64 b) {
    return ((b > 0) && (a < S64_MIN + b)) ||
           ((b < 0) && (a > S64_MAX + b));
}

static inline bool tnum_is_const(struct tnum var_off) {
    return var_off.mask == 0;
}

static inline struct tnum tnum_add(struct tnum a, struct tnum b) {
    return (struct tnum){a.value + b.value, a.mask | b.mask};
}

static inline struct tnum tnum_sub(struct tnum a, struct tnum b) {
    return (struct tnum){a.value - b.value, a.mask | b.mask};
}

static inline bool reg_is_pkt_pointer(const struct bpf_reg_state *reg) {
    return reg->type == PTR_TO_PACKET_END;
}

static inline void __mark_reg_unknown(struct bpf_reg_state *reg) {
    reg->type = 0;
    reg->id = 0;
    reg->off = 0;
    reg->var_off = (struct tnum){0, 0};
    reg->smin_value = S64_MIN;
    reg->smax_value = S64_MAX;
    reg->umin_value = 0;
    reg->umax_value = U64_MAX;
    reg->raw = 0;
}

static inline void __update_reg_bounds(struct bpf_reg_state *reg) {
    /* Empty implementation for compilation */
}

static inline void __reg_deduce_bounds(struct bpf_reg_state *reg) {
    /* Empty implementation for compilation */
}

static inline void __reg_bound_offset(struct bpf_reg_state *reg) {
    /* Empty implementation for compilation */
}

static inline bool check_reg_sane_offset(struct bpf_verifier_env *env, 
                                       const struct bpf_reg_state *reg,
                                       enum bpf_reg_type type) {
    return true;
}

static inline bool check_map_access(struct bpf_verifier_env *env, u32 regno, 
                                  s32 off, int size, bool zero_size_allowed) {
    return false;
}

static inline bool check_stack_access(struct bpf_verifier_env *env, 
                                    const struct bpf_reg_state *reg,
                                    s32 off, int size) {
    return false;
}

static inline void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {
    /* Empty implementation for compilation */
}

extern const char * const bpf_alu_string[16];
extern const char * const reg_type_str[16];