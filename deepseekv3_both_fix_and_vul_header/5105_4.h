#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef int16_t s16;
typedef int32_t s32;

enum bpf_reg_type {
    NOT_INIT,
    /* other register types would be defined here */
};

struct bpf_subprog_info {
    u32 stack_depth;
};

struct bpf_verifier_env {
    struct {
        struct bpf_insn *insnsi;
        int len;
        struct bpf_subprog_info *subprog_info;
        int subprog_cnt;
        struct {
            u32 stack_depth;
        } *aux;
    } *prog;
    void *prev_linfo;
    struct bpf_verifier_state *cur_state;
    int insn_idx;
    int prev_insn_idx;
    struct {
        int level;
    } log;
    bool allow_ptr_leaks;
    struct {
        bool seen;
        enum bpf_reg_type ptr_type;
    } *insn_aux_data;
    struct bpf_subprog_info *subprog_info;
    int subprog_cnt;
};

struct bpf_verifier_state {
    int curframe;
    bool speculative;
    struct bpf_func_state *frame[1];
};

struct bpf_func_state {
    /* minimal definition for compilation */
};

struct bpf_reg_state {
    enum bpf_reg_type type;
};

struct bpf_insn {
    u8 code;
    u8 src_reg;
    u8 dst_reg;
    s16 off;
    s32 imm;
};

struct bpf_insn_cbs {
    void (*cb_print)(struct bpf_verifier_env *, const char *, ...);
    void *private_data;
};

#define GFP_KERNEL 0
#define ENOMEM (-12)
#define EFAULT (-14)
#define E2BIG (-7)
#define EAGAIN (-11)
#define EINVAL (-22)
#define EACCES (-13)
#define ENOENT (-2)

#define BPF_MAIN_FUNC 0
#define BPF_COMPLEXITY_LIMIT_INSNS 1000000
#define BPF_REG_0 0
#define BPF_PSEUDO_CALL 1
#define SRC_OP 1
#define DST_OP_NO_MARK 2
#define BPF_READ 0
#define BPF_WRITE 1
#define BPF_XADD 0
#define BPF_ALU 0x04
#define BPF_ALU64 0x07
#define BPF_LDX 0x01
#define BPF_STX 0x03
#define BPF_ST 0x02
#define BPF_JMP 0x05
#define BPF_CALL 0x80
#define BPF_JA 0x00
#define BPF_EXIT 0x90
#define BPF_LD 0x00
#define BPF_ABS 0x20
#define BPF_IND 0x40
#define BPF_IMM 0x00
#define BPF_K 0x00
#define BPF_MEM 0x60

#define BPF_CLASS(code) ((code) & 0x07)
#define BPF_OP(code) ((code) & 0xf0)
#define BPF_MODE(code) ((code) & 0x07)
#define BPF_SIZE(code) ((code) & 0x18)
#define BPF_SRC(code) ((code) & 0x08)

static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}

static inline void verbose(struct bpf_verifier_env *env, const char *fmt, ...) {}
static inline void print_verifier_state(struct bpf_verifier_env *env, struct bpf_func_state *frame) {}
static inline void verbose_linfo(struct bpf_verifier_env *env, int idx, const char *str) {}
static inline void print_bpf_insn(const struct bpf_insn_cbs *cbs, struct bpf_insn *insn, bool allow) {}
static inline void cond_resched(void) {}
static inline bool signal_pending(void *current) { return false; }
static inline bool need_resched(void) { return false; }

static inline int init_func_state(struct bpf_verifier_env *env, struct bpf_func_state *frame,
                                int callsite, int frameno, int subprogno) { return 0; }
static inline int is_state_visited(struct bpf_verifier_env *env, int idx) { return 0; }
static inline bool bpf_prog_is_dev_bound(void *aux) { return false; }
static inline int bpf_prog_offload_verify_insn(struct bpf_verifier_env *env, int idx, int prev_idx) { return 0; }
static inline struct bpf_reg_state *cur_regs(struct bpf_verifier_env *env) { return NULL; }
static inline int check_alu_op(struct bpf_verifier_env *env, struct bpf_insn *insn) { return 0; }
static inline int check_reg_arg(struct bpf_verifier_env *env, int reg, int op) { return 0; }
static inline int check_mem_access(struct bpf_verifier_env *env, int idx, int reg, int off, int size, int op, int dst_reg, bool b) { return 0; }
static inline bool reg_type_mismatch(enum bpf_reg_type a, enum bpf_reg_type b) { return false; }
static inline int check_xadd(struct bpf_verifier_env *env, int idx, struct bpf_insn *insn) { return 0; }
static inline bool is_ctx_reg(struct bpf_verifier_env *env, int reg) { return false; }
static inline int check_func_call(struct bpf_verifier_env *env, struct bpf_insn *insn, int *idx) { return 0; }
static inline int check_helper_call(struct bpf_verifier_env *env, int imm, int idx) { return 0; }
static inline int prepare_func_exit(struct bpf_verifier_env *env, int *idx) { return 0; }
static inline int check_reference_leak(struct bpf_verifier_env *env) { return 0; }
static inline bool is_pointer_value(struct bpf_verifier_env *env, int reg) { return false; }
static inline int check_return_code(struct bpf_verifier_env *env) { return 0; }
static inline int pop_stack(struct bpf_verifier_env *env, int *prev_idx, int *idx) { return 0; }
static inline int check_cond_jmp_op(struct bpf_verifier_env *env, struct bpf_insn *insn, int *idx) { return 0; }
static inline int check_ld_abs(struct bpf_verifier_env *env, struct bpf_insn *insn) { return 0; }
static inline int check_ld_imm(struct bpf_verifier_env *env, struct bpf_insn *insn) { return 0; }

static const char *reg_type_str[] = { "NOT_INIT" };
static inline struct bpf_reg_state *reg_state(struct bpf_verifier_env *env, int reg) { return NULL; }

static void *current = NULL;