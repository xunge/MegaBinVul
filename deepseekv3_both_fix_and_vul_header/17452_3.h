#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef unsigned char u_char;

typedef struct njs_value_s {
    int type;
    union {
        int retval;
        struct {
            u_char *start;
            size_t size;
            size_t length;
        } string;
    } data;
} njs_value_t;

typedef struct njs_vm_s {
    njs_value_t retval;
} njs_vm_t;

typedef struct njs_function_s njs_function_t;

typedef struct njs_string_prop_s {
    u_char *start;
    size_t size;
    size_t length;
} njs_string_prop_t;

typedef enum {
    NJS_OK,
    NJS_ERROR
} njs_int_t;

typedef uint32_t njs_uint_t;
typedef uint32_t njs_index_t;

#define njs_slow_path(expr) (expr)
#define njs_is_null_or_undefined(value) 0
#define njs_is_defined(value) 0
#define njs_is_function(value) 0
#define njs_is_byte_or_ascii_string(prop) 0
#define njs_is_byte_string(prop) 0

#define njs_wellknown_symbol(symbol) (njs_value_t){0}
#define njs_argument(args, index) (&args[index])
#define njs_lvalue_arg(lvalue, args, nargs, index) (lvalue)
#define njs_value_arg(value) (value)
#define njs_function(value) ((njs_function_t*)value)
#define njs_set_number(value, num) do {} while (0)
#define njs_value_undefined (njs_value_t){0}

static void njs_type_error(njs_vm_t *vm, const char *msg, const char *type);
static const char *njs_type_string(int type);
static njs_int_t njs_value_method(njs_vm_t *vm, njs_value_t *value,
    const njs_value_t *key, njs_value_t *retval);
static njs_int_t njs_function_call(njs_vm_t *vm, njs_function_t *function,
    njs_value_t *this, njs_value_t *args, njs_uint_t nargs, njs_value_t *retval);
static njs_int_t njs_value_to_string(njs_vm_t *vm, njs_value_t *value,
    njs_value_t *dst);
static size_t njs_string_prop(njs_string_prop_t *prop, njs_value_t *value);
static int64_t njs_string_index_of(njs_string_prop_t *string,
    njs_string_prop_t *search, int64_t from_pos);
static njs_int_t njs_string_get_substitution(njs_vm_t *vm, njs_value_t *matched,
    njs_value_t *string, int64_t pos, njs_value_t *captures,
    njs_uint_t ncaptures, njs_value_t *groups, njs_value_t *replace,
    njs_value_t *retval);
static u_char *njs_string_offset(const u_char *start, const u_char *end,
    int64_t offset);
static u_char *njs_string_alloc(njs_vm_t *vm, njs_value_t *value, size_t size,
    size_t length);
static u_char *njs_cpymem(u_char *dst, const u_char *src, size_t len);