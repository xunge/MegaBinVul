#include <stdlib.h>

#define XML_MAX_LOOKUP_LIMIT 10000000
#define INPUT_CHUNK 4096
#define XML_ERR_INTERNAL_ERROR 1
#define XML_PARSE_HUGE (1<<0)
#define XML_PARSER_EOF 5

typedef struct _xmlParserInputBuffer xmlParserInputBuffer;
typedef struct _xmlParserInput xmlParserInput;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef int (*xmlInputReadCallback)(void *context, char *buffer, int len);

struct _xmlParserInputBuffer {
    xmlInputReadCallback readcallback;
};

struct _xmlParserInput {
    const char *cur;
    const char *base;
    const char *end;
    xmlParserInputBuffer *buf;
};

typedef xmlParserCtxt *xmlParserCtxtPtr;

struct _xmlParserCtxt {
    xmlParserInput *input;
    int options;
    int instate;
};

void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
int xmlParserInputGrow(xmlParserInput *input, int chunk);
void xmlPopInput(xmlParserCtxtPtr ctxt);
int xmlNop(void);