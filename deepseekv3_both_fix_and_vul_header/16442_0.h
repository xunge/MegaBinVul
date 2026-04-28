#include <stddef.h>

typedef void* VALUE;
#define Qnil ((VALUE)0)
#define rb_eRuntimeError ((VALUE)1)

typedef struct _xmlDoc {
    struct _xmlDoc *doc;
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xmlRelaxNG xmlRelaxNG;
typedef xmlRelaxNG *xmlRelaxNGPtr;

typedef struct _xmlRelaxNGParserCtxt xmlRelaxNGParserCtxt;
typedef xmlRelaxNGParserCtxt *xmlRelaxNGParserCtxtPtr;

typedef struct _xmlError {
} xmlError;
typedef xmlError *xmlErrorPtr;

extern void Nokogiri_error_array_pusher(void *ctx, const char *msg, ...);
extern void Nokogiri_error_raise(VALUE ctx, xmlErrorPtr error);
extern void dealloc(void *schema);
extern VALUE rb_ary_new(void);
extern void rb_raise(VALUE exception, const char *fmt, ...);
extern VALUE Data_Wrap_Struct(VALUE klass, void (*mark)(), void (*free)(), void *ptr);
extern void rb_iv_set(VALUE obj, const char *name, VALUE val);
extern int rb_scan_args(int argc, VALUE *argv, const char *fmt, ...);
extern VALUE rb_const_get(VALUE klass, VALUE name);
extern VALUE rb_intern(const char *name);
#define Data_Get_Struct(obj, type, sval) ((sval) = (type*)(obj))

extern xmlRelaxNGParserCtxtPtr xmlRelaxNGNewDocParserCtxt(xmlDocPtr doc);
extern void xmlSetStructuredErrorFunc(void *ctx, void (*handler)(void *ctx, const char *msg, ...));
extern xmlRelaxNGPtr xmlRelaxNGParse(xmlRelaxNGParserCtxtPtr ctxt);
extern void xmlRelaxNGFreeParserCtxt(xmlRelaxNGParserCtxtPtr ctxt);
extern xmlErrorPtr xmlGetLastError(void);
extern void xmlRelaxNGSetParserStructuredErrors(xmlRelaxNGParserCtxtPtr ctxt, void (*errorfunc)(void *ctx, const char *msg, ...), void *ctx);

VALUE mNokogiriXml;