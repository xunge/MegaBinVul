#include <stdio.h>

typedef enum {
    OT_LAST_PRIMITIVE
} obj_ty_t;

typedef struct obj_t {
    obj_ty_t obj_ty;
} obj_t;

typedef struct obj_composite_t {
    obj_ty_t obj_ty;
    struct obj_composite_t* reverse_nesting_order;
} obj_composite_t;

void dump_primitive_obj(FILE* f, obj_t* obj);
void dump_composite_obj(FILE* f, obj_composite_t* cobj);