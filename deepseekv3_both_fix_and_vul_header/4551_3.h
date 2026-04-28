#include <stdlib.h>
#include <string.h>

typedef struct _zval_struct {
    int type;
    void *value;
} zval;

typedef struct _xmlDoc {
    void *_private;
} xmlDoc;

typedef struct _xmlNode {
    // dummy structure
} xmlNode;

typedef xmlNode* xmlNodePtr;
typedef xmlDoc* xmlDocPtr;

typedef struct _dom_doc_props {
    // dummy structure
} dom_doc_props;

typedef dom_doc_props *dom_doc_propsptr;

typedef struct {
    dom_doc_propsptr doc_props;
} dom_document;

typedef struct _dom_object {
    dom_document *document;
    void *node;
} dom_object;

typedef struct _php_libxml_node_object {
    // dummy structure
} php_libxml_node_object;

typedef struct _htmlParserCtxt {
    struct {
        void (*error)(void *, const char *, ...);
        void (*warning)(void *, const char *, ...);
    } vctxt;
    struct {
        void (*error)(void *, const char *, ...);
        void (*warning)(void *, const char *, ...);
    } *sax;
    xmlDoc *myDoc;
} htmlParserCtxt;
typedef htmlParserCtxt *htmlParserCtxtPtr;

#define DOM_LOAD_FILE 1
#define TSRMLS_CC
#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define FAILURE -1
#define RETURN_FALSE do { } while(0)
#define RETURN_TRUE do { } while(0)
#define php_error_docref(...)
#define E_WARNING 2
#define Z_OBJCE_P(zval_p) NULL
#define instanceof_function(...) 0
#define zend_object_store_get_object(...) NULL
#define dom_object_get_node(...) NULL
#define php_libxml_decrement_node_ptr(...)
#define php_libxml_decrement_doc_ref(...) 0
#define php_libxml_increment_doc_ref(...) 0
#define php_libxml_increment_node_ptr(...)
#define DOM_RET_OBJ(...)

static zval* getThis(void) { return NULL; }
static int zend_parse_parameters(int num_args, const char *type_spec, ...) { return 0; }
static size_t xmlStrlen(const char *str) { return strlen(str); }
static htmlParserCtxtPtr htmlCreateFileParserCtxt(const char *filename, const char *encoding) { return NULL; }
static htmlParserCtxtPtr htmlCreateMemoryParserCtxt(const char *buffer, int size) { return NULL; }
static void htmlCtxtUseOptions(htmlParserCtxtPtr ctxt, long options) {}
static void htmlParseDocument(htmlParserCtxtPtr ctxt) {}
static void htmlFreeParserCtxt(htmlParserCtxtPtr ctxt) {}
static void php_libxml_ctx_error(void *ctx, const char *msg, ...) {}
static void php_libxml_ctx_warning(void *ctx, const char *msg, ...) {}