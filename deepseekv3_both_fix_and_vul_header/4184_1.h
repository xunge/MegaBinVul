#include <stdlib.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef unsigned char xmlChar;

#define RAW (ctxt->input->cur[0])
#define NEXT (ctxt->input->cur++)
#define CUR_PTR (ctxt->input->cur)
#define SKIP_BLANKS 

enum {
    XML_PARSER_DTD,
    XML_PARSER_EOF
};

enum {
    XML_ERR_INTERNAL_ERROR,
    XML_ERR_DOCTYPE_NOT_FINISHED
};

struct _xmlParserInput {
    const xmlChar *cur;
    unsigned int consumed;
};

struct _xmlParserCtxt {
    int instate;
    struct _xmlParserInput *input;
    int inputNr;
};

void xmlParseMarkupDecl(xmlParserCtxtPtr ctxt);
void xmlParsePEReference(xmlParserCtxtPtr ctxt);
void xmlPopInput(xmlParserCtxtPtr ctxt);
void xmlFatalErr(xmlParserCtxtPtr ctxt, int code, const char *msg);