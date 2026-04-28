#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define fallthrough __attribute__((fallthrough))

typedef int64_t s64;
typedef uint64_t u64;
typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;

#define BPF_ALU64 0x07
#define BPF_ADD 0x00
#define BPF_SUB 0x10
#define BPF_AND 0x50
#define BPF_OR 0x40
#define BPF_XOR 0xa0
#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_OP(code) ((code) & 0xf0)

#define S64_MIN (-9223372036854775807LL - 1)
#define S64_MAX 9223372036854775807LL
#define U64_MAX 18446744073709551615ULL

#define EACCES 13
#define EINVAL 22

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_reg_state {
    int type;
    int id;
    s64 smin_value;
    s64 smax_value;
    u64 umin_value;
    u64 umax_value;
    struct tnum var_off;
    s32 off;
    u32 raw;
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
    int id_gen;
};

struct bpf_insn {
    u8 code;
    u8 dst_reg;
};

struct bpf_sanitize_info {
};

struct bpf_insn_aux_data {
};

enum {
    PTR_TO_MAP_VALUE_OR_NULL,
    CONST_PTR_TO_MAP,
    PTR_TO_PACKET_END,
    PTR_TO_SOCKET,
    PTR_TO_SOCKET_OR_NULL,
    PTR_TO_SOCK_COMMON,
    PTR_TO_SOCK_COMMON_OR_NULL,
    PTR_TO_TCP_SOCK,
    PTR_TO_TCP_SOCK_OR_NULL,
    PTR_TO_XDP_SOCK,
    PTR_TO_STACK
};

static const char *reg_type_str[] = {
    "PTR_TO_MAP_VALUE_OR_NULL",
    "CONST_PTR_TO_MAP",
    "PTR_TO_PACKET_END",
    "PTR_TO_SOCKET",
    "PTR_TO_SOCKET_OR_NULL",
    "PTR_TO_SOCK_COMMON",
    "PTR_TO_SOCK_COMMON_OR_NULL",
    "PTR_TO_TCP_SOCK",
    "PTR_TO_TCP_SOCK_OR_NULL",
    "PTR_TO_XDP_SOCK",
    "PTR_TO_STACK"
};

static const char *bpf_alu_string[] = {
    "ADD",
    "SUB",
    "AND",
    "OR",
    "XOR"
};

static bool tnum_is_const(struct tnum t) { return t.mask == 0; }
static struct tnum tnum_add(struct tnum a, struct tnum b) { return (struct tnum){0}; }
static struct tnum tnum_sub(struct tnum a, struct tnum b) { return (struct tnum){0}; }
static bool signed_add_overflows(s64 a, s64 b) { return false; }
static bool signed_sub_overflows(s64 a, s64 b) { return false; }
static bool reg_is_pkt_pointer(const struct bpf_reg_state *reg) { return false; }
static bool sanitize_needed(u8 opcode) { return false; }
static int sanitize_ptr_alu(struct bpf_verifier_env *env, struct bpf_insn *insn,
                          const struct bpf_reg_state *ptr_reg,
                          const struct bpf_reg_state *off_reg,
                          struct bpf_reg_state *dst_reg,
                          void *aux, bool is_dst) { return 0; }
static int sanitize_err(struct bpf_verifier_env *env, struct bpf_insn *insn,
                       int ret, const struct bpf_reg_state *off_reg,
                       struct bpf_reg_state *dst_reg) { return 0; }
static bool check_reg_sane_offset(struct bpf_verifier_env *env,
                                const struct bpf_reg_state *reg,
                                int type) { return true; }
static void __mark_reg_unknown(struct bpf_verifier_env *env,
                              struct bpf_reg_state *reg) {}
static void __mark_reg32_unbounded(struct bpf_reg_state *reg) {}
static void __update_reg_bounds(struct bpf_reg_state *reg) {}
static void __reg_deduce_bounds(struct bpf_reg_state *reg) {}
static void __reg_bound_offset(struct bpf_reg_state *reg) {}
static int sanitize_check_bounds(struct bpf_verifier_env *env,
                               struct bpf_insn *insn,
                               struct bpf_reg_state *dst_reg) { return 0; }
static void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {}