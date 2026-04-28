#include <stdint.h>

typedef struct mrb_state mrb_state;
typedef struct mrb_irep mrb_irep;

struct RProc {
  uint32_t flags;
  union {
    mrb_irep *irep;
    void (*func)(void);
  } body;
  struct RProc *upper;
  struct REnv {
    void *env;
  } e;
};

#define MRB_PROC_CFUNC_P(p) ((p)->flags & 0x01)

void mrb_irep_incref(mrb_state *mrb, mrb_irep *irep);