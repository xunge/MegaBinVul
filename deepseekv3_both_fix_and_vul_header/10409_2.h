#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned char xmlChar;

struct _xmlNode {
    xmlChar *content;
};
typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;

struct _xsltTransformContext {
    xmlChar *lasttext;
    int lasttuse;
    int lasttsize;
};
typedef struct _xsltTransformContext xsltTransformContext;
typedef xsltTransformContext *xsltTransformContextPtr;

void xsltTransformError(xsltTransformContextPtr ctxt, void *node, xmlNodePtr target, const char *msg);
void *xmlRealloc(void *ptr, size_t size);
size_t xmlStrlen(const xmlChar *str);
void xmlNodeAddContent(xmlNodePtr node, const xmlChar *content);