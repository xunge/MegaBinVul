#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define XCOFF_TYPE_COUNT 34

typedef void *debug_type;

struct stab_handle {
    debug_type *xcoff_types;
};

#define DEBUG_TYPE_NULL NULL
#define _(x) x

debug_type debug_make_int_type(void *dhandle, int size, bool unsignedp);
debug_type debug_make_void_type(void *dhandle);
debug_type debug_make_float_type(void *dhandle, int size);
debug_type debug_make_bool_type(void *dhandle, int size);
debug_type debug_make_complex_type(void *dhandle, int size);
debug_type debug_name_type(void *dhandle, const char *name, debug_type type);