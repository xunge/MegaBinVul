#include <stdint.h>
#include <stdbool.h>

typedef intptr_t mrb_int;
typedef bool mrb_bool;
typedef uintptr_t mrb_value;

enum mrb_fiber_state {
    MRB_FIBER_TRANSFERRED,
    MRB_FIBER_RUNNING,
    MRB_FIBER_RESUMED,
    MRB_FIBER_TERMINATED,
    MRB_FIBER_CREATED
};

struct RProc;
struct REnv;
struct mrb_context;
struct mrb_callinfo;

typedef struct mrb_state {
    struct mrb_context *c;
    struct mrb_context *root_c;
} mrb_state;

struct mrb_callinfo {
    mrb_int n;
    struct RProc *proc;
    mrb_value *stack;
    const uint8_t *pc;
};

struct RProc {
    struct REnv *env;
};

struct REnv {
    mrb_value *stack;
};

struct mrb_context {
    enum mrb_fiber_state status;
    struct mrb_context *prev;
    struct mrb_context *root_c;
    mrb_value *stbase;
    struct mrb_callinfo *cibase;
    struct mrb_callinfo *ci;
    mrb_bool vmexec;
};

#define E_FIBER_ERROR 0
#define TRUE true
#define FALSE false
#define MRB_PROC_ENV(p) ((struct REnv*)((p)->env))
#define MARK_CONTEXT_MODIFY(c) do {} while (0)

static struct mrb_context* fiber_check(struct mrb_state *mrb, mrb_value self);
static void fiber_check_cfunc(struct mrb_state *mrb, struct mrb_context *c);
static void fiber_switch_context(struct mrb_state *mrb, struct mrb_context *c);
static mrb_value fiber_result(struct mrb_state *mrb, const mrb_value *a, mrb_int len);
static mrb_value mrb_ary_new_from_values(struct mrb_state *mrb, mrb_int len, const mrb_value *a);
static mrb_value mrb_vm_exec(struct mrb_state *mrb, struct RProc *proc, const uint8_t *pc);
static void mrb_stack_extend(struct mrb_state *mrb, mrb_int len);
static void mrb_raise(struct mrb_state *mrb, int exc, const char *msg);