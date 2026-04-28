#include <stdlib.h>

typedef struct _wddx_stack {
    void **elements;
    int top;
} wddx_stack;

typedef struct _st_entry {
    int type;
    void *data;
    char *varname;
} st_entry;

#define IS_UNDEF 0
#define ST_FIELD 0
#define SUCCESS 0

void efree(void *ptr);
void zval_ptr_dtor(void *ptr);