#include <stdint.h>
#include <stdbool.h>

#define BPF_REG_0 0
#define SRC_OP 1
#define DST_OP 2
#define DST_OP_NO_MARK 3
#define REG_LIVE_WRITTEN 1
#define SCALAR_VALUE 0
#define BPF_ALU64 1
#define BPF_X 0
#define BPF_K 1
#define BPF_END 0xd0
#define BPF_NEG 0x80
#define BPF_MOV 0xb0
#define BPF_MOD 0x90
#define BPF_DIV 0x30
#define BPF_LSH 0x60
#define BPF_RSH 0x70
#define BPF_ARSH 0xc0
#define EINVAL 22
#define EACCES 13

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int16_t s16;
typedef int32_t s32;

struct bpf_verifier_env;
struct bpf_reg_state;

struct bpf_insn {
    u8 code;
    u8 dst_reg;
    u8 src_reg;
    s16 off;
    s32 imm;
};

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_reg_state {
    int type;
    struct tnum var_off;
    int live;
};

static u8 BPF_OP(u8 code) { return code & 0xf0; }
static u8 BPF_SRC(u8 code) { return code & 0x08; }
static u8 BPF_CLASS(u8 code) { return code & 0x07; }

static struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env) { return 0; }
static int check_reg_arg(struct bpf_verifier_env *env, int reg, int type) { return 0; }
static bool is_pointer_value(struct bpf_verifier_env *env, int reg) { return false; }
static void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {}
static void mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *regs, int reg) {}
static void __update_reg_bounds(struct bpf_reg_state *reg) {}
static void __mark_reg_known(struct bpf_reg_state *reg, u64 value) {}
static int adjust_reg_min_max_vals(struct bpf_verifier_env *env, struct bpf_insn *insn) { return 0; }

static struct tnum tnum_cast(struct tnum a, int size) {
    a.value &= (1ULL << size) - 1;
    a.mask &= (1ULL << size) - 1;
    return a;
}