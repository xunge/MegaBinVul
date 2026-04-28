#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <stdbool.h>

#define BPF_OP(code) ((code) & 0xf0)
#define BPF_SRC(code) ((code) & 0x08)
#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_REG_0 0
#define BPF_X 0x08
#define BPF_K 0x00
#define BPF_ALU 0x04
#define BPF_ALU64 0x07
#define BPF_MOV 0xb0
#define BPF_END 0xd0
#define BPF_NEG 0x80
#define BPF_ARSH 0xc0
#define BPF_MOD 0x90
#define BPF_DIV 0x30
#define BPF_LSH 0x60
#define BPF_RSH 0x70
#define BPF_ADD 0x00

#define SRC_OP 1
#define DST_OP 2

#define UNKNOWN_VALUE 0
#define CONST_IMM 1
#define FRAME_PTR 2
#define PTR_TO_STACK 3

typedef uint8_t u8;

struct bpf_insn {
    uint8_t code;
    uint8_t dst_reg;
    uint8_t src_reg;
    int16_t off;
    int32_t imm;
};

struct reg_state {
    int type;
    void *map_ptr;
    int imm;
};

struct verifier_state {
    struct reg_state *regs;
};

struct verifier_env {
    struct verifier_state cur_state;
};

static void verbose(const char *fmt, ...);
static int check_reg_arg(struct reg_state *regs, int reg, int op);
static bool is_pointer_value(struct verifier_env *env, int reg);