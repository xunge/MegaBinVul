#include <stdio.h>

typedef struct _zval_struct {
    int type;
} zval;

typedef struct _var_entries {
    long used_slots;
    zval **data;
    struct _var_entries *next;
} var_entries;

typedef struct _php_unserialize_data_t {
    var_entries *first;
} *php_unserialize_data_t;

#define PHPAPI
#define VAR_ENTRIES_DBG 0
#define Z_TYPE_PP(ppzval) ((*ppzval)->type)