#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned char xmlChar;

typedef struct _xmlEntity xmlEntity;
typedef xmlEntity *xmlEntityPtr;

typedef struct _xmlParserInput xmlParserInput;
typedef struct _xmlParserCtxt {
    int instate;
    int options;
    int replaceEntities;
    int nbentities;
    xmlParserInput *input;
} xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;

struct _xmlParserInput {
    const xmlChar *cur;
};

struct _xmlEntity {
    int etype;
    xmlChar *name;
    xmlChar *content;
    int owner;
};

#define XML_PARSER_BUFFER_SIZE 1024
#define XML_MAX_TEXT_LENGTH 10000000
#define XML_PARSE_HUGE (1 << 19)
#define XML_PARSER_ATTRIBUTE_VALUE 1
#define XML_PARSER_EOF 2
#define XML_ERR_ATTRIBUTE_NOT_STARTED 3
#define XML_ERR_ATTRIBUTE_NOT_FINISHED 4
#define XML_ERR_LT_IN_ATTRIBUTE 5
#define XML_ERR_INVALID_CHAR 6
#define XML_INTERNAL_PREDEFINED_ENTITY 1
#define XML_SUBSTITUTE_REF 1

#define NXT(n) (ctxt->input->cur[(n)])
#define CUR_CHAR(l) (*(ctxt->input->cur))
#define NEXT (ctxt->input->cur++)
#define NEXTL(l) (ctxt->input->cur += (l))
#define RAW (*(ctxt->input->cur))
#define IS_CHAR(c) ((c) >= 0x20 && (c) <= 0xFFFD)
#define COPY_BUF(l,buf,len,c) (buf[len++] = (c))
#define GROW (ctxt->input->cur++)

void xmlFatalErr(xmlParserCtxtPtr ctxt, int code, const char *msg);
void xmlFatalErrMsg(xmlParserCtxtPtr ctxt, int code, const char *msg);
void xmlErrMemory(xmlParserCtxtPtr ctxt, const char *msg);
int xmlParseCharRef(xmlParserCtxtPtr ctxt);
xmlEntityPtr xmlParseEntityRef(xmlParserCtxtPtr ctxt);
xmlChar *xmlStringDecodeEntities(xmlParserCtxtPtr ctxt, const xmlChar *content, int what, int end, int end2, int end3);
int xmlStrlen(const xmlChar *str);
void *xmlMallocAtomic(size_t size);
void xmlFree(void *ptr);
int xmlCopyChar(int len, xmlChar *out, int val);
void growBuffer(xmlChar *buf, int size);