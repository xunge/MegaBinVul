#include <stdint.h>
#include <stddef.h>

typedef int njs_ret_t;
typedef unsigned char u_char;

typedef struct njs_value_s njs_value_t;
typedef struct njs_array_s njs_array_t;
typedef struct njs_slice_prop_s njs_slice_prop_t;
typedef struct njs_string_prop_s njs_string_prop_t;
typedef struct njs_object_value_s njs_object_value_t;
typedef struct njs_vm_s njs_vm_t;

struct njs_value_s {
    int type;
    union {
        struct {
            njs_object_value_t *object_value;
        } u;
    } data;
};

struct njs_array_s {
    njs_value_t *start;
};

struct njs_slice_prop_s {
    int64_t start;
    int64_t length;
    int64_t string_length;
};

struct njs_string_prop_s {
    const u_char *start;
    size_t size;
    uint32_t length;
};

struct njs_object_value_s {
    njs_value_t value;
};

struct njs_vm_s {
    njs_value_t retval;
};

#define NJS_OBJECT_STRING 1
#define NXT_ERROR (-1)
#define NXT_OK (0)
#define NJS_ARRAY_SPARE 0
#define nxt_slow_path(cond) (cond)
#define nxt_fast_path(cond) (cond)

extern njs_value_t njs_value_invalid;

static njs_array_t* njs_array_alloc(njs_vm_t *vm, int64_t length, int spare);
static void njs_set_array(njs_value_t *val, njs_array_t *array);
static int njs_is_array(njs_value_t *val);
static njs_value_t* njs_array_start(njs_value_t *val);
static int njs_is_string(njs_value_t *val);
static int njs_is_object(njs_value_t *val);
static int64_t njs_string_prop(njs_string_prop_t *prop, njs_value_t *val);
static void njs_string_slice_string_prop(njs_string_prop_t *dst, njs_string_prop_t *src, njs_slice_prop_t *slice);
static u_char* njs_string_short_start(njs_value_t *val);
static void njs_string_short_set(njs_value_t *val, size_t size, int utf8);
static u_char* nxt_utf8_copy(u_char *dst, const u_char **src, const u_char *end);
static void njs_uint32_to_string(njs_value_t *val, uint32_t num);
static njs_ret_t njs_value_property(njs_vm_t *vm, njs_value_t *obj, njs_value_t *name, njs_value_t *value, int flags);