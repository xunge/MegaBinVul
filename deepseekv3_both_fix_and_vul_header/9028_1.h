#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;

struct _xmlError {
    int code;
};

struct _xmlEntity {
    int checked;
    int etype;
    xmlChar *content;
    xmlChar *name;
};

struct _xmlParserCtxt {
    int depth;
    int options;
    struct _xmlError lastError;
    int nbentities;
};

typedef struct _xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlEntity *xmlEntityPtr;

#define XML_PARSER_BIG_BUFFER_SIZE 1024
#define XML_PARSER_BUFFER_SIZE 1024
#define XML_PARSE_HUGE (1<<15)
#define XML_SUBSTITUTE_REF 1
#define XML_SUBSTITUTE_PEREF 2
#define XML_INTERNAL_PREDEFINED_ENTITY 1
#define XML_ERR_ENTITY_LOOP 1
#define XML_ERR_INTERNAL_ERROR 2

#define CUR_SCHAR(p, l) (*(p))
#define COPY_BUF(l,b,n,c) (b[n++] = c)

extern void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
extern void xmlFatalErrMsg(xmlParserCtxtPtr ctxt, int error, const char *msg);
extern void xmlErrMemory(xmlParserCtxtPtr ctxt, const char *msg);
extern void xmlGenericError(void *ctx, const char *msg, ...);
extern void *xmlGenericErrorContext;
extern int xmlParserDebugEntities;
extern xmlChar *xmlMallocAtomic(size_t size);
extern void xmlFree(void *ptr);
extern int xmlParserEntityCheck(xmlParserCtxtPtr ctxt, size_t size, xmlEntityPtr ent, int flags);
extern void xmlLoadEntityContent(xmlParserCtxtPtr ctxt, xmlEntityPtr ent);
extern int xmlParseStringCharRef(xmlParserCtxtPtr ctxt, const xmlChar **str);
extern xmlEntityPtr xmlParseStringEntityRef(xmlParserCtxtPtr ctxt, const xmlChar **str);
extern xmlEntityPtr xmlParseStringPEReference(xmlParserCtxtPtr ctxt, const xmlChar **str);
extern xmlChar *xmlStringDecodeEntities(xmlParserCtxtPtr ctxt, const xmlChar *str, int what, xmlChar end, xmlChar end2, xmlChar end3);
extern size_t xmlStrlen(const xmlChar *str);
extern void growBuffer(xmlChar *buffer, size_t size);