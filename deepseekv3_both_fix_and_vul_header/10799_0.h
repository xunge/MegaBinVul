#include <stdbool.h>
#include <stdint.h>

typedef struct gravity_vm gravity_vm;
typedef struct gravity_list_t gravity_list_t;
typedef struct gravity_value_t gravity_value_t;

#define VALUE_ISA_INT(x) (0)
#define VALUE_AS_INT(x) (0)
#define VALUE_FROM_NULL (gravity_value_t){0}
#define VALUE_FROM_OBJECT(x) (gravity_value_t){0}
#define GET_VALUE(x) (gravity_value_t){0}
#define RETURN_ERROR(...) return false
#define RETURN_VALUE(x, y) return true
#define MAX_ALLOCATION (0)

#define marray_push(type, array, value) (0)