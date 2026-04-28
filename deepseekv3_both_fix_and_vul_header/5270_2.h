#include <stdlib.h>

typedef unsigned char xmlChar;

typedef struct _xmlDoc {
    xmlChar *URL;
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xsltDocument {
    xmlDocPtr doc;
    struct _xsltDocument *next;
} xsltDocument;
typedef xsltDocument *xsltDocumentPtr;

typedef struct _xsltStylesheet {
    xsltDocumentPtr docList;
    void *dict;
} xsltStylesheet;
typedef xsltStylesheet *xsltStylesheetPtr;

typedef struct _xsltSecurityPrefs xsltSecurityPrefs;
typedef xsltSecurityPrefs *xsltSecurityPrefsPtr;

#define XSLT_PARSE_OPTIONS 0
#define XSLT_LOAD_STYLESHEET 1

extern xsltSecurityPrefsPtr xsltGetDefaultSecurityPrefs(void);
extern int xsltCheckRead(xsltSecurityPrefsPtr sec, void *context, const xmlChar *URI);
extern void xsltTransformError(void *ctx, void *node, const char *msg, ...);
extern int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
extern xmlDocPtr xsltDocDefaultLoader(const xmlChar *URI, void *dict, int options, void *ctxt, int type);
extern xsltDocumentPtr xsltNewStyleDocument(xsltStylesheetPtr style, xmlDocPtr doc);