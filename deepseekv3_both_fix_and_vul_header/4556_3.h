#include <stdlib.h>
#include <string.h>

typedef struct _xmlDoc {
    void *_private;
} xmlDoc;
typedef struct _xmlNode xmlNode;
typedef xmlNode* xmlNodePtr;
typedef xmlDoc* xmlDocPtr;

typedef struct _zval {
    union {
        long lval;
        struct {
            void *ce;
        } obj;
    } value;
    int type;
} zval;

typedef struct _dom_doc_props dom_doc_props;
typedef dom_doc_props *dom_doc_propsptr;
typedef struct _php_libxml_node_object php_libxml_node_object;

typedef struct _dom_object {
    struct {
        dom_doc_props *doc_props;
    } *document;
} dom_object;

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
typedef htmlParserCtxt* htmlParserCtxtPtr;

#define DOM_LOAD_FILE 1
#define TSRMLS_CC
#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define ZEND_NUM_ARGS() ht
#define FAILURE -1
#define RETURN_FALSE { RETVAL_FALSE; return; }
#define RETURN_TRUE { RETVAL_TRUE; return; }
#define E_WARNING 2
#define php_error_docref(...)
#define Z_OBJCE_P(zval_p) ((zval_p)->value.obj.ce)
#define instanceof_function(ce1, ce2, ...) ((ce1) == (ce2))
#define zend_object_store_get_object(...) NULL
#define dom_object_get_node(...) NULL
#define php_libxml_decrement_node_ptr(...)
#define php_libxml_decrement_doc_ref(...) 0
#define php_libxml_increment_doc_ref(...) 0
#define php_libxml_increment_node_ptr(...)
#define DOM_RET_OBJ(...)
#define RETVAL_FALSE do { (return_value)->value.lval = 0; (return_value)->type = 8; } while (0)
#define RETVAL_TRUE do { (return_value)->value.lval = 1; (return_value)->type = 8; } while (0)

extern void *dom_document_class_entry;
extern void php_libxml_ctx_error(void *ctx, const char *msg, ...);
extern void php_libxml_ctx_warning(void *ctx, const char *msg, ...);

static size_t xmlStrlen(const char *str) { return strlen(str); }
static htmlParserCtxtPtr htmlCreateFileParserCtxt(const char *filename, const char *encoding) { return NULL; }
static htmlParserCtxtPtr htmlCreateMemoryParserCtxt(const char *buffer, int size) { return NULL; }
static void htmlCtxtUseOptions(htmlParserCtxtPtr ctxt, long options) {}
static void htmlParseDocument(htmlParserCtxtPtr ctxt) {}
static void htmlFreeParserCtxt(htmlParserCtxtPtr ctxt) {}
static zval* getThis(void) { return NULL; }
static int zend_parse_parameters(int num_args, const char *type_spec, ...) { return 0; }