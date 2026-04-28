#include <stdlib.h>

typedef unsigned char xmlChar;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlSAXHandler xmlSAXHandler;

struct _xmlValidCtxt {
    void (*warning)(void *ctx, const char *msg, ...);
    void (*error)(void *ctx, const char *msg, ...);
};

struct _xmlSAXHandler {
    void (*ignorableWhitespace)(void *ctx, const xmlChar *ch, int len);
    void (*warning)(void *ctx, const char *msg, ...);
    void (*error)(void *ctx, const char *msg, ...);
    void (*fatalError)(void *ctx, const char *msg, ...);
    void (*startElement)(void *ctx, const xmlChar *name, const xmlChar **atts);
    void (*endElement)(void *ctx, const xmlChar *name);
    void (*startElementNs)(void *ctx, const xmlChar *localname, const xmlChar *prefix, const xmlChar *URI, int nb_namespaces, const xmlChar **namespaces, int nb_attributes, int nb_defaulted, const xmlChar **attributes);
    void (*endElementNs)(void *ctx, const xmlChar *localname, const xmlChar *prefix, const xmlChar *URI);
    int initialized;
    void (*cdataBlock)(void *ctx, const xmlChar *value, int len);
};

struct _xmlParserCtxt {
    const xmlChar *encoding;
    int recovery;
    int options;
    int loadsubset;
    int replaceEntities;
    int pedantic;
    int keepBlanks;
    int validate;
    struct _xmlValidCtxt vctxt;
    xmlSAXHandler *sax;
    int dictNames;
    void *dict;
    int linenumbers;
};

#define XML_PARSE_RECOVER 1
#define XML_PARSE_DTDLOAD 2
#define XML_PARSE_DTDATTR 4
#define XML_PARSE_NOENT 8
#define XML_PARSE_PEDANTIC 16
#define XML_PARSE_NOBLANKS 32
#define XML_PARSE_DTDVALID 64
#define XML_PARSE_NOWARNING 128
#define XML_PARSE_NOERROR 256
#define XML_PARSE_SAX1 512
#define XML_PARSE_NODICT 1024
#define XML_PARSE_NOCDATA 2048
#define XML_PARSE_NSCLEAN 4096
#define XML_PARSE_NONET 8192
#define XML_PARSE_COMPACT 16384
#define XML_PARSE_OLD10 32768
#define XML_PARSE_NOBASEFIX 65536
#define XML_PARSE_HUGE 131072
#define XML_PARSE_OLDSAX 262144
#define XML_PARSE_IGNORE_ENC 524288
#define XML_PARSE_BIG_LINES 1048576

#define XML_DETECT_IDS 1
#define XML_COMPLETE_ATTRS 2

void *xmlFree(void *mem);
xmlChar *xmlStrdup(const xmlChar *cur);
void xmlDictSetLimit(void *dict, size_t limit);
void xmlSAX2IgnorableWhitespace(void *ctx, const xmlChar *ch, int len);
void xmlSAX2StartElement(void *ctx, const xmlChar *name, const xmlChar **atts);
void xmlSAX2EndElement(void *ctx, const xmlChar *name);