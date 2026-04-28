#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct _zval {
    int type;
    void *value;
} zval;

typedef struct _xmlDoc {
    void *_private;
} xmlDoc;

typedef struct _xmlNode {
    int dummy;
} xmlNode;
typedef xmlNode* xmlNodePtr;
typedef xmlDoc* xmlDocPtr;

typedef struct _xmlParserCtxt {
    void *userData;
    void (*error)(void *ctx, const char *msg, ...);
    void (*warning)(void *ctx, const char *msg, ...);
} xmlParserCtxt;

typedef struct _xmlSAXHandler {
    void (*error)(void *ctx, const char *msg, ...);
    void (*warning)(void *ctx, const char *msg, ...);
} xmlSAXHandler;

typedef struct _htmlParserCtxt {
    xmlParserCtxt vctxt;
    xmlSAXHandler *sax;
    xmlDocPtr myDoc;
} htmlParserCtxt;
typedef htmlParserCtxt* htmlParserCtxtPtr;

typedef struct _dom_doc_props {
    int dummy;
} dom_doc_props;
typedef dom_doc_props *dom_doc_propsptr;

typedef struct _dom_document {
    dom_doc_propsptr doc_props;
} dom_document;

typedef struct _dom_object {
    dom_document *document;
    void *node;
} dom_object;

typedef struct _php_libxml_node_object {
    void *node;
} php_libxml_node_object;

void (*php_libxml_ctx_error)(void *ctx, const char *msg, ...);
void (*php_libxml_ctx_warning)(void *ctx, const char *msg, ...);

static zval* getThis(void) { return NULL; }
static int zend_parse_parameters(int num_args, const char *type_spec, ...) { return 0; }
static void php_error_docref(void *ref, int type, const char *format, ...) {}
static htmlParserCtxtPtr htmlCreateFileParserCtxt(const char *filename, const char *encoding) { return NULL; }
static int xmlStrlen(const char *str) { return str ? strlen(str) : 0; }
static htmlParserCtxtPtr htmlCreateMemoryParserCtxt(const char *buffer, int size) { return NULL; }
static void htmlCtxtUseOptions(htmlParserCtxtPtr ctxt, long options) {}
static void htmlParseDocument(htmlParserCtxtPtr ctxt) {}
static void htmlFreeParserCtxt(htmlParserCtxtPtr ctxt) {}
static int instanceof_function(void *ce1, void *ce2) { return 0; }
static void* zend_object_store_get_object(void *obj) { return NULL; }
static void* dom_object_get_node(dom_object *obj) { return NULL; }
static void php_libxml_decrement_node_ptr(php_libxml_node_object *obj) {}
static int php_libxml_decrement_doc_ref(php_libxml_node_object *obj) { return 0; }
static int php_libxml_increment_doc_ref(php_libxml_node_object *obj, xmlDoc *doc) { return 0; }
static void php_libxml_increment_node_ptr(php_libxml_node_object *obj, xmlNodePtr node, void *ptr) {}

#define DOM_LOAD_FILE 1
#define TSRMLS_CC
#define INTERNAL_FUNCTION_PARAMETERS int ht, void *return_value, void **return_value_ptr, void *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define FAILURE -1
#define E_WARNING 2
#define RETURN_FALSE do {*(int*)return_value = 0;} while(0)
#define RETURN_TRUE do {*(int*)return_value = 1;} while(0)
#define Z_OBJCE_P(zval_p) ((void*)0)
#define DOM_RET_OBJ(node, retobj, ce) do { *(int*)retobj = (int)(intptr_t)node; } while(0)

void *dom_document_class_entry;