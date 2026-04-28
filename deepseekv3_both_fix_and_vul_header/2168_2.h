#include <string.h>
#include <stdlib.h>

typedef unsigned char xmlChar;
#define BAD_CAST (xmlChar *)
#define XSLT_NAMESPACE ((const xmlChar *) "http://www.w3.org/1999/XSL/Transform")
#define XML_TEXT_NODE 3
#define XSLT_REFACTORED
#define xsltXSLTAttrMarker ((void *)1)

typedef struct _xmlNs xmlNs;
typedef xmlNs *xmlNsPtr;

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlAttr xmlAttr;
typedef xmlAttr *xmlAttrPtr;

typedef struct _xmlDict xmlDict;
typedef struct _xmlDoc xmlDoc;

struct _xmlNs {
    xmlChar *href;
    xmlChar *prefix;
};

struct _xmlNode {
    int type;
    xmlChar *content;
    xmlNodePtr next;
    xmlNodePtr parent;
    xmlAttrPtr properties;
    xmlDoc *doc;
    xmlDict *dict;
};

struct _xmlAttr {
    void *psvi;
    xmlNsPtr ns;
    xmlChar *name;
    xmlNodePtr children;
    xmlNodePtr parent;
    xmlAttrPtr next;
    xmlAttrPtr prev;
    xmlAttrPtr last;
    xmlDoc *doc;
};

struct _xmlDoc {
    xmlDict *dict;
};

typedef struct _xsltTransformContext {
    xmlNodePtr insert;
    xmlDict *dict;
    int internalized;
    xmlNodePtr node;
} xsltTransformContext;
typedef xsltTransformContext *xsltTransformContextPtr;

xmlChar *xmlStrdup(const xmlChar *cur);
int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
xmlChar *xmlDictLookup(xmlDict *dict, const xmlChar *name, int len);
xmlAttrPtr xmlNewDocProp(xmlDoc *doc, const xmlChar *name, const xmlChar *value);
xmlNodePtr xmlNewText(const xmlChar *content);
int xmlIsID(xmlDoc *doc, xmlNodePtr elem, xmlAttrPtr attr);
void xmlAddID(xmlDoc *doc, xmlDoc *doc2, xmlChar *value, xmlAttrPtr attr);
void xsltTransformError(xsltTransformContextPtr ctxt, xmlNodePtr node, xmlNodePtr inst, const char *message, ...);
xmlChar *xsltEvalAVT(xsltTransformContextPtr ctxt, void *avt, xmlNodePtr node);
xmlNsPtr xsltGetSpecialNamespace(xsltTransformContextPtr ctxt, xmlNodePtr node, const xmlChar *href, const xmlChar *prefix, xmlNodePtr target);
xmlNsPtr xsltGetNamespace(xsltTransformContextPtr ctxt, xmlNodePtr node, xmlNsPtr ns, xmlNodePtr target);
void xsltApplyAttributeSet(xsltTransformContextPtr ctxt, xmlNodePtr node, xmlNodePtr inst, xmlNodePtr insert);