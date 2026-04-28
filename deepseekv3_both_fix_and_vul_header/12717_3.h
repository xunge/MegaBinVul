#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;
typedef int64_t s64;

#define BPF_OP(code) ((code) & 0xf0)
#define BPF_ALU_NEG_VALUE 0x01
#define BPF_ALU_IMMEDIATE 0x02
#define BPF_ALU_SANITIZE_SRC 0x04
#define BPF_ALU_SANITIZE_DST 0x08
#define REASON_STACK 1

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_insn_aux_data {
    u32 alu_state;
    u32 alu_limit;
};

struct bpf_verifier_env {
    struct bpf_verifier_state *cur_state;
    int insn_idx;
};

struct bpf_insn {
    u8 code;
};

struct bpf_reg_state {
    struct tnum var_off;
    s64 smin_value;
};

struct bpf_sanitize_info {
    struct bpf_insn_aux_data aux;
};

struct bpf_verifier_state {
    bool speculative;
};

static inline bool tnum_is_const(struct tnum t) { return t.mask == 0; }
static struct bpf_insn_aux_data *cur_aux(struct bpf_verifier_env *env) { return NULL; }
static bool can_skip_alu_sanitation(struct bpf_verifier_env *env, struct bpf_insn *insn) { return false; }
static int retrieve_ptr_limit(const struct bpf_reg_state *ptr_reg, const struct bpf_reg_state *off_reg, u32 *alu_limit, u8 opcode) { return 0; }
static int update_alu_sanitation_state(struct bpf_insn_aux_data *aux, u32 alu_state, u32 alu_limit) { return 0; }
static bool push_stack(struct bpf_verifier_env *env, int insn_idx, int prev_insn_idx, bool speculative) { return false; }