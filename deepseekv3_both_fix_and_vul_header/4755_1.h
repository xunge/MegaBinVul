#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlEntity xmlEntity;
typedef xmlEntity *xmlEntityPtr;

#define XML_PARSER_BIG_BUFFER_SIZE 1024
#define XML_PARSER_BUFFER_SIZE 1024
#define XML_SUBSTITUTE_REF 1
#define XML_SUBSTITUTE_PEREF 2
#define XML_PARSE_HUGE (1 << 19)
#define XML_PARSE_NOENT (1 << 1)
#define XML_PARSE_DTDVALID (1 << 3)
#define XML_INTERNAL_PREDEFINED_ENTITY 1

extern int xmlParserDebugEntities;

#define CUR_SCHAR(str, l) (*(str))
#define COPY_BUF(l, buf, n, c) (buf[n++] = c)

enum {
    XML_ERR_ENTITY_LOOP,
    XML_ERR_INTERNAL_ERROR,
    XML_ERR_ENTITY_PROCESSING
};

struct _xmlParserCtxt {
    int depth;
    int options;
    int validate;
    struct {
        int code;
    } lastError;
    int nbentities;
};

struct _xmlEntity {
    int checked;
    int etype;
    xmlChar *name;
    xmlChar *content;
};

extern void *xmlMallocAtomic(size_t size);
extern void xmlFree(void *ptr);
extern void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
extern void xmlFatalErrMsg(xmlParserCtxtPtr ctxt, int error, const char *msg);
extern void xmlErrMemory(xmlParserCtxtPtr ctxt, const char *msg);
extern void xmlWarningMsg(xmlParserCtxtPtr ctxt, int error, const char *msg, const char *arg1, void *arg2);
extern int xmlParseStringCharRef(xmlParserCtxtPtr ctxt, const xmlChar **str);
extern xmlEntityPtr xmlParseStringEntityRef(xmlParserCtxtPtr ctxt, const xmlChar **str);
extern xmlEntityPtr xmlParseStringPEReference(xmlParserCtxtPtr ctxt, const xmlChar **str);
extern int xmlParserEntityCheck(xmlParserCtxtPtr ctxt, size_t size, xmlEntityPtr ent, int flag);
extern void xmlLoadEntityContent(xmlParserCtxtPtr ctxt, xmlEntityPtr ent);
extern xmlChar *xmlStringDecodeEntities(xmlParserCtxtPtr ctxt, const xmlChar *str, int what, xmlChar end, xmlChar end2, xmlChar end3);
extern int xmlStrlen(const xmlChar *str);
extern void xmlGenericError(void *ctx, const char *msg, ...);
extern void *xmlGenericErrorContext;

static void growBuffer(xmlChar *buffer, size_t size) {}