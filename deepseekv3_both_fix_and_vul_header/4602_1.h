#include <stddef.h>

typedef unsigned char xmlChar;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlDict xmlDict;

static int nbParseNCNameComplex;

#define GROW
#define CUR_PTR (ctxt->input->cur)
#define BASE_PTR (ctxt->input->base)
#define CUR_CHAR(l) (*CUR_PTR)
#define NEXTL(l) (CUR_PTR++)
#define XML_PARSER_CHUNK_SIZE 4096
#define XML_MAX_NAME_LENGTH 1000
#define XML_PARSE_HUGE (1 << 15)
#define XML_PARSER_EOF 1
#define XML_ERR_NAME_TOO_LONG 1

int xmlIsNameStartChar(xmlParserCtxtPtr ctxt, int c);
int xmlIsNameChar(xmlParserCtxtPtr ctxt, int c);
void xmlFatalErr(xmlParserCtxtPtr ctxt, int err, const char *msg);
xmlChar *xmlDictLookup(xmlDict *dict, const char *name, int len);

struct _xmlParserCtxt {
    int options;
    int instate;
    struct _xmlParserInput *input;
    xmlDict *dict;
};

struct _xmlParserInput {
    const char *cur;
    const char *base;
};