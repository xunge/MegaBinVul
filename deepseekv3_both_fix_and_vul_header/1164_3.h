#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_int_t;

#define NJS_OK 0
#define NJS_ERROR (-1)
#define njs_slow_path(expr) (expr)

typedef struct njs_vm_s {
    void *start;
} njs_vm_t;

njs_int_t njs_module_load(njs_vm_t *vm);
njs_int_t njs_vmcode_interpreter(njs_vm_t *vm, void *start, ...);