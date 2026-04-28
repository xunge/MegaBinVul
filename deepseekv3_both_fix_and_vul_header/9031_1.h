#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlSAXHandler xmlSAXHandler;
typedef struct _xmlSAXLocator xmlSAXLocator;
typedef struct _xmlInput xmlInput;
typedef struct _xmlBuf xmlBuf;
typedef struct _xmlDoc xmlDoc;
typedef enum {
    XML_CHAR_ENCODING_NONE,
    XML_CHAR_ENCODING_ERROR,
    XML_CHAR_ENCODING_UTF8,
    XML_CHAR_ENCODING_UTF16LE,
    XML_CHAR_ENCODING_UTF16BE,
    XML_CHAR_ENCODING_UCS4LE,
    XML_CHAR_ENCODING_UCS4BE,
    XML_CHAR_ENCODING_EBCDIC,
    XML_CHAR_ENCODING_UCS4_2143,
    XML_CHAR_ENCODING_UCS4_3412,
    XML_CHAR_ENCODING_LAST
} xmlCharEncoding;

#define XML_PARSER_EOF 1
#define XML_PARSER_DTD 2
#define XML_PARSER_PROLOG 3
#define XML_PARSER_CONTENT 4
#define XML_PARSER_EPILOG 5
#define XML_ERR_DOCUMENT_EMPTY 1
#define XML_ERR_UNSUPPORTED_ENCODING 2
#define XML_ERR_DOCUMENT_END 3
#define XML_DOC_WELLFORMED 1
#define XML_DOC_DTDVALID 2
#define XML_DOC_NSVALID 4
#define XML_DOC_OLD10 8
#define XML_PARSE_OLD10 1
#define SAX_COMPAT_MODE "SAX_COMPAT_MODE"
#define XML_DEFAULT_VERSION "1.0"

#define GROW
#define RAW (*ctxt->input->cur)
#define NXT(n) (*(ctxt->input->cur + (n)))
#define NEXT (ctxt->input->cur++)
#define CUR RAW
#define CUR_PTR ctxt->input->cur
#define CMP5(p, c1, c2, c3, c4, c5) \
    (*(p) == (c1) && *((p)+1) == (c2) && *((p)+2) == (c3) && \
     *((p)+3) == (c4) && *((p)+4) == (c5))
#define CMP9(p, c1, c2, c3, c4, c5, c6, c7, c8, c9) \
    (*(p) == (c1) && *((p)+1) == (c2) && *((p)+2) == (c3) && \
     *((p)+3) == (c4) && *((p)+4) == (c5) && *((p)+5) == (c6) && \
     *((p)+6) == (c7) && *((p)+7) == (c8) && *((p)+8) == (c9))
#define IS_BLANK_CH(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')
#define SKIP_BLANKS while (IS_BLANK_CH(RAW)) NEXT

struct _xmlParserCtxt {
    xmlInput *input;
    xmlSAXHandler *sax;
    void *userData;
    int instate;
    int errNo;
    int standalone;
    int disableSAX;
    int wellFormed;
    int valid;
    int nsWellFormed;
    int options;
    xmlChar *version;
    xmlChar *encoding;
    xmlDoc *myDoc;
    xmlChar *intSubName;
    xmlChar *extSubSystem;
    xmlChar *extSubURI;
    int inSubset;
};

struct _xmlSAXHandler {
    void (*setDocumentLocator)(void *ctx, const xmlSAXLocator *loc);
    void (*startDocument)(void *ctx);
    void (*endDocument)(void *ctx);
    void (*externalSubset)(void *ctx, const xmlChar *name,
                          const xmlChar *ExternalID, const xmlChar *SystemID);
};

struct _xmlSAXLocator {
    int dummy;
};
extern xmlSAXLocator xmlDefaultSAXLocator;

struct _xmlInput {
    xmlBuf *buf;
    xmlChar *cur;
    xmlChar *end;
    int standalone;
    int compressed;
};

struct _xmlBuf {
    int compressed;
};

struct _xmlDoc {
    xmlChar *version;
    int properties;
    int compression;
};

void xmlInitParser(void);
xmlCharEncoding xmlDetectCharEncoding(const xmlChar *in, int len);
void xmlSwitchEncoding(xmlParserCtxtPtr ctxt, xmlCharEncoding enc);
void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
void xmlFatalErrMsg(xmlParserCtxtPtr ctxt, int error, const char *msg);
void xmlParseXMLDecl(xmlParserCtxtPtr ctxt);
void xmlParseMisc(xmlParserCtxtPtr ctxt);
void xmlParseDocTypeDecl(xmlParserCtxtPtr ctxt);
void xmlParseInternalSubset(xmlParserCtxtPtr ctxt);
void xmlParseElement(xmlParserCtxtPtr ctxt);
void xmlCleanSpecialAttr(xmlParserCtxtPtr ctxt);
void xmlDetectSAX2(xmlParserCtxtPtr ctxt);
xmlChar *xmlCharStrdup(const char *cur);
void xmlFreeDoc(xmlDoc *doc);
int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);