#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef struct gravity_vm gravity_vm;
typedef struct gravity_function_t gravity_function_t;
typedef struct gravity_closure_t gravity_closure_t;
typedef struct gravity_object_t gravity_object_t;
typedef struct gravity_list_t gravity_list_t;

typedef int64_t gravity_int_t;
typedef double gravity_float_t;

typedef enum {
    EXEC_TYPE_SPECIAL
} execution_type_t;

typedef enum {
    json_none = 0,
    json_null,
    json_string,
    json_integer,
    json_double,
    json_object,
    json_array,
    json_boolean
} json_type;

typedef struct json_object_entry {
    const char *name;
    struct json_value *value;
} json_object_entry;

typedef struct json_value {
    json_type type;
    union {
        struct {
            const char *ptr;
            size_t length;
        } string;
        int64_t integer;
        double dbl;
        bool boolean;
        struct {
            json_object_entry *values;
            size_t length;
        } object;
        struct {
            struct json_value **values;
            size_t length;
        } array;
    } u;
} json_value;

typedef union {
    gravity_int_t i;
    gravity_float_t f;
    bool b;
    gravity_object_t *p;
} gravity_value_t;

struct gravity_function_t {
    uint16_t tag;
    uint16_t index;
    uint16_t nparams;
    uint16_t nlocals;
    uint16_t ntemps;
    uint16_t nupvalues;
    bool useargs;
    char *identifier;
    gravity_closure_t *special[2];
    uint32_t ninsts;
    void *bytecode;
};

struct gravity_list_t {
    gravity_value_t *array;
    uint32_t size;
};

#define VALUE_FROM_INT(x) ((gravity_value_t){.i = (x)})
#define VALUE_FROM_FLOAT(x) ((gravity_value_t){.f = (x)})
#define VALUE_FROM_BOOL(x) ((gravity_value_t){.b = (x)})
#define VALUE_FROM_OBJECT(x) ((gravity_value_t){.p = (gravity_object_t*)(x)})
#define VALUE_FROM_NULL ((gravity_value_t){.p = NULL})
#define VALUE_FROM_STRING(vm, s, l) ((gravity_value_t){.p = NULL})

#define GRAVITY_JSON_LABELIDENTIFIER "identifier"
#define GRAVITY_JSON_LABELTAG "tag"
#define GRAVITY_JSON_LABELINDEX "index"
#define GRAVITY_JSON_GETTER "getter"
#define GRAVITY_JSON_SETTER "setter"
#define GRAVITY_JSON_LABELNPARAM "nparam"
#define GRAVITY_JSON_LABELNLOCAL "nlocal"
#define GRAVITY_JSON_LABELNTEMP "ntemp"
#define GRAVITY_JSON_LABELNUPV "nupv"
#define GRAVITY_JSON_LABELARGS "args"
#define GRAVITY_JSON_LABELBYTECODE "bytecode"
#define GRAVITY_JSON_LABELPOOL "pool"

#define DEBUG_DESERIALIZE(fmt, ...)

#define marray_push(type, array, value) do { \
    (array) = realloc((array), sizeof(type) * (++(*(size_t*)((char*)(array) - sizeof(size_t))))); \
    (array)[(*(size_t*)((char*)(array) - sizeof(size_t))) - 1] = (value); \
} while(0)

gravity_function_t *gravity_function_new(gravity_vm *vm, const char *identifier, uint16_t tag, uint16_t nparams, uint16_t nlocals, void *bytecode);
void gravity_function_free(gravity_vm *vm, gravity_function_t *f);
int string_casencmp(const char *s1, const char *s2, size_t n);
char *string_dup(const char *s);
void *gravity_bytecode_deserialize(const char *data, size_t len, uint32_t *ninsts);
gravity_closure_t *gravity_closure_new(gravity_vm *vm, gravity_function_t *f);
gravity_object_t *gravity_object_deserialize(gravity_vm *vm, json_value *json);
struct gravity_list_t *gravity_list_new(gravity_vm *vm, uint32_t size);
void gravity_function_cpool_add(gravity_vm *vm, gravity_function_t *f, gravity_value_t v);