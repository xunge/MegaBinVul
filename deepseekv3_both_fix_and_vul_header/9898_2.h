#include <stdio.h>

typedef struct _xmlNode {
    int type;
    struct _xmlDoc *doc;
} xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlDoc {
    // minimal doc structure
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xmlNs {
    struct _xmlDoc *context;
} xmlNs;
typedef xmlNs *xmlNsPtr;

typedef unsigned char xmlChar;

typedef struct _xmlXPathContext {
    xmlNodePtr node;
    xmlDocPtr doc;
} xmlXPathContext;

typedef struct _xmlXPathParserContext {
    struct _xmlXPathContext *context;
    struct _xmlXPathObject *value;
    int error;
} xmlXPathParserContext;
typedef xmlXPathParserContext *xmlXPathParserContextPtr;

typedef struct _xmlXPathObject {
    int type;
    struct _xmlNodeSet *nodesetval;
} xmlXPathObject;
typedef xmlXPathObject *xmlXPathObjectPtr;

typedef struct _xmlNodeSet {
    int nodeNr;
    xmlNodePtr *nodeTab;
} xmlNodeSet;
typedef xmlNodeSet *xmlNodeSetPtr;

#define XPATH_NODESET 1
#define XPATH_INVALID_TYPE 2
#define XPATH_INVALID_ARITY 3
#define XML_NAMESPACE_DECL 1

void xsltTransformError(void *ctx, void *a, void *b, const char *msg, ...);
void *xsltXPathGetTransformContext(xmlXPathParserContextPtr ctxt);
xmlXPathObjectPtr valuePop(xmlXPathParserContextPtr ctxt);
void valuePush(xmlXPathParserContextPtr ctxt, xmlXPathObjectPtr val);
xmlXPathObjectPtr xmlXPathNewCString(const char *str);
xmlXPathObjectPtr xmlXPathNewString(const xmlChar *str);
void xmlXPathFreeObject(xmlXPathObjectPtr obj);
int xmlXPathCmpNodes(xmlNodePtr node1, xmlNodePtr node2);