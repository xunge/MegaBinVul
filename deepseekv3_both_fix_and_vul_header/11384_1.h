#include <stdint.h>
#include <string.h>

typedef int ecma_value_t;
typedef struct ecma_object_t ecma_object_t;
typedef uint8_t lit_utf8_byte_t;

#define ECMA_VALUE_EMPTY 0
#define ECMA_IS_VALUE_ERROR(x) 0
#define JERRY_ASSERT(x) (void)(x)
#define JMEM_DEFINE_LOCAL_ARRAY(name, size, type) type name[size]
#define JMEM_FINALIZE_LOCAL_ARRAY(name) (void)(name)
#define ECMA_TRY_CATCH(call_value, expr, ret_value) ecma_value_t call_value = expr
#define ECMA_FINALIZE(call_value) (void)(call_value)

#define ECMA_ERR_MSG(msg) msg

static int ecma_is_typedarray(ecma_value_t val) { return 0; }
static ecma_value_t ecma_raise_type_error(const char* msg) { return 0; }
static int ecma_op_is_callable(ecma_value_t val) { return 0; }
static ecma_object_t* ecma_get_object_from_value(ecma_value_t val) { return NULL; }
static uint32_t ecma_typedarray_get_length(ecma_object_t* obj) { return 0; }
static lit_utf8_byte_t* ecma_typedarray_get_buffer(ecma_object_t* obj) { return NULL; }
static uint8_t ecma_typedarray_get_element_size_shift(ecma_object_t* obj) { return 0; }
static int ecma_is_value_empty(ecma_value_t val) { return 0; }
static ecma_value_t ecma_make_uint32_value(uint32_t val) { return 0; }
static ecma_value_t ecma_op_typedarray_get_index_prop(ecma_object_t* obj, uint32_t index) { return 0; }
static int ecma_is_value_number(ecma_value_t val) { return 0; }
static ecma_value_t ecma_op_function_call(ecma_object_t* func, ecma_value_t this_val, ecma_value_t args[], int count) { return 0; }
static int ecma_op_to_boolean(ecma_value_t val) { return 0; }
static void ecma_fast_free_value(ecma_value_t val) {}
static ecma_value_t ecma_op_create_typedarray_with_type_and_length(ecma_object_t* obj, uint32_t len) { return 0; }
static uint32_t ecma_typedarray_get_offset(ecma_object_t* obj) { return 0; }