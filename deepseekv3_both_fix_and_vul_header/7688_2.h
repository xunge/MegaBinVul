#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef uint32_t ecma_value_t;

typedef struct ecma_object_t {
    // dummy structure
} ecma_object_t;

typedef struct ecma_typedarray_info_t {
    uint32_t id;
    uint32_t length;
    uint8_t* buffer_p;
    void* array_buffer_p;
    uint32_t element_size;
    uint32_t shift;
    uint32_t offset;
} ecma_typedarray_info_t;

typedef struct ecma_collection_t {
    uint32_t item_count;
    ecma_value_t* buffer_p;
} ecma_collection_t;

typedef ecma_value_t (*ecma_typedarray_getter_fn_t)(const void*);
typedef ecma_value_t (*ecma_typedarray_setter_fn_t)(void*, ecma_value_t);

#define JERRY_ASSERT(expr) ((void)0)
#define JMEM_DEFINE_LOCAL_ARRAY(name, size, type) type name[size]
#define JMEM_FINALIZE_LOCAL_ARRAY(name) ((void)0)
#define ECMA_VALUE_ERROR 0
#define ECMA_IS_VALUE_ERROR(value) ((value) == ECMA_VALUE_ERROR)
#define ECMA_ERR_MSG(msg) msg
#define ecma_error_arraybuffer_is_detached "ArrayBuffer is detached"

typedef uint8_t lit_utf8_byte_t;

static ecma_typedarray_getter_fn_t ecma_get_typedarray_getter_fn(uint32_t id);
static ecma_object_t* ecma_get_object_from_value(ecma_value_t value);
static ecma_value_t ecma_op_create_typedarray_with_type_and_length(uint32_t id, uint32_t length);
static ecma_value_t ecma_make_uint32_value(uint32_t value);
static ecma_value_t ecma_op_function_call(ecma_object_t* func_obj, ecma_value_t this_val, ecma_value_t args[], uint32_t arg_count);
static void ecma_fast_free_value(ecma_value_t value);
static bool ecma_arraybuffer_is_detached(void* array_buffer);
static void ecma_free_value(ecma_value_t value);
static ecma_value_t ecma_raise_type_error(const char* msg);
static bool ecma_op_to_boolean(ecma_value_t value);
static ecma_value_t ecma_make_number_value(uint32_t value);
static ecma_value_t ecma_typedarray_species_create(ecma_value_t this_arg, ecma_value_t* args, uint32_t arg_count);
static ecma_typedarray_info_t ecma_typedarray_get_info(ecma_object_t* obj);
static void* ecma_typedarray_get_buffer(ecma_object_t* obj);
static uint32_t ecma_typedarray_get_offset(ecma_object_t* obj);
static ecma_typedarray_setter_fn_t ecma_get_typedarray_setter_fn(uint32_t id);
static ecma_collection_t* ecma_new_collection(void);
static void ecma_collection_push_back(ecma_collection_t* collection, ecma_value_t value);
static void ecma_collection_free(ecma_collection_t* collection);
static bool ecma_is_value_number(ecma_value_t value);
static bool ecma_is_value_bigint(ecma_value_t value);