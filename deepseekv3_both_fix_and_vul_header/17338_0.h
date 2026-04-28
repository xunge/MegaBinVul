#include <stddef.h>
#include <stdint.h>

typedef struct mrb_state mrb_state;
typedef uintptr_t mrb_value;

#define MRB_API
#define E_TYPE_ERROR 0
#define MRB_TT_SCLASS 0
#define MRB_FLAG_IS_FROZEN 0

struct RBasic;
struct RClass;
struct RObject {
    struct RClass *c;
    uint32_t flags;
};

int mrb_immediate_p(mrb_value val);
int mrb_type(mrb_value val);
struct RClass* mrb_obj_class(mrb_state *mrb, mrb_value obj);
void* mrb_obj_alloc(mrb_state *mrb, int type, struct RClass *klass);
struct RClass* mrb_singleton_class_clone(mrb_state *mrb, mrb_value obj);
void mrb_field_write_barrier(mrb_state *mrb, struct RBasic *a, struct RBasic *b);
mrb_value mrb_obj_value(void *p);
void init_copy(mrb_state *mrb, mrb_value clone, mrb_value obj);
struct RObject* mrb_obj_ptr(mrb_value obj);
void mrb_raise(mrb_state *mrb, int exc, const char *msg);
void mrb_raisef(mrb_state *mrb, int exc, const char *fmt, mrb_value obj);