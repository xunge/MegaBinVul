#include <dlfcn.h>
#include <stddef.h>

struct dl_handle {
    void *ptr;
    int open;
    int enable_close;
};

typedef void* VALUE;
#define Qnil NULL
#define NIL_P(x) ((x) == Qnil)
#define NUM2INT(x) (*(int*)(x))
#define StringValuePtr(x) ((char*)(x))
#define HAVE_DLERROR 1

extern int rb_scan_args(int argc, VALUE argv[], const char *fmt, ...);
extern void rb_bug(const char *msg);
extern void *dlopen(const char *filename, int flags);
extern char *dlerror(void);
extern int dlclose(void *handle);
extern void rb_raise(VALUE exc, const char *fmt, ...);
extern void Data_Get_Struct(VALUE obj, void *type, void **handle);
extern int rb_block_given_p(void);
extern VALUE rb_yield(VALUE arg);
extern VALUE rb_ensure(VALUE (*func)(VALUE), VALUE arg1, VALUE (*ensure_func)(VALUE), VALUE arg2);
extern VALUE rb_dlhandle_close(VALUE self);

#define rb_eDLError ((void*)1)
#define Data_Get_Struct(obj, type, handle) Data_Get_Struct(obj, NULL, (void**)(handle))