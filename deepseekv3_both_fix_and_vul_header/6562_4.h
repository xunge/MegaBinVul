#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int16_t s16;
typedef int32_t s32;
typedef uint8_t u8;
typedef uint32_t u32;

#define BPF_COMPLEXITY_LIMIT_INSNS 1000000
#define NOT_INIT 0
#define SRC_OP 1
#define DST_OP_NO_MARK 2
#define GFP_KERNEL 0
#define ENOMEM 12
#define EFAULT 14
#define E2BIG 7
#define EINVAL 22
#define EACCES 13
#define ENOENT 2

enum bpf_reg_type {
    PTR_TO_CTX,
    /* other types... */
};

enum bpf_class {
    BPF_LD = 0x00,
    BPF_LDX = 0x01,
    BPF_ST = 0x02,
    BPF_STX = 0x03,
    BPF_ALU = 0x04,
    BPF_JMP = 0x05,
    BPF_ALU64 = 0x07
};

enum bpf_op {
    BPF_JA = 0x00,
    BPF_CALL = 0x80,
    BPF_EXIT = 0x90
};

enum bpf_src {
    BPF_K = 0x00
};

enum bpf_mode {
    BPF_IMM = 0x00,
    BPF_ABS = 0x20,
    BPF_IND = 0x40,
    BPF_MEM = 0x60,
    BPF_XADD = 0xc0
};

enum bpf_access {
    BPF_READ = 0,
    BPF_WRITE = 1
};

enum bpf_reg {
    BPF_REG_0 = 0
};

struct bpf_verifier_env {
    struct bpf_prog *prog;
    struct bpf_verifier_state *cur_state;
    struct {
        int level;
    } log;
    bool allow_ptr_leaks;
    struct {
        bool seen;
        enum bpf_reg_type ptr_type;
    } *insn_aux_data;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
    int len;
    struct {
        int stack_depth;
    } *aux;
};

struct bpf_verifier_state {
    struct bpf_reg_state *regs;
    struct bpf_verifier_state *parent;
};

struct bpf_reg_state {
    enum bpf_reg_type type;
};

struct bpf_insn {
    u32 code;
    u8 src_reg;
    u8 dst_reg;
    s16 off;
    s32 imm;
};

static inline u8 BPF_CLASS(u32 code) { return code >> 28; }
static inline u8 BPF_OP(u32 code) { return (code >> 24) & 0xf; }
static inline u8 BPF_SRC(u32 code) { return (code >> 23) & 0x1; }
static inline u8 BPF_MODE(u32 code) { return (code >> 21) & 0x3; }
static inline u8 BPF_SIZE(u32 code) { return (code >> 19) & 0x3; }

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static bool need_resched(void) { return false; }
static void cond_resched(void) {}
static void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {}

static void init_reg_state(struct bpf_verifier_env *env, struct bpf_reg_state *regs) {}
static int is_state_visited(struct bpf_verifier_env *env, int insn_idx) { return 0; }
static void print_verifier_state(struct bpf_verifier_env *env, struct bpf_verifier_state *state) {}
static void print_bpf_insn(void (*verbose)(struct bpf_verifier_env *, const char *, ...), 
                         struct bpf_verifier_env *env, struct bpf_insn *insn, bool allow_ptr_leaks) {}
static int ext_analyzer_insn_hook(struct bpf_verifier_env *env, int insn_idx, int prev_insn_idx) { return 0; }
static struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env) { return NULL; }
static int check_alu_op(struct bpf_verifier_env *env, struct bpf_insn *insn) { return 0; }
static int check_reg_arg(struct bpf_verifier_env *env, u32 reg, int type) { return 0; }
static int check_mem_access(struct bpf_verifier_env *env, int insn_idx, u32 regno, int off, 
                          int size, int value, int dst_reg) { return 0; }
static int check_xadd(struct bpf_verifier_env *env, int insn_idx, struct bpf_insn *insn) { return 0; }
static int check_call(struct bpf_verifier_env *env, u32 func_id, int insn_idx) { return 0; }
static int is_pointer_value(struct bpf_verifier_env *env, int regno) { return 0; }
static int check_return_code(struct bpf_verifier_env *env) { return 0; }
static int pop_stack(struct bpf_verifier_env *env, int *prev_insn_idx, int *insn_idx) { return 0; }
static int check_cond_jmp_op(struct bpf_verifier_env *env, struct bpf_insn *insn, int *insn_idx) { return 0; }
static int check_ld_abs(struct bpf_verifier_env *env, struct bpf_insn *insn) { return 0; }
static int check_ld_imm(struct bpf_verifier_env *env, struct bpf_insn *insn) { return 0; }