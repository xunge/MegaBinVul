#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

typedef struct gravity_vm gravity_vm;
typedef struct gravity_class_t gravity_class_t;
typedef struct gravity_function_t gravity_function_t;
typedef struct gravity_closure_t gravity_closure_t;
typedef struct gravity_list_t gravity_list_t;
typedef struct gravity_map_t gravity_map_t;

typedef union {
    int64_t n;
    double f;
    void *p;
} gravity_value_t;

struct gravity_class_t {
    const char *identifier;
};

struct gravity_function_t {
    const char *identifier;
    uint32_t tag;
    void *internal;
};

struct gravity_closure_t {
    struct gravity_function_t *f;
};

#define VALUE_ISA_STRING(v) (false)
#define VALUE_ISA_INT(v) (false)
#define VALUE_ISA_BOOL(v) (false)
#define VALUE_ISA_NULL(v) (false)
#define VALUE_ISA_UNDEFINED(v) (false)
#define VALUE_ISA_FLOAT(v) (false)
#define VALUE_ISA_CLASS(v) (false)
#define VALUE_ISA_FUNCTION(v) (false)
#define VALUE_ISA_CLOSURE(v) (false)
#define VALUE_ISA_LIST(v) (false)
#define VALUE_ISA_MAP(v) (false)

#define VALUE_AS_CLASS(v) ((gravity_class_t *)(v).p)
#define VALUE_AS_FUNCTION(v) ((gravity_function_t *)(v).p)
#define VALUE_AS_CLOSURE(v) ((gravity_closure_t *)(v).p)
#define VALUE_AS_LIST(v) ((gravity_list_t *)(v).p)
#define VALUE_AS_MAP(v) ((gravity_map_t *)(v).p)

#define VALUE_FROM_CSTRING(vm, s) ((gravity_value_t){.p = (void *)s})
#define VALUE_FROM_ERROR(s) ((gravity_value_t){.p = NULL})

#define GRAVITY_ENABLE_INT64 1
#define GRAVITY_STRING_INDEX 0
#define EXEC_TYPE_INTERNAL 0

gravity_value_t convert_list2string(gravity_vm *vm, gravity_list_t *list);
gravity_value_t convert_map2string(gravity_vm *vm, gravity_map_t *map);
gravity_value_t convert_object_string(gravity_vm *vm, gravity_value_t v);
gravity_closure_t *gravity_vm_fastlookup(gravity_vm *vm, gravity_class_t *cls, uint32_t index);
bool gravity_vm_runclosure(gravity_vm *vm, gravity_closure_t *closure, gravity_value_t v, void *arg, uint32_t arg_count);
gravity_value_t gravity_vm_result(gravity_vm *vm);
gravity_class_t *gravity_value_getclass(gravity_value_t v);