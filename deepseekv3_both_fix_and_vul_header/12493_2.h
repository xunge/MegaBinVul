#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint32_t u32;

struct tnum {
    unsigned long value;
    unsigned long mask;
};

struct bpf_reg_state {
    long smin_value;
    struct tnum var_off;
};

struct bpf_insn_aux_data {
    u32 alu_state;
    u32 alu_limit;
};

struct bpf_verifier_state {
    bool speculative;
};

struct bpf_verifier_env {
    struct bpf_verifier_state *cur_state;
    int insn_idx;
};

struct bpf_insn {
    u8 code;
};

enum {
    BPF_ALU_NEG_VALUE = 1,
    BPF_ALU_IMMEDIATE = 2,
    BPF_ALU_SANITIZE_SRC = 4,
    BPF_ALU_SANITIZE_DST = 8,
    REASON_STACK = 1
};

static inline bool tnum_is_const(struct tnum t) {
    return !t.mask;
}

#define BPF_OP(code) ((code) & 0xf0)

static inline struct bpf_insn_aux_data *cur_aux(struct bpf_verifier_env *env) {
    return NULL;
}

static inline bool can_skip_alu_sanitation(struct bpf_verifier_env *env, struct bpf_insn *insn) {
    return false;
}

static inline int retrieve_ptr_limit(const struct bpf_reg_state *ptr_reg,
                                   const struct bpf_reg_state *off_reg,
                                   u32 *alu_limit, u8 opcode) {
    return 0;
}

static inline int update_alu_sanitation_state(struct bpf_insn_aux_data *aux,
                                            u32 alu_state, u32 alu_limit) {
    return 0;
}

static inline bool push_stack(struct bpf_verifier_env *env,
                            int insn_idx, int prev_insn_idx,
                            bool speculative) {
    return false;
}