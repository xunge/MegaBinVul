#include <stddef.h>

typedef unsigned char xmlChar;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlDict xmlDict;

#define XML_PARSER_EOF 1
#define XML_PARSE_OLD10 1
#define XML_PARSE_HUGE 2
#define XML_PARSER_CHUNK_SIZE 1024
#define XML_MAX_NAME_LENGTH 100000
#define XML_ERR_NAME_TOO_LONG 1
#define XML_ERR_INTERNAL_ERROR 2

#define CUR_CHAR(l) (*(ctxt->input->cur))
#define NEXTL(l) (ctxt->input->cur++)
#define GROW
#define IS_LETTER(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))
#define IS_DIGIT(c) ((c) >= '0' && (c) <= '9')
#define IS_COMBINING(c) 0
#define IS_EXTENDER(c) 0

struct _xmlParserInput {
    const xmlChar *cur;
    const xmlChar *base;
};

struct _xmlParserCtxt {
    int instate;
    int options;
    struct _xmlParserInput *input;
    xmlDict *dict;
};

void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
const xmlChar *xmlDictLookup(xmlDict *dict, const xmlChar *name, int len);

#ifdef DEBUG
int nbParseNameComplex = 0;
#endif