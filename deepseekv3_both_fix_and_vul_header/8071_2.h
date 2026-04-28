#include <stdlib.h>

typedef struct _xmlXPathParserContext xmlXPathParserContext;
typedef xmlXPathParserContext *xmlXPathParserContextPtr;
typedef struct _xmlXPathObject xmlXPathObject;
typedef xmlXPathObject *xmlXPathObjectPtr;
typedef struct _xmlLocationSet xmlLocationSet;
typedef xmlLocationSet *xmlLocationSetPtr;
typedef struct _xmlNodeSet xmlNodeSet;
typedef xmlNodeSet *xmlNodeSetPtr;
typedef unsigned char xmlChar;

#define ATTRIBUTE_UNUSED
#define XP_ERROR(code)
#define CHECK_ARITY(n)
#define CHECK_TYPE(type)
#define CHECK_ERROR if (ctxt->error) return

typedef struct _xmlXPathContext {
    void *node;
    int contextSize;
    int proximityPosition;
} xmlXPathContext;

struct _xmlXPathParserContext {
    xmlXPathContext *context;
    const xmlChar *cur;
    xmlXPathObjectPtr value;
    int error;
};

struct _xmlXPathObject {
    int type;
    xmlNodeSetPtr nodesetval;
};

struct _xmlNodeSet {
    void **nodeTab;
    int nodeNr;
};

xmlXPathObjectPtr valuePop(xmlXPathParserContextPtr ctxt);
void valuePush(xmlXPathParserContextPtr ctxt, xmlXPathObjectPtr value);
xmlLocationSetPtr xmlXPtrLocationSetCreate(void *);
void xmlXPtrLocationSetAdd(xmlLocationSetPtr set, xmlXPathObjectPtr range);
xmlXPathObjectPtr xmlXPathNewNodeSet(void *node);
void xmlXPathEvalExpr(xmlXPathParserContextPtr ctxt);
void xmlXPathFreeObject(xmlXPathObjectPtr obj);
xmlXPathObjectPtr xmlXPtrNewRangeNodeObject(void *node, xmlXPathObjectPtr obj);
xmlXPathObjectPtr xmlXPtrWrapLocationSet(xmlLocationSetPtr set);