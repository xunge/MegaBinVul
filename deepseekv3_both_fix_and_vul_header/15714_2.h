#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>

#define BPF_REG_SIZE 8
#define MAX_BPF_STACK 512
#define BITS_PER_BYTE 8
#define EACCES 13
#define EINVAL 22
#define MAX_BPF_FRAMES 8

typedef uint8_t u8;

enum {
    STACK_MISC,
    STACK_ZERO,
    NOT_INIT,
    SCALAR_VALUE,
    PTR_TO_STACK
};

struct bpf_reg_state {
    unsigned int type;
    uint64_t umax_value;
    unsigned int id;
    unsigned int live;
};

struct bpf_stack_slot {
    struct bpf_reg_state spilled_ptr;
    u8 slot_type[BPF_REG_SIZE];
};

struct bpf_func_state {
    struct bpf_stack_slot stack[MAX_BPF_STACK / BPF_REG_SIZE];
    int frameno;
    struct bpf_reg_state regs[64];
};

struct bpf_insn {
    int imm;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
};

struct bpf_verifier_state {
    struct bpf_func_state *frame[MAX_BPF_FRAMES];
    int curframe;
};

struct bpf_insn_aux_data {
    bool sanitize_stack_spill;
};

struct bpf_verifier_env {
    struct bpf_prog *prog;
    bool allow_ptr_leaks;
    bool bypass_spec_v4;
    bool bpf_capable;
    struct bpf_verifier_state *cur_state;
    struct bpf_insn_aux_data *insn_aux_data;
};

#define REG_LIVE_WRITTEN 0x8

static inline int fls64(uint64_t x) {
    return x ? sizeof(x) * CHAR_BIT - __builtin_clzll(x) : 0;
}

static inline unsigned long round_up(unsigned long x, unsigned long y) {
    return ((x + y - 1) / y) * y;
}

static int insn_stack_access_flags(int frameno, int spi) { return 0; }
static int grow_stack_state(struct bpf_func_state *state, int size) { return 0; }
static bool is_spilled_reg(struct bpf_stack_slot *slot) { return false; }
static void verbose(struct bpf_verifier_env *env, const char *fmt) {}
static bool is_spillable_regtype(unsigned int type) { return false; }
static int destroy_if_dynptr_stack_slot(struct bpf_verifier_env *env, struct bpf_func_state *state, int spi) { return 0; }
static void mark_stack_slot_scratched(struct bpf_verifier_env *env, int spi) {}
static bool register_is_bounded(struct bpf_reg_state *reg) { return false; }
static void save_register_state(struct bpf_verifier_env *env, struct bpf_func_state *state, int spi, struct bpf_reg_state *reg, int size) {}
static bool is_bpf_st_mem(struct bpf_insn *insn) { return false; }
static void __mark_reg_known(struct bpf_reg_state *reg, int imm) {}
static void verbose_linfo(struct bpf_verifier_env *env, int insn_idx, const char *sep) {}
static bool is_stack_slot_special(struct bpf_stack_slot *slot) { return false; }
static void scrub_spilled_slot(u8 *slot_type) {}
static bool register_is_null(struct bpf_reg_state *reg) { return false; }
static int mark_chain_precision(struct bpf_verifier_env *env, int regno) { return 0; }
static int push_jmp_history(struct bpf_verifier_env *env, struct bpf_verifier_state *state, int flags) { return 0; }