#include <dlfcn.h>

#define RTLD_NEXT ((void *) -1l)

typedef unsigned long VALUE;
const char *StringValueCStr(VALUE str);
static VALUE fiddle_handle_sym(void *handle, const char *sym);