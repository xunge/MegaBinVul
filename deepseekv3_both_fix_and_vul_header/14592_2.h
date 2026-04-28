#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uintptr_t ecma_value_t;

typedef struct vm_frame_ctx_t {
    uint8_t call_operation;
    const uint8_t *byte_code_p;
    ecma_value_t *stack_top_p;
    ecma_value_t lex_env_p;
    ecma_value_t this_binding;
    ecma_value_t *registers;
} vm_frame_ctx_t;

typedef struct ecma_collection_t {
    ecma_value_t *buffer_p;
    uint32_t item_count;
} ecma_collection_t;

typedef struct ecma_environment_record_t {
    // Placeholder for environment record fields
} ecma_environment_record_t;

typedef struct ecma_object_t {
    // Placeholder for object fields
} ecma_object_t;

typedef enum {
    VM_EXEC_SUPER_CALL,
    CBC_EXT_OPCODE,
    CBC_EXT_SPREAD_SUPER_CALL,
    CBC_END
} vm_opcodes_t;

#define JERRY_ASSERT(expr)
#define ECMA_GET_INTERNAL_VALUE_POINTER(type, value) ((type *)(value))
#define ECMA_IS_VALUE_ERROR(value) (0)
#define ECMA_VALUE_ERROR ((ecma_value_t)0)
#define JERRY_UNLIKELY(expr) (expr)
#define JERRY_DEBUGGER 0
#define VM_OC_PUT_STACK (1 << 0)
#define VM_OC_PUT_BLOCK (1 << 1)
#define VM_GET_REGISTER(frame_ctx, index) ((frame_ctx)->registers[index])
#define VM_GET_REGISTERS(frame_ctx) ((frame_ctx)->registers)

#define ECMA_ERR_VALUE_FOR_CLASS_HERITAGE_IS_NOT_A_CONSTRUCTOR "Value for class heritage is not a constructor"
#define ECMA_ERR_SUPER_CONSTRUCTOR_MAY_ONLY_BE_CALLED_ONCE "Super constructor may only be called once"

extern const uint8_t *vm_error_byte_code_p;
extern const uint32_t vm_decode_table[];
extern ecma_object_t *current_new_target_p;
#define JERRY_CONTEXT(field) (field)

static bool ecma_is_constructor(ecma_value_t value);
static bool ecma_op_this_binding_is_initialized(ecma_environment_record_t *env_rec_p);
static ecma_value_t ecma_raise_type_error(const char *msg);
static ecma_value_t ecma_raise_reference_error(const char *msg);
static ecma_environment_record_t *ecma_op_get_environment_record(ecma_value_t lex_env);
static ecma_object_t *ecma_get_object_from_value(ecma_value_t value);
static ecma_value_t ecma_op_function_construct(ecma_object_t *func_obj_p, ecma_object_t *new_target_p,
                                              ecma_value_t *arguments_p, uint32_t arguments_list_len);
static void ecma_free_value(ecma_value_t value);
static void ecma_fast_free_value(ecma_value_t value);
static void ecma_collection_destroy(ecma_collection_t *collection_p);
static bool ecma_is_value_object(ecma_value_t value);
static void ecma_op_bind_this_value(ecma_environment_record_t *env_rec_p, ecma_value_t this_value);
static ecma_value_t opfunc_init_class_fields(ecma_value_t class_func, ecma_value_t this_value);
static ecma_value_t vm_get_class_function(vm_frame_ctx_t *frame_ctx_p);