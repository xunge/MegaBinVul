#include <stdlib.h>
#include <string.h>

typedef int zend_bool;
#define TSRMLS_DC
#define PG(x) (x)
int allow_url_fopen;

#define XML_PARSE_DTDLOAD (1 << 1)

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlSAXHandler xmlSAXHandler;

struct _xmlParserCtxt {
    int keepBlanks;
    int options;
    xmlSAXHandler *sax;
    int wellFormed;
    xmlDocPtr myDoc;
    char *directory;
};

struct _xmlDoc {
    char *URL;
};

struct _xmlSAXHandler {
    void (*ignorableWhitespace)(void*, const char*, int);
    void (*comment)(void*, const char*);
    void (*warning)(void*, const char*, ...);
    void (*error)(void*, const char*, ...);
};

void soap_ignorableWhitespace(void *ctx, const char *ch, int len);
void soap_Comment(void *ctx, const char *value);
void cleanup_xml_node(xmlNodePtr node);
xmlParserCtxtPtr xmlCreateFileParserCtxt(const char *filename);
void xmlParseDocument(xmlParserCtxtPtr ctxt);
void xmlFreeDoc(xmlDocPtr doc);
void xmlFreeParserCtxt(xmlParserCtxtPtr ctxt);
char *xmlCharStrdup(const char *cur);