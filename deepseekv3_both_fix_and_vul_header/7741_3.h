#include <stddef.h>

typedef unsigned long VALUE;

struct RString {
    long len;
    char *ptr;
};

#define T_STRING 1
#define NIL_P(obj) ((obj) == 0)
#define RSTRING_LEN(str) (((struct RString*)(str))->len)
#define StringValuePtr(str) (((struct RString*)(str))->ptr)
#define Data_Wrap_Struct(klass, mark, free, ptr) ((VALUE)(ptr))
#define Check_Type(x, t) 
#define rb_eRuntimeError 1
#define rb_eArgError 2
#define rb_raise(err, msg) 

typedef struct _xmlParserCtxt {
    void *sax;
} xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;

extern xmlParserCtxtPtr xmlCreateMemoryParserCtxt(const char *buffer, int size);
extern void xmlFree(void *ptr);
extern void deallocate(xmlParserCtxtPtr ctxt);