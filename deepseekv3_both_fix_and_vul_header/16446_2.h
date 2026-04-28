#include <stddef.h>

typedef unsigned long VALUE;
typedef struct xmlSchema xmlSchema;
typedef xmlSchema* xmlSchemaPtr;
typedef struct xmlSchemaParserCtxt xmlSchemaParserCtxt;
typedef xmlSchemaParserCtxt* xmlSchemaParserCtxtPtr;
typedef struct xmlError xmlError;
typedef xmlError* xmlErrorPtr;

#define Qnil 0
#define NUM2INT(x) (x)
#define RSTRING_LEN(x) 0
#define StringValuePtr(x) NULL
#define rb_ary_new() 0
#define rb_const_get(x, y) 0
#define rb_eRuntimeError 0
#define rb_funcall(x, y, z) 0
#define rb_intern(x) 0
#define rb_iv_set(x, y, z) 
#define rb_raise(x, y) 
#define rb_scan_args(a, b, c, d, e) 0

extern VALUE mNokogiriXml;
extern void Nokogiri_error_array_pusher(void *ctx, const char *msg, ...);
extern void Nokogiri_error_raise(VALUE document, xmlErrorPtr error);
extern void dealloc(void *schema);
extern xmlSchemaPtr xmlSchemaNewMemParserCtxt(const char*, int);
extern void xmlSetStructuredErrorFunc(void*, void*);
extern xmlSchemaPtr xmlSchemaParse(xmlSchemaParserCtxtPtr);
extern void xmlSchemaFreeParserCtxt(xmlSchemaParserCtxtPtr);
extern xmlErrorPtr xmlGetLastError();
extern VALUE Data_Wrap_Struct(VALUE, void*, void*, void*);