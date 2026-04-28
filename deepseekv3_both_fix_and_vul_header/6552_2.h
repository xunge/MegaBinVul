#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;

enum bpf_access_type {
    BPF_READ,
    BPF_WRITE
};

enum bpf_reg_type {
    SCALAR_VALUE,
    PTR_TO_MAP_VALUE,
    PTR_TO_CTX,
    PTR_TO_STACK,
    PTR_TO_PACKET,
    PTR_TO_PACKET_META,
    PTR_TO_PACKET_END
};

struct tnum {
    uint64_t value;
    uint64_t mask;
};

struct bpf_reg_state {
    enum bpf_reg_type type;
    int off;
    struct tnum var_off;
    int value;
    int id;
    int range;
};

struct bpf_verifier_state {
    struct bpf_reg_state *regs;
};

struct bpf_prog_aux {
    int stack_depth;
};

struct bpf_prog {
    struct bpf_prog_aux *aux;
};

struct bpf_verifier_env {
    struct bpf_verifier_state *cur_state;
    struct bpf_prog *prog;
};

#define MAX_BPF_STACK 512
#define EACCES 13
#define BPF_REG_SIZE 8

static const char *reg_type_str[] = {
    [SCALAR_VALUE] = "SCALAR_VALUE",
    [PTR_TO_MAP_VALUE] = "PTR_TO_MAP_VALUE",
    [PTR_TO_CTX] = "PTR_TO_CTX",
    [PTR_TO_STACK] = "PTR_TO_STACK",
    [PTR_TO_PACKET] = "PTR_TO_PACKET",
    [PTR_TO_PACKET_META] = "PTR_TO_PACKET_META",
    [PTR_TO_PACKET_END] = "PTR_TO_PACKET_END"
};

static inline struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env) {
    return env->cur_state->regs;
}

static inline int bpf_size_to_bytes(int bpf_size) {
    return bpf_size;
}

static inline bool tnum_is_const(struct tnum var) {
    return !var.mask;
}

static inline struct tnum tnum_cast(struct tnum var, int size) {
    return var;
}