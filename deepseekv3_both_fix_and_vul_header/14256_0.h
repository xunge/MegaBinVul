#include <stdbool.h>
#include <stdint.h>

struct bpf_insn {
    uint8_t code;
    uint8_t src_reg;
    int32_t off;
    int32_t imm;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
    uint32_t len;
};

#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_OP(code) ((code) & 0xf0)
#define BPF_JMP 0x05
#define BPF_EXIT 0x90
#define BPF_CALL 0x80
#define BPF_PSEUDO_CALL 0x01

typedef uint32_t u32;
typedef uint8_t u8;