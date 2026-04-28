#include <stddef.h>
#include <string.h>

typedef unsigned char xmlChar;

typedef struct _xmlParserInput {
    const xmlChar *cur;
    const xmlChar *end;
    int col;
} xmlParserInput;

typedef struct _xmlNode {
    int line;
} xmlNode;

typedef struct _xmlSAXHandler {
    void (*endElementNs)(void *ctx, const xmlChar *name, const xmlChar *prefix, const xmlChar *URI);
} xmlSAXHandler;

typedef struct _xmlParserCtxt {
    xmlParserInput *input;
    const xmlChar *name;
    int instate;
    xmlNode *node;
    xmlSAXHandler *sax;
    void *userData;
    int disableSAX;
} xmlParserCtxt;

typedef xmlParserCtxt *xmlParserCtxtPtr;

#define RAW (*ctxt->input->cur)
#define NXT(val) (ctxt->input->cur[(val)])
#define NEXT1 (ctxt->input->cur++)
#define SKIP(val) (ctxt->input->cur += (val))
#define GROW
#define SKIP_BLANKS
#define IS_BYTE_CHAR(c) (1)
#define BAD_CAST (xmlChar*)
#define XML_ERR_LTSLASH_REQUIRED 1
#define XML_ERR_GT_REQUIRED 2
#define XML_ERR_TAG_NAME_MISMATCH 3
#define XML_PARSER_EOF 4

static void xmlFatalErr(xmlParserCtxtPtr ctxt, int code, const char *str) {}
static int xmlStrncmp(const xmlChar *s1, const xmlChar *s2, int len) { return 0; }
static xmlChar *xmlParseNameAndCompare(xmlParserCtxtPtr ctxt, const xmlChar *name) { return NULL; }
static xmlChar *xmlParseQNameAndCompare(xmlParserCtxtPtr ctxt, const xmlChar *name, const xmlChar *prefix) { return NULL; }
static void xmlFatalErrMsgStrIntStr(xmlParserCtxtPtr ctxt, int code, const char *msg, const xmlChar *str1, int num, const xmlChar *str2) {}
static void spacePop(xmlParserCtxtPtr ctxt) {}
static void nsPop(xmlParserCtxtPtr ctxt, int nr) {}