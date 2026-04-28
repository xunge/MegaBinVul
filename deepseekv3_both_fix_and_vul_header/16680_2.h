#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef int32_t s32;
typedef int64_t s64;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;

#define S64_MIN (-9223372036854775807LL - 1)
#define S64_MAX 9223372036854775807LL
#define U64_MAX 18446744073709551615ULL

#define EACCES 13
#define EINVAL 22

#define BPF_OP(code) ((code) & 0xf0)
#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_ADD 0x00
#define BPF_SUB 0x10
#define BPF_AND 0x50
#define BPF_OR 0x40
#define BPF_XOR 0xa0
#define BPF_ALU64 0x07

#define PTR_TO_MAP_VALUE_OR_NULL 1
#define CONST_PTR_TO_MAP 2
#define PTR_TO_PACKET_END 3
#define PTR_TO_SOCKET 4
#define PTR_TO_SOCKET_OR_NULL 5
#define PTR_TO_SOCK_COMMON 6
#define PTR_TO_SOCK_COMMON_OR_NULL 7
#define PTR_TO_TCP_SOCK 8
#define PTR_TO_TCP_SOCK_OR_NULL 9
#define PTR_TO_XDP_SOCK 10
#define PTR_TO_MAP_VALUE 11
#define PTR_TO_STACK 12

#define fallthrough __attribute__((fallthrough))

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_reg_state {
    u32 type;
    u32 id;
    s64 smin_value;
    s64 smax_value;
    u64 umin_value;
    u64 umax_value;
    struct tnum var_off;
    s32 off;
    u64 raw;
};

struct bpf_insn {
    u8 code;
    u8 dst_reg;
    u8 src_reg;
};

struct bpf_func_state {
    struct bpf_reg_state *regs;
};

struct bpf_verifier_state {
    struct bpf_func_state **frame;
    u32 curframe;
};

struct bpf_verifier_env {
    struct bpf_verifier_state *cur_state;
    bool allow_ptr_leaks;
    bool bypass_spec_v1;
    u32 id_gen;
};

extern const char *bpf_alu_string[];
extern const char *reg_type_str[];

static bool signed_add_overflows(s64 a, s64 b) {
    return ((b > 0) && (a > S64_MAX - b)) ||
           ((b < 0) && (a < S64_MIN - b));
}

static bool signed_sub_overflows(s64 a, s64 b) {
    return ((b > 0) && (a < S64_MIN + b)) ||
           ((b < 0) && (a > S64_MAX + b));
}

static bool tnum_is_const(struct tnum t);
static struct tnum tnum_add(struct tnum a, struct tnum b);
static struct tnum tnum_sub(struct tnum a, struct tnum b);
static void __mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *reg);
static void __mark_reg32_unbounded(struct bpf_reg_state *reg);
static bool check_reg_sane_offset(struct bpf_verifier_env *env, const struct bpf_reg_state *reg, int reg_type);
static int sanitize_ptr_alu(struct bpf_verifier_env *env, struct bpf_insn *insn, const struct bpf_reg_state *ptr_reg, struct bpf_reg_state *dst_reg, bool negative);
static bool reg_is_pkt_pointer(const struct bpf_reg_state *reg);
static void __update_reg_bounds(struct bpf_reg_state *reg);
static void __reg_deduce_bounds(struct bpf_reg_state *reg);
static void __reg_bound_offset(struct bpf_reg_state *reg);
static int check_map_access(struct bpf_verifier_env *env, u32 regno, int off, int size, bool zero_size_allowed);
static bool check_stack_access_for_ptr_arithmetic(struct bpf_verifier_env *env, int regno, const struct bpf_reg_state *reg, int off);
static void verbose(struct bpf_verifier_env *env, const char *fmt, ...);