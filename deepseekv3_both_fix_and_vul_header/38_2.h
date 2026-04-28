#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;
typedef unsigned char u_char;

typedef struct njs_vm_s njs_vm_t;

struct njs_value_s {
    int type;
    union {
        void *ptr;
        int64_t i64;
        double num;
    } data;
};
typedef struct njs_value_s njs_value_t;

struct njs_iterator_args_s {
    njs_value_t *value;
    int64_t from;
    int64_t to;
};
typedef struct njs_iterator_args_s njs_iterator_args_t;

typedef njs_int_t (*njs_iterator_handler_t)(njs_vm_t *vm, njs_iterator_args_t *args, njs_value_t *value, int64_t index);

struct njs_string_prop_s {
    const u_char *start;
    size_t size;
};
typedef struct njs_string_prop_s njs_string_prop_t;

struct njs_object_value_s {
    void *object;
    int type;
    int unused;
    njs_value_t *value;
};
typedef struct njs_object_value_s njs_object_value_t;

struct njs_array_s {
    struct {
        void *object;
        int fast_array;
    } object;
    int64_t length;
    njs_value_t *start;
};
typedef struct njs_array_s njs_array_t;

#define njs_is_array(v) 0
#define njs_is_string(v) 0
#define njs_is_object_string(v) 0
#define njs_is_object(v) 0
#define njs_slow_path(cond) (cond)
#define njs_fast_path(cond) (cond)
#define njs_fast_object(cond) (cond)

#define NJS_OK 0
#define NJS_ERROR -1
#define NJS_DONE 1
#define NJS_DECLINED 2

#define NJS_OBJ_TYPE_STRING 0

static njs_value_t njs_value_invalid = {0};
#define njs_value_arg(v) (v)
#define njs_is_valid(v) 0
#define njs_array(v) ((njs_array_t *)(v))
#define njs_object_value(v) ((njs_value_t *)(v))
#define njs_set_object_value(v, o) do { (v)->data.ptr = o; } while (0)

extern njs_int_t njs_value_property_i64(njs_vm_t *vm, njs_value_t *value, int64_t index, njs_value_t *prop);
extern njs_int_t njs_iterator_object_handler(njs_vm_t *vm, njs_iterator_handler_t handler, njs_iterator_args_t *args, njs_value_t *value, int64_t index);
extern njs_object_value_t *njs_object_value_alloc(njs_vm_t *vm, int type, int unused, njs_value_t *value);
extern njs_array_t *njs_array_indices(njs_vm_t *vm, njs_value_t *value);
extern void njs_array_destroy(njs_vm_t *vm, njs_array_t *array);
extern int64_t njs_string_prop(njs_string_prop_t *string_prop, njs_value_t *value);
extern const u_char *njs_string_offset(const u_char *start, const u_char *end, int64_t index);
extern const u_char *njs_utf8_next(const u_char *p, const u_char *end);
extern const u_char *njs_utf8_prev(const u_char *p);
extern njs_int_t njs_string_new(njs_vm_t *vm, njs_value_t *value, const u_char *start, size_t length, int unused);
extern double njs_string_to_index(njs_value_t *value);