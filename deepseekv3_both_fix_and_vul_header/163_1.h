#include <stdint.h>

typedef intptr_t njs_ret_t;
typedef uint32_t nxt_uint_t;
typedef uint32_t njs_index_t;

typedef struct {
    union {
        struct njs_array_t *array;
    } u;
} njs_value_data_t;

typedef struct {
    njs_value_data_t data;
} njs_value_t;

typedef struct njs_array_t {
    nxt_uint_t length;
    njs_value_t *start;
    njs_value_t *data;
} njs_array_t;

typedef struct njs_vm_t {
    njs_value_t retval;
} njs_vm_t;

#define NXT_OK 0
#define nxt_slow_path(cond) (cond)
#define njs_is_array(v) (1)
#define njs_value_number_set(v, n) (void)0
njs_ret_t njs_array_expand(njs_vm_t *vm, njs_array_t *array, nxt_uint_t n, int zero);