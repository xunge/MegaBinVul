#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXPATHLEN PATH_MAX

typedef struct _xmlDoc xmlDoc;
typedef xmlDoc* xmlDocPtr;

typedef struct _dom_object {
    void *std;
    void *node;
    void *document;
    void *ce;
    void *properties;
    void *base_obj;
    int prop_handler_status;
} dom_object;

typedef void* xmlRelaxNGParserCtxtPtr;
typedef void* xmlRelaxNGPtr;
typedef void* xmlRelaxNGValidCtxtPtr;
typedef void (*xmlRelaxNGValidityErrorFunc)(void *ctx, const char *msg, ...);
typedef void (*xmlRelaxNGValidityWarningFunc)(void *ctx, const char *msg, ...);

#define DOM_LOAD_FILE 1
#define DOM_LOAD_STRING 2

typedef struct _zend_class_entry zend_class_entry;
typedef struct _zval zval;

#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval **return_value_ptr, zval *this_ptr, int return_value_used
#define TSRMLS_CC
#define ZEND_NUM_ARGS() ht
#define FAILURE -1
#define RETURN_FALSE do { return; } while (0)
#define RETURN_TRUE do { return; } while (0)
#define E_WARNING 2
#define E_ERROR 1

static zend_class_entry *dom_document_class_entry = NULL;
static void* dom_object_get_node(dom_object *obj) { return NULL; }
static char* _dom_get_valid_file_path(const char *source, char *resolved_path, int maxlen) { return NULL; }
static void php_libxml_error_handler(void *ctx, const char *msg, ...) {}
static void php_error_docref(const char *docref, int type, const char *format, ...) {}
static void php_error(int type, const char *format, ...) {}
static zval* getThis() { return NULL; }
static int zend_parse_method_parameters(int num_args, zval *this_ptr, const char *type_spec, ...) { return 0; }

#define DOM_GET_OBJ(docp, id, type, intern) \
    do { \
        intern = NULL; \
        docp = NULL; \
    } while (0)

static void xmlRelaxNGSetParserErrors(xmlRelaxNGParserCtxtPtr ctxt, 
                                    xmlRelaxNGValidityErrorFunc err, 
                                    xmlRelaxNGValidityWarningFunc warn, 
                                    void *ctx) {}
static xmlRelaxNGPtr xmlRelaxNGParse(xmlRelaxNGParserCtxtPtr ctxt) { return NULL; }
static void xmlRelaxNGFreeParserCtxt(xmlRelaxNGParserCtxtPtr ctxt) {}
static xmlRelaxNGParserCtxtPtr xmlRelaxNGNewParserCtxt(const char *URL) { return NULL; }
static xmlRelaxNGParserCtxtPtr xmlRelaxNGNewMemParserCtxt(const char *buffer, int size) { return NULL; }
static xmlRelaxNGValidCtxtPtr xmlRelaxNGNewValidCtxt(xmlRelaxNGPtr schema) { return NULL; }
static void xmlRelaxNGFree(xmlRelaxNGPtr schema) {}
static void xmlRelaxNGSetValidErrors(xmlRelaxNGValidCtxtPtr ctxt, 
                                   xmlRelaxNGValidityErrorFunc err, 
                                   xmlRelaxNGValidityWarningFunc warn, 
                                   void *ctx) {}
static int xmlRelaxNGValidateDoc(xmlRelaxNGValidCtxtPtr ctxt, xmlDocPtr doc) { return 0; }
static void xmlRelaxNGFreeValidCtxt(xmlRelaxNGValidCtxtPtr ctxt) {}