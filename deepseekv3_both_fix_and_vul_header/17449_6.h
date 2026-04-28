#include <stdint.h>
#include <math.h>
#include <stddef.h>
#include <sys/types.h>

typedef int njs_int_t;
typedef unsigned char u_char;

struct njs_vm_s;
struct njs_value_s;
struct njs_object_prop_s;
struct njs_str_s;

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_object_prop_s njs_object_prop_t;
typedef struct njs_str_s njs_str_t;

struct njs_str_s {
    size_t  length;
    u_char  *start;
};

struct njs_value_s {
    union {
        struct {
            union {
                njs_value_t *value;
                njs_int_t (*prop_handler)(njs_vm_t *, njs_object_prop_t *, 
                                         njs_value_t *, njs_value_t *, njs_value_t *);
            } u;
            uint32_t magic32;
        } data;
        double num;
    };
};

struct njs_array_s {
    uint32_t length;
};

struct njs_object_s {
    int extensible;
};

struct njs_object_prop_s {
    njs_value_t value;
    njs_value_t getter;
    njs_value_t setter;
    uint8_t type;
    uint8_t writable;
    uint8_t enumerable;
    uint8_t configurable;
};

struct njs_lvlhsh_query_s {
    njs_str_t key;
    uint32_t key_hash;
    void *value;
    uint8_t replace;
    void *pool;
};

struct njs_property_query_s {
    struct njs_lvlhsh_query_s lhq;
    njs_value_t key;
    uint8_t temp;
};

struct njs_vm_s {
    void *mem_pool;
    njs_value_t retval;
};

typedef struct njs_array_s njs_array_t;
typedef struct njs_object_s njs_object_t;
typedef struct njs_lvlhsh_query_s njs_lvlhsh_query_t;
typedef struct njs_property_query_s njs_property_query_t;

enum {
    NJS_OK,
    NJS_ERROR,
    NJS_DECLINED,
    NJS_PROPERTY_QUERY_SET,
    NJS_ATTRIBUTE_UNSET,
    NJS_ATTRIBUTE_TRUE,
    NJS_ATTRIBUTE_FALSE,
    NJS_PROPERTY,
    NJS_PROPERTY_HANDLER,
    NJS_PROPERTY_REF,
    NJS_PROPERTY_TYPED_ARRAY_REF,
    NJS_WHITEOUT,
    NJS_LENGTH_HASH
};

enum njs_object_prop_define_e {
    NJS_OBJECT_PROP_DESCRIPTOR,
    NJS_OBJECT_PROP_GETTER,
    NJS_OBJECT_PROP_SETTER
};
typedef enum njs_object_prop_define_e njs_object_prop_define_t;

extern const njs_value_t njs_value_invalid;
extern const njs_value_t njs_value_undefined;

#define njs_str(str) { sizeof(str) - 1, (u_char *) str }

static inline int njs_slow_path(int cond) { return cond; }
static inline int njs_fast_path(int cond) { return !cond; }

static njs_object_t *njs_object(njs_value_t *value) { return (njs_object_t *)value; }
static njs_value_t *njs_object_hash(njs_value_t *object) { return object; }
static njs_array_t *njs_array(njs_value_t *value) { return (njs_array_t *)value; }
static njs_array_t *njs_typed_array(njs_value_t *value) { return (njs_array_t *)value; }
static int njs_is_key(njs_value_t *value) { return 1; }
static int njs_is_string(njs_value_t *value) { return 1; }
static int njs_is_typed_array(njs_value_t *value) { return 0; }
static int njs_is_valid(njs_value_t *value) { return 1; }
static int njs_is_accessor_descriptor(njs_object_prop_t *prop) { return 0; }
static int njs_is_data_descriptor(njs_object_prop_t *prop) { return 1; }
static int njs_is_generic_descriptor(njs_object_prop_t *prop) { return 0; }
static int njs_values_same(njs_value_t *val1, njs_value_t *val2) { return 1; }
static int njs_values_strict_equal(njs_value_t *val1, njs_value_t *val2) { return 1; }
static int njs_strstr_eq(const njs_str_t *str1, const njs_str_t *str2) { return 1; }
static double njs_string_to_index(njs_value_t *value) { return 0; }
static void njs_set_invalid(njs_value_t *value) {}
static void njs_set_undefined(njs_value_t *value) {}
static void njs_property_query_init(njs_property_query_t *pq, int type, int temp) {}
static njs_int_t njs_value_to_key(njs_vm_t *vm, njs_value_t *src, njs_value_t *dst) { return NJS_OK; }
static njs_int_t njs_property_query(njs_vm_t *vm, njs_property_query_t *pq, njs_value_t *object, njs_value_t *key) { return NJS_OK; }
static njs_object_prop_t *njs_object_prop_alloc(njs_vm_t *vm, njs_value_t *name, const njs_value_t *value, int attr) { return NULL; }
static njs_int_t njs_descriptor_prop(njs_vm_t *vm, njs_object_prop_t *prop, njs_value_t *value) { return NJS_OK; }
static njs_int_t njs_key_string_get(njs_vm_t *vm, njs_value_t *key, njs_str_t *str) { return NJS_OK; }
static njs_int_t njs_type_error(njs_vm_t *vm, const char *msg, ...) { return NJS_ERROR; }
static njs_int_t njs_internal_error(njs_vm_t *vm, const char *msg, ...) { return NJS_ERROR; }
static njs_int_t njs_lvlhsh_insert(void *hash, void *lhq) { return NJS_OK; }
static njs_int_t njs_array_convert_to_slow_array(njs_vm_t *vm, njs_array_t *array) { return NJS_OK; }
static njs_int_t njs_array_length_redefine(njs_vm_t *vm, njs_value_t *object, uint32_t length) { return NJS_OK; }
static njs_int_t njs_array_length_set(njs_vm_t *vm, njs_value_t *object, njs_object_prop_t *prev, njs_value_t *value) { return NJS_OK; }
static njs_int_t njs_typed_array_set_value(njs_vm_t *vm, njs_array_t *array, uint32_t index, njs_value_t *value) { return NJS_OK; }
static const char *njs_prop_type_string(int type) { return ""; }