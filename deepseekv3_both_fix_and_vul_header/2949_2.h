#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;

typedef struct _xmlNode xmlNode;
struct _xmlNode {
    void *doc;
    // other members omitted
};
typedef xmlNode *xmlNodePtr;

typedef struct _xmlNs xmlNs;
typedef xmlNs *xmlNsPtr;

#define IS_BLANK_CH(c) ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\r'))

typedef struct _xsltKeyDef {
    const xmlChar *name;
    const xmlChar *nameURI;
    xmlChar *match;
    xmlChar *use;
    xmlNodePtr inst;
    xmlNsPtr *nsList;
    int nsNr;
    void *comp;
    void *usecomp;
    struct _xsltKeyDef *next;
} xsltKeyDef, *xsltKeyDefPtr;

typedef struct _xsltStylesheet {
    xsltKeyDefPtr keys;
    int errors;
} xsltStylesheet, *xsltStylesheetPtr;

xmlChar *xmlStrdup(const xmlChar *cur);
xmlChar *xmlStrcat(xmlChar *cur, const xmlChar *add);
xmlChar *xmlStrncat(xmlChar *cur, const xmlChar *add, int len);
void xmlFree(void *ptr);
xmlNsPtr *xmlGetNsList(xmlNodePtr doc, xmlNodePtr node);
int skipPredicate(const xmlChar *pattern, int start);
xsltKeyDefPtr xsltNewKeyDef(const xmlChar *name, const xmlChar *nameURI);
void xsltTransformError(void *ctx, xsltStylesheetPtr style, xmlNodePtr node, const char *msg, ...);
void *xsltXPathCompile(xsltStylesheetPtr style, const xmlChar *str);
void *xsltXPathCompileFlags(xsltStylesheetPtr style, const xmlChar *str, int flags);