#include <stddef.h>

typedef enum {
  MRB_TT_FALSE,
  MRB_TT_TRUE,
  MRB_TT_CPTR,
  MRB_TT_SYMBOL,
  MRB_TT_INTEGER,
  MRB_TT_FLOAT
} mrb_vtype;

typedef struct RBasic {
  struct RClass *c;
} RBasic;

typedef struct RClass RClass;

typedef struct mrb_state {
  struct RClass *nil_class;
  struct RClass *false_class;
  struct RClass *true_class;
} mrb_state;

typedef struct {
  union {
    struct RBasic *p;
    void *ptr;
  } value;
  mrb_vtype tt;
} mrb_value;

#define MRB_API
#define MRB_NO_FLOAT
#define mrb_nil_p(v) ((v).tt == MRB_TT_FALSE && (v).value.p == NULL)
#define mrb_type(v) ((v).tt)
#define mrb_basic_ptr(v) ((v).value.p)

void prepare_singleton_class(mrb_state *mrb, struct RBasic *obj);