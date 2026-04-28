#include <stdint.h>
#include <stddef.h>

typedef intptr_t njs_int_t;

typedef struct njs_value_s njs_value_t;
typedef struct njs_object_prop_s njs_object_prop_t;

typedef struct {
    int fast_array;
} njs_object_t;

typedef struct {
    njs_object_t object;
    uint32_t length;
    njs_value_t *start;
    void *data;
} njs_array_t;

struct njs_value_s {
    int valid;
};

struct njs_object_prop_s {
    njs_value_t value;
};

typedef struct {
    void *mem_pool;
} njs_vm_t;

#define njs_slow_path(cond) (cond)
#define NJS_OK 0
#define NJS_ERROR -1

static int njs_is_valid(njs_value_t *val) {
    return val->valid;
}

static void njs_set_array(njs_value_t *val, njs_array_t *arr) {
    val->valid = 1;
}

static void njs_uint32_to_string(njs_value_t *val, uint32_t num) {
    val->valid = 1;
}

static njs_object_prop_t* njs_object_property_add(njs_vm_t *vm, njs_value_t *val,
                                                njs_value_t *index, int flag) {
    static njs_object_prop_t prop;
    return &prop;
}

static void njs_mp_free(void *pool, void *ptr) {
}