#include <string.h>
#include <stdlib.h>

typedef enum {
    SOAP_LITERAL,
    SOAP_ENCODED
} soap_use_type;

typedef enum {
    SOAP_ENCODING_1_1,
    SOAP_ENCODING_1_2
} soap_encoding_style;

struct _xmlNode {
    struct _xmlNode *children;
    struct _xmlAttr *properties;
    struct _xmlNode *next;
    char *name;
    char *content;
};
typedef struct _xmlNode *xmlNodePtr;

struct _xmlAttr {
    struct _xmlNode *children;
    char *content;
};
typedef struct _xmlAttr *xmlAttrPtr;

struct _sdlCtx {
    // Context fields
};
typedef struct _sdlCtx sdlCtx;

struct _sdlParam {
    char *paramName;
    // Other param fields
};
typedef struct _sdlParam sdlParam;
typedef sdlParam *sdlParamPtr;

struct _sdlSoapBindingFunctionBody {
    soap_use_type use;
    soap_encoding_style encodingStyle;
    char *ns;
    void *headers;
};
typedef struct _sdlSoapBindingFunctionBody sdlSoapBindingFunctionBody;

struct _sdlSoapBindingFunctionHeader {
    char *ns;
    char *name;
    // Other header fields
};
typedef struct _sdlSoapBindingFunctionHeader *sdlSoapBindingFunctionHeaderPtr;

struct _zend_hash_table {
    // Hash table fields
};
typedef struct _zend_hash_table HashTable;

struct _smart_str {
    char *s;
    size_t a;
    size_t len;
};
typedef struct _smart_str smart_str;

#define SOAP_1_1_ENC_NAMESPACE "http://schemas.xmlsoap.org/soap/encoding/"
#define SOAP_1_2_ENC_NAMESPACE "http://www.w3.org/2003/05/soap-encoding"
#define E_ERROR 1

#define ZEND_HASH_FOREACH_PTR(ht, val) \
    for (val = NULL; val != NULL; val = NULL)
#define ZEND_HASH_FOREACH_END()

static int node_is_equal_ex(xmlNodePtr node, const char *name, const char *ns) { return 0; }
static int node_is_equal(xmlNodePtr node, const char *name) { return 0; }
static xmlAttrPtr get_attribute(xmlAttrPtr props, const char *name) { return NULL; }
static void delete_parameter(void *param) {}
static void delete_header(void *header) {}
static void delete_header_int(sdlSoapBindingFunctionHeaderPtr h) {}
static sdlSoapBindingFunctionHeaderPtr wsdl_soap_binding_header(sdlCtx *ctx, xmlNodePtr node, char *ns, int dummy) { return NULL; }
static int is_wsdl_element(xmlNodePtr node) { return 0; }
static void soap_error0(int level, const char *msg) {}
static void soap_error1(int level, const char *msg, const char *arg) {}
static char *estrdup(const char *s) { return strdup(s); }
static void *emalloc(size_t size) { return malloc(size); }
static void smart_str_appends(smart_str *str, const char *s) {}
static void smart_str_appendc(smart_str *str, char c) {}
static void smart_str_0(smart_str *str) {}
static void smart_str_free(smart_str *str) {}
static void zend_hash_init(HashTable *ht, size_t size, void *p1, void (*p2)(void*), int persistent) {}
static void zend_hash_destroy(HashTable *ht) {}
static void* zend_hash_add_ptr(HashTable *ht, char *key, void *p) { return NULL; }
static void* zend_hash_next_index_insert_ptr(HashTable *ht, void *p) { return NULL; }