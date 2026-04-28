#include <stdint.h>
#include <stdbool.h>

struct bpf_verifier_env {
    bool allow_ptr_leaks;
};

struct bpf_insn {
    uint8_t code;
    uint8_t dst_reg;
    uint8_t src_reg;
    int16_t off;
    int32_t imm;
};

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;

#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_SRC(code) ((code) & 0x08)
#define BPF_OP(code) ((code) >> 4)
#define BPF_MODE(code) ((code) & 0xe0)
#define BPF_SIZE(code) ((code) & 0x18)
#define BPF_X 0x08
#define BPF_ALU 0x04
#define BPF_ALU64 0x07
#define BPF_STX 0x05
#define BPF_ST 0x02
#define BPF_LDX 0x01
#define BPF_LD 0x00
#define BPF_JMP 0x05
#define BPF_MEM 0x60
#define BPF_XADD 0xc0
#define BPF_ABS 0x20
#define BPF_IND 0x40
#define BPF_IMM 0x00
#define BPF_DW 0x18
#define BPF_PSEUDO_MAP_FD 1
#define BPF_JA 0x00
#define BPF_EXIT 0x90
#define BPF_CALL 0x80

extern const char *bpf_alu_string[];
extern const char *bpf_ldst_string[];
extern const char *bpf_jmp_string[];
extern const char *bpf_class_string[];
extern const char *func_id_name(int id);

void verbose(const char *fmt, ...);