#include <stddef.h>
#include <ctype.h>

typedef unsigned char xmlChar;

#define IS_BLANK_CH(c) (isblank((c)))
#define SKIP_BLANKS while (IS_BLANK_CH(CUR)) NEXT
#define NEXT ctxt->cur++
#define CUR (*ctxt->cur)
#define NXT(off) (ctxt->cur[(off)])
#define PUSH(op, val, val2, novar) \
    xsltPatPush(ctxt->comp, op, val, val2, novar)

enum {
    XSLT_OP_ROOT,
    XSLT_OP_PARENT, 
    XSLT_OP_ANCESTOR
};

typedef struct _xsltParserContext {
    const xmlChar *cur;
    struct {
        double priority;
    } *comp;
    int error;
} xsltParserContext;
typedef xsltParserContext *xsltParserContextPtr;

void xsltCompileRelativePathPattern(xsltParserContextPtr ctxt, xmlChar *name, int novar);
void xsltPatPush(void *comp, int op, void *val, void *val2, int novar);
xmlChar *xsltScanNCName(xsltParserContextPtr ctxt);
int xmlXPathIsNodeType(const xmlChar *name);
void xsltCompileIdKeyPattern(xsltParserContextPtr ctxt, xmlChar *name, int arg1, int novar, int arg2);
void xsltTransformError(void *a, void *b, void *c, const char *msg);