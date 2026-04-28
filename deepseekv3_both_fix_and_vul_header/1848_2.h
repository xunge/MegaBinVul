#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

typedef intptr_t njs_int_t;
typedef uintptr_t njs_uint_t;
typedef uintptr_t njs_index_t;
typedef unsigned char u_char;

struct njs_value_s {
    int type;
    union {
        int i;
        void *p;
    } data;
};

typedef struct njs_value_s njs_value_t;

struct njs_vm_s {
    void *mem_pool;
    njs_value_t retval;
};

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_object_s njs_object_t;
typedef struct njs_function_s njs_function_t;

struct njs_string_prop_s {
    const u_char *start;
    size_t size;
};

typedef struct njs_string_prop_s njs_string_prop_t;

struct njs_json_parse_ctx_s {
    njs_vm_t *vm;
    void *pool;
    int depth;
    const u_char *start;
    const u_char *end;
};

typedef struct njs_json_parse_ctx_s njs_json_parse_ctx_t;

struct njs_json_parse_s {
    njs_function_t *function;
    int depth;
};

typedef struct njs_json_parse_s njs_json_parse_t;

njs_value_t njs_string_empty;

#define NJS_OK 0
#define NJS_ERROR 1
#define NJS_JSON_MAX_DEPTH 32

#define njs_slow_path(expr) (expr)
#define njs_is_string(v) ((v)->type == 1)
#define njs_is_function(v) ((v)->type == 2)
#define njs_is_object(v) ((v)->type == 3)
#define njs_function(v) ((njs_function_t *)(v))
#define njs_value_to_string(vm, dst, src) (NJS_OK)
#define njs_lvalue_arg(lv, args, nargs, idx) ((args) + (idx))
#define njs_arg(args, nargs, idx) ((args) + (idx))
#define njs_value_arg(v) (v)

static const u_char *njs_json_skip_space(const u_char *p, const u_char *end);
static void njs_json_parse_exception(njs_json_parse_ctx_t *ctx, const char *msg, const u_char *pos);
static const u_char *njs_json_parse_value(njs_json_parse_ctx_t *ctx, njs_value_t *value, const u_char *p);
static njs_object_t *njs_json_wrap_value(njs_vm_t *vm, njs_value_t *wrapper, njs_value_t *value);
static njs_int_t njs_json_internalize_property(njs_vm_t *vm, njs_function_t *reviver, njs_value_t *wrapper, njs_value_t *name, njs_uint_t depth, njs_value_t *retval);
static njs_int_t njs_json_parse_iterator(njs_vm_t *vm, njs_json_parse_t *parse, njs_value_t *value);
static void njs_string_prop(njs_string_prop_t *string, njs_value_t *text);