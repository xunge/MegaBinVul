#include <stddef.h>

struct bpf_insn {
    unsigned char code;
    signed char off;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
    int len;
};

#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_JMP 0x05
#define BPF_OP(code) ((code) >> 4)
#define BPF_CALL 0x80
#define BPF_EXIT 0x90