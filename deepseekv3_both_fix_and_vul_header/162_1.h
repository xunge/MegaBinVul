#include <stdint.h>
#include <string.h>

typedef int njs_ret_t;

#define nxt_fast_path(expr) (expr)
#define nxt_slow_path(expr) (expr)
#define NXT_OK 0
#define NXT_ERROR (-1)
#define NJS_ARRAY_MAX_LENGTH UINT32_MAX

typedef struct njs_value_s {
    // dummy definition to make sizeof work
    char data[8];
} njs_value_t;

typedef struct nxt_mp_s nxt_mp_t;

typedef struct njs_vm_s {
    nxt_mp_t *mem_pool;
} njs_vm_t;

typedef struct njs_array_s {
    uint32_t    size;
    uint32_t    length;
    njs_value_t *data;
    njs_value_t *start;
} njs_array_t;

void* nxt_mp_align(nxt_mp_t *mp, size_t alignment, size_t size);
void nxt_mp_free(nxt_mp_t *mp, void *p);
void njs_memory_error(njs_vm_t *vm);