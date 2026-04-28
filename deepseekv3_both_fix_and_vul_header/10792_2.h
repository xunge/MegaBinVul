#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef enum {
    EXEC_TYPE_INTERNAL
} exec_type_t;

typedef struct gravity_vm gravity_vm;
typedef struct gravity_function {
    exec_type_t tag;
    void *internal;
} gravity_function_t;

typedef struct gravity_closure {
    gravity_function_t *f;
} gravity_closure_t;

typedef union {
    double f;
    int64_t n;
    void *p;
} gravity_value_t;

typedef int64_t gravity_int_t;

#define VALUE_ISA_INT(v) (0)
#define VALUE_ISA_FLOAT(v) (0)
#define VALUE_ISA_BOOL(v) (0)
#define VALUE_ISA_NULL(v) (0)
#define VALUE_ISA_UNDEFINED(v) (0)
#define VALUE_ISA_STRING(v) (0)
#define VALUE_FROM_INT(i) ((gravity_value_t){.n = (i)})
#define VALUE_FROM_ERROR(e) ((gravity_value_t){.p = (e)})
#define VALUE_AS_STRING(v) ((const char *)(v).p)
#define GRAVITY_INT_INDEX (0)

gravity_value_t convert_string2number(const char *s, bool b);
gravity_value_t gravity_value_getclass(gravity_value_t v);
gravity_closure_t *gravity_vm_fastlookup(gravity_vm *vm, gravity_value_t v, int i);
gravity_value_t gravity_vm_result(gravity_vm *vm);
int gravity_vm_runclosure(gravity_vm *vm, gravity_closure_t *c, gravity_value_t v, void *p, int i);
gravity_closure_t *gravity_vm_getclosure(gravity_vm *vm);
void *convert_object_int;