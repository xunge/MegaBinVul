#include <stddef.h>

typedef struct mrb_state mrb_state;
typedef struct RProc RProc;

typedef struct {
    union {
        void *p;
        int i;
    } value;
} mrb_value;

#define mrb_get_arg1(mrb) ((mrb_value){0})
#define mrb_proc_p(v) (0)
#define mrb_raise(mrb, exc, msg) 
#define mrb_proc_ptr(v) ((RProc*)NULL)
#define mrb_proc_copy(...) 
#define E_ARGUMENT_ERROR (0)