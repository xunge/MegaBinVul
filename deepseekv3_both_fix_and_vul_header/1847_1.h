#include <stddef.h>
#include <stdint.h>

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_value_s {
    uint64_t data;
} njs_value_t;
typedef struct njs_function_s njs_function_t;
typedef ptrdiff_t njs_jump_off_t;
typedef uintptr_t njs_index_t;

#define njs_slow_path(cond) (cond)
#define NJS_ERROR (-1)

typedef struct njs_vmcode_function_copy_s {
    uint8_t op;
    uint8_t padding[7];
} njs_vmcode_function_copy_t;

njs_value_t* njs_scope_valid_value(njs_vm_t *vm, njs_index_t retidx);
njs_function_t* njs_function_value_copy(njs_vm_t *vm, njs_value_t *value);
int njs_is_undefined(njs_value_t *value);