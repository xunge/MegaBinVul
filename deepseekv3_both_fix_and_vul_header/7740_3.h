#include <stdint.h>
#include <stddef.h>

typedef uintptr_t VALUE;
typedef int xmlCharEncoding;

typedef struct _xmlParserCtxt {
    void *sax;
} xmlParserCtxt;
typedef xmlParserCtxt* xmlParserCtxtPtr;

typedef int (*xmlInputReadCallback)(void *context, char *buffer, int len);
typedef int (*xmlInputCloseCallback)(void *context);

static unsigned int id_read;
static VALUE rb_eTypeError;

static inline int NUM2INT(VALUE x) { return (int)x; }

static void deallocate(void *ptr) {}
static int noko_io_read(void *context, char *buffer, int len) { return 0; }
static int noko_io_close(void *context) { return 0; }

extern xmlParserCtxtPtr xmlCreateIOParserCtxt(void*, void*, xmlInputReadCallback, xmlInputCloseCallback, void*, xmlCharEncoding);
extern void xmlFree(void*);
extern int rb_respond_to(VALUE, unsigned int);
extern void rb_raise(VALUE, const char*);
extern VALUE Data_Wrap_Struct(VALUE, void*, void (*)(void*), void*);