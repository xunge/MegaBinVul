#include <string.h>
#include <stdlib.h>

typedef struct _xmlNode {
    struct _xmlAttr *properties;
    struct _xmlNode *children;
    struct _xmlNode *next;
    char *name;
    char *content;
} xmlNode;

typedef struct _xmlAttr {
    struct _xmlAttr *next;
    char *name;
    struct _xmlNode *children;
    char *content;
} xmlAttr;

typedef xmlNode* xmlNodePtr;
typedef xmlAttr* xmlAttrPtr;

typedef struct _HashTable {
    unsigned int nTableSize;
    unsigned int nTableMask;
    unsigned int nNumOfElements;
    unsigned int nNextFreeElement;
    void *pInternalPointer;
    void *pListHead;
    void *pListTail;
    void *arBuckets;
} HashTable;

typedef struct _sdlCtx {
    HashTable messages;
    void *sdl;
} sdlCtx;

typedef struct _sdlElement {
    char *name;
    char *namens;
    void *encode;
} sdlElement;

typedef struct _sdlSoapBindingFunctionHeader {
    char *name;
    char *ns;
    int use;
    int encodingStyle;
    void *encode;
    sdlElement *element;
    HashTable *headerfaults;
} sdlSoapBindingFunctionHeader;

typedef sdlSoapBindingFunctionHeader* sdlSoapBindingFunctionHeaderPtr;

typedef struct {
    char *s;
    size_t a;
} smart_str;

enum {
    E_ERROR,
    SOAP_ENCODED,
    SOAP_LITERAL,
    SOAP_ENCODING_1_1,
    SOAP_ENCODING_1_2
};

#define WSDL_NAMESPACE "http://schemas.xmlsoap.org/wsdl/"
#define SOAP_1_1_ENC_NAMESPACE "http://schemas.xmlsoap.org/soap/encoding/"
#define SOAP_1_2_ENC_NAMESPACE "http://www.w3.org/2003/05/soap-encoding"

void* emalloc(size_t size);
void* ecalloc(size_t nmemb, size_t size);
char* estrdup(const char *s);
void efree(void *ptr);
void soap_error0(int level, const char *message);
void soap_error1(int level, const char *message, const char *arg);
xmlAttrPtr get_attribute(xmlAttrPtr properties, const char *name);
xmlNodePtr get_node_with_attribute_ex(xmlNodePtr children, const char *node_name, const char *ns, const char *attr_name, char *attr_value, void *unused);
int node_is_equal_ex(xmlNodePtr node, const char *name, const char *ns);
int node_is_equal(xmlNodePtr node, const char *name);
int is_wsdl_element(xmlNodePtr node);
void* zend_hash_str_find_ptr(HashTable *ht, const char *str, size_t len);
int zend_hash_add_ptr(HashTable *ht, void *key, void *data);
void zend_hash_init(HashTable *ht, size_t size, void *pDestructor, void *pDestructorParam, int persistent);
void smart_str_appends(smart_str *str, const char *append);
void smart_str_appendc(smart_str *str, char append);
void smart_str_0(smart_str *str);
void smart_str_free(smart_str *str);
void delete_header(void *data);
void delete_header_int(void *data);
void* get_encoder_from_prefix(void *sdl, xmlNodePtr part, const char *content);
void* get_element(void *sdl, xmlNodePtr part, const char *content);