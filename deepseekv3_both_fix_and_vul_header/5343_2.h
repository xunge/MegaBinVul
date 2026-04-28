#include <stdlib.h>
#include <string.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlEntity xmlEntity;
typedef xmlEntity *xmlEntityPtr;
typedef struct _xmlParserInput xmlParserInput;
typedef xmlParserInput *xmlParserInputPtr;
typedef unsigned char xmlChar;
typedef enum {
    XML_PARSER_CDATA_SECTION,
    XML_PARSER_COMMENT,
    XML_PARSER_START_TAG,
    XML_PARSER_END_TAG,
    XML_PARSER_EOF,
    XML_PARSER_PROLOG,
    XML_PARSER_START,
    XML_PARSER_MISC,
    XML_PARSER_ENTITY_DECL,
    XML_PARSER_CONTENT,
    XML_PARSER_ATTRIBUTE_VALUE,
    XML_PARSER_PI,
    XML_PARSER_SYSTEM_LITERAL,
    XML_PARSER_PUBLIC_LITERAL,
    XML_PARSER_EPILOG,
    XML_PARSER_ENTITY_VALUE,
    XML_PARSER_DTD,
    XML_PARSER_IGNORE
} xmlParserState;

typedef enum {
    XML_ERR_PEREF_AT_EOF,
    XML_ERR_PEREF_IN_PROLOG,
    XML_ERR_PEREF_IN_EPILOG,
    XML_ERR_PEREF_NO_NAME,
    XML_ERR_UNDECLARED_ENTITY,
    XML_ERR_ENTITY_IS_PARAMETER,
    XML_ERR_PEREF_SEMICOL_MISSING,
    XML_WAR_UNDECLARED_ENTITY
} xmlParserErrors;

typedef enum {
    XML_INTERNAL_PARAMETER_ENTITY,
    XML_EXTERNAL_PARAMETER_ENTITY
} xmlEntityType;

typedef enum {
    XML_CHAR_ENCODING_NONE
} xmlCharEncoding;

#define XML_PARSE_NOENT 1
#define XML_PARSE_DTDVALID 2

#define RAW (*ctxt->input->cur)
#define NXT(i) (ctxt->input->cur[(i)])
#define CUR_PTR (ctxt->input->cur)
#define CMP5(p, c1, c2, c3, c4, c5) \
    ((p)[0] == (c1) && (p)[1] == (c2) && (p)[2] == (c3) && (p)[3] == (c4) && (p)[4] == (c5))
#define IS_BLANK_CH(c) ((c) == 0x20 || (c) == 0x9 || (c) == 0xD || (c) == 0xA)
#define NEXT (ctxt->input->cur++)
#define GROW

struct _xmlParserInput {
    const xmlChar *cur;
    const xmlChar *end;
    void (*free)(void *);
};

struct _xmlEntity {
    xmlEntityType etype;
};

struct _xmlSaxHandler {
    xmlEntityPtr (*getParameterEntity)(void *userData, const xmlChar *name);
};

struct _xmlValidCtxt {
    void (*error)(void *ctx, const char *msg, ...);
};

struct _xmlParserCtxt {
    xmlParserState instate;
    int external;
    int inputNr;
    struct _xmlParserInput *input;
    struct _xmlSaxHandler *sax;
    void *userData;
    int standalone;
    int hasExternalSubset;
    int hasPErefs;
    int validate;
    struct _xmlValidCtxt vctxt;
    int valid;
    int options;
};

extern int xmlParserDebugEntities;
extern void *xmlGenericErrorContext;
extern const xmlChar *xmlParseName(xmlParserCtxtPtr ctxt);
extern void xmlFatalErr(xmlParserCtxtPtr ctxt, xmlParserErrors error, const char *info);
extern void xmlFatalErrMsgStr(xmlParserCtxtPtr ctxt, xmlParserErrors error, const char *msg, const xmlChar *str);
extern void xmlValidityError(xmlParserCtxtPtr ctxt, xmlParserErrors error, const char *msg, const xmlChar *str, void *ctx);
extern void xmlWarningMsg(xmlParserCtxtPtr ctxt, xmlParserErrors error, const char *msg, const xmlChar *str, void *ctx);
extern xmlParserInputPtr xmlNewBlanksWrapperInputStream(xmlParserCtxtPtr ctxt, xmlEntityPtr entity);
extern int xmlPushInput(xmlParserCtxtPtr ctxt, xmlParserInputPtr input);
extern xmlParserInputPtr xmlNewEntityInputStream(xmlParserCtxtPtr ctxt, xmlEntityPtr entity);
extern xmlCharEncoding xmlDetectCharEncoding(const xmlChar *start, int len);
extern void xmlSwitchEncoding(xmlParserCtxtPtr ctxt, xmlCharEncoding enc);
extern void xmlParseTextDecl(xmlParserCtxtPtr ctxt);
extern void xmlGenericError(void *ctx, const char *msg, ...);
extern void deallocblankswrapper(void *ctx);