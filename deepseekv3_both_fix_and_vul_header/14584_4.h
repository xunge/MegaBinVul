#include <stdbool.h>
#include <stddef.h>

typedef unsigned int ecma_value_t;
typedef struct ecma_object_t ecma_object_t;

#define JERRY_ATTR_ALWAYS_INLINE
#define JERRY_ASSERT(expr)
#define ECMA_GET_POINTER(type, value) (value)
#define ECMA_SET_POINTER(field, value) ((field) = (value))
#define ECMA_VALUE_TRUE ((ecma_value_t)0)
#define ECMA_VALUE_FALSE ((ecma_value_t)1)
#define JERRY_BUILTIN_PROXY 0

extern bool ecma_is_lexical_environment(ecma_object_t *obj_p);
extern bool ECMA_OBJECT_IS_PROXY(ecma_object_t *obj_p);
extern bool ecma_is_value_object(ecma_value_t value);
extern bool ecma_is_value_null(ecma_value_t value);
extern ecma_object_t* ecma_op_ordinary_object_get_prototype_of(ecma_object_t *obj_p);
extern ecma_object_t* ecma_get_object_from_value(ecma_value_t value);
extern bool ecma_op_ordinary_object_is_extensible(ecma_object_t *obj_p);
extern bool ecma_op_object_is_fast_array(ecma_object_t *obj_p);
extern void ecma_fast_array_convert_to_normal(ecma_object_t *obj_p);

struct ecma_object_t {
    union {
        struct {
            ecma_object_t *prototype_cp;
        } u2;
    };
};