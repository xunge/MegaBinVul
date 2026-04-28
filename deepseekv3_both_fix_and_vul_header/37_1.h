#include <stdint.h>
#include <stddef.h>

typedef int njs_int_t;

typedef struct njs_value_s {
    // Placeholder for njs_value_t structure
    int type;
    union {
        uint32_t u32;
        void *data;
    } u;
} njs_value_t;

typedef struct njs_object_prop_s {
    njs_value_t value;
    // Other members omitted for brevity
} njs_object_prop_t;

typedef struct njs_vm_s {
    void *mem_pool;
    // Other members omitted for brevity
} njs_vm_t;

typedef struct njs_array_s {
    uint32_t length;
    njs_value_t *start;
    struct {
        int fast_array;
    } object;
} njs_array_t;

#define njs_slow_path(expr) (expr)
#define NJS_ERROR (-1)
#define NJS_OK (0)

void njs_set_array(njs_value_t *value, njs_array_t *array);
int njs_is_valid(njs_value_t *value);
void njs_uint32_to_string(njs_value_t *value, uint32_t num);
njs_object_prop_t* njs_object_property_add(njs_vm_t *vm, njs_value_t *value, njs_value_t *index, int flag);
void njs_mp_free(void *pool, void *ptr);