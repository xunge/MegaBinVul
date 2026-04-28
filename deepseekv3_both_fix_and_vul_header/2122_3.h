#include <stdio.h>

typedef unsigned char xmlChar;

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef struct _xmlNs xmlNs;
typedef xmlNs *xmlNsPtr;
typedef struct _xmlXPathParserContext xmlXPathParserContext;
typedef xmlXPathParserContext *xmlXPathParserContextPtr;
typedef struct _xmlXPathObject xmlXPathObject;
typedef xmlXPathObject *xmlXPathObjectPtr;
typedef struct _xmlXPathContext xmlXPathContext;
typedef struct _xmlNodeSet xmlNodeSet;
typedef xmlNodeSet *xmlNodeSetPtr;

#define XPATH_NODESET 1
#define XPATH_INVALID_TYPE 2
#define XPATH_INVALID_ARITY 3
#define XML_NAMESPACE_DECL 1

struct _xmlNode {
    int type;
    xmlDocPtr doc;
};

struct _xmlNs {
    void *context;
};

struct _xmlXPathParserContext {
    xmlXPathObjectPtr value;
    int error;
    struct {
        xmlNodePtr node;
        xmlDocPtr doc;
    } *context;
};

struct _xmlXPathObject {
    int type;
    xmlNodeSetPtr nodesetval;
};

struct _xmlNodeSet {
    int nodeNr;
    xmlNodePtr *nodeTab;
};

void xsltTransformError(void *ctx, void *node, void *elem, const char *msg, ...);
void *xsltXPathGetTransformContext(xmlXPathParserContextPtr ctxt);
xmlXPathObjectPtr valuePop(xmlXPathParserContextPtr ctxt);
void valuePush(xmlXPathParserContextPtr ctxt, xmlXPathObjectPtr value);
xmlXPathObjectPtr xmlXPathNewCString(const char *str);
xmlXPathObjectPtr xmlXPathNewString(const xmlChar *str);
void xmlXPathFreeObject(xmlXPathObjectPtr obj);
int xmlXPathCmpNodes(xmlNodePtr node1, xmlNodePtr node2);