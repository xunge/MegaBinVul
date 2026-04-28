#include <stdint.h>
#include <stddef.h>

typedef struct njs_vm_s {
    void *mem_pool;
} njs_vm_t;

typedef struct njs_value_s njs_value_t;
typedef struct njs_array_s njs_array_t;
typedef int njs_int_t;

#define NJS_OK 0
#define NJS_ERROR (-1)
#define njs_slow_path(cond) (cond)

#define NJS_ARRAY_LARGE_OBJECT_LENGTH 1024

typedef struct {
    njs_array_t *data;
    njs_value_t *value;
    int64_t to;
} njs_iterator_args_t;

extern njs_int_t njs_object_length(njs_vm_t *vm, njs_value_t *iterator, int64_t *length);
extern njs_array_t *njs_array_alloc(njs_vm_t *vm, int zero, int64_t length, int64_t size);
extern njs_int_t njs_object_iterate(njs_vm_t *vm, njs_iterator_args_t *args, void *handler);
extern void njs_mp_free(void *mem_pool, void *data);
extern void njs_memzero(void *buf, size_t n);
extern void *njs_iterator_to_array_handler;

static int64_t njs_min(int64_t a, int64_t b) {
    return a < b ? a : b;
}