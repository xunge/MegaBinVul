#include <stddef.h>
#include <limits.h>

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_CC
#define TSRMLS_C
#define TSRMLS_D
#define DOM_LOAD_FILE 1
#define DOM_LOAD_STRING 2
#define XML_SCHEMA_VAL_VC_I_CREATE 1
#define MAXPATHLEN PATH_MAX
#define FAILURE (-1)
#define SUCCESS 0
#define E_WARNING 2
#define E_ERROR 1
#define RETURN_FALSE do { return; } while(0)
#define RETURN_TRUE do { return; } while(0)
#define ZEND_NUM_ARGS() 0
#define DOM_GET_OBJ(docp, id, type, intern) do { } while(0)

typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef struct _xmlSchemaParserCtxt xmlSchemaParserCtxt;
typedef xmlSchemaParserCtxt *xmlSchemaParserCtxtPtr;
typedef struct _xmlSchema xmlSchema;
typedef xmlSchema *xmlSchemaPtr;
typedef struct _xmlSchemaValidCtxt xmlSchemaValidCtxt;
typedef xmlSchemaValidCtxt *xmlSchemaValidCtxtPtr;
typedef void (*xmlSchemaValidityErrorFunc)(void *ctx, const char *msg, ...);
typedef void (*xmlSchemaValidityWarningFunc)(void *ctx, const char *msg, ...);

typedef struct _dom_object {
    void *node;
    void *document;
    int handle;
    void *prop_handler;
} dom_object;

typedef struct _zval zval;
typedef struct _zend_class_entry zend_class_entry;

/* Dummy function declarations */
static inline xmlSchemaParserCtxtPtr xmlSchemaNewParserCtxt(const char *filename) { return NULL; }
static inline xmlSchemaParserCtxtPtr xmlSchemaNewMemParserCtxt(const char *buffer, int size) { return NULL; }
static inline void xmlSchemaSetParserErrors(xmlSchemaParserCtxtPtr ctxt, 
    xmlSchemaValidityErrorFunc err, xmlSchemaValidityWarningFunc warn, void *ctx) {}
static inline xmlSchemaPtr xmlSchemaParse(xmlSchemaParserCtxtPtr ctxt) { return NULL; }
static inline void xmlSchemaFreeParserCtxt(xmlSchemaParserCtxtPtr ctxt) {}
static inline xmlSchemaValidCtxtPtr xmlSchemaNewValidCtxt(xmlSchemaPtr schema) { return NULL; }
static inline void xmlSchemaFree(xmlSchemaPtr schema) {}
static inline void xmlSchemaSetValidOptions(xmlSchemaValidCtxtPtr ctxt, int options) {}
static inline void xmlSchemaSetValidErrors(xmlSchemaValidCtxtPtr ctxt, 
    xmlSchemaValidityErrorFunc err, xmlSchemaValidityWarningFunc warn, void *ctx) {}
static inline int xmlSchemaValidateDoc(xmlSchemaValidCtxtPtr ctxt, xmlDocPtr doc) { return 0; }
static inline void xmlSchemaFreeValidCtxt(xmlSchemaValidCtxtPtr ctxt) {}

extern zend_class_entry *dom_document_class_entry;
extern int zend_parse_method_parameters(int num_args, void *this_ptr, const char *type_spec, ...);
extern void *getThis(void);
extern void php_error_docref(const char *docref, int type, const char *format, ...);
extern void php_error(int type, const char *format, ...);
extern void *dom_object_get_node(void *intern);
extern char *_dom_get_valid_file_path(const char *source, char *resolved_path, int maxlen);
extern void php_libxml_error_handler(void *ctx, const char *msg, ...);