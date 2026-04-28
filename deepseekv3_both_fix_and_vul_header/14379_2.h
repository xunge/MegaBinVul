#include <stdint.h>

typedef intptr_t mrb_int;
typedef struct mrb_state mrb_state;

struct RBasic {
  uint32_t flags;
};

typedef union mrb_value {
  uint64_t w;
  struct RBasic *value;
} mrb_value;

struct RArray {
  struct RBasic c;
  union {
    struct {
      mrb_value *ptr;
      mrb_int len;
      mrb_int aux;
    } heap;
    struct RArray *shared;
  } as;
  mrb_int len;
};

#define ARY_LEN(a) ((a)->len)
#define ARY_PTR(a) ((a)->as.heap.ptr)
#define ARY_SET_LEN(a, l) ((a)->len = (l))
#define ARY_SHARED_P(a) ((a)->as.heap.aux & 0x100)
#define ARY_SHIFT_SHARED_MIN 16
#define E_ARGUMENT_ERROR ((void*)1)

struct RArray* mrb_ary_ptr(mrb_value self);
mrb_value mrb_ary_shift(mrb_state *mrb, mrb_value self);
int mrb_get_args(mrb_state *mrb, const char *format, ...);
void ary_modify_check(mrb_state *mrb, struct RArray *a);
mrb_value mrb_ary_new(mrb_state *mrb);
void mrb_raise(mrb_state *mrb, void *exc, const char *msg);
mrb_value mrb_ary_new_from_values(mrb_state *mrb, mrb_int n, mrb_value *vals);
void ary_make_shared(mrb_state *mrb, struct RArray *a);