#include <stddef.h>

typedef struct _xmlDoc {
    unsigned char *URL;
    void *children;
} xmlDoc;

typedef struct _xsltDocument {
    xmlDoc *doc;
    unsigned char *URL;
    struct _xsltDocument *next;
} *xsltDocumentPtr;

typedef struct _xsltTransformContext {
    void *sec;
    xsltDocumentPtr docList;
    void *dict;
    int parserOptions;
    int xinclude;
    int debugStatus;
} *xsltTransformContextPtr;

typedef xmlDoc *xmlDocPtr;
typedef unsigned char xmlChar;

#define XSLT_LOAD_DOCUMENT 0
#define XSLT_DEBUG_NONE 0
#define LIBXML_XINCLUDE_ENABLED
#define LIBXML_VERSION 20603

int xsltCheckRead(void *sec, xsltTransformContextPtr ctxt, const xmlChar *URI);
void xsltTransformError(xsltTransformContextPtr ctxt, void *node, void *inst, const char *msg, ...);
int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
xmlDocPtr xsltDocDefaultLoader(const xmlChar *URI, void *dict, int options, void *ctxt, int type);
void xmlXIncludeProcessFlags(xmlDocPtr doc, int options);
void xmlXIncludeProcess(xmlDocPtr doc);
int xsltNeedElemSpaceHandling(xsltTransformContextPtr ctxt);
void xsltApplyStripSpaces(xsltTransformContextPtr ctxt, void *node);
void *xmlDocGetRootElement(xmlDocPtr doc);
void xmlXPathOrderDocElems(xmlDocPtr doc);
xsltDocumentPtr xsltNewDocument(xsltTransformContextPtr ctxt, xmlDocPtr doc);