#include <string.h>
#include <stdlib.h>

#define WSDL_NAMESPACE "http://schemas.xmlsoap.org/wsdl/"
#define XSD_NAMESPACE "http://www.w3.org/2001/XMLSchema"
#define E_ERROR 1

typedef struct _xmlNode {
    struct _xmlNode *children;
    struct _xmlNode *next;
    struct _xmlAttr *properties;
    struct _xmlDoc *doc;
    char *name;
    char *URL;
    char *content;
} xmlNode;

typedef struct _xmlAttr {
    struct _xmlNode *children;
    char *content;
    char *name;
    struct _xmlAttr *next;
} xmlAttr;

typedef struct _xmlDoc {
    struct _xmlNode *children;
    char *URL;
} xmlDoc;

typedef struct _xmlError {
    char *message;
} xmlError;

typedef xmlNode* xmlNodePtr;
typedef xmlAttr* xmlAttrPtr;
typedef xmlDoc* xmlDocPtr;
typedef xmlError* xmlErrorPtr;
typedef unsigned char xmlChar;

typedef struct _zval zval;
typedef struct _sdl {
    char *target_ns;
} sdl;
typedef sdl* sdlPtr;

typedef struct _sdlCtx {
    void *sdl;
    void *docs;
    void *messages;
    void *portTypes;
    void *bindings;
    void *services;
} sdlCtx;

extern int zend_hash_str_exists(void *ht, const char *str, size_t len);
extern void* zend_hash_str_add_ptr(void *ht, const char *str, size_t len, void *pData);
extern char* estrdup(const char *s);
extern size_t xmlStrlen(const xmlChar *str);
extern xmlChar* xmlBuildURI(const xmlChar *URI, const xmlChar *base);
extern void xmlFree(void *ptr);
extern xmlChar* xmlNodeGetBase(xmlDocPtr doc, xmlNodePtr node);
extern xmlErrorPtr xmlGetLastError(void);
extern xmlDocPtr soap_xmlParseFile(const char *filename);
extern void sdl_set_uri_credentials(sdlCtx *ctx, const char *struri);
extern void sdl_restore_uri_credentials(sdlCtx *ctx);
extern void soap_error0(int type, const char *error);
extern void soap_error1(int type, const char *error, const char *str);
extern void soap_error2(int type, const char *error, const char *str1, const char *str2);
extern xmlNodePtr get_node_ex(xmlNodePtr node, const char *name, const char *ns);
extern xmlAttrPtr get_attribute(xmlAttrPtr node, const char *name);
extern int is_wsdl_element(xmlNodePtr node);
extern int node_is_equal(xmlNodePtr node, const char *name);
extern int node_is_equal_ex(xmlNodePtr node, const char *name, const char *ns);
extern void load_schema(sdlCtx *ctx, xmlNodePtr schema);