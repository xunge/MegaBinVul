#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;

typedef struct _xmlNode {
    int type;
    struct _xmlNode *parent;
    struct _xmlDoc *doc;
} xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlAttr {
    xmlNode node;
    xmlNodePtr parent;
} xmlAttr;
typedef xmlAttr *xmlAttrPtr;

typedef struct _xmlDoc {
    xmlChar *URL;
} xmlDoc;

typedef struct _xmlNs xmlNs;

typedef struct _xmlXPathContext xmlXPathContext;

typedef struct _xmlNodeSet {
    int nodeNr;
    xmlNodePtr *nodeTab;
} xmlNodeSet;

typedef struct _xmlXPathObject {
    int type;
    xmlNodeSet *nodesetval;
    xmlChar *stringval;
} xmlXPathObject;
typedef xmlXPathObject *xmlXPathObjectPtr;

typedef struct _xmlXPathParserContext {
    xmlXPathContext *context;
    xmlXPathObjectPtr value;
    int error;
} xmlXPathParserContext;
typedef xmlXPathParserContext *xmlXPathParserContextPtr;

typedef struct _xsltStylesheet {
    xmlDoc *doc;
    xmlChar *URL;
} xsltStylesheet;

typedef struct _xsltTransformContext {
    xsltStylesheet *style;
    xmlNodePtr inst;
} xsltTransformContext;
typedef xsltTransformContext *xsltTransformContextPtr;

#define XPATH_INVALID_ARITY 1
#define XPATH_INVALID_TYPE 2
#define XPATH_NODESET 1
#define XPATH_STRING 2
#define XML_ELEMENT_NODE 1
#define XML_TEXT_NODE 3
#define XML_CDATA_SECTION_NODE 4
#define XML_PI_NODE 7
#define XML_COMMENT_NODE 8
#define XML_ATTRIBUTE_NODE 2

#define IS_XSLT_REAL_NODE(n) \
    (((n)->type == XML_ELEMENT_NODE) || \
     ((n)->type == XML_TEXT_NODE) || \
     ((n)->type == XML_CDATA_SECTION_NODE) || \
     ((n)->type == XML_PI_NODE) || \
     ((n)->type == XML_COMMENT_NODE) || \
     ((n)->type == XML_ATTRIBUTE_NODE))

void xsltTransformError(xsltTransformContextPtr ctx, xmlNodePtr node, const char *msg, ...);
xsltTransformContextPtr xsltXPathGetTransformContext(xmlXPathParserContextPtr ctxt);
xmlXPathObjectPtr valuePop(xmlXPathParserContextPtr ctxt);
void valuePush(xmlXPathParserContextPtr ctxt, xmlXPathObjectPtr value);
void xmlXPathStringFunction(xmlXPathParserContextPtr ctxt, int nargs);
xmlXPathObjectPtr xmlXPathNewNodeSet(xmlNodePtr node);
xmlXPathObjectPtr xmlXPathObjectCopy(xmlXPathObjectPtr obj);
void xmlXPathFreeObject(xmlXPathObjectPtr obj);
xmlChar *xmlNodeGetBase(xmlDoc *doc, xmlNodePtr node);
xmlChar *xmlBuildURI(const xmlChar *URI, const xmlChar *base);
void xmlFree(void *ptr);
int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
void xsltDocumentFunctionLoadDocument(xmlXPathParserContextPtr ctxt, xmlChar *URI);
xmlNodeSet *xmlXPathNodeSetMerge(xmlNodeSet *set1, xmlNodeSet *set2);