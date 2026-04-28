#include <stdint.h>
#include <stddef.h>

typedef struct _mp_bound_slice_t {
    intptr_t start;
    intptr_t stop;
    intptr_t step;
} mp_bound_slice_t;

typedef intptr_t mp_obj_t;
typedef intptr_t mp_int_t;

#define STATIC static
#define MP_OBJ_NEW_SMALL_INT(x) ((mp_obj_t)(x))

mp_int_t mp_obj_int_get_checked(mp_obj_t obj);
void mp_obj_slice_indices(mp_obj_t slice, mp_int_t length, mp_bound_slice_t *result);
mp_obj_t mp_obj_new_tuple(size_t n, const mp_obj_t *items);