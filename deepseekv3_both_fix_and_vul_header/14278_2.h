#include <stddef.h>

typedef struct mrb_state mrb_state;
typedef struct mrb_irep mrb_irep;

struct RProc {
    unsigned int flags;
    union {
        void *irep;
        void (*func)(mrb_state*, void*);
    } body;
    struct RProc *upper;
    struct {
        void *env;
        void *target_class;
    } e;
};

#define MRB_PROC_CFUNC_P(p) ((p)->flags & 0x01)

void mrb_irep_incref(mrb_state *mrb, mrb_irep *irep);