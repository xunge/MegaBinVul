#include <stdint.h>
#include <stdbool.h>

#define BPF_REG_0 0
#define SRC_OP 1
#define BPF_JSLE 0xe0
#define BPF_X 0x08
#define BPF_K 0x00
#define BPF_JEQ 0x10
#define BPF_JNE 0x50
#define EINVAL 22
#define EACCES 13
#define EFAULT 14

typedef uint8_t u8;
typedef int16_t s16;
typedef int32_t s32;
typedef uint64_t u64;

enum bpf_reg_type {
    SCALAR_VALUE,
    // other types would be defined here
};

struct tnum {
    u64 value;
    u64 mask;
};

struct bpf_reg_state {
    enum bpf_reg_type type;
    struct tnum var_off;
    // other fields would be defined here
};

struct bpf_func_state {
    struct bpf_reg_state *regs;
    // other fields would be defined here
};

struct bpf_verifier_state {
    struct bpf_func_state **frame;
    int curframe;
    // other fields would be defined here
};

struct bpf_insn {
    u8 code;
    u8 src_reg;
    u8 dst_reg;
    s16 off;
    s32 imm;
};

struct bpf_verifier_env {
    struct bpf_verifier_state *cur_state;
    struct {
        int level;
    } log;
    // other fields would be defined here
};

#define BPF_OP(code) ((code) & 0xf0)
#define BPF_SRC(code) ((code) & 0x08)