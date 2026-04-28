#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _zval {
    int type;
    union {
        long lval;
        double dval;
        void *ptr;
    } value;
} zval;

typedef struct _HashTable {
    unsigned int nTableSize;
    unsigned int nNumOfElements;
    void **pInternalPointer;
    void **pListHead;
    void **pListTail;
} HashTable;

typedef unsigned char xmlChar;

typedef struct _xmlNs {
    const xmlChar *href;
    const xmlChar *prefix;
} xmlNs;

typedef struct _xmlNode {
    void *private;
    int type;
    const char *name;
    struct _xmlNode *children;
    struct _xmlNode *last;
    struct _xmlNode *parent;
    struct _xmlNode *next;
    struct _xmlNode *prev;
    struct _xmlDoc *doc;
    xmlNs *ns;
    struct _xmlAttr *properties;
    const xmlChar *content;
} xmlNode;

typedef xmlNode *xmlNodePtr;

typedef struct _xmlAttr {
    void *private;
    int type;
    const char *name;
    struct _xmlNode *children;
    struct _xmlNode *last;
    struct _xmlAttr *next;
    struct _xmlAttr *prev;
    struct _xmlDoc *doc;
    struct _xmlNs *ns;
} xmlAttr;

typedef xmlAttr *xmlAttrPtr;

typedef struct _sdl {
    char *source;
    HashTable functions;
    HashTable *requests;
    HashTable *bindings;
} sdl;

typedef sdl *sdlPtr;

typedef struct _sdlCtx {
    sdlPtr sdl;
    HashTable docs;
    HashTable messages;
    HashTable bindings;
    HashTable portTypes;
    HashTable services;
} sdlCtx;

typedef struct _sdlBinding {
    int bindingType;
    char *name;
    char *location;
    void *bindingAttributes;
} sdlBinding;

typedef sdlBinding *sdlBindingPtr;

typedef struct _sdlSoapBinding {
    int style;
    int transport;
} sdlSoapBinding;

typedef sdlSoapBinding *sdlSoapBindingPtr;

typedef struct _sdlFunction {
    char *functionName;
    char *requestName;
    char *responseName;
    HashTable *requestParameters;
    HashTable *responseParameters;
    HashTable *faults;
    void *bindingAttributes;
    sdlBindingPtr binding;
} sdlFunction;

typedef sdlFunction *sdlFunctionPtr;

typedef struct _sdlSoapBindingFunction {
    char *soapAction;
    int style;
    void *input;
    void *output;
} sdlSoapBindingFunction;

typedef sdlSoapBindingFunction *sdlSoapBindingFunctionPtr;

typedef struct _sdlFault {
    char *name;
    HashTable *details;
    void *bindingAttributes;
} sdlFault;

typedef sdlFault *sdlFaultPtr;

typedef struct _sdlSoapBindingFunctionFault {
    int use;
    char *ns;
    int encodingStyle;
} sdlSoapBindingFunctionFault;

typedef sdlSoapBindingFunctionFault *sdlSoapBindingFunctionFaultPtr;

#define E_ERROR 1
#define WSDL_SOAP11_NAMESPACE "http://schemas.xmlsoap.org/wsdl/soap/"
#define WSDL_SOAP12_NAMESPACE "http://schemas.xmlsoap.org/wsdl/soap12/"
#define RPC_SOAP12_NAMESPACE "http://www.w3.org/2003/05/soap-rpc"
#define WSDL_HTTP11_NAMESPACE "http://schemas.xmlsoap.org/wsdl/http/"
#define WSDL_HTTP12_NAMESPACE "http://www.w3.org/2003/05/soap/bindings/HTTP/"
#define WSDL_NAMESPACE "http://schemas.xmlsoap.org/wsdl/"
#define WSDL_HTTP_TRANSPORT "http://schemas.xmlsoap.org/soap/http"
#define SOAP_1_1_ENC_NAMESPACE "http://schemas.xmlsoap.org/soap/encoding/"
#define SOAP_1_2_ENC_NAMESPACE "http://www.w3.org/2003/05/soap-encoding"

enum {
    BINDING_SOAP,
    BINDING_HTTP
};

enum {
    SOAP_DOCUMENT,
    SOAP_RPC
};

enum {
    SOAP_TRANSPORT_HTTP
};

enum {
    SOAP_ENCODED,
    SOAP_LITERAL
};

enum {
    SOAP_ENCODING_1_1,
    SOAP_ENCODING_1_2
};

static void *emalloc(size_t size) { return malloc(size); }
static void efree(void *ptr) { free(ptr); }
static char *estrdup(const char *s) { return strdup(s); }
static char *php_strtolower(char *s, size_t len) { 
    for (size_t i = 0; i < len; i++) s[i] = tolower(s[i]);
    return s; 
}

static void delete_function(void *data) { efree(data); }
static void delete_document(void *data) { efree(data); }
static void delete_binding(void *data) { efree(data); }
static void delete_fault(void *data) { efree(data); }

static int is_wsdl_element(xmlNodePtr node) { return 1; }
static int node_is_equal(xmlNodePtr node, const char *name) { return strcmp(node->name, name) == 0; }
static int node_is_equal_ex(xmlNodePtr node, const char *name, const char *ns) { 
    return strcmp(node->name, name) == 0 && (ns == NULL || (node->ns && strcmp((char*)node->ns->href, ns) == 0));
}

static xmlAttrPtr get_attribute(xmlAttrPtr props, const char *name) {
    while (props) {
        if (strcmp(props->name, name) == 0) return props;
        props = props->next;
    }
    return NULL;
}

static xmlNodePtr get_node_ex(xmlNodePtr node, const char *name, const char *ns) {
    while (node) {
        if (node_is_equal_ex(node, name, ns)) return node;
        node = node->next;
    }
    return NULL;
}

static xmlNodePtr get_node_with_attribute_ex(xmlNodePtr node, const char *name, const char *ns, 
                                           const char *attr_name, const char *attr_value, const char *attr_ns) {
    while (node) {
        if (node_is_equal_ex(node, name, ns)) {
            xmlAttrPtr attr = get_attribute(node->properties, attr_name);
            if (attr && attr->children && strcmp((char*)attr->children->content, attr_value) == 0) {
                return node;
            }
        }
        node = node->next;
    }
    return NULL;
}

static void zend_hash_init(HashTable *ht, unsigned int size, void *pDestructor, void (*pDestructorFn)(void *), int persistent) {
    ht->nTableSize = size;
    ht->nNumOfElements = 0;
    ht->pInternalPointer = NULL;
    ht->pListHead = NULL;
    ht->pListTail = NULL;
}

static unsigned int zend_hash_num_elements(HashTable *ht) {
    return ht->nNumOfElements;
}

static void zend_hash_internal_pointer_reset(HashTable *ht) {
    ht->pInternalPointer = ht->pListHead;
}

static void *zend_hash_get_current_data_ptr(HashTable *ht) {
    return ht->pInternalPointer ? *ht->pInternalPointer : NULL;
}

static int zend_hash_str_add_ptr(HashTable *ht, const char *key, size_t len, void *pData) {
    return 0;
}

static void zend_hash_next_index_insert_ptr(HashTable *ht, void *pData) {}

static void zend_hash_move_forward(HashTable *ht) {
    if (ht->pInternalPointer) ht->pInternalPointer++;
}

static void zend_hash_destroy(HashTable *ht) {}

static void soap_error0(int type, const char *format) {}
static void soap_error1(int type, const char *format, const char *arg1) {}
static void soap_error2(int type, const char *format, const char *arg1, const char *arg2) {}

static void load_wsdl_ex(zval *this_ptr, char *struri, sdlCtx *ctx, int recursive) {}
static void schema_pass2(sdlCtx *ctx) {}
static HashTable *wsdl_message(sdlCtx *ctx, const xmlChar *message) { return NULL; }
static void wsdl_soap_binding_body(sdlCtx *ctx, xmlNodePtr input, const char *ns, 
                                  sdlSoapBindingFunctionPtr *binding, HashTable *parameters) {}