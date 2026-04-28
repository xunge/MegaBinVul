#include <stddef.h>

typedef void* VALUE;

struct htmlParserCtxt {
    void* sax;
    int errNo;
};
typedef struct htmlParserCtxt* htmlParserCtxtPtr;

struct xmlCharEncodingHandler;
typedef struct xmlCharEncodingHandler* xmlCharEncodingHandlerPtr;

#define T_STRING 0
#define NIL_P(x) 0
#define RTEST(x) 0
#define RSTRING_LEN(x) 0
#define StringValuePtr(x) NULL
#define StringValueCStr(x) NULL
#define Check_Type(x, y)
#define rb_raise(x, y, ...)
#define rb_eRuntimeError NULL
#define rb_eArgError NULL
#define Data_Wrap_Struct(a, b, c, d) NULL
#define XML_ERR_UNSUPPORTED_ENCODING 0

void deallocate(void* ptr) {}
htmlParserCtxtPtr htmlCreateMemoryParserCtxt(const char*, int) { return NULL; }
void xmlFree(void*);
xmlCharEncodingHandlerPtr xmlFindCharEncodingHandler(const char*) { return NULL; }
void xmlSwitchToEncoding(htmlParserCtxtPtr, xmlCharEncodingHandlerPtr) {}