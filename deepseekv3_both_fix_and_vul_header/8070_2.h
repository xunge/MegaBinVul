#include <stddef.h>

typedef struct _xmlXPathContext {
    int xptr;
    void *here;
    void *origin;
} xmlXPathContext;
typedef xmlXPathContext *xmlXPathContextPtr;

typedef struct _xmlDoc {} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xmlNode {} xmlNode;
typedef xmlNode *xmlNodePtr;

typedef unsigned char xmlChar;

xmlXPathContextPtr xmlXPathNewContext(xmlDocPtr doc);
void xmlXPathRegisterFunc(xmlXPathContextPtr ctxt, const xmlChar *name, void *f);

void xmlXPtrRangeToFunction(void *ctxt, int nargs);
void xmlXPtrRangeFunction(void *ctxt, int nargs);
void xmlXPtrRangeInsideFunction(void *ctxt, int nargs);
void xmlXPtrStringRangeFunction(void *ctxt, int nargs);
void xmlXPtrStartPointFunction(void *ctxt, int nargs);
void xmlXPtrEndPointFunction(void *ctxt, int nargs);
void xmlXPtrHereFunction(void *ctxt, int nargs);
void xmlXPtrOriginFunction(void *ctxt, int nargs);