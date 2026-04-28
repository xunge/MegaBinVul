#include <stdint.h>
#include <string.h>
#include <stddef.h>

typedef intptr_t njs_int_t;

typedef struct {
    uint32_t fast_array;
} njs_object_t;

typedef struct njs_value_s {
    uint64_t value;
} njs_value_t;

typedef struct {
    njs_value_t *start;
    njs_value_t *data;
    uint32_t size;
    uint32_t length;
    njs_object_t object;
} njs_array_t;

typedef struct {
    void *mem_pool;
} njs_vm_t;

#define NJS_OK 0
#define NJS_ERROR -1

#define njs_fast_path(expr) (expr)
#define njs_slow_path(expr) (expr)
#define njs_assert(expr) ((void)0)

void* njs_mp_align(void *pool, size_t alignment, size_t size);
void njs_mp_free(void *pool, void *p);
void njs_memory_error(njs_vm_t *vm);