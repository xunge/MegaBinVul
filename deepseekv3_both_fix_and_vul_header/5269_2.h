#include <stddef.h>

typedef unsigned char xmlChar;
typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef struct _xsltStylesheet xsltStylesheet;
typedef xsltStylesheet *xsltStylesheetPtr;
typedef struct _xsltSecurityPrefs xsltSecurityPrefs;
typedef xsltSecurityPrefs *xsltSecurityPrefsPtr;
typedef struct _xsltTransformContext xsltTransformContext;
typedef xsltTransformContext *xsltTransformContextPtr;
typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlDict xmlDict;
typedef xmlDict *xmlDictPtr;

typedef enum {
    XSLT_LOAD_START
} xsltLoadType;

#define XSLT_PARSE_OPTIONS 0
#define WITH_XSLT_DEBUG_PARSING

extern void *xsltGenericDebugContext;
extern void xsltGenericDebug(void *ctx, const char *msg, ...);
extern void xsltInitGlobals(void);
extern xsltSecurityPrefsPtr xsltGetDefaultSecurityPrefs(void);
extern int xsltCheckRead(xsltSecurityPrefsPtr sec, xsltTransformContextPtr ctxt, const xmlChar *URL);
extern void xsltTransformError(xsltTransformContextPtr ctxt, xsltStylesheetPtr style, xmlNodePtr node, const char *message, ...);
extern xmlDocPtr xsltDocDefaultLoader(const xmlChar *URI, xmlDictPtr dict, int options, void *ctxt, xsltLoadType type);
extern xsltStylesheetPtr xsltParseStylesheetDoc(xmlDocPtr doc);
extern void xmlFreeDoc(xmlDocPtr doc);