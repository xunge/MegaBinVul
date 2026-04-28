#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define BPF_OP(code) ((code) & 0xf0)
#define BPF_SRC(code) ((code) & 0x08)
#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_JMP32 0x06
#define BPF_JA 0x00
#define BPF_JSLE 0xd0
#define BPF_X 0x08
#define BPF_K 0x00
#define BPF_REG_0 0
#define BPF_JEQ 0x10
#define BPF_JNE 0x50
#define SRC_OP 2
#define SCALAR_VALUE 1
#define EINVAL 22
#define EACCES 13
#define EFAULT 14
#define BPF_LOG_LEVEL 1

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int16_t s16;
typedef int32_t s32;

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_insn {
    u8 code;
    u8 dst_reg;
    u8 src_reg;
    s16 off;
    s32 imm;
};

struct bpf_reg_state {
    int type;
    struct tnum var_off;
    u32 id;
};

struct bpf_func_state {
    struct bpf_reg_state *regs;
};

struct bpf_verifier_state {
    struct bpf_func_state **frame;
    int curframe;
    struct bpf_verifier_state *cur_state;
};

struct bpf_verifier_env {
    struct bpf_verifier_state *cur_state;
    struct {
        u32 level;
    } log;
    bool bypass_spec_v1;
};

#define WARN_ON_ONCE(condition) (condition)

static inline bool tnum_is_const(struct tnum tn) { return !tn.mask; }
static inline struct tnum tnum_subreg(struct tnum tn) { return tn; }
static inline bool __is_pointer_value(bool allow_ptr_leaks, const struct bpf_reg_state *reg) { return false; }
static int verbose(struct bpf_verifier_env *env, const char *fmt, ...) { return 0; }
static int check_reg_arg(struct bpf_verifier_env *env, u32 regno, int op) { return 0; }
static bool is_pointer_value(struct bpf_verifier_env *env, int regno) { return false; }
static int is_branch_taken(struct bpf_reg_state *reg, u64 val, u8 opcode, bool is_jmp32) { return 0; }
static bool reg_is_pkt_pointer_any(const struct bpf_reg_state *reg) { return false; }
static int is_pkt_ptr_branch_taken(struct bpf_reg_state *dst_reg, struct bpf_reg_state *src_reg, u8 opcode) { return 0; }
static int mark_chain_precision(struct bpf_verifier_env *env, int regno) { return 0; }
static bool sanitize_speculative_path(struct bpf_verifier_env *env, struct bpf_insn *insn, int next_idx, int curr_idx) { return false; }
static struct bpf_verifier_state *push_stack(struct bpf_verifier_env *env, int insn_idx, int prev_insn_idx, bool speculative) { return NULL; }
static void reg_set_min_max(struct bpf_reg_state *true_reg, struct bpf_reg_state *false_reg, u64 val, u32 val32, u8 opcode, bool is_jmp32) {}
static void reg_set_min_max_inv(struct bpf_reg_state *true_reg, struct bpf_reg_state *false_reg, u64 val, u32 val32, u8 opcode, bool is_jmp32) {}
static void reg_combine_min_max(struct bpf_reg_state *true_src, struct bpf_reg_state *true_dst, struct bpf_reg_state *false_src, struct bpf_reg_state *false_dst, u8 opcode) {}
static void find_equal_scalars(struct bpf_verifier_state *state, struct bpf_reg_state *known_reg) {}
static bool reg_type_may_be_null(int type) { return false; }
static void mark_ptr_or_null_regs(struct bpf_verifier_state *state, u32 regno, bool is_null) {}
static bool try_match_pkt_pointers(struct bpf_insn *insn, struct bpf_reg_state *dst_reg, struct bpf_reg_state *src_reg, struct bpf_verifier_state *this_branch, struct bpf_verifier_state *other_branch) { return false; }
static void print_verifier_state(struct bpf_verifier_env *env, struct bpf_func_state *state) {}