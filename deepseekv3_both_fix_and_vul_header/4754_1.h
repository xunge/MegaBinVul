#include <stdlib.h>
#include <string.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlParserInput xmlParserInput;
typedef xmlParserInput *xmlParserInputPtr;
typedef struct _xmlElementContent xmlElementContent;
typedef xmlElementContent *xmlElementContentPtr;
typedef unsigned char xmlChar;

struct _xmlElementContent {
    void *parent;
};

struct _xmlSAXHandler {
    void (*elementDecl)(void *userData, const xmlChar *name, int type, xmlElementContentPtr content);
};

struct _xmlParserInput {
    const xmlChar *cur;
};

struct _xmlParserCtxt {
    xmlParserInputPtr input;
    int inputNr;
    int external;
    void *myDoc;
    struct _xmlSAXHandler *sax;
    int disableSAX;
    void *userData;
};

#define CUR_PTR (ctxt->input->cur)
#define CUR (*ctxt->input->cur)
#define RAW (*ctxt->input->cur)
#define NXT(offset) (*(ctxt->input->cur + (offset)))
#define SKIP(len) (ctxt->input->cur += (len))
#define SKIP_BLANKS while (IS_BLANK_CH(CUR)) NEXT
#define NEXT (ctxt->input->cur++)
#define CMP9(p, c1, c2, c3, c4, c5, c6, c7, c8, c9) \
    (*(p) == c1 && *((p)+1) == c2 && *((p)+2) == c3 && *((p)+3) == c4 && \
     *((p)+4) == c5 && *((p)+5) == c6 && *((p)+6) == c7 && *((p)+7) == c8 && \
     *((p)+8) == c9)
#define CMP5(p, c1, c2, c3, c4, c5) \
    (*(p) == c1 && *((p)+1) == c2 && *((p)+2) == c3 && *((p)+3) == c4 && \
     *((p)+4) == c5)
#define IS_BLANK_CH(c) ((c) == 0x20 || (c) == 0x9 || (c) == 0xD || (c) == 0xA)

#define XML_ELEMENT_TYPE_EMPTY 1
#define XML_ELEMENT_TYPE_ANY 2

enum {
    XML_ERR_SPACE_REQUIRED,
    XML_ERR_NAME_REQUIRED,
    XML_ERR_PEREF_IN_INT_SUBSET,
    XML_ERR_ELEMCONTENT_NOT_STARTED,
    XML_ERR_GT_REQUIRED,
    XML_ERR_ENTITY_BOUNDARY
};

void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *msg);
void xmlFatalErrMsg(xmlParserCtxtPtr ctxt, int error, const char *msg);
void xmlPopInput(xmlParserCtxtPtr ctxt);
xmlChar *xmlParseName(xmlParserCtxtPtr ctxt);
int xmlParseElementContentDecl(xmlParserCtxtPtr ctxt, const xmlChar *name, xmlElementContentPtr *result);
void xmlFreeDocElementContent(void *doc, xmlElementContentPtr elem);