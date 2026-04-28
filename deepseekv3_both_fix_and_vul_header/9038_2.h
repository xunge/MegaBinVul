#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlCharEncodingHandler xmlCharEncodingHandler;
typedef xmlCharEncodingHandler *xmlCharEncodingHandlerPtr;

struct _xmlParserInput {
    const xmlChar *cur;
    xmlChar *encoding;
    struct _xmlParserInputBuffer *buf;
};

struct _xmlParserInputBuffer {
    xmlCharEncodingHandlerPtr encoder;
};

struct _xmlParserCtxt {
    int options;
    xmlChar *encoding;
    struct _xmlParserInput *input;
    int errNo;
};

#define SKIP_BLANKS while (IS_BLANK(*(ctxt->input->cur))) NEXT
#define IS_BLANK(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')
#define CUR_PTR (ctxt->input->cur)
#define CMP8(p, c1, c2, c3, c4, c5, c6, c7, c8) \
    (*(p) == (c1) && *((p)+1) == (c2) && *((p)+2) == (c3) && *((p)+3) == (c4) && \
     *((p)+4) == (c5) && *((p)+5) == (c6) && *((p)+6) == (c7) && *((p)+7) == (c8))
#define SKIP(n) (ctxt->input->cur += (n))
#define RAW (*(ctxt->input->cur))
#define NEXT (ctxt->input->cur++)

#define BAD_CAST (xmlChar *)

#define XML_PARSE_IGNORE_ENC (1 << 0)

enum {
    XML_ERR_EQUAL_REQUIRED,
    XML_ERR_STRING_NOT_CLOSED,
    XML_ERR_STRING_NOT_STARTED,
    XML_ERR_INVALID_ENCODING,
    XML_ERR_UNSUPPORTED_ENCODING
};

void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
void xmlFatalErrMsg(xmlParserCtxtPtr ctxt, int error, const char *msg);
void xmlFatalErrMsgStr(xmlParserCtxtPtr ctxt, int error, const char *msg, const char *str);
void xmlFree(void *ptr);
xmlChar *xmlParseEncName(xmlParserCtxtPtr ctxt);
int xmlStrcasecmp(const xmlChar *str1, const xmlChar *str2);
xmlCharEncodingHandlerPtr xmlFindCharEncodingHandler(const char *name);
int xmlSwitchToEncoding(xmlParserCtxtPtr ctxt, xmlCharEncodingHandlerPtr handler);