#include <stdlib.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlEntity xmlEntity;
typedef xmlEntity *xmlEntityPtr;
typedef struct _xmlParserInput xmlParserInput;
typedef xmlParserInput *xmlParserInputPtr;
typedef struct _xmlChar xmlChar;
typedef const xmlChar *xmlCharPtr;
typedef struct _xmlSAXHandler xmlSAXHandler;
typedef xmlSAXHandler *xmlSAXHandlerPtr;

#define RAW (*ctxt->input->cur)
#define NEXT (ctxt->input->cur++)
#define CUR_PTR (ctxt->input->cur)
#define NXT(n) (ctxt->input->cur[n])
#define CMP5(p, c1, c2, c3, c4, c5) \
    ((p[0] == c1) && (p[1] == c2) && (p[2] == c3) && (p[3] == c4) && (p[4] == c5))
#define IS_BLANK_CH(c) ((c == 0x20) || (c == 0x9) || (c == 0xD) || (c == 0xA))

enum {
    XML_PARSER_EOF,
    XML_ERR_NAME_REQUIRED,
    XML_ERR_ENTITYREF_SEMICOL_MISSING,
    XML_ERR_UNDECLARED_ENTITY,
    XML_WAR_UNDECLARED_ENTITY,
    XML_ERR_UNSUPPORTED_ENCODING,
    XML_INTERNAL_PARAMETER_ENTITY,
    XML_EXTERNAL_PARAMETER_ENTITY,
    XML_PARSE_NOENT = 1 << 0,
    XML_PARSE_DTDVALID = 1 << 1,
    XML_PARSE_DTDLOAD = 1 << 2,
    XML_PARSE_DTDATTR = 1 << 3
};

struct _xmlParserCtxt {
    xmlParserInputPtr input;
    int instate;
    int standalone;
    int hasExternalSubset;
    int hasPErefs;
    int nbentities;
    int valid;
    int errNo;
    int options;
    int replaceEntities;
    int validate;
    void *userData;
    xmlSAXHandlerPtr sax;
};

struct _xmlEntity {
    int etype;
};

struct _xmlParserInput {
    unsigned char *cur;
    void (*free)(void*);
};

struct _xmlSAXHandler {
    xmlEntityPtr (*getParameterEntity)(void *ctx, const xmlChar *name);
};

xmlCharPtr xmlParseName(xmlParserCtxtPtr ctxt);
void xmlFatalErrMsg(xmlParserCtxtPtr ctxt, int code, const char *msg);
void xmlFatalErr(xmlParserCtxtPtr ctxt, int code, const char *msg);
void xmlFatalErrMsgStr(xmlParserCtxtPtr ctxt, int code, const char *msg, const xmlChar *str);
void xmlWarningMsg(xmlParserCtxtPtr ctxt, int code, const char *msg, const xmlChar *str, void *data);
void xmlParserEntityCheck(xmlParserCtxtPtr ctxt, int val1, void *ptr, int val2);
xmlParserInputPtr xmlNewBlanksWrapperInputStream(xmlParserCtxtPtr ctxt, xmlEntityPtr entity);
int xmlPushInput(xmlParserCtxtPtr ctxt, xmlParserInputPtr input);
xmlParserInputPtr xmlNewEntityInputStream(xmlParserCtxtPtr ctxt, xmlEntityPtr entity);
void xmlParseTextDecl(xmlParserCtxtPtr ctxt);
void xmlHaltParser(xmlParserCtxtPtr ctxt);
void deallocblankswrapper(void *ctx);