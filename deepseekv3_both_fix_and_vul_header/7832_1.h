#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;
typedef struct njs_vm_s njs_vm_t;
typedef struct njs_typed_array_s njs_typed_array_t;
typedef struct njs_value_s njs_value_t;
typedef struct njs_array_buffer_s njs_array_buffer_t;

#define NJS_OK 0
#define NJS_ERROR (-1)
#define njs_slow_path(expr) (expr)

njs_int_t njs_value_to_number(njs_vm_t *vm, njs_value_t *value, double *num);
njs_array_buffer_t* njs_typed_array_writable(njs_vm_t *vm, njs_typed_array_t *array);
void njs_typed_array_prop_set(njs_vm_t *vm, njs_typed_array_t *array, uint32_t index, double value);
void njs_set_number(njs_value_t *value, double num);