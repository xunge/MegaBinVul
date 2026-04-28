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
    struct tnum var_off;
    long smin_value;
    long smax_value;
};

struct bpf_insn {
    u8 code;
};

struct bpf_insn_aux_data {
    u32 alu_state;
    u32 alu_limit;
};

struct bpf_sanitize_info {
    struct bpf_insn_aux_data aux;
    bool mask_to_left;
};

struct bpf_verifier_state {
    bool speculative;
};

struct bpf_verifier_env {
    struct bpf_verifier_state *cur_state;
    struct bpf_insn_aux_data *aux_data;
    int insn_idx;
};

enum {
    BPF_ADD,
    BPF_SUB,
    BPF_ALU_NEG_VALUE,
    BPF_ALU_IMMEDIATE,
    BPF_ALU_SANITIZE_SRC,
    BPF_ALU_SANITIZE_DST,
    REASON_BOUNDS,
    REASON_STACK
};

#define BPF_OP(code) ((code) & 0xf0)

static inline bool tnum_is_const(struct tnum t) { return !t.mask; }
static inline struct bpf_insn_aux_data *cur_aux(struct bpf_verifier_env *env) { return env->aux_data; }
static inline bool can_skip_alu_sanitation(struct bpf_verifier_env *env, struct bpf_insn *insn) { return false; }

// First version with 3 parameters
static inline int retrieve_ptr_limit_3(const struct bpf_reg_state *ptr_reg, u32 *alu_limit, bool mask_to_left) { return 0; }

// Second version with 4 parameters
static inline int retrieve_ptr_limit_4(const struct bpf_reg_state *ptr_reg, const struct bpf_reg_state *off_reg, u32 *alu_limit, u8 opcode) { return 0; }

static inline int update_alu_sanitation_state(struct bpf_insn_aux_data *aux, u32 alu_state, u32 alu_limit) { return 0; }
static inline bool push_stack(struct bpf_verifier_env *env, int insn_idx, int prev_insn_idx, bool speculative) { return false; }