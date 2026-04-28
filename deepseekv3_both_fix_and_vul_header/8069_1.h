#include <stdlib.h>
#include <string.h>

typedef struct _xmlXPathParserContext xmlXPathParserContext;
typedef xmlXPathParserContext *xmlXPathParserContextPtr;
typedef unsigned char xmlChar;

#define CUR (ctxt->cur[0])
#define NXT(n) (ctxt->cur[(n)])
#define IS_ASCII_DIGIT(c) ((c) >= '0' && (c) <= '9')
#define IS_BLANK_CH(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')
#define SKIP_BLANKS while (IS_BLANK_CH(CUR)) ctxt->cur++
#define SKIP(n) (ctxt->cur += (n))
#define BAD_CAST (xmlChar *)

struct _xmlXPathParserContext {
    const xmlChar *cur;
    int xptr;
    struct {
        int last;
    } *comp;
};

extern void *xmlGenericErrorContext;
extern xmlChar *xmlXPathScanName(xmlXPathParserContextPtr ctxt);
extern int xmlStrlen(const xmlChar *str);
extern xmlChar *xmlStrstr(const xmlChar *haystack, const xmlChar *needle);
extern int xmlXPathIsNodeType(const xmlChar *name);
extern int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
extern void xmlFree(void *ptr);
extern void xmlGenericError(void *ctx, const char *msg);
extern void xmlXPathCompLocationPath(xmlXPathParserContextPtr ctxt);
extern void xmlXPathCompFilterExpr(xmlXPathParserContextPtr ctxt);
extern void xmlXPathCompRelativeLocationPath(xmlXPathParserContextPtr ctxt);

#define XP_ERROR(x) 
#define PUSH_LEAVE_EXPR(x, y, z) 
#define PUSH_LONG_EXPR(x, y, z, a, b, c) 
#define PUSH_UNARY_EXPR(x, y, z, a) 
#define CHECK_ERROR 
#define XPATH_OP_ROOT 0
#define XPATH_OP_NODE 0
#define XPATH_OP_COLLECT 0
#define XPATH_OP_RESET 0
#define AXIS_DESCENDANT_OR_SELF 0
#define NODE_TEST_TYPE 0
#define NODE_TYPE_NODE 0
#define XPATH_EXPR_ERROR 0