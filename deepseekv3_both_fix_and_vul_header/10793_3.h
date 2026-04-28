#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct gravity_vm gravity_vm;
typedef struct gravity_closure_t gravity_closure_t;
typedef double gravity_float_t;

typedef union {
    gravity_float_t f;
    int64_t n;
    void *p;
} gravity_value_t;

struct gravity_function_t {
    int tag;
    void *internal;
};

struct gravity_closure_t {
    struct gravity_function_t *f;
};

#define VALUE_ISA_FLOAT(v) (0)
#define VALUE_ISA_INT(v) (0)
#define VALUE_ISA_BOOL(v) (0)
#define VALUE_ISA_NULL(v) (0)
#define VALUE_ISA_UNDEFINED(v) (0)
#define VALUE_ISA_STRING(v) (0)
#define VALUE_FROM_FLOAT(f) ((gravity_value_t){f})
#define VALUE_AS_STRING(v) ((const char *)(v).p)
#define VALUE_FROM_ERROR(e) ((gravity_value_t){0})
#define GRAVITY_FLOAT_INDEX (0)
#define EXEC_TYPE_INTERNAL (0)

gravity_value_t convert_string2number(const char *s, bool isFloat);
gravity_value_t gravity_vm_result(gravity_vm *vm);
bool gravity_vm_runclosure(gravity_vm *vm, gravity_closure_t *closure, gravity_value_t v, void *arg, int arg_count);
gravity_value_t convert_object_float(gravity_vm *vm, gravity_value_t v);
void *gravity_value_getclass(gravity_value_t v);
gravity_closure_t *gravity_vm_fastlookup(gravity_vm *vm, void *cls, int index);