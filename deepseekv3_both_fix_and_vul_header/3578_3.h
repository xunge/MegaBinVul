#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint32_t u32;

#define SEEN_DATAREF 1
#define SEEN_XREG    2
#define SEEN_MEM     4

struct sk_filter {
    const struct sock_filter *insns;
    int len;
    void *bpf_func;
};

struct sock_filter {
    uint16_t code;
    uint8_t jt;
    uint8_t jf;
    uint32_t k;
};

struct sk_buff {
    uint32_t len;
    uint32_t data_len;
    void *data;
    uint16_t protocol;
    void *dev;
    uint32_t mark;
    uint32_t rxhash;
    uint16_t queue_mapping;
};

struct net_device {
    uint32_t ifindex;
};

struct work_struct {
    unsigned long data;
};

#define GFP_KERNEL 0
#define CONFIG_SMP 1
static int cpu_number = 0;
#define KERN_ERR 0
#define DUMP_PREFIX_ADDRESS 0

#define EMIT1(b)        do { *prog++ = (b); } while (0)
#define EMIT2(b1, b2)       do { EMIT1(b1); EMIT1(b2); } while (0)
#define EMIT3(b1, b2, b3)   do { EMIT1(b1); EMIT1(b2); EMIT1(b3); } while (0)
#define EMIT4(b1, b2, b3, b4)   do { EMIT1(b1); EMIT1(b2); EMIT1(b3); EMIT1(b4); } while (0)

#define EMIT(b, size)   do { *prog++ = (b); } while (0)
#define EMIT1_off32(op, off) do { EMIT1(op); EMIT(off, 4); } while (0)

#define CLEAR_A() EMIT2(0x31, 0xc0)
#define CLEAR_X() EMIT2(0x31, 0xdb)

#define X86_JE 0x74
#define X86_JNE 0x75
#define X86_JBE 0x76
#define X86_JA 0x77
#define X86_JAE 0x73
#define X86_JB 0x72

#define EMIT_JMP(offset) \
    do { \
        if (is_imm8(offset)) { \
            EMIT2(0xeb, offset); \
        } else { \
            EMIT1(0xe9); \
            EMIT(offset, 4); \
        } \
    } while (0)

#define EMIT_COND_JMP(op, offset) \
    do { \
        if (is_imm8(offset)) { \
            EMIT2(op, offset); \
        } else { \
            EMIT2(0x0f, op + 0x10); \
            EMIT(offset, 4); \
        } \
    } while (0)

#define COND_SEL(op_code, op_true, op_false) \
    case op_code: \
        t_op = op_true; \
        f_op = op_false; \
        goto cond_branch;

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define FIELD_SIZEOF(type, field) sizeof(((type *)0)->field)
#define unlikely(x) (x)
#define WARN_ON(condition) (condition)
#define pr_err(fmt, ...) 
#define print_hex_dump(level, prefix_str, prefix_type, rowsize, groupsize, buf, len, ascii)

#define max_t(type, x, y) ((x) > (y) ? (x) : (y))

static int bpf_jit_enable;

static void *kmalloc(size_t size, int flags) { return malloc(size); }
static void kfree(void *ptr) { free(ptr); }
static void *module_alloc(size_t size) { return malloc(size); }
static void module_free(void *module, void *ptr) { free(ptr); }
static int is_imm8(int value) { return value >= -128 && value <= 127; }
static int is_near(int offset) { return offset >= -128 && offset <= 127; }
static void bpf_flush_icache(void *start, void *end) {}

static u8 *sk_load_word;
static u8 *sk_load_half;
static u8 *sk_load_byte;
static u8 *sk_load_byte_msh;
static u8 *sk_load_word_ind;
static u8 *sk_load_half_ind;
static u8 *sk_load_byte_ind;

enum {
    BPF_S_RET_K,
    BPF_S_LD_W_LEN,
    BPF_S_ANC_PROTOCOL,
    BPF_S_ANC_IFINDEX,
    BPF_S_ANC_MARK,
    BPF_S_ANC_RXHASH,
    BPF_S_ANC_CPU,
    BPF_S_ANC_QUEUE,
    BPF_S_LD_W_ABS,
    BPF_S_LD_H_ABS,
    BPF_S_LD_B_ABS,
    BPF_S_ALU_ADD_X,
    BPF_S_ALU_ADD_K,
    BPF_S_ALU_SUB_X,
    BPF_S_ALU_SUB_K,
    BPF_S_ALU_MUL_X,
    BPF_S_ALU_MUL_K,
    BPF_S_ALU_DIV_X,
    BPF_S_ALU_DIV_K,
    BPF_S_ALU_AND_X,
    BPF_S_ALU_AND_K,
    BPF_S_ALU_OR_X,
    BPF_S_ALU_OR_K,
    BPF_S_ALU_LSH_X,
    BPF_S_ALU_LSH_K,
    BPF_S_ALU_RSH_X,
    BPF_S_ALU_RSH_K,
    BPF_S_ALU_NEG,
    BPF_S_RET_A,
    BPF_S_MISC_TAX,
    BPF_S_MISC_TXA,
    BPF_S_LD_IMM,
    BPF_S_LDX_IMM,
    BPF_S_LD_MEM,
    BPF_S_LDX_MEM,
    BPF_S_ST,
    BPF_S_STX,
    BPF_S_LDX_W_LEN,
    BPF_S_LDX_B_MSH,
    BPF_S_LD_W_IND,
    BPF_S_LD_H_IND,
    BPF_S_LD_B_IND,
    BPF_S_JMP_JA,
    BPF_S_JMP_JGT_K,
    BPF_S_JMP_JGE_K,
    BPF_S_JMP_JEQ_K,
    BPF_S_JMP_JSET_K,
    BPF_S_JMP_JGT_X,
    BPF_S_JMP_JGE_X,
    BPF_S_JMP_JEQ_X,
    BPF_S_JMP_JSET_X
};