#include <stdlib.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef unsigned char xmlChar;

#define XML_DEFAULT_VERSION "1.0"
#define XML_ERR_SPACE_REQUIRED 1
#define XML_ERR_VERSION_MISSING 2
#define XML_ERR_UNKNOWN_VERSION 3
#define XML_ERR_UNSUPPORTED_ENCODING 4
#define XML_ERR_XMLDECL_NOT_FINISHED 5
#define XML_WAR_UNKNOWN_VERSION 6
#define XML_PARSE_OLD10 (1<<0)

#define RAW (*ctxt->input->cur)
#define NXT(i) (*(ctxt->input->cur + (i)))
#define CUR_PTR (ctxt->input->cur)
#define SKIP(i) (ctxt->input->cur += (i))
#define NEXT (ctxt->input->cur++)
#define IS_BLANK_CH(c) ((c) == 0x20 || (c) == 0x9 || (c) == 0xD || (c) == 0xA)
#define SKIP_BLANKS while (IS_BLANK_CH(RAW)) NEXT
#define GROW (ctxt->input->cur = CUR_PTR + 1)
#define MOVETO_ENDTAG(p) while (*p != '>') p++

enum {
    XML_PARSER_EOF
};

struct _xmlParserInput {
    xmlChar *cur;
    int standalone;
    const xmlChar *encoding;
};

struct _xmlParserCtxt {
    struct _xmlParserInput *input;
    const xmlChar *version;
    int options;
    int errNo;
    int instate;
};

extern void xmlFatalErr(xmlParserCtxtPtr ctxt, int code, const char *msg);
extern void xmlFatalErrMsg(xmlParserCtxtPtr ctxt, int code, const char *msg);
extern void xmlFatalErrMsgStr(xmlParserCtxtPtr ctxt, int code, const char *msg, const xmlChar *str);
extern void xmlWarningMsg(xmlParserCtxtPtr ctxt, int code, const char *msg, const xmlChar *str, void *data);
extern xmlChar *xmlParseVersionInfo(xmlParserCtxtPtr ctxt);
extern void xmlParseEncodingDecl(xmlParserCtxtPtr ctxt);
extern int xmlParseSDDecl(xmlParserCtxtPtr ctxt);
extern int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
extern void xmlFree(void *ptr);