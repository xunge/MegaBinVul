#include <stddef.h>

typedef struct mrb_state mrb_state;

typedef struct {
    int tt;
} mrb_value;

typedef struct RBasic {
    int tt;
} RBasic;

typedef struct mrb_callinfo {
    int nregs;
} mrb_callinfo;

typedef struct mrb_context {
    mrb_value *stack;
    mrb_value *stbase;
    mrb_value *stend;
    mrb_callinfo *ci;
} mrb_context;

enum {
    MRB_TT_FREE
};

static int mrb_immediate_p(mrb_value v) { return 0; }
static mrb_value mrb_nil_value(void) { mrb_value v = {0}; return v; }
static RBasic* mrb_basic_ptr(mrb_value v) { return (RBasic*)&v; }
static void mrb_gc_mark(mrb_state *mrb, RBasic *b) {}