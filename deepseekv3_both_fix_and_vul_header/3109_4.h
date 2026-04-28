#include <stddef.h>

#define XML_PARSE_DTDLOAD (1<<1)

typedef unsigned char xmlChar;

typedef struct _xmlSAXHandler {
    void (*ignorableWhitespace)(void *ctx, const xmlChar *ch, int len);
    void (*comment)(void *ctx, const xmlChar *value);
    void (*warning)(void *ctx, const char *msg, ...);
    void (*error)(void *ctx, const char *msg, ...);
} xmlSAXHandler;

typedef struct _xmlParserCtxt {
    int keepBlanks;
    int options;
    int wellFormed;
    char *directory;
    struct _xmlDoc *myDoc;
    xmlSAXHandler *sax;
} xmlParserCtxt;

typedef struct _xmlDoc {
    xmlChar *URL;
} xmlDoc;

typedef struct _xmlNode {
    // basic node structure
} xmlNode;

typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef xmlDoc *xmlDocPtr;
typedef xmlNode *xmlNodePtr;
typedef int zend_bool;

#define TSRMLS_DC
#define PG(name) name
zend_bool allow_url_fopen;

void soap_ignorableWhitespace(void *ctx, const xmlChar *ch, int len);
void soap_Comment(void *ctx, const xmlChar *value);
void cleanup_xml_node(xmlNodePtr node);
xmlParserCtxtPtr xmlCreateFileParserCtxt(const char *filename);
void xmlParseDocument(xmlParserCtxtPtr ctxt);
void xmlFreeDoc(xmlDocPtr doc);
void xmlFreeParserCtxt(xmlParserCtxtPtr ctxt);
xmlChar *xmlCharStrdup(const char *cur);