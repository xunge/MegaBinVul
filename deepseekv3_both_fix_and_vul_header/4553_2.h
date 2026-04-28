#include <stddef.h>
#include <limits.h>
#include <stdio.h>

#define MAXPATHLEN PATH_MAX

typedef struct _xmlDoc xmlDoc;
typedef struct _xmlSchema xmlSchema;
typedef struct _xmlSchemaParserCtxt xmlSchemaParserCtxt;
typedef struct _xmlSchemaValidCtxt xmlSchemaValidCtxt;
typedef xmlSchemaParserCtxt* xmlSchemaParserCtxtPtr;
typedef xmlSchema* xmlSchemaPtr;
typedef xmlSchemaValidCtxt* xmlSchemaValidCtxtPtr;
typedef xmlDoc* xmlDocPtr;

typedef void (*xmlSchemaValidityErrorFunc)(void *ctx, const char *msg, ...);
typedef void (*xmlSchemaValidityWarningFunc)(void *ctx, const char *msg, ...);

typedef struct _dom_object {
    void *ptr;
    void *node;
} dom_object;

typedef struct _zval zval;
typedef struct _zend_class_entry zend_class_entry;

#define DOM_LOAD_FILE 1
#define DOM_LOAD_STRING 2
#define XML_SCHEMA_VAL_VC_I_CREATE 1

extern zend_class_entry *dom_document_class_entry;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_CC 
#define TSRMLS_DC 
#define ZEND_NUM_ARGS() ht
#define RETURN_FALSE 
#define RETURN_TRUE 
#define FAILURE -1
#define SUCCESS 0
#define E_WARNING 2
#define E_ERROR 1

#define DOM_GET_OBJ(docp, id, type, intern) \
    intern = (dom_object *)id; \
    docp = (type)intern->ptr;

int zend_parse_method_parameters(int num_args, zval *this_ptr, const char *type_spec, ...);
zval *getThis(void);
void php_error_docref(const char *docref, int type, const char *format, ...);
void php_error(int type, const char *format, ...);
void php_libxml_error_handler(void *ctx, const char *msg, ...);
char *_dom_get_valid_file_path(const char *source, char *resolved_path, int max_path_len);
void *dom_object_get_node(dom_object *intern);

xmlSchemaParserCtxtPtr xmlSchemaNewParserCtxt(const char *URL);
xmlSchemaParserCtxtPtr xmlSchemaNewMemParserCtxt(const char *buffer, int size);
void xmlSchemaSetParserErrors(xmlSchemaParserCtxtPtr ctxt,
                             xmlSchemaValidityErrorFunc err,
                             xmlSchemaValidityWarningFunc warn,
                             void *ctx);
xmlSchemaPtr xmlSchemaParse(xmlSchemaParserCtxtPtr ctxt);
void xmlSchemaFreeParserCtxt(xmlSchemaParserCtxtPtr ctxt);
xmlSchemaValidCtxtPtr xmlSchemaNewValidCtxt(xmlSchemaPtr schema);
void xmlSchemaFree(xmlSchemaPtr schema);
void xmlSchemaSetValidOptions(xmlSchemaValidCtxtPtr ctxt, int options);
void xmlSchemaSetValidErrors(xmlSchemaValidCtxtPtr ctxt,
                           xmlSchemaValidityErrorFunc err,
                           xmlSchemaValidityWarningFunc warn,
                           void *ctx);
int xmlSchemaValidateDoc(xmlSchemaValidCtxtPtr ctxt, xmlDocPtr doc);
void xmlSchemaFreeValidCtxt(xmlSchemaValidCtxtPtr ctxt);