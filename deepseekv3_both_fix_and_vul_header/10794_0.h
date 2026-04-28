#include <stdbool.h>
#include <string.h>

typedef struct gravity_vm gravity_vm;
typedef struct gravity_value_t gravity_value_t;
typedef struct gravity_string_t gravity_string_t;
typedef struct gravity_closure_t gravity_closure_t;

#define VALUE_ISA_BOOL(v) (false)
#define VALUE_ISA_INT(v) (false)
#define VALUE_ISA_FLOAT(v) (false) 
#define VALUE_ISA_NULL(v) (false)
#define VALUE_ISA_UNDEFINED(v) (false)
#define VALUE_ISA_STRING(v) (false)

#define VALUE_FROM_BOOL(b) ((gravity_value_t){0})
#define VALUE_FROM_FALSE ((gravity_value_t){0})
#define VALUE_FROM_ERROR(e) ((gravity_value_t){0})

#define VALUE_AS_STRING(v) ((gravity_string_t *)0)

#define GRAVITY_BOOL_INDEX 0

#define EXEC_TYPE_INTERNAL 0

struct gravity_value_t {
    union {
        int n;
        double f;
    };
};

struct gravity_string_t {
    char *s;
    size_t len;
};

struct gravity_closure_t {
    struct {
        int tag;
        void *internal;
    } *f;
};

gravity_value_t gravity_value_getclass(gravity_value_t v);
gravity_value_t gravity_vm_result(gravity_vm *vm);
bool gravity_vm_runclosure(gravity_vm *vm, gravity_closure_t *closure, gravity_value_t v, void *arg, int n);
gravity_closure_t *gravity_vm_fastlookup(gravity_vm *vm, gravity_value_t cls, int index);
gravity_value_t convert_object_bool(gravity_vm *vm, gravity_value_t v);