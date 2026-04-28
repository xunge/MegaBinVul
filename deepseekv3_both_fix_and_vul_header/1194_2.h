#include <stdint.h>
#include <stdlib.h>

typedef uint32_t mrb_sym;
typedef intptr_t mrb_int;

typedef struct mrb_state mrb_state;
typedef struct RClass RClass;
typedef struct RProc RProc;
typedef struct RArray RArray;

typedef struct mrb_value {
    union {
        void *p;
        mrb_int i;
        mrb_sym sym;
    } value;
    uint32_t tt;
} mrb_value;

typedef struct mrb_callinfo {
    mrb_sym mid;
    int n;
    int cci;
    int nk;
    mrb_value *stack;
    union {
        RClass *target_class;
    } u;
} mrb_callinfo;

typedef struct mrb_context {
    mrb_callinfo *ci;
    mrb_value *stack;
} mrb_context;

struct mrb_state {
    mrb_context *c;
};

typedef union {
    mrb_value (*func)(mrb_state*, mrb_value);
    RProc *proc;
} mrb_method_body;

typedef struct {
    mrb_method_body body;
    uint32_t flags;
} mrb_method_t;

enum {
    CINFO_NONE
};

#define MRB_METHOD_UNDEF_P(m) ((m).flags == 0)
#define MRB_METHOD_CFUNC_P(m) ((m).flags & 1)
#define MRB_METHOD_NOARG_P(m) ((m).flags & 2)
#define MRB_METHOD_PROC_P(m) ((m).flags & 4)
#define MRB_METHOD_CFUNC(m) ((m).body.func)
#define MRB_METHOD_PROC(m) ((m).body.proc)

struct RArray {
    mrb_value *ptr;
    mrb_int len;
};

#define RARRAY_PTR(a) ((struct RArray*)((a).value.p))->ptr
#define RARRAY_LEN(a) ((struct RArray*)((a).value.p))->len

mrb_sym mrb_obj_to_sym(mrb_state*, mrb_value);
mrb_value mrb_funcall_with_block(mrb_state*, mrb_value, mrb_sym, mrb_int, const mrb_value*, mrb_value);
void mrb_get_args(mrb_state*, const char*, ...);
RClass* mrb_class(mrb_state*, mrb_value);
mrb_method_t mrb_method_search_vm(mrb_state*, RClass**, mrb_sym);
void mrb_argnum_error(mrb_state*, int, int, int);
mrb_value mrb_ary_subseq(mrb_state*, mrb_value, mrb_int, mrb_int);
void check_method_noarg(mrb_state*, mrb_callinfo*);
void mrb_vm_ci_proc_set(mrb_callinfo*, RProc*);
mrb_value exec_irep(mrb_state*, mrb_value, RProc*);