#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

typedef struct njs_value_s {
    int type;
    union {
        int32_t integer;
        double number;
        void *pointer;
    } data;
} njs_value_t;

typedef struct njs_vm_s {
    njs_value_t retval;
} njs_vm_t;

typedef struct njs_array_s {
    struct {
        int fast_array;
    } object;
    njs_value_t *start;
    uint32_t length;
} njs_array_t;

typedef struct njs_vmcode_array_s {
    uint32_t length;
    int ctor;
} njs_vmcode_array_t;

typedef intptr_t njs_jump_off_t;

#define njs_fast_path(expr) (expr)
#define NJS_ERROR (-1)
#define NJS_ARRAY_SPARE 0

static njs_array_t* njs_array_alloc(njs_vm_t *vm, int a, int b, int c);
void njs_set_invalid(njs_value_t *value);
void njs_set_array(njs_value_t *value, njs_array_t *array);