#include <stdint.h>
#include <math.h>
#include <string.h>

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_array_s njs_array_t;
typedef struct njs_typed_array_s njs_typed_array_t;
typedef struct njs_array_buffer_s njs_array_buffer_t;
typedef struct njs_object_s njs_object_t;
typedef struct njs_lvlhsh_s njs_lvlhsh_s;

typedef enum {
    NJS_OK,
    NJS_ERROR,
    NJS_DECLINED
} njs_int_t;

typedef enum {
    NJS_TYPED_ARRAY,
} njs_object_type_t;

typedef enum {
    NJS_BOOL_FALSE,
    NJS_BOOL_TRUE,
} njs_bool_t;

typedef uint32_t njs_uint_t;

struct njs_value_s {
    /* value definition */
};

struct njs_array_s {
    njs_value_t *start;
    uint32_t length;
};

struct njs_lvlhsh_s {
    /* hash table definition */  
};

struct njs_object_s {
    njs_lvlhsh_s hash;
    njs_lvlhsh_s shared_hash;
    njs_object_t *__proto__;
    njs_object_type_t type;
    unsigned extensible:1;
    unsigned fast_array:1;
};

struct njs_array_buffer_s {
    union {
        uint8_t u8[0];
    } u;
    size_t size;
};

struct njs_typed_array_s {
    njs_array_buffer_t *buffer;
    uint64_t offset;
    uint64_t byte_length;
    njs_object_type_t type;
    njs_object_t object;
};

struct njs_vm_s {
    struct {
        njs_object_t object;
    } prototypes[1];
    void *mem_pool;
};

#define njs_slow_path(expr) (expr)
#define njs_is_array_buffer(value) (0)
#define njs_is_typed_array(value) (0)
#define njs_is_object(value) (0)
#define njs_is_fast_array(value) (0)
#define njs_is_detached_buffer(buffer) (0)
#define njs_is_defined(value) (0)
#define njs_arg(args, nargs, index) (&args[index])
#define njs_argument(args, index) (&args[index])

static uint32_t njs_typed_array_element_size(njs_object_type_t type) { return 0; }
static njs_array_buffer_t *njs_array_buffer(njs_value_t *value) { return NULL; }
static njs_int_t njs_value_to_index(njs_vm_t *vm, njs_value_t *value, uint64_t *index) { return NJS_OK; }
static void njs_range_error(njs_vm_t *vm, const char *msg, ...) {}
static void njs_type_error(njs_vm_t *vm, const char *msg) {}
static njs_typed_array_t *njs_typed_array(njs_value_t *value) { return NULL; }
static int64_t njs_typed_array_length(njs_typed_array_t *array) { return 0; }
static njs_array_t *njs_array(njs_value_t *value) { return NULL; }
static njs_int_t njs_object_length(njs_vm_t *vm, njs_value_t *value, int64_t *length) { return NJS_OK; }
static njs_array_buffer_t *njs_array_buffer_alloc(njs_vm_t *vm, uint64_t size, njs_bool_t zeroing) { return NULL; }
static double njs_typed_array_prop(njs_typed_array_t *array, int64_t index) { return 0.0; }
static void njs_typed_array_prop_set(njs_vm_t *vm, njs_typed_array_t *array, int64_t index, double value) {}
static njs_int_t njs_value_to_number(njs_vm_t *vm, njs_value_t *value, double *num) { return NJS_OK; }
static njs_int_t njs_value_property_i64(njs_vm_t *vm, njs_value_t *value, int64_t index, njs_value_t *prop) { return NJS_OK; }
static void njs_lvlhsh_init(njs_lvlhsh_s *hash) {}
static void njs_memory_error(njs_vm_t *vm) {}
static void *njs_mp_zalloc(void *pool, size_t size) { return NULL; }