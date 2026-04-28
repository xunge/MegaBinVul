#include <stdint.h>

typedef intptr_t mrb_int;
typedef uint8_t mrb_bool;

typedef union {
  void *p;
  mrb_int i;
  double f;
} mrb_value;

enum mrb_fiber_state {
  MRB_FIBER_CREATED,
  MRB_FIBER_RUNNING,
  MRB_FIBER_RESUMED,
  MRB_FIBER_TRANSFERRED,
  MRB_FIBER_TERMINATED
};

struct REnv {
  mrb_value *stack;
};

struct RProc {
  struct REnv *env;
};

struct mrb_callinfo {
  struct RProc *proc;
  const uint8_t *pc;
  int argc;
};

struct mrb_context {
  enum mrb_fiber_state status;
  struct mrb_context *prev;
  mrb_value *stack;
  mrb_value *stend;
  struct mrb_callinfo *ci;
  struct mrb_callinfo *cibase;
  mrb_bool vmexec;
};

typedef struct mrb_state {
  struct mrb_context *c;
  struct mrb_context *root_c;
} mrb_state;

#define MRB_PROC_ENV(p) ((struct REnv*)((p)->env))
#define MARK_CONTEXT_MODIFY(c) do { } while (0)
#define TRUE 1

extern struct mrb_context *fiber_check(mrb_state *mrb, mrb_value self);
extern void mrb_raise(mrb_state *mrb, void *exc, const char *msg);
extern void mrb_stack_extend(mrb_state *mrb, int len);
extern void fiber_check_cfunc(mrb_state *mrb, struct mrb_context *c);
extern void fiber_switch_context(mrb_state *mrb, struct mrb_context *c);
extern mrb_value fiber_result(mrb_state *mrb, const mrb_value *a, mrb_int len);
extern mrb_value mrb_vm_exec(mrb_state *mrb, struct RProc *proc, const uint8_t *pc);

extern void *E_FIBER_ERROR;