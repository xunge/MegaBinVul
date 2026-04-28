#include <stdio.h>
#include <stdlib.h>

typedef struct _xmlParserInput {
    char *filename;
    int line;
    char *cur;
} xmlParserInput;
typedef xmlParserInput *xmlParserInputPtr;

typedef struct _xmlParserCtxt {
    xmlParserInputPtr input;
    int inputNr;
    int options;
    int instate;
} xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;

extern int xmlParserDebugEntities;
extern void *xmlGenericErrorContext;
extern void xmlGenericError(void *ctx, const char *msg, ...);
extern void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *info);
extern xmlParserInputPtr inputPop(xmlParserCtxtPtr ctxt);
extern void xmlFreeInputStream(xmlParserInputPtr input);
extern int inputPush(xmlParserCtxtPtr ctxt, xmlParserInputPtr input);

#define XML_PARSE_HUGE (1<<15)
#define XML_ERR_ENTITY_LOOP 104
#define XML_PARSER_EOF 5

#define GROW