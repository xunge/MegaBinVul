#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define HAVE_DLERROR 1
#define FUNC_STDCALL 1

struct dl_handle {
    int open;
    void *ptr;
};

#define VALUE int
#define rb_secure(x)
#define StringValuePtr(x) (x)
#define Data_Get_Struct(a,b,c) (c = (struct dl_handle*)a)
#define rb_raise(a,b,...)
#define rb_eDLError 0
#define PTR2NUM(x) (int)(x)
#define xmalloc malloc
#define xrealloc realloc
#define xfree free