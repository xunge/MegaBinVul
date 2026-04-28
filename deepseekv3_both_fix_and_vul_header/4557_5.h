#include <limits.h>
#include <stddef.h>

#define MAXPATHLEN PATH_MAX
#define INTERNAL_FUNCTION_PARAMETERS int ht, zval *return_value, zval *this_ptr, int return_value_used, zend_execute_data *execute_data
#define TSRMLS_CC
#define DOM_LOAD_FILE 1
#define DOM_LOAD_STRING 2
#define FAILURE (-1)
#define SUCCESS 0
#define E_WARNING 2
#define E_ERROR 1
#define RETURN_FALSE do { return; } while(0)
#define RETURN_TRUE do { return; } while(0)
#define ZEND_NUM_ARGS() 0
#define DOM_GET_OBJ(docp, id, type, intern) do { } while(0)

typedef struct _dom_object {
    void *std;
    void *node;
    void *document;
    void *ce;
    void *properties;
    void *base_obj;
} dom_object;

typedef struct _xmlDoc xmlDoc;
typedef xmlDoc* xmlDocPtr;
typedef void* xmlRelaxNGParserCtxtPtr;
typedef void* xmlRelaxNGPtr;
typedef void* xmlRelaxNGValidCtxtPtr;
typedef void (*xmlRelaxNGValidityErrorFunc)(void *ctx, const char *msg, ...);
typedef void (*xmlRelaxNGValidityWarningFunc)(void *ctx, const char *msg, ...);
typedef struct _zval zval;
typedef struct _HashTable HashTable;
typedef struct _zend_class_entry zend_class_entry;
typedef struct _zend_object zend_object;
typedef struct _zend_execute_data zend_execute_data;

extern zend_class_entry *dom_document_class_entry;
extern int zend_parse_method_parameters(int num_args, const char *type_spec, ...);
extern zval *getThis(void);
extern char *_dom_get_valid_file_path(const char *source, char *resolved_path, int maxlen);
extern void *xmlRelaxNGNewParserCtxt(const char *filename);
extern void *xmlRelaxNGNewMemParserCtxt(const char *buffer, int size);
extern void xmlRelaxNGSetParserErrors(void *parser, 
    xmlRelaxNGValidityErrorFunc error_func,
    xmlRelaxNGValidityWarningFunc warn_func,
    void *ctx);
extern void *xmlRelaxNGParse(void *parser);
extern void xmlRelaxNGFreeParserCtxt(void *parser);
extern void *dom_object_get_node(void *intern);
extern void *xmlRelaxNGNewValidCtxt(void *schema);
extern void xmlRelaxNGFree(void *schema);
extern void xmlRelaxNGSetValidErrors(void *valid, 
    xmlRelaxNGValidityErrorFunc error_func,
    xmlRelaxNGValidityWarningFunc warn_func,
    void *ctx);
extern int xmlRelaxNGValidateDoc(void *valid, void *doc);
extern void xmlRelaxNGFreeValidCtxt(void *valid);
extern void php_error_docref(const char *docref, int type, const char *format, ...);
extern void php_error(int type, const char *format, ...);
extern void php_libxml_error_handler(void *ctx, const char *msg, ...);