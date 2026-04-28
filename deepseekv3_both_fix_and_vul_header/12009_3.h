#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;
typedef int16_t s16;
typedef int32_t s32;

#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_OP(code) ((code) >> 4)
#define BPF_MODE(code) ((code) & 0xe0)
#define BPF_SRC(code) ((code) & 0x08)

#define BPF_REG_FP 10
#define BPF_PSEUDO_CALL 1
#define BPF_PSEUDO_KFUNC_CALL 2
#define BPF_REG_SIZE 8

#define BPF_ALU 0x04
#define BPF_ALU64 0x07
#define BPF_MOV 0xb0
#define BPF_X 0x08
#define BPF_LDX 0x01
#define BPF_STX 0x03
#define BPF_ST 0x02
#define BPF_JMP 0x05
#define BPF_JMP32 0x06
#define BPF_CALL 0x80
#define BPF_EXIT 0x90
#define BPF_LD 0x00
#define BPF_IND 0x40
#define BPF_ABS 0x20

#define BPF_LOG_LEVEL2 2
#define ENOTSUPP 524
#define EFAULT 14

#define WARN_ONCE(condition, message) ((void)0)

struct bpf_insn {
    u8 code;
    u8 dst_reg:4;
    u8 src_reg:4;
    s16 off;
    s32 imm;
};

struct bpf_verifier_env;
struct bpf_prog;

struct bpf_insn_cbs {
    int (*cb_call)(void *, const struct bpf_insn *);
    void (*cb_print)(struct bpf_verifier_env *, const char *, ...);
    void *private_data;
};

struct bpf_verifier_env {
    struct bpf_prog *prog;
    struct {
        u32 level;
    } log;
    bool allow_ptr_leaks;
};

struct bpf_prog {
    struct bpf_insn *insnsi;
};

extern int disasm_kfunc_name(void *private_data, const struct bpf_insn *insn);
extern void verbose(struct bpf_verifier_env *env, const char *fmt, ...);
extern void print_bpf_insn(const struct bpf_insn_cbs *cbs, const struct bpf_insn *insn, bool allow_ptr_leaks);
extern bool is_callback_calling_function(u32 imm);