#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BPF_OP(code)  ((code) & 0xf0)
#define BPF_SRC(code) ((code) & 0x08)
#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_REG_0 0
#define BPF_ALU64 0x07
#define BPF_X 0x08
#define BPF_K 0x00
#define BPF_END 0xd0
#define BPF_NEG 0x80
#define BPF_MOV 0xb0
#define BPF_MOD 0x90
#define BPF_DIV 0x30
#define BPF_LSH 0x60
#define BPF_RSH 0x70
#define BPF_ARSH 0xc0

#define SRC_OP 1
#define DST_OP 2
#define DST_OP_NO_MARK 3

#define REG_LIVE_WRITTEN 0x8
#define DEF_NOT_SUBREG 0

#define SCALAR_VALUE 1

#define EINVAL 22
#define EACCES 13

typedef uint8_t u8;
typedef uint32_t u32;
typedef int16_t s16;
typedef int32_t s32;

struct bpf_verifier_env {
    unsigned int id_gen;
    unsigned int insn_idx;
};

struct bpf_reg_state {
    int type;
    int id;
    int live;
    int subreg_def;
};

struct bpf_insn {
    u8 code;
    u8 src_reg;
    u8 dst_reg;
    s16 off;
    s32 imm;
};

static inline struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env) { return NULL; }
static int check_reg_arg(struct bpf_verifier_env *env, int reg, int type) { return 0; }
static bool is_pointer_value(struct bpf_verifier_env *env, int reg) { return false; }
static void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {}
static void mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *regs, int reg) {}
static void __mark_reg_known(struct bpf_reg_state *reg, unsigned long imm) {}
static void zext_32_to_64(struct bpf_reg_state *reg) {}
static int adjust_reg_min_max_vals(struct bpf_verifier_env *env, struct bpf_insn *insn) { return 0; }