#include <stdlib.h>

typedef struct _zval_struct zval;
typedef struct _st_entry st_entry;
typedef struct _wddx_stack wddx_stack;

#define SUCCESS 0
#define ST_FIELD 0

void zval_ptr_dtor(zval **zval_ptr);
void efree(void *ptr);

struct _st_entry {
    zval *data;
    char *varname;
    int type;
};

struct _wddx_stack {
    void **elements;
    int top;
};