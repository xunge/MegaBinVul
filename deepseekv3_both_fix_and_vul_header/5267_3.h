#include <stdlib.h>

typedef unsigned char xmlChar;

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlDoc {
    xmlChar *URL;
    // 其他必要的字段...
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xsltStylesheet {
    struct _xsltStylesheet *parent;
    struct _xsltStylesheet *imports;
    struct _xsltStylesheet *next;
    xmlDocPtr doc;
    void *dict;
} xsltStylesheet;

typedef struct _xsltSecurityPrefs xsltSecurityPrefs;
typedef xsltStylesheet *xsltStylesheetPtr;
typedef xsltSecurityPrefs *xsltSecurityPrefsPtr;

#define XSLT_PARSE_OPTIONS 0
#define XSLT_LOAD_STYLESHEET 0

// 函数声明
xmlChar* xmlGetNsProp(xmlNodePtr node, const xmlChar* name, const xmlChar* ns);
void xsltTransformError(void* ctx, xsltStylesheetPtr style, xmlNodePtr node, const char* msg, ...);
xmlChar* xmlNodeGetBase(xmlDocPtr doc, xmlNodePtr node);
xmlChar* xmlBuildURI(const xmlChar* uri, const xmlChar* base);
int xmlStrEqual(const xmlChar* str1, const xmlChar* str2);
xsltSecurityPrefsPtr xsltGetDefaultSecurityPrefs(void);
int xsltCheckRead(xsltSecurityPrefsPtr sec, void* ctxt, const xmlChar* URL);
xmlDocPtr xsltDocDefaultLoader(const xmlChar* URI, void* dict, int options, void* ctxt, int type);
xsltStylesheetPtr xsltParseStylesheetImportedDoc(xmlDocPtr doc, xsltStylesheetPtr parent);
void xsltFixImportedCompSteps(xsltStylesheetPtr style, xsltStylesheetPtr import);
void xmlFreeDoc(xmlDocPtr doc);
void xmlFree(void* ptr);