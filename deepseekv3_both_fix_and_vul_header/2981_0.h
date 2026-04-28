#include <stddef.h>

#define XML_PARSE_HUGE (1<<0)
#define XML_MAX_TEXT_LENGTH 10000000
#define XML_PARSER_NON_LINEAR 10
#define XML_PARSER_BIG_ENTITY 1000000
#define XML_ERR_ENTITY_LOOP 1

typedef struct _xmlParserInput xmlParserInput;
typedef struct _xmlEntity xmlEntity;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef xmlEntity *xmlEntityPtr;

struct _xmlParserInput {
    const char *cur;
    const char *base;
    size_t consumed;
};

struct _xmlEntity {
    size_t checked;
};

struct _xmlParserCtxt {
    unsigned long options;
    struct {
        int code;
    } lastError;
    xmlParserInput *input;
    size_t sizeentities;
    size_t nbentities;
};

void xmlFatalErr(xmlParserCtxtPtr ctxt, int code, const char *msg);