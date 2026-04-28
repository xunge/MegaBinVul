#include <stdint.h>
#include <stdbool.h>
#include <linux/errno.h>

typedef uint8_t u8;
typedef uint32_t u32;

#define BPF_K 0x00
#define BPF_ALU_NEG_VALUE 0x01
#define BPF_ALU_SANITIZE_SRC 0x02
#define BPF_ALU_SANITIZE_DST 0x04

struct bpf_insn {
    u8 code;
};

struct bpf_reg_state {
    // minimal definition needed for compilation
};

struct bpf_insn_aux_data {
    u32 alu_state;
    u32 alu_limit;
};

struct bpf_verifier_state {
    bool speculative;
};

struct bpf_verifier_env {
    bool allow_ptr_leaks;
    struct bpf_verifier_state *cur_state;
    int insn_idx;
};

static inline u8 BPF_OP(u8 code) { return code & 0xf0; }
static inline u8 BPF_SRC(u8 code) { return code & 0x08; }

static inline struct bpf_insn_aux_data *cur_aux(struct bpf_verifier_env *env) { return 0; }
static int retrieve_ptr_limit(const struct bpf_reg_state *ptr_reg, u32 *alu_limit, u8 opcode, bool off_is_neg) { return 0; }
static bool push_stack(struct bpf_verifier_env *env, int prev_insn_idx, int insn_idx, bool speculative) { return false; }