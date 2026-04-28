#include <stdlib.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt* xmlParserCtxtPtr;
typedef struct _xmlDoc xmlDoc;
typedef xmlDoc* xmlDocPtr;
typedef char xmlChar;
typedef void (*xmlSAXHandler)(void);

#define XML_PARSE_DTDLOAD 1
#define XML_PARSE_HUGE 2
#define LIBXML_VERSION 20703

struct _xmlParserCtxt {
    int options;
    struct _xmlSAXHandler* sax;
    int wellFormed;
    xmlDocPtr myDoc;
    char* directory;
};

struct _xmlDoc {
    xmlChar* URL;
};

struct _xmlSAXHandler {
    void (*ignorableWhitespace)(void* ctx, const xmlChar* ch, int len);
    void (*comment)(void* ctx, const xmlChar* msg);
    void (*warning)(void* ctx, const char* msg, ...);
    void (*error)(void* ctx, const char* msg, ...);
};

void soap_ignorableWhitespace(void* ctx, const xmlChar* ch, int len);
void soap_Comment(void* ctx, const xmlChar* msg);

xmlParserCtxtPtr xmlCreateMemoryParserCtxt(const void* buf, size_t buf_size);
void xmlParseDocument(xmlParserCtxtPtr ctxt);
void xmlFreeDoc(xmlDocPtr doc);
void xmlFreeParserCtxt(xmlParserCtxtPtr ctxt);
xmlChar* xmlCharStrdup(const char* cur);