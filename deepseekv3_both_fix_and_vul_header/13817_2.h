#include <stddef.h>

typedef struct _xmlNode {
    int type;
    struct _xmlNode *parent;
} xmlNode;

typedef struct _xmlXPathContext {
    xmlNode *node;
} xmlXPathContext;

typedef struct _xmlXPathParserContext {
    xmlXPathContext *context;
} xmlXPathParserContext;

typedef struct _xsltTransformContext {
    xmlXPathContext *xpathCtxt;
} xsltTransformContext;

typedef struct _xsltCompMatch {
    // 占位结构体
} xsltCompMatch;

typedef xmlNode *xmlNodePtr;
typedef xmlXPathParserContext *xmlXPathParserContextPtr;
typedef xsltTransformContext *xsltTransformContextPtr;
typedef xsltCompMatch *xsltCompMatchPtr;

#define XML_DOCUMENT_NODE 1

// 函数声明
xmlXPathParserContextPtr xmlXPathNewParserContext(void *a, xmlXPathContext *b);
xmlNodePtr xmlXPathNextAncestor(xmlXPathParserContextPtr a, xmlNodePtr b);
xmlNodePtr xmlXPathNextPrecedingSibling(xmlXPathParserContextPtr a, xmlNodePtr b);
void xmlXPathFreeParserContext(xmlXPathParserContextPtr a);
int xsltTestCompMatchList(xsltTransformContextPtr a, xmlNodePtr b, xsltCompMatchPtr c);
int xsltTestCompMatchCount(xsltTransformContextPtr a, xmlNodePtr b, xsltCompMatchPtr c, xmlNodePtr d);