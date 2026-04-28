#include <stdlib.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;

#define GROW
#define CUR ctxt->input->cur[0]
#define NXT(n) ctxt->input->cur[n]
#define RAW ctxt->input->cur[0]

enum {
    XML_PARSER_EOF,
    XML_PARSER_DTD
};

struct _xmlParserInput {
    const char *cur;
};

struct _xmlParserCtxt {
    struct _xmlParserInput *input;
    int instate;
    int external;
    int inputNr;
};

void xmlParseElementDecl(xmlParserCtxtPtr ctxt);
void xmlParseEntityDecl(xmlParserCtxtPtr ctxt);
void xmlParseAttributeListDecl(xmlParserCtxtPtr ctxt);
void xmlParseNotationDecl(xmlParserCtxtPtr ctxt);
void xmlParseComment(xmlParserCtxtPtr ctxt);
void xmlParsePI(xmlParserCtxtPtr ctxt);
void xmlParsePEReference(xmlParserCtxtPtr ctxt);
void xmlParseConditionalSections(xmlParserCtxtPtr ctxt);