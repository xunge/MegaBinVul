#include <stddef.h>

typedef void* VALUE;
typedef struct rb_scan_args_t rb_scan_args_t;
typedef int rb_intern_t;
typedef struct xmlRelaxNGParserCtxt* xmlRelaxNGParserCtxtPtr;
typedef struct xmlRelaxNG* xmlRelaxNGPtr;
typedef struct xmlError* xmlErrorPtr;

#define Qnil NULL
#define HAVE_XMLRELAXNGSETPARSERSTRUCTUREDERRORS

extern VALUE mNokogiriXml;
extern VALUE rb_eRuntimeError;
extern VALUE rb_ary_new();
extern int rb_scan_args(int argc, VALUE *argv, const char *fmt, ...);
extern VALUE rb_const_get(VALUE outer, rb_intern_t id);
extern rb_intern_t rb_intern(const char *name);
extern void rb_raise(VALUE exception, const char *fmt, ...);
extern VALUE Data_Wrap_Struct(VALUE klass, void *mark, void (*free)(void *), void *ptr);
extern void rb_iv_set(VALUE obj, const char *name, VALUE val);
extern const char *StringValuePtr(VALUE string);
extern int RSTRING_LEN(VALUE string);
extern void xmlSetStructuredErrorFunc(void *ctx, void (*handler)(void *ctx, xmlErrorPtr error));
extern void xmlRelaxNGSetParserStructuredErrors(xmlRelaxNGParserCtxtPtr ctxt, void (*serror)(void *ctx, xmlErrorPtr error), void *ctx);
extern xmlRelaxNGParserCtxtPtr xmlRelaxNGNewMemParserCtxt(const char *buffer, int size);
extern xmlRelaxNGPtr xmlRelaxNGParse(xmlRelaxNGParserCtxtPtr ctxt);
extern void xmlRelaxNGFreeParserCtxt(xmlRelaxNGParserCtxtPtr ctxt);
extern xmlErrorPtr xmlGetLastError();
extern void Nokogiri_error_raise(VALUE ctx, xmlErrorPtr error);
extern void Nokogiri_error_array_pusher(void *ctx, xmlErrorPtr error);
extern void dealloc(void *ptr);