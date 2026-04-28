#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;

typedef struct _xmlParserInputBuffer {
    void *encoder;
} xmlParserInputBuffer;

typedef struct _xmlParserInput {
    xmlChar *encoding;
    xmlParserInputBuffer *buf;
    const xmlChar *cur;
} xmlParserInput;

typedef struct _xmlParserCtxt {
    unsigned long options;
    xmlChar *encoding;
    struct _xmlParserInput *input;
} xmlParserCtxt;

typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlCharEncodingHandler xmlCharEncodingHandler;
typedef xmlCharEncodingHandler *xmlCharEncodingHandlerPtr;

#define SKIP_BLANKS
#define CUR_PTR (ctxt->input->cur)
#define CMP8(p, a, b, c, d, e, f, g, h) \
    ((p)[0] == (a) && \
     (p)[1] == (b) && \
     (p)[2] == (c) && \
     (p)[3] == (d) && \
     (p)[4] == (e) && \
     (p)[5] == (f) && \
     (p)[6] == (g) && \
     (p)[7] == (h))
#define SKIP(n) (ctxt->input->cur += (n))
#define RAW (*ctxt->input->cur)
#define NEXT (ctxt->input->cur++)
#define BAD_CAST (const xmlChar *)

enum {
    XML_ERR_EQUAL_REQUIRED,
    XML_ERR_STRING_NOT_CLOSED,
    XML_ERR_STRING_NOT_STARTED,
    XML_ERR_INVALID_ENCODING,
    XML_ERR_UNSUPPORTED_ENCODING
};

#define XML_PARSE_IGNORE_ENC (1 << 0)

xmlChar *xmlParseEncName(xmlParserCtxtPtr ctxt);
void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
void xmlFatalErrMsg(xmlParserCtxtPtr ctxt, int error, const char *msg);
void xmlFatalErrMsgStr(xmlParserCtxtPtr ctxt, int error, const char *msg, const xmlChar *str);
void xmlFree(void *ptr);
int xmlStrcasecmp(const xmlChar *str1, const xmlChar *str2);
xmlCharEncodingHandlerPtr xmlFindCharEncodingHandler(const char *name);
int xmlSwitchToEncoding(xmlParserCtxtPtr ctxt, xmlCharEncodingHandlerPtr handler);