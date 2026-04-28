#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;

typedef struct _xmlParserInput {
    const xmlChar *cur;
    const xmlChar *base;
} xmlParserInput;
typedef xmlParserInput *xmlParserInputPtr;

typedef struct _xmlURI {
    char *fragment;
} xmlURI;
typedef xmlURI *xmlURIPtr;

typedef struct _xmlEntity {
    xmlChar *orig;
} xmlEntity;
typedef xmlEntity *xmlEntityPtr;

typedef struct _xmlDoc {
    const xmlChar *version;
    int properties;
    void *intSubset;
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xmlSAXHandler {
    void (*entityDecl)(void *ctx, const xmlChar *name, int type, const xmlChar *publicId, const xmlChar *systemId, const xmlChar *content);
    void (*unparsedEntityDecl)(void *ctx, const xmlChar *name, const xmlChar *publicId, const xmlChar *systemId, const xmlChar *notationName);
    xmlEntityPtr (*getEntity)(void *ctx, const xmlChar *name);
    xmlEntityPtr (*getParameterEntity)(void *ctx, const xmlChar *name);
} xmlSAXHandler;
typedef xmlSAXHandler *xmlSAXHandlerPtr;

typedef struct _xmlParserCtxt {
    xmlParserInputPtr input;
    int instate;
    xmlSAXHandlerPtr sax;
    int disableSAX;
    void *userData;
    xmlDocPtr myDoc;
    int replaceEntities;
} xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;

#define CUR_PTR (ctxt->input->cur)
#define RAW (*CUR_PTR)
#define NEXT (ctxt->input->cur++)
#define CMP8(p, c1, c2, c3, c4, c5, c6, c7, c8) \
    (*(p) == c1 && *((p)+1) == c2 && *((p)+2) == c3 && *((p)+3) == c4 && \
     *((p)+4) == c5 && *((p)+5) == c6 && *((p)+6) == c7 && *((p)+7) == c8)
#define CMP5(p, c1, c2, c3, c4, c5) \
    (*(p) == c1 && *((p)+1) == c2 && *((p)+2) == c3 && *((p)+3) == c4 && *((p)+4) == c5)
#define SHRINK (ctxt->input->cur = ctxt->input->base)
#define SKIP(n) (ctxt->input->cur += (n))
#define SKIP_BLANKS (xmlSkipBlankChars(ctxt))
#define IS_BLANK_CH(c) (xmlIsBlankChar(c))
#define CUR (*ctxt->input->cur)

#define XML_PARSER_ENTITY_DECL 1
#define XML_PARSER_EOF 2
#define XML_ERR_SPACE_REQUIRED 1
#define XML_ERR_NAME_REQUIRED 2
#define XML_ERR_VALUE_REQUIRED 3
#define XML_ERR_INVALID_URI 4
#define XML_ERR_URI_FRAGMENT 5
#define XML_ERR_ENTITY_NOT_FINISHED 6
#define XML_ERR_ENTITY_BOUNDARY 7
#define XML_NS_ERR_COLON 8
#define XML_INTERNAL_PARAMETER_ENTITY 1
#define XML_EXTERNAL_PARAMETER_ENTITY 2
#define XML_INTERNAL_GENERAL_ENTITY 3
#define XML_EXTERNAL_GENERAL_PARSED_ENTITY 4
#define XML_DOC_INTERNAL 1
#define SAX_COMPAT_MODE (const xmlChar *)"1.0"
#define BAD_CAST (xmlChar *)

extern void xmlFatalErrMsg(xmlParserCtxtPtr ctxt, int error, const char *msg);
extern void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
extern void xmlFatalErrMsgStr(xmlParserCtxtPtr ctxt, int error, const char *msg, const xmlChar *str);
extern void xmlNsErr(xmlParserCtxtPtr ctxt, int error, const char *msg, const xmlChar *name, const xmlChar *extra1, const xmlChar *extra2);
extern void xmlErrMsgStr(xmlParserCtxtPtr ctxt, int error, const char *msg, const xmlChar *str);
extern void xmlErrMemory(xmlParserCtxtPtr ctxt, const char *msg);
extern xmlChar *xmlParseName(xmlParserCtxtPtr ctxt);
extern xmlChar *xmlParseEntityValue(xmlParserCtxtPtr ctxt, xmlChar **orig);
extern xmlChar *xmlParseExternalID(xmlParserCtxtPtr ctxt, xmlChar **literal, int external);
extern xmlURIPtr xmlParseURI(const char *str);
extern void xmlFreeURI(xmlURIPtr uri);
extern int xmlSkipBlankChars(xmlParserCtxtPtr ctxt);
extern int xmlIsBlankChar(int c);
extern xmlChar *xmlStrchr(const xmlChar *str, xmlChar val);
extern int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
extern xmlDocPtr xmlNewDoc(const xmlChar *version);
extern void *xmlNewDtd(xmlDocPtr doc, const xmlChar *name, const xmlChar *ExternalID, const xmlChar *SystemID);
extern void xmlSAX2EntityDecl(xmlParserCtxtPtr ctxt, const xmlChar *name, int type, const xmlChar *publicId, const xmlChar *systemId, const xmlChar *content);
extern xmlEntityPtr xmlSAX2GetEntity(xmlParserCtxtPtr ctxt, const xmlChar *name);
extern void xmlFree(void *ptr);