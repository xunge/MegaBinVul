#include <stddef.h>

typedef struct mrb_state mrb_state;
typedef struct mrb_value mrb_value;
typedef struct RProc RProc;
typedef struct mrb_context mrb_context;
typedef struct mrb_callinfo mrb_callinfo;

struct RProc {
    int flags;
    void *env;
};

struct mrb_value {
    int dummy;
};

struct mrb_callinfo {
    struct {
        void *env;
    } u;
};

struct mrb_context {
    mrb_callinfo *ci;
    mrb_callinfo *cibase;
};

struct mrb_state {
    mrb_context *c;
};

#define MRB_TT_PROC 0
#define MRB_PROC_STRICT_P(p) 0
#define MRB_PROC_ORPHAN 0
#define MRB_PROC_ENV(p) ((p)->env)
#define MRB_SYM(name) 0
#define MRB_OBJ_ALLOC(mrb, type, klass) NULL
#define mrb_class_ptr(val) NULL
#define mrb_proc_ptr(val) NULL
#define mrb_obj_value(p) (mrb_value){0}
#define mrb_get_args(mrb, fmt, ...) 0
#define mrb_proc_copy(...) ((void)0)
#define mrb_funcall_with_block(mrb, recv, mid, argc, argv, block) (mrb_value){0}