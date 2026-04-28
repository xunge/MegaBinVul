#include <stdint.h>
#include <stdbool.h>

#define BPF_REG_0 0
#define SRC_OP 1
#define DST_OP 2
#define DST_OP_NO_MARK 3
#define REG_LIVE_WRITTEN 0x8
#define SCALAR_VALUE 1
#define EINVAL 22
#define EACCES 13

enum {
    BPF_ALU64 = 0x07,
    BPF_END = 0xd0,
    BPF_NEG = 0x80,
    BPF_MOV = 0xb0,
    BPF_MOD = 0x90,
    BPF_DIV = 0x30,
    BPF_LSH = 0x60,
    BPF_RSH = 0x70,
    BPF_ARSH = 0xc0,
    BPF_X = 0x08,
    BPF_K = 0x00
};

#define BPF_OP(code) ((code) & 0xf0)
#define BPF_SRC(code) ((code) & 0x08)
#define BPF_CLASS(code) ((code) & 0x07)

struct bpf_verifier_env;
struct bpf_reg_state {
    int type;
    uint64_t var_off;
    unsigned live;
};

struct bpf_insn {
    uint8_t code;
    uint8_t src_reg;
    uint8_t dst_reg;
    int16_t off;
    int32_t imm;
};

typedef uint32_t u32;
typedef uint8_t u8;

static struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env);
static int check_reg_arg(struct bpf_verifier_env *env, u32 regno, int arg);
static bool is_pointer_value(struct bpf_verifier_env *env, int regno);
static void verbose(struct bpf_verifier_env *env, const char *fmt, ...);
static void mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *regs, u32 regno);
static void __update_reg_bounds(struct bpf_reg_state *reg);
static void __mark_reg_known(struct bpf_reg_state *reg, uint64_t imm);
static int adjust_reg_min_max_vals(struct bpf_verifier_env *env, struct bpf_insn *insn);
static uint64_t tnum_cast(uint64_t var_off, int size);