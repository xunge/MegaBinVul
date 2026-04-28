#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlParserInput xmlParserInput;
typedef enum {
    XML_PARSER_EOF,
    XML_PARSER_IGNORE
} xmlParserInputState;

#define XML_ERR_CONDSEC_INVALID 1
#define XML_ERR_ENTITY_BOUNDARY 2
#define XML_ERR_EXT_SUBSET_NOT_FINISHED 3
#define XML_ERR_CONDSEC_INVALID_KEYWORD 4
#define XML_ERR_CONDSEC_NOT_FINISHED 5

#define CUR_PTR ((const xmlChar*)ctxt->input->cur)
#define RAW (*ctxt->input->cur)
#define CUR (*ctxt->input->cur)
#define NEXT (ctxt->input->cur++)
#define NXT(n) (ctxt->input->cur[n])
#define SKIP(n) (ctxt->input->cur += (n))
#define SKIP_BLANKS while (IS_BLANK_CH(CUR)) NEXT
#define CMP7(p, c1, c2, c3, c4, c5, c6, c7) \
    (p[0] == c1 && p[1] == c2 && p[2] == c3 && p[3] == c4 && \
     p[4] == c5 && p[5] == c6 && p[6] == c7)
#define CMP6(p, c1, c2, c3, c4, c5, c6) \
    (p[0] == c1 && p[1] == c2 && p[2] == c3 && p[3] == c4 && \
     p[4] == c5 && p[5] == c6)
#define IS_BLANK_CH(c) (c == 0x20 || c == 0x9 || c == 0xD || c == 0xA)
#define SHRINK

extern int xmlParserDebugEntities;
extern void *xmlGenericErrorContext;

void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
void xmlValidityError(xmlParserCtxtPtr ctxt, int error, const char *msg, const char *arg1, const char *arg2);
void xmlGenericError(void *ctx, const char *msg, ...);
void xmlParsePEReference(xmlParserCtxtPtr ctxt);
void xmlParseMarkupDecl(xmlParserCtxtPtr ctxt);
void xmlPopInput(xmlParserCtxtPtr ctxt);

struct _xmlParserInput {
    const char *cur;
    const char *filename;
    int line;
    int id;
    unsigned int consumed;
};

struct _xmlParserCtxt {
    xmlParserInput *input;
    int inputNr;
    int instate;
    int disableSAX;
    int recovery;
};