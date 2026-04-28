#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct gravity_vm gravity_vm;
typedef struct gravity_object gravity_object_t;
typedef struct gravity_value gravity_value_t;
typedef struct gravity_string gravity_string_t;
typedef struct gravity_class gravity_class_t;

#define VALUE_ISA_STRING(v) ((v).type == GRAVITY_VALUE_STRING)
#define VALUE_ISA_CLOSURE(v) ((v).type == GRAVITY_VALUE_CLOSURE)
#define VALUE_ISA_INSTANCE(v) ((v).type == GRAVITY_VALUE_INSTANCE)
#define VALUE_ISA_CLASS(v) ((v).type == GRAVITY_VALUE_CLASS)
#define VALUE_AS_OBJECT(v) ((gravity_object_t *)(v).p)
#define VALUE_AS_STRING(v) ((gravity_string_t *)(v).p)
#define GET_VALUE(i) (args[i])
#define RETURN_ERROR(msg) return false
#define RETURN_NOVALUE() return true
#define GRAVITY_VM_ANONYMOUS_PREFIX "anon."

enum {
    GRAVITY_VALUE_UNDEFINED,
    GRAVITY_VALUE_NULL,
    GRAVITY_VALUE_BOOL,
    GRAVITY_VALUE_INT,
    GRAVITY_VALUE_FLOAT,
    GRAVITY_VALUE_STRING,
    GRAVITY_VALUE_INSTANCE,
    GRAVITY_VALUE_CLASS,
    GRAVITY_VALUE_CLOSURE
};

struct gravity_value {
    uint32_t type;
    union {
        bool b;
        int64_t i;
        double f;
        void *p;
    };
};

struct gravity_string {
    char *s;
};

struct gravity_class {
    char *identifier;
    gravity_class_t *superclass;
    gravity_object_t *objclass;
};

struct gravity_object {
    gravity_class_t *objclass;
};

int string_casencmp(const char *s1, const char *s2, size_t n);
gravity_class_t *gravity_value_getclass(gravity_value_t v);
char *gravity_vm_anonymous(gravity_vm *vm);
gravity_class_t *gravity_class_new_pair(gravity_vm *vm, const char *identifier, gravity_class_t *superclass, size_t ivar_num, size_t cvar_num);
gravity_class_t *gravity_class_get_meta(gravity_class_t *c);
void gravity_gc_push(gravity_vm *vm, gravity_object_t *obj);
void gravity_class_bind(gravity_class_t *c, const char *key, gravity_value_t value);