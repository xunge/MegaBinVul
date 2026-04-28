#include <stdlib.h>

struct _xmlNode {
    int type;
    const char *name;
    struct _xmlNs *ns;
    struct _xmlNode *next;
    struct _xmlNode *prev;
    struct _xmlNode *parent;
    struct _xmlNode *children;
    struct _xmlDoc *doc;
};

struct _xmlNs {
    const char *href;
    struct _xmlNs *next;
};

struct _xmlXPathContext {
    struct _xmlNode *node;
};

struct _xmlXPathParserContext {
    struct _xmlXPathContext *context;
};

struct _xsltTransformContext {
    struct _xmlXPathContext *xpathCtxt;
};

struct _xsltCompMatch {
    int dummy;
};

typedef struct _xmlNode xmlNode;
typedef struct _xmlNs xmlNs;
typedef struct _xmlXPathContext xmlXPathContext;
typedef struct _xmlXPathParserContext xmlXPathParserContext;
typedef struct _xsltTransformContext xsltTransformContext;
typedef struct _xsltCompMatch xsltCompMatch;

typedef xmlNode* xmlNodePtr;
typedef xmlNs* xmlNsPtr;
typedef xmlXPathContext* xmlXPathContextPtr;
typedef xmlXPathParserContext* xmlXPathParserContextPtr;
typedef xsltTransformContext* xsltTransformContextPtr;
typedef xsltCompMatch* xsltCompMatchPtr;

enum {
    XML_DOCUMENT_NODE = 1
};

int xmlStrEqual(const char *str1, const char *str2);
xmlXPathParserContextPtr xmlXPathNewParserContext(const char *str, xmlXPathContextPtr ctx);
xmlNodePtr xmlXPathNextAncestor(xmlXPathParserContextPtr parser, xmlNodePtr node);
xmlNodePtr xmlXPathNextPrecedingSibling(xmlXPathParserContextPtr parser, xmlNodePtr node);
void xmlXPathFreeParserContext(xmlXPathParserContextPtr parser);
int xsltTestCompMatchList(xsltTransformContextPtr context, xmlNodePtr node, xsltCompMatchPtr pat);