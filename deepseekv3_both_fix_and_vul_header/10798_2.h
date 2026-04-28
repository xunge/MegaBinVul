#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_ALLOCATION 1024

typedef struct gravity_vm gravity_vm;
typedef struct gravity_value_t gravity_value_t;
typedef int64_t gravity_int_t;

struct gravity_string_t {
    char *s;
    uint32_t len;
};

typedef struct gravity_string_t gravity_string_t;

#define VALUE_ISA_INT(val) (false)
#define VALUE_AS_INT(val) (0)
#define VALUE_AS_STRING(val) ((gravity_string_t *)(NULL))
#define VALUE_FROM_OBJECT(obj) (gravity_value_t{})
#define GET_VALUE(index) (gravity_value_t{})

#define RETURN_ERROR(msg, ...)
#define RETURN_VALUE(val, rindex)

static void *mem_alloc(size_t size) { return NULL; }
struct gravity_string_t *gravity_string_new(gravity_vm *vm, char *s, uint32_t len, uint32_t alloc) { return NULL; }