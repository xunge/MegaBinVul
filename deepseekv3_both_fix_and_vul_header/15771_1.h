#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

typedef int mrb_int;
typedef unsigned int mrb_bool;
typedef unsigned int mrb_sym;
typedef double mrb_float;

#define TRUE 1
#define FALSE 0

struct mrb_state;
struct mrb_data_type;
struct RArray;
struct RBasic;

typedef struct {
    mrb_int argc;
} mrb_callinfo;

typedef struct {
    mrb_callinfo *ci;
    int *stack;
} mrb_context;

typedef struct {
    mrb_context *c;
} mrb_state;

typedef struct {
    const char *const *table;
    int *values;
    uint32_t num;
    uint32_t required;
    int *rest;
} mrb_kwargs;

typedef struct {
    char *ptr;
    mrb_int len;
} mrb_string;

typedef struct {
    int *ptr;
    mrb_int len;
    void *c;
} mrb_array;

typedef struct {
    void *ptr;
} mrb_hash;

typedef int mrb_value;

#define mrb_nil_p(v) ((v) == 0)
#define mrb_nil_value() (0)
#define mrb_undef_value() (-1)
#define mrb_test(v) ((v) != 0)
#define mrb_fixnum(v) (v)
#define mrb_to_int(mrb, v) (v)
#define mrb_to_flo(mrb, v) ((mrb_float)(v))
#define mrb_to_str(mrb, v) (v)
#define mrb_hash_p(v) (0)
#define mrb_hash_dup(mrb, v) (v)
#define mrb_hash_new(mrb) (0)
#define mrb_hash_key_p(mrb, h, k) (0)
#define mrb_hash_delete_key(mrb, h, k) (0)
#define mrb_hash_empty_p(mrb, h) (1)
#define mrb_hash_keys(mrb, h) (0)
#define mrb_ary_ptr(v) ((struct RArray*)0)
#define mrb_ary_new_from_values(mrb, n, p) (0)
#define mrb_data_get_ptr(mrb, v, t) (NULL)
#define mrb_istruct_p(v) (0)
#define mrb_istruct_ptr(v) (NULL)
#define mrb_symbol_value(s) (s)
#define mrb_intern_cstr(mrb, s) (0)
#define mrb_gc_protect(mrb, v)
#define mrb_raise(mrb, exc, msg)
#define mrb_raisef(mrb, exc, fmt, ...)
#define ARY_PTR(a) ((int*)0)
#define ARY_LEN(a) (0)
#define RSTRING_PTR(s) (NULL)
#define RSTRING_LEN(s) (0)
#define RSTRING_CSTR(mrb, s) (NULL)
#define RARRAY(v) ((mrb_array*)0)
#define RARRAY_PTR(v) ((int*)0)

#define MRB_API
#define E_ARGUMENT_ERROR 0
#define E_TYPE_ERROR 0
#define MRB_WITHOUT_FLOAT

static mrb_value to_ary(mrb_state *mrb, mrb_value v) { return v; }
static mrb_value to_hash(mrb_state *mrb, mrb_value v) { return v; }
static mrb_sym to_sym(mrb_state *mrb, mrb_value v) { return 0; }
static int class_ptr_p(mrb_value v) { return 0; }
static void mrb_hash_check_kdict(mrb_state *mrb, mrb_value v) {}