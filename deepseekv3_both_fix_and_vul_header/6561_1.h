#include <stdbool.h>
#include <stddef.h>

#define MAX_BPF_STACK 512
#define BPF_REG_SIZE 8
#define EACCES 13

enum {
    PTR_TO_STACK,
    STACK_MISC,
};

struct tnum {
    unsigned long value;
    unsigned long mask;
};

struct bpf_reg_state {
    int type;
    int off;
    struct tnum var_off;
};

struct bpf_stack_state {
    int slot_type[BPF_REG_SIZE];
};

struct bpf_verifier_state {
    struct bpf_reg_state *regs;
    int allocated_stack;
    struct bpf_stack_state *stack;
};

struct bpf_prog_aux {
    int stack_depth;
};

struct bpf_prog {
    struct bpf_prog_aux *aux;
};

struct bpf_call_arg_meta {
    bool raw_mode;
    int access_size;
    int regno;
};

struct bpf_verifier_env {
    struct bpf_verifier_state *cur_state;
    struct bpf_prog *prog;
    void (*verbose)(struct bpf_verifier_env *env, const char *fmt, ...);
};

extern const char *reg_type_str[];

static bool register_is_null(struct bpf_reg_state reg);
static bool tnum_is_const(struct tnum t);
static void tnum_strn(char *buf, size_t size, struct tnum t);