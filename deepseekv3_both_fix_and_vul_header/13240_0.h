#include <stdint.h>

typedef intptr_t njs_int_t;

typedef struct njs_vm_s njs_vm_t;
typedef struct njs_value_s njs_value_t;

#define njs_slow_path(expr) (expr)
#define NJS_ERROR (-1)

int njs_is_object(const njs_value_t *value);
njs_int_t njs_type_error(njs_vm_t *vm, const char *msg);
njs_int_t njs_error_to_string2(njs_vm_t *vm, njs_value_t *retval, const njs_value_t *error, int flag);