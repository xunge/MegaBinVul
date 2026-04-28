#include <stddef.h>

typedef unsigned long VALUE;
#define Qnil 0

typedef struct _xmlDoc {
    struct _xmlDoc *doc;
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xmlSchema xmlSchema;
typedef xmlSchema *xmlSchemaPtr;

typedef struct _xmlSchemaParserCtxt xmlSchemaParserCtxt;
typedef xmlSchemaParserCtxt *xmlSchemaParserCtxtPtr;

typedef struct _xmlError xmlError;
typedef xmlError *xmlErrorPtr;

typedef enum {
    rb_eArgError,
    rb_eRuntimeError
} ruby_error_type;

typedef void (*xmlStructuredErrorFunc)(void *userData, const xmlError *error);

#define Data_Get_Struct(obj, type, val) ((val) = (type*)0)
#define rb_ary_new() (0)
#define rb_raise(exc, fmt) 
#define rb_iv_set(obj, name, val) 
#define Data_Wrap_Struct(klass, mark, free, ptr) (0)
#define dealloc(schema) 
#define has_blank_nodes_p(node_cache) (0)
#define Nokogiri_error_raise(ctx, error) 
#define DOC_NODE_CACHE(doc) ((void*)0)

extern xmlSchemaParserCtxtPtr xmlSchemaNewDocParserCtxt(xmlDocPtr doc);
extern xmlSchemaPtr xmlSchemaParse(xmlSchemaParserCtxtPtr ctxt);
extern void xmlSchemaFreeParserCtxt(xmlSchemaParserCtxtPtr ctxt);
extern void xmlSetStructuredErrorFunc(void *ctx, xmlStructuredErrorFunc handler);
extern xmlErrorPtr xmlGetLastError(void);

static void Nokogiri_error_array_pusher(void *ctx, const xmlError *error) {}

VALUE mNokogiriXml;
VALUE rb_intern(const char *name);
VALUE rb_const_get(VALUE klass, VALUE name);
VALUE rb_funcall(VALUE recv, VALUE mid, int argc, ...);
int rb_scan_args(int argc, VALUE *argv, const char *fmt, ...);
int NUM2INT(VALUE num);