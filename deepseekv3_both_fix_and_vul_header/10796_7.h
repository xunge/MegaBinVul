#include <stdint.h>
#include <stddef.h>

#define MAX_ALLOCATION 0
#define MARRAY_DEFAULT_SIZE 0

typedef struct gravity_vm gravity_vm;
typedef struct gravity_object_t gravity_object_t;
typedef struct gravity_class_t gravity_class_t;
typedef struct gravity_list_t gravity_list_t;
typedef struct gravity_value_t gravity_value_t;

extern gravity_class_t *gravity_class_list;

struct gravity_class_t {
    int dummy;
};

struct gravity_value_t {
    int dummy;
};

struct gravity_list_t {
    gravity_class_t *isa;
    void *array;
};

void *mem_alloc(size_t size);
void marray_init(void *array);
void marray_resize(void *array, size_t size);
void gravity_vm_transfer(gravity_vm *vm, gravity_object_t *obj);

#define marray_resize(type, array, size) marray_resize(array, size)