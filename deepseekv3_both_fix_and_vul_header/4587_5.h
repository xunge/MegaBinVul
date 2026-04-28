#include <stdio.h>

#define VAR_ENTRIES_MAX 64
#define VAR_ENTRIES_DBG 0
#define SUCCESS 1

typedef struct _zval {
    int type;
    void *value;
} zval;

typedef struct _var_entries {
    long used_slots;
    struct _zval **data;
    struct _var_entries *next;
} var_entries;

typedef struct {
    var_entries *first;
} *php_unserialize_data_t;