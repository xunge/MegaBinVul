#include <stdlib.h>
#include <string.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlParserInputBuffer xmlParserInputBuffer;
typedef xmlParserInputBuffer *xmlParserInputBufferPtr;
typedef struct _xmlBuf xmlBuf;

typedef enum {
    XML_ERR_OK,
    XML_ERR_INTERNAL_ERROR,
    XML_ERR_INVALID_ENCODING,
    XML_ERR_DOCUMENT_END
} xmlParserErrors;

typedef enum {
    XML_PARSER_START,
    XML_PARSER_EOF,
    XML_PARSER_EPILOG
} xmlParserState;

#define XML_MAX_TEXT_LENGTH 1000
#define XML_MAX_LOOKUP_LIMIT 1000
#define XML_PARSE_HUGE (1 << 19)
#define BAD_CAST (xmlChar *)

typedef unsigned char xmlChar;

struct _xmlCharEncodingHandler {
    char *name;
};

struct _xmlParserInputBuffer {
    xmlBuf *buffer;
    xmlBuf *raw;
    struct _xmlCharEncodingHandler *encoder;
    size_t rawconsumed;
};

struct _xmlParserInput {
    const xmlChar *base;
    const xmlChar *cur;
    const xmlChar *end;
    xmlParserInputBufferPtr buf;
    int length;
};

struct _xmlParserCtxt {
    int errNo;
    int disableSAX;
    xmlParserState instate;
    struct _xmlParserInput *input;
    int options;
    int wellFormed;
    struct _xmlSAXHandler *sax;
    void *userData;
};

struct _xmlSAXHandler {
    void (*endDocument)(void *userData);
};

extern void *xmlGenericErrorContext;

size_t xmlBufGetInputBase(xmlBuf *buf, struct _xmlParserInput *input);
size_t xmlBufUse(xmlBuf *buf);
void xmlBufSetInputBaseCur(xmlBuf *buf, struct _xmlParserInput *input, size_t base, size_t cur);
int xmlParserInputBufferPush(xmlParserInputBufferPtr in, int size, const char *chunk);
int xmlCharEncInput(xmlParserInputBufferPtr in);
void xmlDetectSAX2(xmlParserCtxtPtr ctxt);
void xmlParseTryOrFinish(xmlParserCtxtPtr ctxt, int terminate);
int xmlParseCheckTransition(xmlParserCtxtPtr ctxt, const char *str, int len);
void xmlFatalErr(xmlParserCtxtPtr ctxt, xmlParserErrors error, const char *msg);
xmlChar *xmlStrcasestr(const xmlChar *haystack, const xmlChar *needle);
void xmlGenericError(void *ctx, const char *msg, ...);