#include <string.h>
#include <stdlib.h>

typedef unsigned char xmlChar;
typedef struct _xmlNode xmlNode;
typedef struct _xmlAttr xmlAttr;
typedef struct _xmlNs xmlNs;
typedef struct _xmlDict xmlDict;
typedef struct _xmlDoc xmlDoc;
typedef struct _xsltTransformContext xsltTransformContext;

typedef xmlAttr* xmlAttrPtr;
typedef xmlNode* xmlNodePtr;
typedef xmlNs* xmlNsPtr;
typedef xsltTransformContext* xsltTransformContextPtr;

#define XML_ATTRIBUTE_NODE 2
#define XML_TEXT_NODE 3
#define XSLT_NAMESPACE ((const xmlChar *)"http://www.w3.org/1999/XSL/Transform")
#define BAD_CAST (xmlChar *)

struct _xmlNode {
    void* _private;
    int type;
    const xmlChar* name;
    struct _xmlNode* children;
    struct _xmlNode* last;
    struct _xmlNode* parent;
    struct _xmlNode* next;
    struct _xmlNode* prev;
    struct _xmlDoc* doc;
    xmlNs* ns;
    xmlChar* content;
    struct _xmlAttr* properties;
    void* psvi;
};

struct _xmlAttr {
    void* _private;
    int type;
    const xmlChar* name;
    struct _xmlNode* children;
    struct _xmlNode* last;
    struct _xmlNode* parent;
    struct _xmlAttr* next;
    struct _xmlAttr* prev;
    struct _xmlDoc* doc;
    xmlNs* ns;
    void* psvi;
};

struct _xmlNs {
    struct _xmlNs* next;
    const xmlChar* href;
    const xmlChar* prefix;
};

struct _xmlDoc {
    xmlDict* dict;
};

struct _xsltTransformContext {
    xmlDict* dict;
    int internalized;
};

int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
xmlChar* xmlStrdup(const xmlChar *cur);
void xmlFreeNodeList(xmlNodePtr cur);
xmlAttrPtr xmlNewNsProp(xmlNodePtr node, xmlNsPtr ns, const xmlChar* name, const xmlChar* value);
xmlNodePtr xmlNewText(const xmlChar* content);
const xmlChar* xmlDictLookup(xmlDict* dict, const xmlChar* name, int len);
void xsltTransformError(xsltTransformContextPtr ctxt, xmlNodePtr node, xmlNodePtr inst, const char *msg, ...);
xmlChar* xsltEvalAVT(xsltTransformContextPtr ctxt, void* avt, xmlNodePtr node);
xmlNsPtr xsltGetNamespace(xsltTransformContextPtr ctxt, xmlNodePtr node, xmlNsPtr ns, xmlNodePtr out);