#include <stdlib.h>
#include <stddef.h>

typedef struct _xmlParserCtxt {
    int options;
    struct _xmlSAXHandler *sax;
    int wellFormed;
    char *directory;
    struct _xmlDoc *myDoc;
} xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;

typedef struct _xmlDoc {
    char *URL;
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xmlSAXHandler {
    void (*ignorableWhitespace)(void *ctx, const char *ch, int len);
    void (*comment)(void *ctx, const char *value);
    void (*warning)(void *ctx, const char *msg, ...);
    void (*error)(void *ctx, const char *msg, ...);
} xmlSAXHandler;

typedef unsigned char xmlChar;
typedef int zend_bool;

#define XML_PARSE_DTDLOAD 1
#define XML_PARSE_HUGE 2
#define LIBXML_VERSION 20703

void soap_ignorableWhitespace(void *ctx, const xmlChar *ch, int len);
void soap_Comment(void *ctx, const xmlChar *value);
xmlParserCtxtPtr xmlCreateMemoryParserCtxt(const void *buf, size_t buf_size);
void xmlParseDocument(xmlParserCtxtPtr ctxt);
void xmlFreeDoc(xmlDocPtr cur);
void xmlFreeParserCtxt(xmlParserCtxtPtr ctxt);
xmlChar *xmlCharStrdup(const char *cur);
zend_bool php_libxml_disable_entity_loader(zend_bool disable);