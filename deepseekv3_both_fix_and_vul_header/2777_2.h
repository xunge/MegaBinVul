#include <stddef.h>

typedef struct _xmlSAXHandler {
    void (*ignorableWhitespace)(void *ctx, const char *ch, int len);
    void (*comment)(void *ctx, const char *msg);
    void (*warning)(void *ctx, const char *msg);
    void (*error)(void *ctx, const char *msg);
} xmlSAXHandler;

typedef struct _xmlParserCtxt {
    int keepBlanks;
    int options;
    xmlSAXHandler *sax;
    int wellFormed;
    struct _xmlDoc *myDoc;
    char *directory;
} xmlParserCtxt;

typedef struct _xmlDoc {
    char *URL;
} xmlDoc;

typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef xmlDoc *xmlDocPtr;
typedef void *xmlNodePtr;

typedef int zend_bool;

#define TSRMLS_DC
#define PG(x) (x)
#define XML_PARSE_DTDLOAD (1 << 1)

extern int allow_url_fopen;
extern void soap_ignorableWhitespace(void *ctx, const char *ch, int len);
extern void soap_Comment(void *ctx, const char *msg);
extern void cleanup_xml_node(xmlNodePtr node);
extern xmlParserCtxtPtr xmlCreateFileParserCtxt(const char *filename);
extern void xmlFreeParserCtxt(xmlParserCtxtPtr ctxt);
extern void xmlParseDocument(xmlParserCtxtPtr ctxt);
extern void xmlFreeDoc(xmlDocPtr doc);
extern char *xmlCharStrdup(const char *cur);