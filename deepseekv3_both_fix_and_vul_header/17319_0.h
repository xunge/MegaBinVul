#include <stdint.h>

typedef struct mrb_state mrb_state;
typedef uintptr_t mrb_value;
typedef intptr_t mrb_int;

enum mrb_vtype {
  MRB_TT_FALSE = 0,
  MRB_TT_FREE,
  MRB_TT_TRUE,
  MRB_TT_FIXNUM,
  MRB_TT_SYMBOL,
  MRB_TT_UNDEF,
  MRB_TT_FLOAT,
  MRB_TT_CPTR,
  MRB_TT_OBJECT,
  MRB_TT_CLASS,
  MRB_TT_MODULE,
  MRB_TT_ICLASS,
  MRB_TT_SCLASS,
  MRB_TT_PROC,
  MRB_TT_ARRAY,
  MRB_TT_HASH,
  MRB_TT_STRING,
  MRB_TT_RANGE,
  MRB_TT_EXCEPTION,
  MRB_TT_FILE,
  MRB_TT_ENV,
  MRB_TT_DATA,
  MRB_TT_FIBER,
  MRB_TT_ISTRUCT,
  MRB_TT_BREAK,
  MRB_TT_MAXDEFINE
};

mrb_int mrb_type(mrb_value obj);
void copy_class(mrb_state *mrb, mrb_value dest, mrb_value obj);
void mrb_iv_copy(mrb_state *mrb, mrb_value dest, mrb_value obj);
void mrb_iv_remove(mrb_state *mrb, mrb_value obj, mrb_int sym);
mrb_int mrb_intern_lit(mrb_state *mrb, const char *str);
void mrb_istruct_copy(mrb_value dest, mrb_value obj);
mrb_value mrb_funcall(mrb_state *mrb, mrb_value obj, const char *name, mrb_int argc, ...);