#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

typedef struct _HashTable {
    void *pInternalPointer;
    void *pListHead;
    void *pListTail;
    void *arBuckets;
    unsigned int nNumOfElements;
    unsigned int nTableSize;
    unsigned int nTableMask;
    uint32_t nNextFreeElement;
} HashTable;

typedef struct _xmlNode {
    struct _xmlNode *children;
    struct _xmlNode *next;
    struct _xmlAttr *properties;
    struct _xmlNs *ns;
    char *name;
    char *content;
} xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlAttr {
    struct _xmlAttr *next;
    struct _xmlNode *children;
    char *name;
    char *content;
} xmlAttr;
typedef xmlAttr *xmlAttrPtr;

typedef struct _xmlNs {
    char *href;
} xmlNs;
typedef xmlNs *xmlNsPtr;

typedef struct _sdlCtx {
    HashTable messages;
    void *sdl;
} sdlCtx;

typedef struct _sdlParam {
    char *paramName;
    void *encode;
    struct _sdlElement *element;
    int order;
} sdlParam;
typedef sdlParam *sdlParamPtr;

typedef struct _sdlElement {
    void *encode;
} sdlElement;

typedef char xmlChar;

#define WSDL_NAMESPACE "http://schemas.xmlsoap.org/wsdl/"
#define E_ERROR 1

static void delete_parameter(void *param) { free(param); }
static void* emalloc(size_t size) { return malloc(size); }
static char* estrdup(const char* str) { return strdup(str); }
static xmlAttrPtr get_attribute(xmlAttrPtr properties, const char* name) { return NULL; }
static void* get_encoder_from_prefix(void* sdl, xmlNodePtr node, xmlChar* content) { return NULL; }
static void* get_element(void* sdl, xmlNodePtr node, xmlChar* content) { return NULL; }
static int node_is_equal(xmlNodePtr node, const char* name) { return 0; }
static void soap_error1(int level, const char* format, ...) {}
static void* zend_hash_str_find_ptr(HashTable *ht, const char *str, size_t len) { return NULL; }
static int zend_hash_init(HashTable *ht, uint32_t nSize, void *pDestructor, void (*destructor)(void*), int persistent) { return 0; }
static int zend_hash_next_index_insert_ptr(HashTable *ht, void *pData) { return 0; }