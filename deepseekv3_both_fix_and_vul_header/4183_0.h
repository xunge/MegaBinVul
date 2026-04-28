#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define HAVE_DLERROR 1
#define FUNC_STDCALL 1
#define __CYGWIN__ 1
#define _WIN32 1
#define __MINGW32__ 1

typedef unsigned long VALUE;
#define rb_secure(x)
#define rb_eFiddleError 0
#define rb_raise(e, ...)
#define PTR2NUM(x) (VALUE)(x)
#define xmalloc malloc
#define xrealloc realloc
#define xfree free