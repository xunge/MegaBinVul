#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlParserInput xmlParserInput;
typedef int xmlParserInputState;

#define SKIP(n)
#define SKIP_BLANKS
#define CMP7(p, a, b, c, d, e, f, g) (memcmp(p, (const char[]){a,b,c,d,e,f,g}, 7) == 0)
#define CMP6(p, a, b, c, d, e, f) (memcmp(p, (const char[]){a,b,c,d,e,f}, 6) == 0)
#define RAW (*ctxt->input->cur)
#define NEXT (ctxt->input->cur++)
#define NXT(n) (*(ctxt->input->cur + n))
#define IS_BLANK_CH(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')
#define CUR (*ctxt->input->cur)
#define CUR_PTR (ctxt->input->cur)
#define SHRINK
#define XML_PARSER_EOF 0
#define XML_PARSER_IGNORE 1
#define XML_ERR_CONDSEC_INVALID 0
#define XML_ERR_ENTITY_BOUNDARY 0
#define XML_ERR_EXT_SUBSET_NOT_FINISHED 0
#define XML_ERR_CONDSEC_INVALID_KEYWORD 0
#define XML_ERR_CONDSEC_NOT_FINISHED 0

extern int xmlParserDebugEntities;
extern void *xmlGenericErrorContext;

struct _xmlParserInput {
    int id;
    char *filename;
    int line;
    const xmlChar *cur;
    const xmlChar *end;
    unsigned int consumed;
};

struct _xmlParserCtxt {
    xmlParserInput *input;
    int inputNr;
    xmlParserInputState instate;
    int disableSAX;
    int recovery;
};

void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
void xmlHaltParser(xmlParserCtxtPtr ctxt);
void xmlValidityError(xmlParserCtxtPtr ctxt, int error, const char *msg, const char *arg1, const char *arg2);
void xmlGenericError(void *ctx, const char *msg, ...);
void xmlParsePEReference(xmlParserCtxtPtr ctxt);
void xmlParseMarkupDecl(xmlParserCtxtPtr ctxt);
void xmlPopInput(xmlParserCtxtPtr ctxt);