#include <stdint.h>

typedef struct mrb_state mrb_state;
typedef uint32_t mrb_sym;

struct RBasic {
  struct RClass *c;
  uint32_t tt;
  uint32_t flags;
};

struct RClass {
  struct RBasic base;
  struct RClass *super;
  void *mt;
  void *iv;
  uint32_t tt;
  uint32_t flags;
  struct RClass *c;
};

struct RObject {
  struct RBasic base;
};

struct mrb_state {
  struct RClass *class_class;
};

void* mt_new(mrb_state *mrb);
void make_metaclass(mrb_state *mrb, struct RClass *c);
void mrb_field_write_barrier(mrb_state *mrb, struct RBasic *a, struct RBasic *b);
void mrb_obj_iv_set(mrb_state *mrb, struct RObject *obj, mrb_sym sym, void *val);
void* mrb_obj_value(void *o);

enum {
  MRB_TT_SCLASS,
  MRB_TT_CLASS,
  MRB_TT_ICLASS
};

enum {
  MRB_FL_CLASS_IS_INHERITED,
  MRB_FL_OBJ_IS_FROZEN
};

#define MRB_OBJ_ALLOC(mrb, tt, cls) ((struct RClass*)0)
#define MRB_SYM(__attached__) (0)