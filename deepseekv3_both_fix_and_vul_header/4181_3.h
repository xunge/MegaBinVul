#include <dlfcn.h>
#include <string.h>
#include <strings.h>

struct dl_handle {
    void *ptr;
    int open;
    int enable_close;
};

typedef unsigned long VALUE;
#define NUM2INT(x) ((int)(x))
#define NIL_P(x) ((x) == 0)
#define StringValuePtr(x) ((char*)(x))
#define STRCASECMP strcasecmp
#define rb_scan_args(argc, argv, fmt, arg1, arg2) 0
#define rb_secure(x)
#define rb_raise(err, fmt, msg)
#define TypedData_Get_Struct(obj, type, data_type, sval) ((sval) = (type*)0)
#define rb_block_given_p() 0
#define rb_ensure(func, arg1, cleanup, arg2)
#define rb_yield
#define Qnil 0
#define rb_bug(msg)