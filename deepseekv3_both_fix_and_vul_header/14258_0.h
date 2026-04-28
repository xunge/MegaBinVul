#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define BPF_MEMWORDS 16
#define MAX_BPF_STACK 512
#define BPF_REG_FP 10
#define MAX_BPF_REG 11
#define BPF_MAXINSNS 4096
#define GFP_KERNEL 0
#define __GFP_NOWARN 0
#define EINVAL 22
#define ENOMEM 12
#define S16_MIN (-32768)
#define S16_MAX 32767

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint16_t u16;
typedef int32_t s32;
typedef int16_t s16;

struct sock_filter {
    u16 code;
    u8 jt;
    u8 jf;
    u32 k;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
    struct {
        int stack_depth;
    } *aux;
};

struct bpf_insn {
    u8 code;
    u8 dst_reg:4;
    u8 src_reg:4;
    s16 off;
    s32 imm;
};

struct sk_buff {
    unsigned int len;
};

#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_MODE(code) ((code) & 0xe0)
#define BPF_OP(code) ((code) & 0xf0)
#define BPF_SRC(code) ((code) & 0x08)
#define BPF_RVAL(code) ((code) & 0x18)

#define BPF_ALU 0x04
#define BPF_JMP 0x05
#define BPF_LD 0x00
#define BPF_ST 0x02
#define BPF_STX 0x03
#define BPF_MISC 0x07
#define BPF_ALU64 0x07
#define BPF_MOV 0xb0
#define BPF_EXIT 0x90
#define BPF_RET 0x06
#define BPF_A 0x10
#define BPF_LDX 0x01
#define BPF_IMM 0x00

#define BPF_ADD 0x00
#define BPF_SUB 0x10
#define BPF_AND 0x50
#define BPF_OR 0x40
#define BPF_LSH 0x60
#define BPF_RSH 0x70
#define BPF_XOR 0xa0
#define BPF_MUL 0x20
#define BPF_DIV 0x30
#define BPF_MOD 0x90
#define BPF_NEG 0x80

#define BPF_JA 0x00
#define BPF_JEQ 0x10
#define BPF_JGT 0x20
#define BPF_JGE 0x30
#define BPF_JSET 0x40
#define BPF_JNE 0x50
#define BPF_JLT 0xa0
#define BPF_JLE 0xb0

#define BPF_K 0x00
#define BPF_X 0x08
#define BPF_W 0x00
#define BPF_H 0x08
#define BPF_B 0x10
#define BPF_ABS 0x20
#define BPF_IND 0x40
#define BPF_MEM 0x60
#define BPF_LEN 0x80
#define BPF_MSH 0xa0

#define BPF_TAX 0x00
#define BPF_TXA 0x80

#define BPF_REG_A 0
#define BPF_REG_X 1
#define BPF_REG_TMP 2
#define BPF_REG_CTX 3
#define BPF_REG_ARG1 4
#define BPF_REG_0 0

#define BPF_ALU32_REG(op, d, s) \
    (struct bpf_insn){BPF_ALU | BPF_X | (op), d, s, 0, 0}
#define BPF_ALU32_IMM(op, d, imm) \
    (struct bpf_insn){BPF_ALU | BPF_K | (op), d, 0, 0, imm}
#define BPF_MOV32_REG(d, s) \
    (struct bpf_insn){BPF_ALU | BPF_MOV | BPF_X, d, s, 0, 0}
#define BPF_MOV32_IMM(d, imm) \
    (struct bpf_insn){BPF_ALU | BPF_MOV | BPF_K, d, 0, 0, imm}
#define BPF_MOV64_REG(d, s) \
    (struct bpf_insn){BPF_ALU64 | BPF_MOV | BPF_X, d, s, 0, 0}
#define BPF_MOV32_RAW(code, d, s, imm) \
    (struct bpf_insn){code, d, s, 0, imm}
#define BPF_JMP_IMM(op, d, imm, off) \
    (struct bpf_insn){BPF_JMP | BPF_IMM | (op), d, 0, off, imm}
#define BPF_RAW_INSN(code, d, s, off, imm) \
    (struct bpf_insn){code, d, s, off, imm}
#define BPF_LD_ABS(size, imm) \
    (struct bpf_insn){BPF_LD | BPF_ABS | (size), 0, 0, 0, imm}
#define BPF_STX_MEM(size, d, s, off) \
    (struct bpf_insn){BPF_STX | (size), d, s, off, 0}
#define BPF_LDX_MEM(size, d, s, off) \
    (struct bpf_insn){BPF_LDX | (size), d, s, off, 0}
#define BPF_EXIT_INSN() \
    (struct bpf_insn){BPF_JMP | BPF_EXIT, 0, 0, 0, 0}

#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)

static void *kcalloc(size_t n, size_t size, int flags) {
    return calloc(n, size);
}

static void kfree(void *p) {
    free(p);
}

static void BUG_ON(int condition) {
    if (condition) abort();
}

static int convert_bpf_extensions(struct sock_filter *fp, struct bpf_insn **insn) {
    return 0;
}