#include <stddef.h>

#define DOM_LOAD_FILE 1
#define DOM_LOAD_STRING 2
#define MAXPATHLEN 4096
#define FAILURE (-1)
#define RETURN_FALSE
#define RETURN_TRUE
#define E_WARNING 2
#define E_ERROR 1
#define TSRMLS_CC

typedef struct _xmlDoc xmlDoc;
typedef struct _xmlRelaxNGParserCtxt xmlRelaxNGParserCtxt;
typedef struct _xmlRelaxNG xmlRelaxNG;
typedef struct _xmlRelaxNGValidCtxt xmlRelaxNGValidCtxt;
typedef xmlRelaxNGParserCtxt *xmlRelaxNGParserCtxtPtr;
typedef xmlRelaxNG *xmlRelaxNGPtr;
typedef xmlRelaxNGValidCtxt *xmlRelaxNGValidCtxtPtr;
typedef xmlDoc *xmlDocPtr;
typedef void (*xmlRelaxNGValidityErrorFunc)(void *ctx, const char *msg, ...);
typedef void (*xmlRelaxNGValidityWarningFunc)(void *ctx, const char *msg, ...);

typedef struct _zval {
    int dummy;
} zval;

typedef struct _dom_object {
    void *node;
    void *doc;
} dom_object;

typedef struct {
    int dummy;
} INTERNAL_FUNCTION_PARAMETERS;

#define DOM_GET_OBJ(docp, id, type, intern) \
    do { \
        (docp) = (type)((intern)->doc); \
    } while(0)

static inline void* dom_object_get_node(dom_object *obj) { return obj->node; }
static inline void* getThis() { return NULL; }
static inline int ZEND_NUM_ARGS() { return 0; }
static inline int zend_parse_method_parameters(int a, void* b, const char* c, ...) { return 0; }
static inline void php_error_docref(void* a, int b, const char* c, ...) {}
static inline void php_error(int a, const char* b, ...) {}
static inline char* _dom_get_valid_file_path(char* a, char* b, int c, ...) { return NULL; }
static inline xmlRelaxNGParserCtxtPtr xmlRelaxNGNewParserCtxt(char* a) { return NULL; }
static inline xmlRelaxNGParserCtxtPtr xmlRelaxNGNewMemParserCtxt(char* a, int b) { return NULL; }
static inline void xmlRelaxNGSetParserErrors(xmlRelaxNGParserCtxtPtr a, void* b, void* c, void* d) {}
static inline xmlRelaxNGPtr xmlRelaxNGParse(xmlRelaxNGParserCtxtPtr a) { return NULL; }
static inline void xmlRelaxNGFreeParserCtxt(xmlRelaxNGParserCtxtPtr a) {}
static inline xmlRelaxNGValidCtxtPtr xmlRelaxNGNewValidCtxt(xmlRelaxNGPtr a) { return NULL; }
static inline void xmlRelaxNGFree(xmlRelaxNGPtr a) {}
static inline void xmlRelaxNGSetValidErrors(xmlRelaxNGValidCtxtPtr a, void* b, void* c, void* d) {}
static inline int xmlRelaxNGValidateDoc(xmlRelaxNGValidCtxtPtr a, xmlDocPtr b) { return 0; }
static inline void xmlRelaxNGFreeValidCtxt(xmlRelaxNGValidCtxtPtr a) {}
static inline void php_libxml_error_handler(void *ctx, const char *msg, ...) {}

extern void *dom_document_class_entry;