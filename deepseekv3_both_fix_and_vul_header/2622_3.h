#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>

typedef intptr_t mrb_int;
typedef uintptr_t mrb_sym;
typedef uint8_t mrb_bool;
typedef double mrb_float;

#define FALSE 0
#define TRUE 1

struct mrb_state;
struct mrb_data_type;
struct RArray;
struct RBasic;

typedef struct RBasic {
    uint32_t tt;
} RBasic;

typedef struct RArray {
    RBasic basic;
    mrb_int len;
    struct mrb_value *ptr;
    void *c;
} RArray;

typedef struct mrb_value {
    uint64_t value;
} mrb_value;

typedef struct mrb_state {
    struct {
        struct {
            int argc;
        } *ci;
        mrb_value *stack;
    } *c;
} mrb_state;

#define MRB_API
#define E_ARGUMENT_ERROR 1
#define E_TYPE_ERROR 2
#define E_RANGE_ERROR 3
#define MRB_TT_FIXNUM 1
#define MRB_TT_FLOAT 2
#define MRB_TT_STRING 3
#define MRB_TT_ISTRUCT 4
#define FIXABLE_FLOAT(f) (1)
#define RSTRING_PTR(s) ((char*)0)
#define RSTRING_LEN(s) (0)
#define RARRAY(s) ((struct RArray*)0)
#define RARRAY_PTR(s) ((mrb_value*)0)

struct RArray* mrb_ary_ptr(mrb_value v);
mrb_value mrb_ary_new_from_values(struct mrb_state *mrb, mrb_int len, mrb_value *vals);
mrb_value to_str(struct mrb_state *mrb, mrb_value val);
mrb_value to_ary(struct mrb_state *mrb, mrb_value val);
mrb_value to_hash(struct mrb_state *mrb, mrb_value val);
mrb_value mrb_str_new(struct mrb_state *mrb, const char *p, size_t len);
const char *mrb_string_value_cstr(struct mrb_state *mrb, mrb_value *val);
void *mrb_istruct_ptr(mrb_value val);
void *mrb_data_get_ptr(struct mrb_state *mrb, mrb_value val, const struct mrb_data_type *type);
mrb_sym to_sym(struct mrb_state *mrb, mrb_value val);
mrb_value mrb_Integer(struct mrb_state *mrb, mrb_value val);
mrb_int mrb_fixnum(mrb_value val);
mrb_float mrb_float_value(mrb_value val);
mrb_float mrb_to_flo(struct mrb_state *mrb, mrb_value val);
mrb_bool mrb_test(mrb_value val);
mrb_bool class_ptr_p(mrb_value val);
mrb_bool mrb_nil_p(mrb_value val);
void mrb_raise(struct mrb_state *mrb, int exc, const char *msg);
void mrb_raisef(struct mrb_state *mrb, int exc, const char *fmt, mrb_value arg);
mrb_int mrb_type(mrb_value val);

#define mrb_float(v) mrb_float_value(v)