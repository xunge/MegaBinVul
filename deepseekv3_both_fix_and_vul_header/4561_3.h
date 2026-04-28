#include <stddef.h>

typedef struct _xmlDoc {
    void *_private;
} xmlDoc;

typedef struct _xmlNode {
} xmlNode;

typedef struct _xmlSAXHandler {
    void (*error)(void *ctx, const char *msg, ...);
    void (*warning)(void *ctx, const char *msg, ...);
} xmlSAXHandler;

typedef struct _xmlParserCtxt {
    struct _xmlParserInput *input;
    xmlSAXHandler *sax;
    xmlDoc *myDoc;
    struct {
        void (*error)(void *ctx, const char *msg, ...);
        void (*warning)(void *ctx, const char *msg, ...);
    } vctxt;
} htmlParserCtxt;

typedef htmlParserCtxt *htmlParserCtxtPtr;
typedef xmlNode *xmlNodePtr;
typedef xmlDoc *xmlDocPtr;

typedef struct _dom_doc_props {
} dom_doc_props;

typedef dom_doc_props *dom_doc_propsptr;

typedef struct _dom_object {
    struct {
        dom_doc_propsptr doc_props;
    } *document;
} dom_object;

typedef struct _php_libxml_node_object {
} php_libxml_node_object;

typedef struct _zend_class_entry {
} zend_class_entry;

typedef struct _zval {
    union {
        long lval;
        struct {
            zend_class_entry *ce;
        } obj;
    } value;
} zval;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_CC
#define TSRMLS_DC
#define ZEND_NUM_ARGS() ht
#define FAILURE -1
#define RETURN_FALSE do { ZVAL_FALSE(return_value); return; } while (0)
#define RETURN_TRUE do { ZVAL_TRUE(return_value); return; } while (0)
#define ZVAL_FALSE(z) (z)->value.lval = 0
#define ZVAL_TRUE(z) (z)->value.lval = 1
#define E_WARNING 2
#define DOM_LOAD_FILE 1
#define Z_OBJCE_P(z) ((z)->value.obj.ce)
#define DOM_RET_OBJ(node, ret, ce) do { *ret = 0; } while (0)

extern zend_class_entry *dom_document_class_entry;
extern int instanceof_function(zend_class_entry *ce, zend_class_entry *instanceof_ce);
extern void php_error_docref(const char *docref, int type, const char *format, ...);
extern int zend_parse_parameters(int num_args, const char *type_spec, ...);
extern zval *getThis();
extern void *zend_object_store_get_object(zval *object);
extern xmlNodePtr dom_object_get_node(dom_object *obj);
extern void php_libxml_decrement_node_ptr(php_libxml_node_object *node);
extern int php_libxml_decrement_doc_ref(php_libxml_node_object *node);
extern int php_libxml_increment_doc_ref(php_libxml_node_object *node, xmlDocPtr doc);
extern void php_libxml_increment_node_ptr(php_libxml_node_object *node, xmlNodePtr nodep, void *private_data);
extern void php_libxml_ctx_error(void *ctx, const char *msg, ...);
extern void php_libxml_ctx_warning(void *ctx, const char *msg, ...);
extern htmlParserCtxtPtr htmlCreateFileParserCtxt(const char *filename, const char *encoding);
extern htmlParserCtxtPtr htmlCreateMemoryParserCtxt(const char *buffer, int size);
extern void htmlCtxtUseOptions(htmlParserCtxtPtr ctxt, int options);
extern void htmlParseDocument(htmlParserCtxtPtr ctxt);
extern void htmlFreeParserCtxt(htmlParserCtxtPtr ctxt);
extern int xmlStrlen(const char *str);