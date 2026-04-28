#include <stdint.h>

typedef intptr_t njs_jump_off_t;

typedef struct {
    uint32_t type;
} njs_value_t;

typedef struct {
    njs_value_t retval;
} njs_vm_t;

typedef struct {
    /* placeholder for 2-address VM code */
} njs_vmcode_2addr_t;

#define NJS_VALUE_TYPE_MAX 25

static const njs_value_t njs_string_object;
static const njs_value_t njs_string_undefined;
static const njs_value_t njs_string_boolean;
static const njs_value_t njs_string_number;
static const njs_value_t njs_string_symbol;
static const njs_value_t njs_string_string;
static const njs_value_t njs_string_data;
static const njs_value_t njs_string_external;
static const njs_value_t njs_string_invalid;
static const njs_value_t njs_string_function;