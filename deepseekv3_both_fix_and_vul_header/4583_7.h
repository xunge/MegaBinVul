#include <stdio.h>
#include <stdlib.h>

typedef struct _zval_struct zval;

typedef struct _var_entries {
    struct _var_entries *next;
    long used_slots;
    zval **data;
} var_entries;

typedef struct {
    var_entries *first;
    var_entries *first_dtor;
} *php_unserialize_data_t;

#define PHPAPI
#define VAR_ENTRIES_DBG 0

void efree(void *ptr);
void zval_ptr_dtor(zval **zval_ptr);