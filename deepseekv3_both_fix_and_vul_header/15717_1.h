#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint8_t u8;

enum bpf_access_src {
    ACCESS_HELPER
};

enum bpf_access_type {
    BPF_READ,
    BPF_WRITE
};

#define BPF_REG_SIZE 8
#define STACK_MISC 1
#define STACK_ZERO 2
#define STACK_INVALID 3
#define STACK_DYNPTR 4
#define SCALAR_VALUE 1
#define REG_LIVE_READ64 1
#define EACCES 1
#define EFAULT 2

struct tnum {
    int value;
};

struct bpf_reg_state {
    struct tnum var_off;
    int smin_value;
    int smax_value;
    int type;
    int parent;
};

struct bpf_stack_state {
    u8 slot_type[BPF_REG_SIZE];
    struct bpf_reg_state spilled_ptr;
};

struct bpf_func_state {
    int allocated_stack;
    struct bpf_stack_state *stack;
};

struct bpf_verifier_env {
    bool bypass_spec_v1;
    bool allow_uninit_stack;
    bool allow_ptr_leaks;
};

struct bpf_call_arg_meta {
    bool raw_mode;
    int access_size;
    int regno;
};

static struct bpf_reg_state *reg_state(struct bpf_verifier_env *env, int regno);
static struct bpf_func_state *func(struct bpf_verifier_env *env, struct bpf_reg_state *reg);
static int check_stack_access_within_bounds(struct bpf_verifier_env *env, int regno, int off, int access_size, enum bpf_access_src type, enum bpf_access_type bounds_check_type);
static bool tnum_is_const(struct tnum var_off);
static void verbose(struct bpf_verifier_env *env, const char *fmt, ...);
static void tnum_strn(char *buf, size_t size, struct tnum var_off);
static int __get_spi(int off);
static bool is_spilled_reg(struct bpf_stack_state *stack);
static void __mark_reg_unknown(struct bpf_verifier_env *env, struct bpf_reg_state *reg);
static void scrub_spilled_slot(u8 *slot_type);
static void mark_reg_read(struct bpf_verifier_env *env, struct bpf_reg_state *reg, int parent, int flag);
static int update_stack_depth(struct bpf_verifier_env *env, struct bpf_func_state *state, int min_off);