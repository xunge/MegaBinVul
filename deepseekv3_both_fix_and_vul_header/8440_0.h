#include <stdlib.h>

typedef struct _wddx_stack {
    void **elements;
    int top;
} wddx_stack;

typedef struct _st_entry {
    void *data;
    int type;
    char *varname;
} st_entry;

#define ST_FIELD 0
#define SUCCESS 0

void zval_ptr_dtor(void **);
void efree(void *);