#include <stddef.h>

#define XML_PARSER_EOF 1
#define XML_ERR_USER_STOP 1
#define BAD_CAST (const xmlChar *)

typedef unsigned char xmlChar;

typedef struct _xmlParserInput xmlParserInput;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;

struct _xmlParserInput {
    const xmlChar *cur;
    const xmlChar *base;
};

struct _xmlParserCtxt {
    int instate;
    int errNo;
    int disableSAX;
    xmlParserInput *input;
};