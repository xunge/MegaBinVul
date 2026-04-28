#include <stdint.h>

#define MRB_API

typedef struct mrb_state mrb_state;
typedef intptr_t mrb_int;
typedef double mrb_float;
typedef uintptr_t mrb_sym;

typedef enum {
  MRB_TT_INTEGER,
  MRB_TT_FLOAT,
  MRB_TT_RATIONAL,
  MRB_TT_COMPLEX,
  MRB_TT_STRING,
  MRB_TT_FALSE,
  MRB_TT_TRUE
} mrb_vtype;

typedef struct {
  mrb_vtype tt;
  union {
    mrb_int integer;
    mrb_float f;
  } value;
} mrb_value;

#define MRB_SYM(x) ((mrb_sym)x)
#define E_TYPE_ERROR ((void*)0)
#define to_f 1

mrb_value mrb_type_convert(mrb_state *mrb, mrb_value val, mrb_vtype type, mrb_sym method);
void mrb_raise(mrb_state *mrb, void *exc, const char *msg);

#define mrb_type(val) ((val).tt)
#define mrb_integer(val) ((val).value.integer)
#define mrb_float(val) ((val).value.f)