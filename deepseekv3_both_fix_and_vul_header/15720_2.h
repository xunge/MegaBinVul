#include <stdbool.h>
#include <stddef.h>
#include <linux/types.h>
#include <linux/errno.h>

#define BPF_REG_SIZE 8
#define STACK_MISC 0
#define STACK_ZERO 1
#define STACK_INVALID 2
#define NOT_INIT 0

typedef unsigned char u8;

struct bpf_reg_state {
    int smin_value;
    int smax_value;
};

struct bpf_insn {
    int imm;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
};

struct bpf_verifier_state {
    struct bpf_func_state *frame[1];
    int curframe;
};

struct bpf_stack_slot {
    u8 slot_type[BPF_REG_SIZE];
    struct {
        int type;
    } spilled_ptr;
};

struct bpf_func_state {
    struct bpf_reg_state regs[1];
    struct bpf_stack_slot stack[1];
};

struct bpf_verifier_env {
    struct bpf_prog *prog;
    struct bpf_verifier_state *cur_state;
    bool allow_ptr_leaks;
    bool allow_uninit_stack;
};

static inline int round_up(int value, int align) {
    return (value + align - 1) / align * align;
}

static inline bool register_is_null(struct bpf_reg_state *reg) {
    return false;
}

static inline bool is_bpf_st_mem(struct bpf_insn *insn) {
    return false;
}

static inline int __get_spi(int off) {
    return 0;
}

static inline int destroy_if_dynptr_stack_slot(struct bpf_verifier_env *env, struct bpf_func_state *state, int spi) {
    return 0;
}

static inline void mark_stack_slot_scratched(struct bpf_verifier_env *env, int spi) {
}

static inline void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {
}

static inline int mark_chain_precision(struct bpf_verifier_env *env, int regno) {
    return 0;
}

static inline int grow_stack_state(struct bpf_func_state *state, int size) {
    return 0;
}