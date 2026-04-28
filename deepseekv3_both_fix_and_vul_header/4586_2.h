#include <stdio.h>
#include <stdlib.h>

#define PHPAPI
#define VAR_ENTRIES_MAX 64
#define VAR_ENTRIES_DBG 0

typedef struct _zval_struct {
    int type;
    int refcount__gc;
} zval;

typedef struct _var_entries {
    zval *data[VAR_ENTRIES_MAX];
    size_t used_slots;
    struct _var_entries *next;
} var_entries;

typedef struct _php_unserialize_data_t {
    var_entries *first_dtor;
    var_entries *last_dtor;
} *php_unserialize_data_t;

#define Z_TYPE_PP(ppzval) ((*ppzval)->type)
#define Z_REFCOUNT_PP(ppzval) ((*ppzval)->refcount__gc)

static void *emalloc(size_t size) {
    return malloc(size);
}